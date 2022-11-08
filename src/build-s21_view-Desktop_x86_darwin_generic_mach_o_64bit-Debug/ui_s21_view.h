/********************************************************************************
** Form generated from reading UI file 's21_view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_VIEW_H
#define UI_S21_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "render_scene.h"

QT_BEGIN_NAMESPACE

class Ui_s21_view
{
public:
    QWidget *centralwidget;
    RenderScene *scene;
    QLabel *answer_label;
    QLabel *image_label;
    QLabel *weights_label;
    QPushButton *button_download;
    QLabel *label;
    QPushButton *button_upload;
    QPushButton *button_download_w;
    QPushButton *button_upload_w;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *s21_view)
    {
        if (s21_view->objectName().isEmpty())
            s21_view->setObjectName(QString::fromUtf8("s21_view"));
        s21_view->resize(800, 600);
        centralwidget = new QWidget(s21_view);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scene = new RenderScene(centralwidget);
        scene->setObjectName(QString::fromUtf8("scene"));
        scene->setGeometry(QRect(10, 10, 400, 400));
        scene->setMinimumSize(QSize(400, 400));
        scene->setMaximumSize(QSize(400, 400));
        scene->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background: #FFFFFF;\n"
"}"));
        answer_label = new QLabel(scene);
        answer_label->setObjectName(QString::fromUtf8("answer_label"));
        answer_label->setGeometry(QRect(320, 10, 70, 60));
        answer_label->setMinimumSize(QSize(70, 60));
        answer_label->setMaximumSize(QSize(70, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Umpush")});
        font.setBold(true);
        answer_label->setFont(font);
        answer_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #30D5C8;\n"
"	font-size: 72px;\n"
"   background: rgba(255, 255, 255, 0)\n"
"}"));
        answer_label->setAlignment(Qt::AlignCenter);
        image_label = new QLabel(centralwidget);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(410, 10, 151, 60));
        image_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        weights_label = new QLabel(centralwidget);
        weights_label->setObjectName(QString::fromUtf8("weights_label"));
        weights_label->setGeometry(QRect(410, 80, 151, 60));
        weights_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        button_download = new QPushButton(centralwidget);
        button_download->setObjectName(QString::fromUtf8("button_download"));
        button_download->setGeometry(QRect(580, 10, 60, 60));
        button_download->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	qproperty-icon: url(:/resource/qrc/download.png);\n"
"	qproperty-iconSize: 30px;	\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	border-style: solid;\n"
"	border-width: 0.5px;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-width: 4px;\n"
"    border-color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-width: 4px;\n"
"	border-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: #FFFFFF;\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1\n"
"#4169E1);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 180, 101, 101));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/resource/qrc/sber.png);"));
        button_upload = new QPushButton(centralwidget);
        button_upload->setObjectName(QString::fromUtf8("button_upload"));
        button_upload->setGeometry(QRect(650, 10, 60, 60));
        button_upload->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	qproperty-icon: url(:/resource/qrc/upload.png);\n"
"	qproperty-iconSize: 30px;	\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	border-style: solid;\n"
"	border-width: 0.5px;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-width: 4px;\n"
"    border-color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-width: 4px;\n"
"	border-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: #FFFFFF;\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1\n"
"#4169E1);\n"
"}"));
        button_download_w = new QPushButton(centralwidget);
        button_download_w->setObjectName(QString::fromUtf8("button_download_w"));
        button_download_w->setGeometry(QRect(580, 80, 60, 60));
        button_download_w->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	qproperty-icon: url(:/resource/qrc/download.png);\n"
"	qproperty-iconSize: 30px;	\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	border-style: solid;\n"
"	border-width: 0.5px;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-width: 4px;\n"
"    border-color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-width: 4px;\n"
"	border-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: #FFFFFF;\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1\n"
"#4169E1);\n"
"}"));
        button_upload_w = new QPushButton(centralwidget);
        button_upload_w->setObjectName(QString::fromUtf8("button_upload_w"));
        button_upload_w->setGeometry(QRect(650, 80, 60, 60));
        button_upload_w->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	qproperty-icon: url(:/resource/qrc/upload.png);\n"
"	qproperty-iconSize: 30px;	\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	border-style: solid;\n"
"	border-width: 0.5px;\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-width: 4px;\n"
"    border-color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border-width: 4px;\n"
"	border-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: #FFFFFF;\n"
"	color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1\n"
"#4169E1);\n"
"}"));
        s21_view->setCentralWidget(centralwidget);
        menubar = new QMenuBar(s21_view);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        s21_view->setMenuBar(menubar);
        statusbar = new QStatusBar(s21_view);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        s21_view->setStatusBar(statusbar);

        retranslateUi(s21_view);

        QMetaObject::connectSlotsByName(s21_view);
    } // setupUi

    void retranslateUi(QMainWindow *s21_view)
    {
        s21_view->setWindowTitle(QCoreApplication::translate("s21_view", "s21_view", nullptr));
        answer_label->setText(QString());
        image_label->setText(QCoreApplication::translate("s21_view", "            IMAGE", nullptr));
        weights_label->setText(QCoreApplication::translate("s21_view", "           WEIGHTS", nullptr));
        button_download->setText(QString());
        label->setText(QString());
        button_upload->setText(QString());
        button_download_w->setText(QString());
        button_upload_w->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class s21_view: public Ui_s21_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_VIEW_H
