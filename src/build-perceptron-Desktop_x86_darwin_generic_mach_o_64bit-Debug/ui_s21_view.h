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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>
#include "render_scene.h"

QT_BEGIN_NAMESPACE

class Ui_s21_view
{
public:
    QAction *actionDownload_images;
    QAction *actionSettings;
    QAction *action_upload_images;
    QAction *actionDownload_weights;
    QAction *actionUpload_weights;
    QAction *actionTrain;
    QAction *actionTest;
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox_settings;
    QLabel *selectionPartLabel;
    QLabel *testsLabel;
    QRadioButton *graphTypeButton;
    QLabel *epochNumberLabel;
    QRadioButton *matrixTypeButton;
    QLabel *hiddenLayersLabel;
    QDoubleSpinBox *selectonPartSpinBox;
    QSpinBox *kGroupsSpinBox;
    QCheckBox *crossValidationCheckBox;
    QComboBox *layersBox;
    QLabel *kGroupsLabel;
    QLabel *trainingLabel;
    QLabel *networkTypeLabel;
    QComboBox *epochBox;
    QCustomPlot *plot;
    QGroupBox *groupBox_Metrics;
    QLabel *tLabel;
    QLabel *recallLabel;
    QLabel *pLabel;
    QLabel *aLabel;
    QLabel *accuracyLabel;
    QLabel *timeLabel;
    QLabel *rLabel;
    QLabel *measureLabel;
    QLabel *fLabel;
    QLabel *precisionLabel;
    QGroupBox *groupBox;
    RenderScene *scene;
    QLabel *answer_label;
    QToolBar *toolBar;

    void setupUi(QMainWindow *s21_view)
    {
        if (s21_view->objectName().isEmpty())
            s21_view->setObjectName(QString::fromUtf8("s21_view"));
        s21_view->resize(1275, 590);
        s21_view->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow{\n"
"\n"
"background-image: url(:/resource/qrc/icon.png);\n"
"}\n"
"\n"
"QToolBar {\n"
"background-color: white;\n"
"}\n"
"QToolBar {\n"
"	background-color:  red;\n"
"}"));
        actionDownload_images = new QAction(s21_view);
        actionDownload_images->setObjectName(QString::fromUtf8("actionDownload_images"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/qrc/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDownload_images->setIcon(icon);
        actionSettings = new QAction(s21_view);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/qrc/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon1);
        QFont font;
        font.setPointSize(25);
        actionSettings->setFont(font);
        action_upload_images = new QAction(s21_view);
        action_upload_images->setObjectName(QString::fromUtf8("action_upload_images"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/qrc/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_upload_images->setIcon(icon2);
        actionDownload_weights = new QAction(s21_view);
        actionDownload_weights->setObjectName(QString::fromUtf8("actionDownload_weights"));
        actionDownload_weights->setIcon(icon);
        actionUpload_weights = new QAction(s21_view);
        actionUpload_weights->setObjectName(QString::fromUtf8("actionUpload_weights"));
        actionUpload_weights->setIcon(icon2);
        actionTrain = new QAction(s21_view);
        actionTrain->setObjectName(QString::fromUtf8("actionTrain"));
        QIcon icon3;
        QString iconThemeName = QString::fromUtf8("Train");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(":/resource/qrc/train.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTrain->setIcon(icon3);
        actionTest = new QAction(s21_view);
        actionTest->setObjectName(QString::fromUtf8("actionTest"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("Test");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8(":/resource/qrc/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionTest->setIcon(icon4);
        centralwidget = new QWidget(s21_view);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(940, 10, 151, 121));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"/*	background-color:  qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);*/\n"
"	background-image: url(:/resource/qrc/sber.png);\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	/*border-style: solid;\n"
"	border-width: 4px 4px 4px 4px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);*/\n"
"}"));
        groupBox_settings = new QGroupBox(centralwidget);
        groupBox_settings->setObjectName(QString::fromUtf8("groupBox_settings"));
        groupBox_settings->setGeometry(QRect(0, 130, 391, 410));
        groupBox_settings->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 4px 4px 4px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:		0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        selectionPartLabel = new QLabel(groupBox_settings);
        selectionPartLabel->setObjectName(QString::fromUtf8("selectionPartLabel"));
        selectionPartLabel->setGeometry(QRect(20, 350, 181, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Umpush")});
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        selectionPartLabel->setFont(font1);
        selectionPartLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"\n"
"}"));
        selectionPartLabel->setAlignment(Qt::AlignCenter);
        testsLabel = new QLabel(groupBox_settings);
        testsLabel->setObjectName(QString::fromUtf8("testsLabel"));
        testsLabel->setGeometry(QRect(110, 300, 200, 40));
        testsLabel->setFont(font1);
        testsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        testsLabel->setAlignment(Qt::AlignCenter);
        graphTypeButton = new QRadioButton(groupBox_settings);
        graphTypeButton->setObjectName(QString::fromUtf8("graphTypeButton"));
        graphTypeButton->setGeometry(QRect(270, 70, 120, 40));
        graphTypeButton->setFont(font1);
        graphTypeButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width:                  10px;\n"
"    height:                 10px;\n"
"    border-radius:          7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       #30D5C8;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       #FFFFFF;\n"
"    border:                 2px solid white;\n"
"}"));
        epochNumberLabel = new QLabel(groupBox_settings);
        epochNumberLabel->setObjectName(QString::fromUtf8("epochNumberLabel"));
        epochNumberLabel->setGeometry(QRect(10, 210, 181, 40));
        epochNumberLabel->setFont(font1);
        epochNumberLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"\n"
"}"));
        epochNumberLabel->setAlignment(Qt::AlignCenter);
        matrixTypeButton = new QRadioButton(groupBox_settings);
        matrixTypeButton->setObjectName(QString::fromUtf8("matrixTypeButton"));
        matrixTypeButton->setGeometry(QRect(30, 70, 120, 40));
        matrixTypeButton->setFont(font1);
        matrixTypeButton->setLayoutDirection(Qt::LeftToRight);
        matrixTypeButton->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width:                  10px;\n"
"    height:                 10px;\n"
"    border-radius:          7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       #30D5C8;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       #FFFFFF;\n"
"    border:                 2px solid white;\n"
"}"));
        matrixTypeButton->setChecked(true);
        hiddenLayersLabel = new QLabel(groupBox_settings);
        hiddenLayersLabel->setObjectName(QString::fromUtf8("hiddenLayersLabel"));
        hiddenLayersLabel->setGeometry(QRect(0, 110, 181, 40));
        hiddenLayersLabel->setFont(font1);
        hiddenLayersLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"\n"
"}"));
        hiddenLayersLabel->setAlignment(Qt::AlignCenter);
        selectonPartSpinBox = new QDoubleSpinBox(groupBox_settings);
        selectonPartSpinBox->setObjectName(QString::fromUtf8("selectonPartSpinBox"));
        selectonPartSpinBox->setGeometry(QRect(290, 355, 91, 31));
        selectonPartSpinBox->setFont(font1);
        selectonPartSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"}"));
        selectonPartSpinBox->setMaximum(1.000000000000000);
        selectonPartSpinBox->setSingleStep(0.050000000000000);
        selectonPartSpinBox->setValue(1.000000000000000);
        kGroupsSpinBox = new QSpinBox(groupBox_settings);
        kGroupsSpinBox->setObjectName(QString::fromUtf8("kGroupsSpinBox"));
        kGroupsSpinBox->setGeometry(QRect(290, 255, 91, 31));
        kGroupsSpinBox->setFont(font1);
        kGroupsSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"}"));
        kGroupsSpinBox->setMinimum(1);
        kGroupsSpinBox->setMaximum(10);
        crossValidationCheckBox = new QCheckBox(groupBox_settings);
        crossValidationCheckBox->setObjectName(QString::fromUtf8("crossValidationCheckBox"));
        crossValidationCheckBox->setGeometry(QRect(20, 260, 151, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Umpush")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        crossValidationCheckBox->setFont(font2);
        crossValidationCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 10pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background-color: #202020;\n"
"}\n"
""));
        layersBox = new QComboBox(groupBox_settings);
        layersBox->addItem(QString());
        layersBox->addItem(QString());
        layersBox->addItem(QString());
        layersBox->addItem(QString());
        layersBox->setObjectName(QString::fromUtf8("layersBox"));
        layersBox->setGeometry(QRect(290, 120, 91, 30));
        layersBox->setLayoutDirection(Qt::LeftToRight);
        layersBox->setAutoFillBackground(false);
        layersBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"	selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);;\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}\n"
"\n"
"\n"
""));
        layersBox->setMaxVisibleItems(4);
        kGroupsLabel = new QLabel(groupBox_settings);
        kGroupsLabel->setObjectName(QString::fromUtf8("kGroupsLabel"));
        kGroupsLabel->setGeometry(QRect(200, 250, 81, 40));
        kGroupsLabel->setFont(font2);
        kGroupsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 10pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"\n"
"}"));
        kGroupsLabel->setAlignment(Qt::AlignCenter);
        trainingLabel = new QLabel(groupBox_settings);
        trainingLabel->setObjectName(QString::fromUtf8("trainingLabel"));
        trainingLabel->setGeometry(QRect(100, 160, 200, 40));
        trainingLabel->setFont(font1);
        trainingLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        trainingLabel->setAlignment(Qt::AlignCenter);
        networkTypeLabel = new QLabel(groupBox_settings);
        networkTypeLabel->setObjectName(QString::fromUtf8("networkTypeLabel"));
        networkTypeLabel->setGeometry(QRect(100, 20, 200, 40));
        networkTypeLabel->setFont(font1);
        networkTypeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        networkTypeLabel->setAlignment(Qt::AlignCenter);
        epochBox = new QComboBox(groupBox_settings);
        epochBox->addItem(QString());
        epochBox->addItem(QString());
        epochBox->addItem(QString());
        epochBox->addItem(QString());
        epochBox->addItem(QString());
        epochBox->setObjectName(QString::fromUtf8("epochBox"));
        epochBox->setGeometry(QRect(290, 210, 91, 30));
        epochBox->setLayoutDirection(Qt::LeftToRight);
        epochBox->setAutoFillBackground(false);
        epochBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	background: #202020;\n"
"	selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);;\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}\n"
"\n"
"\n"
""));
        epochBox->setMaxVisibleItems(4);
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(400, 139, 451, 401));
        groupBox_Metrics = new QGroupBox(centralwidget);
        groupBox_Metrics->setObjectName(QString::fromUtf8("groupBox_Metrics"));
        groupBox_Metrics->setGeometry(QRect(0, 0, 861, 131));
        groupBox_Metrics->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 4px 4px 4px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:		0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        tLabel = new QLabel(groupBox_Metrics);
        tLabel->setObjectName(QString::fromUtf8("tLabel"));
        tLabel->setGeometry(QRect(280, 80, 211, 31));
        tLabel->setFont(font1);
        tLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        tLabel->setAlignment(Qt::AlignCenter);
        recallLabel = new QLabel(groupBox_Metrics);
        recallLabel->setObjectName(QString::fromUtf8("recallLabel"));
        recallLabel->setGeometry(QRect(490, 30, 51, 31));
        recallLabel->setFont(font1);
        recallLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}"));
        recallLabel->setAlignment(Qt::AlignCenter);
        pLabel = new QLabel(groupBox_Metrics);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));
        pLabel->setGeometry(QRect(10, 80, 211, 31));
        pLabel->setFont(font1);
        pLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        pLabel->setAlignment(Qt::AlignCenter);
        aLabel = new QLabel(groupBox_Metrics);
        aLabel->setObjectName(QString::fromUtf8("aLabel"));
        aLabel->setGeometry(QRect(10, 30, 211, 31));
        aLabel->setFont(font1);
        aLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        aLabel->setAlignment(Qt::AlignCenter);
        accuracyLabel = new QLabel(groupBox_Metrics);
        accuracyLabel->setObjectName(QString::fromUtf8("accuracyLabel"));
        accuracyLabel->setGeometry(QRect(220, 30, 51, 31));
        accuracyLabel->setFont(font1);
        accuracyLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}"));
        accuracyLabel->setAlignment(Qt::AlignCenter);
        timeLabel = new QLabel(groupBox_Metrics);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(760, 30, 51, 31));
        timeLabel->setFont(font1);
        timeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}"));
        timeLabel->setAlignment(Qt::AlignCenter);
        rLabel = new QLabel(groupBox_Metrics);
        rLabel->setObjectName(QString::fromUtf8("rLabel"));
        rLabel->setGeometry(QRect(280, 30, 211, 31));
        rLabel->setFont(font1);
        rLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        rLabel->setAlignment(Qt::AlignCenter);
        measureLabel = new QLabel(groupBox_Metrics);
        measureLabel->setObjectName(QString::fromUtf8("measureLabel"));
        measureLabel->setGeometry(QRect(490, 80, 51, 31));
        measureLabel->setFont(font1);
        measureLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}"));
        measureLabel->setAlignment(Qt::AlignCenter);
        fLabel = new QLabel(groupBox_Metrics);
        fLabel->setObjectName(QString::fromUtf8("fLabel"));
        fLabel->setGeometry(QRect(550, 30, 211, 31));
        fLabel->setFont(font1);
        fLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 0px 4px 0px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        fLabel->setAlignment(Qt::AlignCenter);
        precisionLabel = new QLabel(groupBox_Metrics);
        precisionLabel->setObjectName(QString::fromUtf8("precisionLabel"));
        precisionLabel->setGeometry(QRect(220, 80, 51, 31));
        precisionLabel->setFont(font1);
        precisionLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 16pt ;\n"
"	font-weight: bold;\n"
"	color: #FFFFFF;\n"
"}"));
        precisionLabel->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(860, 130, 410, 410));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	border-style: solid;\n"
"	border-width: 4px 4px 4px 4px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        scene = new RenderScene(groupBox);
        scene->setObjectName(QString::fromUtf8("scene"));
        scene->setGeometry(QRect(5, 5, 404, 404));
        scene->setMinimumSize(QSize(402, 402));
        scene->setMaximumSize(QSize(404, 404));
        scene->setStyleSheet(QString::fromUtf8("QWidget#answer_label {\n"
"	background: #FFFFFF;\n"
"	border-style: solid;\n"
"	border-width: 4px 4px 4px 4px;\n"
"	border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #30D5C8 , stop:1 #4169E1);\n"
"}"));
        answer_label = new QLabel(scene);
        answer_label->setObjectName(QString::fromUtf8("answer_label"));
        answer_label->setGeometry(QRect(320, 10, 70, 60));
        answer_label->setMinimumSize(QSize(70, 60));
        answer_label->setMaximumSize(QSize(70, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Umpush")});
        font3.setBold(true);
        answer_label->setFont(font3);
        answer_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #30D5C8;\n"
"	font-size: 72px;\n"
"   background: rgba(255, 255, 255, 0)\n"
"}"));
        answer_label->setAlignment(Qt::AlignCenter);
        s21_view->setCentralWidget(centralwidget);
        toolBar = new QToolBar(s21_view);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(50, 32));
        s21_view->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_upload_images);
        toolBar->addAction(actionDownload_images);
        toolBar->addAction(actionSettings);
        toolBar->addAction(actionDownload_weights);
        toolBar->addAction(actionUpload_weights);
        toolBar->addAction(actionTrain);
        toolBar->addAction(actionTest);

        retranslateUi(s21_view);

        layersBox->setCurrentIndex(0);
        epochBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(s21_view);
    } // setupUi

    void retranslateUi(QMainWindow *s21_view)
    {
        s21_view->setWindowTitle(QCoreApplication::translate("s21_view", "s21_view", nullptr));
        actionDownload_images->setText(QCoreApplication::translate("s21_view", "Download", nullptr));
#if QT_CONFIG(tooltip)
        actionDownload_images->setToolTip(QCoreApplication::translate("s21_view", "Dowonload Images", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSettings->setText(QCoreApplication::translate("s21_view", "Settings_off", nullptr));
#if QT_CONFIG(tooltip)
        actionSettings->setToolTip(QCoreApplication::translate("s21_view", "Setting", nullptr));
#endif // QT_CONFIG(tooltip)
        action_upload_images->setText(QCoreApplication::translate("s21_view", "upload_images", nullptr));
#if QT_CONFIG(tooltip)
        action_upload_images->setToolTip(QCoreApplication::translate("s21_view", "Upload Images", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDownload_weights->setText(QCoreApplication::translate("s21_view", "Download", nullptr));
#if QT_CONFIG(tooltip)
        actionDownload_weights->setToolTip(QCoreApplication::translate("s21_view", "Download weights", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUpload_weights->setText(QCoreApplication::translate("s21_view", "Upload_weights", nullptr));
#if QT_CONFIG(tooltip)
        actionUpload_weights->setToolTip(QCoreApplication::translate("s21_view", "Upload Weights", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTrain->setText(QCoreApplication::translate("s21_view", "Train", nullptr));
        actionTest->setText(QCoreApplication::translate("s21_view", "Test", nullptr));
#if QT_CONFIG(tooltip)
        actionTest->setToolTip(QCoreApplication::translate("s21_view", "Test", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        groupBox_settings->setTitle(QCoreApplication::translate("s21_view", "Settings", nullptr));
        selectionPartLabel->setText(QCoreApplication::translate("s21_view", "SELECTION PART", nullptr));
        testsLabel->setText(QCoreApplication::translate("s21_view", "TESTS", nullptr));
        graphTypeButton->setText(QCoreApplication::translate("s21_view", "GRAPH", nullptr));
        epochNumberLabel->setText(QCoreApplication::translate("s21_view", "EPOCH NUMBER", nullptr));
        matrixTypeButton->setText(QCoreApplication::translate("s21_view", "MATRIX", nullptr));
        hiddenLayersLabel->setText(QCoreApplication::translate("s21_view", "HIDDEN LAYERS", nullptr));
        crossValidationCheckBox->setText(QCoreApplication::translate("s21_view", "CROSS VALIDATION", nullptr));
        layersBox->setItemText(0, QCoreApplication::translate("s21_view", "2", nullptr));
        layersBox->setItemText(1, QCoreApplication::translate("s21_view", "3", nullptr));
        layersBox->setItemText(2, QCoreApplication::translate("s21_view", "4", nullptr));
        layersBox->setItemText(3, QCoreApplication::translate("s21_view", "5", nullptr));

        kGroupsLabel->setText(QCoreApplication::translate("s21_view", "K-GROUPS", nullptr));
        trainingLabel->setText(QCoreApplication::translate("s21_view", "TRAINING", nullptr));
        networkTypeLabel->setText(QCoreApplication::translate("s21_view", "NETWORK TYPE", nullptr));
        epochBox->setItemText(0, QCoreApplication::translate("s21_view", "1", nullptr));
        epochBox->setItemText(1, QCoreApplication::translate("s21_view", "2", nullptr));
        epochBox->setItemText(2, QCoreApplication::translate("s21_view", "3", nullptr));
        epochBox->setItemText(3, QCoreApplication::translate("s21_view", "4", nullptr));
        epochBox->setItemText(4, QCoreApplication::translate("s21_view", "5", nullptr));

        groupBox_Metrics->setTitle(QCoreApplication::translate("s21_view", "Metrics", nullptr));
        tLabel->setText(QCoreApplication::translate("s21_view", "TIME", nullptr));
        recallLabel->setText(QCoreApplication::translate("s21_view", "0", nullptr));
        pLabel->setText(QCoreApplication::translate("s21_view", "PRECISION", nullptr));
        aLabel->setText(QCoreApplication::translate("s21_view", "AVERAGE ACCURACY", nullptr));
        accuracyLabel->setText(QCoreApplication::translate("s21_view", "0", nullptr));
        timeLabel->setText(QCoreApplication::translate("s21_view", "0", nullptr));
        rLabel->setText(QCoreApplication::translate("s21_view", "RECALL", nullptr));
        measureLabel->setText(QCoreApplication::translate("s21_view", "0", nullptr));
        fLabel->setText(QCoreApplication::translate("s21_view", "F-MEASURE", nullptr));
        precisionLabel->setText(QCoreApplication::translate("s21_view", "0", nullptr));
        groupBox->setTitle(QString());
        answer_label->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("s21_view", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class s21_view: public Ui_s21_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_VIEW_H
