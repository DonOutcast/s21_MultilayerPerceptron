#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <chrono>
#include <thread>



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
    Ui::s21_view *ui;

};
#endif // S21_VIEW_H
