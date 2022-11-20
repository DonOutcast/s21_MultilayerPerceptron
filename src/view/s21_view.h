#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <chrono>
#include <thread>
#include <QIcon>
#include <QActionGroup>
#include <QButtonGroup>
#include <QCheckBox>
#include <QMainWindow>
#include <QProgressBar>
#include <QRadioButton>
#include <QMessageBox>




using namespace std::chrono_literals;

QT_BEGIN_NAMESPACE
namespace Ui { class s21_view; }
QT_END_NAMESPACE

class s21_view : public QMainWindow
{
    Q_OBJECT

public:
    s21_view(QWidget *parent = nullptr);
    ~s21_view();
    auto Predict() -> void;

private:
    auto setSlots() -> void;  // связывание сигналов со слотами
    auto groupingActionUpperToolBar() -> void;  // группировка actions находящихс в toolBar

private slots:
      void triggeredGroupActionUpper(QAction *action);

private:
      auto action_open_folder() -> void;
      auto action_upload_weights() -> void;
      auto action_download_weights() -> void;
      auto action_upload_images() -> void;
      auto action_download_images() -> void;
      auto action_settings() -> void;
      auto action_test() -> void;
      auto action_train() -> void;
      auto settings_on_off() -> void;

private:
    Ui::s21_view *ui;
    QActionGroup *groupActionUpper_;
    QString filePath_{};
    QString fileName_{};
    const QString weightsPath = "../src/weights/";
    const QString bmpPath = "../src/bmp/";
    const QString emnistPath = "../src/emnist/";
};
#endif // S21_VIEW_H
