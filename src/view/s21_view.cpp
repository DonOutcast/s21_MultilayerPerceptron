#include "s21_view.h"
#include "ui_s21_view.h"

s21_view::s21_view(QWidget *parent) : QMainWindow(parent) , ui(new Ui::s21_view)  ,m_controller(new s21::Controller) ,
    groupActionUpper_(new QActionGroup(this))  {
    ui->setupUi(this);

    ui->plot->setBackground(QColor(32, 32, 32));
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->yAxis->setSubTicks(false);
    ui->plot->xAxis->setBasePen(QPen(Qt::white));
    ui->plot->xAxis->setTickPen(QPen(Qt::white));
    ui->plot->yAxis->setBasePen(QPen(Qt::white));
    ui->plot->yAxis->setTickPen(QPen(Qt::white));
    ui->plot->xAxis->setLabelColor(Qt::white);
    ui->plot->yAxis->setLabelColor(Qt::white);
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setLabel("ERRORS%");
    ui->plot->yAxis->setRange(0, 100);




     ui->scene->SetMainWindow(this);
     m_controller->set_net(s21::NetworkType::MATRIX, this->GetLayersNumber());
     this->SetController(m_controller);
     /*---группировка actions находящихся на верхнем toolBar---*/
     groupingActionUpperToolBar();
     /*-------------------------------------------------------*/
      ui->groupBox_settings->hide();
     this->setSlots();

      ui->kGroupsSpinBox->setDisabled(true);
}

s21_view::~s21_view() {
    delete ui;
}

auto s21_view::Predict() -> void {
  if (!ui->scene->IsClear()) {
//      qDebug() << ui->scene->VectorFromImage();
//      qDebug() << "Befor init";
    m_controller->feed_init_values(ui->scene->VectorFromImage());
//          qDebug() << "Befor forward";
      this->m_controller->feed_forward();
//                qDebug() << "Befor get";
    ui->answer_label->setText(QString(QChar(static_cast<int>(m_controller->get_result() + this->asciiBias))));
//          qDebug() << "AFter all";
  } else {
    ui->answer_label->setText("");
  }

}






auto s21_view::groupingActionUpperToolBar() ->void {
  groupActionUpper_->addAction(ui->actionDownload_images);
  this->groupActionUpper_->addAction(ui->action_upload_images);
  this->groupActionUpper_->addAction(ui->actionSettings);
  this->groupActionUpper_->addAction(ui->actionUpload_weights);
  this->groupActionUpper_->addAction(ui->actionDownload_weights);
//  groupActionUpper_->addAction(ui->act_make_gif);
//  groupActionUpper_->addAction(ui->act_gif_360);
//  groupActionUpper_->addAction(ui->act_screenShot);
//  groupActionUpper_->addAction(ui->act_info);
//  groupActionUpper_->addAction(ui->act_texture);
//  groupActionUpper_->addAction(ui->act_light_on_off);
//  groupActionUpper_->addAction(ui->act_shade);
//  groupActionUpper_->addAction(ui->act_projection);
//  groupActionUpper_->addAction(ui->act_axis_rotate);
//  groupActionUpper_->addAction(ui->act_delete_models);
}

auto s21_view::setSlots() -> void {
    // группа QAction верхнего toolBar
    connect(groupActionUpper_, SIGNAL(triggered(QAction *)), this,
            SLOT(triggeredGroupActionUpper(QAction *)));
    /*----------------------------------------*/
}

auto s21_view::action_open_folder() -> void {
  QString filePath = QFileDialog::getOpenFileName(
      this, "Select a file to open...", QDir::homePath(), "*.obj");
  if (!filePath.isEmpty()) {
//    bool loading_flag = controller.add_object(filePath);
//    if (loading_flag == false) {
      QMessageBox::warning(this, "Information",
                           "Incorrect obj. File. Please retry load another!");
    }
//  else {
//      buttonResetModelClicked();  // если были какие-то натсройки модели,
                                  // скидываем до дэфолтных
//      buttonClearConditionClicked();  // если были сохранены каке-то состояния
                                      // скидываем до 0
//      ui->act_modelCamera->setIcon(
//          QIcon(":/icons_ui/model_camera.png"));  // изменение иконки для модели
                                                  // камеры
//      ui->openGLWidget->update();  // отрисовка выбранного объекта
//    }
//  }
}



auto s21_view::action_download_weights() -> void{
      ui->actionDownload_weights->setIcon(QIcon(":/resource/qrc/download_on.png"));
      filePath_ = QFileDialog::getExistingDirectory(
                     this, "Open directory to save file", weightsPath,
                     QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
                 "/";
      if (!filePath_.isEmpty()) {
        fileName_ = filePath_ + "weights_" +
                   QString::number((this->GetLayersNumber()));
        m_controller->save_weights(fileName_.toStdString() + ".txt");

      }
      ui->actionDownload_weights->setIcon(QIcon(":/resource/qrc/download.png"));
}

auto s21_view::action_upload_weights() -> void {
      ui->actionUpload_weights->setIcon(QIcon(":/resource/qrc/upload_on.png"));
      filePath_ =
          QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                       weightsPath, QFileDialog::tr("(*.txt)"));
      if (!filePath_.isEmpty()) {
        m_controller->load_weights(filePath_.toStdString());
//        m_controller->save_weights(fileName_.toStdString());
      }
     ui->actionUpload_weights->setIcon(QIcon(":/resource/qrc/upload.png"));

}

auto s21_view::action_download_images() -> void {
      ui->actionDownload_images->setIcon(QIcon(":/resource/qrc/download_on.png"));
      if (!ui->scene->IsClear()) {
        QString currentTime =
            QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
        filePath_ =
            QFileDialog::getExistingDirectory(
                this, "Open directory to save file", bmpPath,
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
            "/";
        if (!filePath_.isEmpty()) {
          fileName_ = filePath_ + ui->answer_label->text() + "_" + currentTime;
          ui->scene->GetImage().save(fileName_ + ".bmp", "BMP");
        }

      } else {
        QMessageBox::information(this, "titel", "No have latter for save");
      }
        ui->actionDownload_images->setIcon(QIcon(":/resource/qrc/download.png"));
}

auto s21_view::action_upload_images() -> void {
      ui->action_upload_images->setIcon(QIcon(":/resource/qrc/upload_on.png"));
      filePath_ = QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                               QDir::homePath(), QFileDialog::tr("(*.bmp)"));
      if (!filePath_.isEmpty()) {
        ui->scene->SetImage(filePath_);
        Predict();
       }
      ui->action_upload_images->setIcon(QIcon(":/resource/qrc/upload.png"));
}


auto s21_view::settings_on_off() -> void {
    if (ui->actionSettings->iconText() == "Settings_on") {
      ui->groupBox_settings->hide();
      ui->actionSettings->setIcon(QIcon(":/resource/qrc/setting.png"));
      ui->actionSettings->setIconText("Settings_off");
//      controller.setLightStatus(lightStatus::OFF);
    } else {
      ui->actionSettings->setIcon(QIcon(":/resource/qrc/settings_on.png"));
      ui->actionSettings->setIconText("Settings_on");
//      controller.setLightStatus(lightStatus::ON);
     ui->groupBox_settings->show();

    }
}

auto s21_view::action_train() -> void {
    filePath_ =QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"), emnistPath, QFileDialog::tr("(*.csv)"));
//    if (!this->filePath_.isEmpty())
}


//void MainWindow::on_trainButton_clicked() {
//  filePath =
//      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
//                                   emnistPath, QFileDialog::tr("(*.csv)"));
//  if (!filePath.isEmpty()) {
//    ChangeGUIAccept(false);
//    m_thread = std::thread([&]() {
//      if (settingsWindow->IsCrossValidation()) {
//        if (settingsWindow->GetKGroups() != 1) {
//          emit trainDone(m_controller->CrossValidation(
//              filePath.toStdString(), settingsWindow->GetKGroups()));
//        }
//      } else {
//        emit trainDone(m_controller->Train(filePath.toStdString(),
//                                           settingsWindow->GetEpochNumber()));
//      }
//      ChangeGUIAccept(true);
//    });
//    m_thread.detach();
//  }
//}


auto s21_view::triggeredGroupActionUpper(QAction *action) -> void {
  if (action == ui->actionDownload_images) {
    this->action_download_images();
  }
  else if (action == ui->action_upload_images) {
    this->action_upload_images();
  } else if (action == ui->actionSettings) {
    this->settings_on_off();
  } else if (action == ui->actionUpload_weights) {
      this->action_upload_weights();
  } else if (action == ui->actionDownload_weights) {
      this->action_download_weights();
  }
  //else if (action == ui->act_texture) {
//    action_texture_triggered();
//  } else if (action == ui->act_info) {
//    action_info_triggered();
//  } else if (action == ui->act_delete_models) {
//    action_delete_models();
//  } else if (action == ui->act_screenShot) {
//    action_screenshot();
//  } else if (action == ui->act_make_gif) {
//    action_make_gif();
//  } else if (action == ui->act_gif_360) {
//    action_make_gif_360();
//  } else if (action == ui->act_shade) {
//    action_shade();
//  } else if (action == ui->act_axis_rotate) {
//    action_axis_rotate();
//  }
}


auto s21_view::GetLayersNumber() -> int {
  return ui->layersBox->currentText().toInt();
}

auto s21_view::closeEvent(QCloseEvent* event) -> void {
//  s21::NetworkType netType;
  if (ui->matrixTypeButton->isChecked()) {
//    netType = s21::NetworkType::MATRIX;
  } else {
//    netType = s21::NetworkType::GRAPH;
  }
//  m_controller->SetNet(netType, ui->layersBox->currentText().toInt());
  event->accept();
}

auto s21_view::SetController(s21::Controller* controller) -> void {
  m_controller = controller;
}

auto s21_view::GetSelectionPart() -> double {
  return ui->selectonPartSpinBox->value();
}

auto s21_view::on_crossValidationCheckBox_stateChanged(int arg1) -> void{
  if (arg1) {
    ui->kGroupsSpinBox->setEnabled(true);
  } else {
    ui->kGroupsSpinBox->setValue(1);
    ui->kGroupsSpinBox->setDisabled(true);
  }
}

auto s21_view::GetEpochNumber() -> size_t {
  return ui->epochBox->currentText().toUInt();
}

auto s21_view::IsCrossValidation() -> bool {
  return ui->crossValidationCheckBox->isChecked();
}

auto s21_view::GetKGroups() -> size_t {
  return static_cast<size_t>(ui->kGroupsSpinBox->value());
}



