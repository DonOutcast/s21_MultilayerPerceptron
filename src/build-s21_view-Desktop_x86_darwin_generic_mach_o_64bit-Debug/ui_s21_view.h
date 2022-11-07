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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "renderscene.h"

QT_BEGIN_NAMESPACE

class Ui_s21_view
{
public:
    QWidget *centralwidget;
    RenderScene *scene;
    QLabel *answer_label;
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
    } // retranslateUi

};

namespace Ui {
    class s21_view: public Ui_s21_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_VIEW_H
