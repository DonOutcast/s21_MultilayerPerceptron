#include "s21_view.h"
#include "ui_s21_view.h"

s21_view::s21_view(QWidget *parent) : QMainWindow(parent) , ui(new Ui::s21_view)  ,groupActionUpper_(new QActionGroup(this)) {
    ui->setupUi(this);
     ui->scene->SetMainWindow(this);
     /*---группировка actions находящихся на верхнем toolBar---*/
     groupingActionUpperToolBar();
     /*-------------------------------------------------------*/
      ui->groupBox_settings->hide();
     this->setSlots();
}

s21_view::~s21_view() {
    delete ui;
}

auto s21_view::Predict() -> void {
  if (!ui->scene->IsClear()) {
//    m_controller->FeedInitValues(ui->renderingScene->VectorFromImage());
//    m_controller->FeedForward();
//    ui->answerLabel->setText(QString(
//        QChar(static_cast<int>(m_controller->GetResult()) + asciiBias)));
  } else {
    ui->answer_label->setText("");
  }
}


auto s21_view::groupingActionUpperToolBar() ->void {
  groupActionUpper_->addAction(ui->actionDownload_images);
  this->groupActionUpper_->addAction(ui->action_upload_images);
  this->groupActionUpper_->addAction(ui->actionSettings);
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


//void MainWindow::on_saveWeightsButton_clicked() {
//  filePath = QFileDialog::getExistingDirectory(
//                 this, "Open directory to save file", weightsPath,
//                 QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
//             "/";
//  if (!filePath.isEmpty()) {
//    fileName = filePath + "weights_" +
//               QString::number((settingsWindow->GetLayersNumber()));
//    m_controller->SaveWeights(fileName.toStdString() + ".txt");
//  }
//}

//void MainWindow::on_loadWeigthsButton_clicked() {
//  filePath =
//      QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
//                                   weightsPath, QFileDialog::tr("(*.txt)"));
//  if (!filePath.isEmpty()) {
//    m_controller->LoadWeights(filePath.toStdString());
//  }
//}

//void MainWindow::on_saveImageButton_clicked() {
//  if (!ui->renderingScene->IsClear()) {
//    QString currentTime =
//        QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
//    filePath =
//        QFileDialog::getExistingDirectory(
//            this, "Open directory to save file", bmpPath,
//            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
//        "/";
//    if (!filePath.isEmpty()) {
//      fileName = filePath + ui->answerLabel->text() + "_" + currentTime;
//      ui->renderingScene->GetImage().save(fileName + ".bmp", "BMP");
//    }
//  }
//}

//void MainWindow::on_loadImageButton_clicked() {
//  filePath = QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
//                                          bmpPath, QFileDialog::tr("(*.bmp)"));
//  if (!filePath.isEmpty()) {
//    ui->renderingScene->SetImage(filePath);
//    Predict();
//  }
//}



auto s21_view::action_download_weights() -> void{

}

auto s21_view::action_upload_weights() -> void {

}

auto s21_view::action_download_images() -> void {

}

auto s21_view::action_upload_images() -> void {
      filePath_ = QFileDialog::getOpenFileName(this, QFileDialog::tr("Open file"),
                                              QDir::homePath(), QFileDialog::tr("(*.bmp)"));
      qDebug() << "IN function";
      if (!filePath_.isEmpty()) {
        ui->scene->SetImage(filePath_);
        Predict();
       }
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

auto s21_view::triggeredGroupActionUpper(QAction *action) -> void {
  if (action == ui->actionDownload_images) {
    this->action_open_folder();
  }
  else if (action == ui->action_upload_images) {
    this->action_upload_images();
  } else if (action == ui->actionSettings) {
    this->settings_on_off();
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
