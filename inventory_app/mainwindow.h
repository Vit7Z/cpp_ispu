#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "list_inventory.h"
#include "list_operations.h"

#include <QMainWindow>
#include <QStandardItem>
#include <QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetWindowForListInv();
    void SetWindowForListOper();

private slots:
    void on_pb_file_inv_open_clicked();
    void on_pb_file_opr_open_clicked();
    void on_pb_add_clicked();
    void on_pb_file_inv_sort_name_clicked();
    void on_pb_file_inv_sort_art_clicked();
    void on_pb_file_inv_upd_clicked();
    void on_pb_file_opr_graph_clicked();
    void on_table_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QString *name_open_file;
    QString *start_dir;
    QString *data_time;

    ListInv *list_inv;

    ListOper *list_oper;
    ListOper *list_oper_tmp;

    QStandardItemModel *model_inv;
    QStandardItemModel *model_oper;
};
#endif // MAINWINDOW_H
