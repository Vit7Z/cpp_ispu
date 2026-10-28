/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_file_inv_open;
    QPushButton *pb_file_inv_sort_art;
    QPushButton *pb_file_inv_sort_name;
    QPushButton *pb_file_inv_upd;
    QPushButton *pb_file_opr_open;
    QPushButton *pb_file_opr_graph;
    QTableView *table;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *line_art;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *line_name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *line_unit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *line_quant;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QComboBox *cbox_act;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QPushButton *pb_add;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *l_name_of_open_file;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1110, 760);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1110, 760));
        MainWindow->setMaximumSize(QSize(1110, 760));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(1100, 760));
        centralwidget->setMaximumSize(QSize(1100, 150));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1081, 52));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_file_inv_open = new QPushButton(horizontalLayoutWidget);
        pb_file_inv_open->setObjectName("pb_file_inv_open");
        sizePolicy.setHeightForWidth(pb_file_inv_open->sizePolicy().hasHeightForWidth());
        pb_file_inv_open->setSizePolicy(sizePolicy);
        pb_file_inv_open->setMinimumSize(QSize(40, 50));
        pb_file_inv_open->setMaximumSize(QSize(160, 50));
        QFont font;
        font.setPointSize(10);
        pb_file_inv_open->setFont(font);

        horizontalLayout->addWidget(pb_file_inv_open);

        pb_file_inv_sort_art = new QPushButton(horizontalLayoutWidget);
        pb_file_inv_sort_art->setObjectName("pb_file_inv_sort_art");
        pb_file_inv_sort_art->setMinimumSize(QSize(160, 50));
        pb_file_inv_sort_art->setMaximumSize(QSize(150, 50));
        pb_file_inv_sort_art->setFont(font);

        horizontalLayout->addWidget(pb_file_inv_sort_art);

        pb_file_inv_sort_name = new QPushButton(horizontalLayoutWidget);
        pb_file_inv_sort_name->setObjectName("pb_file_inv_sort_name");
        pb_file_inv_sort_name->setMinimumSize(QSize(190, 50));
        pb_file_inv_sort_name->setMaximumSize(QSize(150, 50));
        pb_file_inv_sort_name->setFont(font);

        horizontalLayout->addWidget(pb_file_inv_sort_name);

        pb_file_inv_upd = new QPushButton(horizontalLayoutWidget);
        pb_file_inv_upd->setObjectName("pb_file_inv_upd");
        pb_file_inv_upd->setMinimumSize(QSize(150, 50));
        pb_file_inv_upd->setMaximumSize(QSize(150, 50));
        pb_file_inv_upd->setFont(font);

        horizontalLayout->addWidget(pb_file_inv_upd);

        pb_file_opr_open = new QPushButton(horizontalLayoutWidget);
        pb_file_opr_open->setObjectName("pb_file_opr_open");
        pb_file_opr_open->setMinimumSize(QSize(120, 50));
        pb_file_opr_open->setMaximumSize(QSize(140, 50));
        pb_file_opr_open->setFont(font);

        horizontalLayout->addWidget(pb_file_opr_open);

        pb_file_opr_graph = new QPushButton(horizontalLayoutWidget);
        pb_file_opr_graph->setObjectName("pb_file_opr_graph");
        pb_file_opr_graph->setMinimumSize(QSize(120, 50));
        pb_file_opr_graph->setMaximumSize(QSize(140, 50));
        pb_file_opr_graph->setFont(font);

        horizontalLayout->addWidget(pb_file_opr_graph);

        table = new QTableView(centralwidget);
        table->setObjectName("table");
        table->setGeometry(QRect(7, 110, 1090, 570));
        sizePolicy.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy);
        table->setMaximumSize(QSize(1090, 570));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 690, 1084, 64));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(140, 20));
        label->setMaximumSize(QSize(140, 20));

        verticalLayout_2->addWidget(label);

        line_art = new QLineEdit(layoutWidget);
        line_art->setObjectName("line_art");
        sizePolicy.setHeightForWidth(line_art->sizePolicy().hasHeightForWidth());
        line_art->setSizePolicy(sizePolicy);
        line_art->setMinimumSize(QSize(140, 34));
        line_art->setMaximumSize(QSize(140, 34));
        QFont font1;
        font1.setPointSize(11);
        line_art->setFont(font1);
        line_art->setMaxLength(50);

        verticalLayout_2->addWidget(line_art);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(220, 0));
        label_2->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label_2);

        line_name = new QLineEdit(layoutWidget);
        line_name->setObjectName("line_name");
        sizePolicy.setHeightForWidth(line_name->sizePolicy().hasHeightForWidth());
        line_name->setSizePolicy(sizePolicy);
        line_name->setMinimumSize(QSize(530, 34));
        line_name->setMaximumSize(QSize(530, 34));
        line_name->setFont(font1);
        line_name->setMaxLength(400);

        verticalLayout->addWidget(line_name);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(70, 20));
        label_4->setMaximumSize(QSize(70, 20));

        verticalLayout_3->addWidget(label_4);

        line_unit = new QLineEdit(layoutWidget);
        line_unit->setObjectName("line_unit");
        sizePolicy.setHeightForWidth(line_unit->sizePolicy().hasHeightForWidth());
        line_unit->setSizePolicy(sizePolicy);
        line_unit->setMinimumSize(QSize(94, 34));
        line_unit->setMaximumSize(QSize(94, 34));
        line_unit->setFont(font1);
        line_unit->setMaxLength(20);

        verticalLayout_3->addWidget(line_unit);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(80, 20));
        label_6->setMaximumSize(QSize(80, 20));

        verticalLayout_4->addWidget(label_6);

        line_quant = new QLineEdit(layoutWidget);
        line_quant->setObjectName("line_quant");
        sizePolicy.setHeightForWidth(line_quant->sizePolicy().hasHeightForWidth());
        line_quant->setSizePolicy(sizePolicy);
        line_quant->setMinimumSize(QSize(94, 34));
        line_quant->setMaximumSize(QSize(94, 34));
        line_quant->setFont(font1);
        line_quant->setMaxLength(16);

        verticalLayout_4->addWidget(line_quant);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(100, 20));
        label_3->setMaximumSize(QSize(100, 20));

        verticalLayout_6->addWidget(label_3);

        cbox_act = new QComboBox(layoutWidget);
        cbox_act->addItem(QString());
        cbox_act->addItem(QString());
        cbox_act->addItem(QString());
        cbox_act->setObjectName("cbox_act");
        sizePolicy.setHeightForWidth(cbox_act->sizePolicy().hasHeightForWidth());
        cbox_act->setSizePolicy(sizePolicy);
        cbox_act->setMinimumSize(QSize(100, 34));
        cbox_act->setMaximumSize(QSize(100, 34));
        cbox_act->setBaseSize(QSize(100, 40));
        cbox_act->setFont(font1);

        verticalLayout_6->addWidget(cbox_act);


        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(100, 20));
        label_7->setMaximumSize(QSize(100, 20));

        verticalLayout_7->addWidget(label_7);

        pb_add = new QPushButton(layoutWidget);
        pb_add->setObjectName("pb_add");
        pb_add->setEnabled(true);
        sizePolicy.setHeightForWidth(pb_add->sizePolicy().hasHeightForWidth());
        pb_add->setSizePolicy(sizePolicy);
        pb_add->setMinimumSize(QSize(100, 34));
        pb_add->setMaximumSize(QSize(100, 34));
        pb_add->setFont(font);

        verticalLayout_7->addWidget(pb_add);


        horizontalLayout_3->addLayout(verticalLayout_7);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 1081, 32));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(6, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(110, 30));
        label_5->setMaximumSize(QSize(110, 30));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        l_name_of_open_file = new QLabel(horizontalLayoutWidget_2);
        l_name_of_open_file->setObjectName("l_name_of_open_file");
        sizePolicy.setHeightForWidth(l_name_of_open_file->sizePolicy().hasHeightForWidth());
        l_name_of_open_file->setSizePolicy(sizePolicy);
        l_name_of_open_file->setMinimumSize(QSize(130, 30));
        l_name_of_open_file->setMaximumSize(QSize(130, 30));
        l_name_of_open_file->setFont(font1);

        horizontalLayout_2->addWidget(l_name_of_open_file);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\270\320\267\320\260\321\206\320\270\321\217 \320\222. \320\235\320\260\320\264\320\276\320\273\320\270\320\275\320\265\321\206 1-80\320\272", nullptr));
        pb_file_inv_open->setText(QCoreApplication::translate("MainWindow", "\320\236\320\242\320\232\320\240\320\253\320\242\320\254\n"
"\320\244\320\260\320\271\320\273 \320\230\320\275\320\262.", nullptr));
        pb_file_inv_sort_art->setText(QCoreApplication::translate("MainWindow", "\320\241\320\236\320\240\320\242\320\230\320\240\320\236\320\222\320\220\320\242\320\254 \320\277\320\276 \320\220\320\240\320\242.\n"
"\320\244\320\260\320\271\320\273 \320\230\320\275\320\262.", nullptr));
        pb_file_inv_sort_name->setText(QCoreApplication::translate("MainWindow", "\320\241\320\236\320\240\320\242\320\230\320\240\320\236\320\222\320\220\320\242\320\254 \320\277\320\276 \320\235\320\220\320\230\320\234\320\225\320\235.\n"
"\320\244\320\260\320\271\320\273 \320\230\320\275\320\262.", nullptr));
        pb_file_inv_upd->setText(QCoreApplication::translate("MainWindow", "\320\236\320\221\320\235\320\236\320\222\320\230\320\242\320\254 (\321\201\320\276\321\205\321\200.)\n"
"\320\244\320\260\320\271\320\273 \320\230\320\275\320\262.", nullptr));
        pb_file_opr_open->setText(QCoreApplication::translate("MainWindow", "\320\236\320\242\320\232\320\240\320\253\320\242\320\254\n"
"\320\244\320\260\320\271\320\273 \320\236\320\277\320\265\321\200.", nullptr));
        pb_file_opr_graph->setText(QCoreApplication::translate("MainWindow", "\320\223\320\240\320\220\320\244\320\230\320\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        line_art->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        line_name->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\225\320\264. \320\270\320\267\320\274.", nullptr));
        line_unit->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273.", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\320\270\321\217", nullptr));
        cbox_act->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        cbox_act->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\205\320\276\320\264", nullptr));
        cbox_act->setItemText(2, QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264", nullptr));

        label_7->setText(QString());
        pb_add->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\271\321\207\320\260\321\201 \320\276\321\202\320\272\321\200\321\213\321\202:", nullptr));
        l_name_of_open_file->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
