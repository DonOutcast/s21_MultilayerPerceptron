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
#include "../controller/controller.h"



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
    auto ChangeGUIAccept(bool accept) -> void;

private:
    auto setSlots() -> void;  // связывание сигналов со слотами
    auto groupingActionUpperToolBar() -> void;  // группировка actions находящихс в toolBar

private slots:
      void triggeredGroupActionUpper(QAction *action);
      auto on_crossValidationCheckBox_stateChanged(int arg1) -> void;

signals:
   void testDone();
   void trainDone(const std::vector<double>& values);


private:
      auto action_open_folder() -> void;
      auto action_upload_weights() -> void;
      auto action_download_weights() -> void;
      auto action_upload_images() -> void;
      auto action_download_images() -> void;
      auto action_settings() -> void;
      auto action_test() -> void;
      auto settings_on_off() -> void;

      auto closeEvent(QCloseEvent* enevet) -> void override;
      auto GetKGroups() -> size_t;
      auto IsCrossValidation() -> bool;
      auto GetEpochNumber() -> size_t;
      auto GetSelectionPart() -> double;
      auto SetController(s21::Controller* controller) -> void;
      auto GetLayersNumber() -> int;

private:
      auto set_configurate_plot() -> void;
      auto action_train() -> void;

public:
      auto AddData(const QString mode, const std::vector<double> values) -> void;
      auto showTrainWindow(const std::vector<double>& values) -> void;

public:
      auto SetAccuracy(const double accuracy) -> void;
      auto SetPrecison(const double precision) -> void;
      auto SetRecall(const double recall) -> void;
      auto SetMeasure(const double measure) -> void;
      auto SetTime(const double time) -> void;

private:
    Ui::s21_view *ui;
    static constexpr int defaultLayers = 2;
    s21::Controller*  m_controller {};
    QActionGroup *groupActionUpper_;
    QString filePath_{};
    QString fileName_{};
    std::thread m_thread_{};
    s21::Metrics m_metrics_{};

    static constexpr int asciiBias = 65;
    const QString weightsPath = "../src/weights/";
    const QString bmpPath = "../src/bmp/";
    const QString emnistPath = "../src/emnist/";
};
#endif // S21_VIEW_H
