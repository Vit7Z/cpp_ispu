#include "mainwindow.h"
#include "file_handler.h"
#include "list_inventory.h"
#include "list_operations.h"
#include "ui_mainwindow.h"
#include "histogram.h"

#include <QDateTime>
#include <QDebug>
#include <QLabel>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QVariant>
#include <QFileDialog>
#include <QSaveFile>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  list_inv = new ListInv();
  list_oper = new ListOper(this);

  model_inv = new QStandardItemModel(this);
  model_oper = new QStandardItemModel(this);
  name_open_file = new QString;
  start_dir = new QString;
  data_time = new QString;

  ui->line_quant->setValidator(new QIntValidator(0, 9000000, this));

  SetWindowForListInv();
}

MainWindow::~MainWindow() {
  delete ui;
  delete model_inv;
  delete model_oper;
  delete list_inv;
  delete list_oper;
  delete list_oper_tmp;
  delete name_open_file;
  delete start_dir;
  delete data_time;
}

// установки полей окна при работе со списком инвентаризации
void MainWindow::SetWindowForListInv() {
    ui->line_art->setEnabled(false);
    ui->line_name->setEnabled(false);
    ui->line_unit->setEnabled(false);
    ui->line_quant->setEnabled(false);
    ui->cbox_act->setEnabled(false);
    ui->pb_add->setEnabled(false);
    ui->l_name_of_open_file->setText(*name_open_file);
}

// установки полей окна при работе со списком операций
void MainWindow::SetWindowForListOper() {
    ui->line_art->setEnabled(true);
    ui->line_name->setEnabled(true);
    ui->line_unit->setEnabled(true);
    ui->line_quant->setEnabled(true);
    ui->cbox_act->setEnabled(true);
    ui->pb_add->setEnabled(true);
    ui->l_name_of_open_file->setText(*name_open_file);
}

// открыть файл инвентаризации
void MainWindow::on_pb_file_inv_open_clicked() {
  model_inv->clear();

  FileHandler *file = new FileHandler;
  file->SelectFile("Файл инвентаризации (*.inv)");

  if (!file->GetFileName().isEmpty()) {
    const QVector<QString> arr = file->ReadFile();
    *name_open_file = QFileInfo(file->GetFileName()).fileName();
    *start_dir = QFileInfo(file->GetFileName()).path();
    delete file;

    list_inv->Clear();
    list_inv->GetListFromFile(arr);
    SetWindowForListInv();
    list_inv->MakeModel(model_inv);
    list_inv->ShowTable(model_inv, ui->table);
  }
}

// открытие файла операций
void MainWindow::on_pb_file_opr_open_clicked() {
  model_oper->clear();

  FileHandler *file = new FileHandler;
  file->SelectFile("Файл операций (*.opr)");

  if (!file->GetFileName().isEmpty()) {
    const QVector<QString> arr = file->ReadFile();
    *name_open_file = QFileInfo(file->GetFileName()).fileName();
    delete file;

    list_oper->Clear();
    list_oper->ReadListFromFile(arr);
    SetWindowForListOper();
    list_oper->MakeModel(model_oper);
    list_oper->ShowTable(model_oper, ui->table);
  }
}

// добавление записи в список операций + в файл операций
void MainWindow::on_pb_add_clicked() {
  if (list_inv->GetHead() == nullptr) {
    list_inv->ShowWarning("ОТКРОЙТЕ файл ИНВЕНТАРИЗАЦИИ прежде чем добавлять!");
  } else {
    QString art_new = ui->line_art->text();
    QString name_new = ui->line_name->text();
    QString unit_new = ui->line_unit->text();
    QString quant_tmp = ui->line_quant->text();
    unsigned int quant_new = quant_tmp.toInt();
    QString act_new = ui->cbox_act->currentText();
    *data_time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm");

    FileHandler *file = new FileHandler;

    if (list_inv->CheckInputData(art_new, name_new, unit_new, quant_new,
                                 act_new) &&
        list_inv->ConfirmInputData(art_new, name_new, unit_new, quant_new,
                                   act_new)) {
      list_inv->AddNodeFromInput(art_new, name_new, unit_new, quant_new,
                                 act_new);
      list_oper->AddItem(art_new, name_new, unit_new, quant_new, act_new,
                         *data_time);
      list_oper->MakeModel(model_oper);
      list_oper->ShowTable(model_oper, ui->table);

      file->AddLineToEndFile(*start_dir, *name_open_file, art_new, name_new,
                             unit_new, quant_new, act_new, *data_time);
    }
    delete file;
  }
}

// сортировка списка инвентаризации по артикулу
void MainWindow::on_pb_file_inv_sort_art_clicked() {
  if (list_inv->GetHead() == nullptr) {
    list_inv->ShowWarning("ОТКРОЙТЕ файл ИНВЕНТАРИЗАЦИИ!");
  } else {
    list_inv->SetField("art");
    list_inv->Sort();
    SetWindowForListInv();
    list_inv->MakeModel(model_inv);
    list_inv->ShowTable(model_inv, ui->table);
  }
}

// сортировка списка инвентаризации по наименованию
void MainWindow::on_pb_file_inv_sort_name_clicked() {
    if(list_inv->GetHead() == nullptr) {
      list_inv->ShowWarning("ОТКРОЙТЕ файл ИНВЕНТАРИЗАЦИИ!");
    } else {
    list_inv->SetField("name");
    list_inv->Sort();
    SetWindowForListInv();
    list_inv->MakeModel(model_inv);
    list_inv->ShowTable(model_inv, ui->table);
    }
}

// обновление списка инвентаризации + сохранение
void MainWindow::on_pb_file_inv_upd_clicked() {
  QString *old_name_inv_file = new QString;
  QString *new_name_inv_file = new QString;

  *new_name_inv_file = *start_dir + "/" + "inventory.inv";
  *old_name_inv_file = *start_dir + "/" + "inventory_old.inv";

  if (!QFile::exists(*old_name_inv_file)) {
    list_inv->ShowWarning("Файл INVENTORY_OLD не НАЙДЕН!");
    return;
  } else {
    QFile::remove(*old_name_inv_file);
    QFile file(*new_name_inv_file);
    QFile::rename(*new_name_inv_file, *old_name_inv_file);
  }

  QFile file(*new_name_inv_file);
  if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
    QTextStream out(&file);

    // for (size_t i = 0; i < list_oper->GetSize(); ++i) {

    // }



list_oper->GroupByArt();






    // QString *str = new QString{};
    // Node* current = list_inv->GetHead();
    // while (current != nullptr) {
    //   *str +=current->article + ";";
    //   *str +=current->name + ";";
    //   *str +=current->unit + ";";
    //   *str +=QString::number(current->quantity);
    //   *str +="\n";
    //   QByteArray text_in_bytes = str->toUtf8();
    //   out << text_in_bytes;
    //   current = current->next;
    //   str->clear();
    // }
    // delete str;
  }
  file.close();
}

void MainWindow::on_pb_file_opr_graph_clicked() {
  if (*name_open_file != "operations.opr") {
    list_inv->ShowWarning("ОТКРОЙТЕ файл ОПЕРАЦИЙ!");
    return;
  }

  QModelIndexList selected_row = ui->table->selectionModel()->selectedRows();

  QString art{};
  QString name{};

  HistogramOper *hist_oper = new HistogramOper();

  if (!selected_row.isEmpty()) {
    int row = selected_row.at(0).row();
    QModelIndex index = ui->table->model()->index(row, 0);
    art = index.data().toString();
    hist_oper->SetArticle(art);
    index = ui->table->model()->index(row, 1);
    name = index.data().toString();
    hist_oper->SetName(name);
    unsigned int total {};

    for(size_t i = 0; i < list_oper->GetSize(); i++) {
      Item tmp_oper = list_oper->GetItem(i);
      QString article = tmp_oper.article;
      if (art == article) {
        QString data_time = tmp_oper.data_time;
        unsigned int quant = tmp_oper.quantity;
        QString act = tmp_oper.act;
        hist_oper->AddDataFromListOper(data_time, quant, act);
        article.clear();
        data_time.clear();
      }
    }
  }

  hist_oper->CreateChart();
  hist_oper->show();
  hist_oper->setWindowTitle("Инвентаризация");
}

void MainWindow::on_table_doubleClicked(const QModelIndex &index) {
  if (index.isValid()) {
    int row = index.row();
    QModelIndex *tmp_art = new QModelIndex;
    QModelIndex *tmp_name = new QModelIndex;
    QModelIndex *tmp_unit = new QModelIndex;
    *tmp_art = index.model()->index(row, 0);
    *tmp_name = index.model()->index(row, 1);
    *tmp_unit = index.model()->index(row, 2);
    ui->line_art->setText((*tmp_art).data().toString());
    ui->line_name->setText((*tmp_name).data().toString());
    ui->line_unit->setText((*tmp_unit).data().toString());
    delete tmp_art;
    delete tmp_name;
    delete tmp_unit;
  }
}
