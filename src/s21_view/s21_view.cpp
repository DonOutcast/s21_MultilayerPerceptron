#include "s21_view.h"
#include "ui_s21_view.h"

s21_view::s21_view(QWidget *parent) : QMainWindow(parent) , ui(new Ui::s21_view) {
    ui->setupUi(this);
     ui->scene->SetMainWindow(this);

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
