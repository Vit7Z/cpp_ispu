#include "list_operations.h"
#include <QMessageBox>
#include <QVector>

ListOper::~ListOper() {}

void ListOper::ReadListFromFile(const QVector<QString> &string_list) {
  Item *new_item = new Item;

  for (size_t i = 0; i < string_list.size(); i++) {
    QStringList string = string_list[i].split(";");
    QString article = string.at(0);
    QString name = string.at(1);
    QString unit = string.at(2);
    unsigned int quantity = string.at(3).toInt();
    QString act = string.at(4);
    QString data_time = string.at(5);

    new_item->article = article;
    new_item->name = name;
    new_item->unit = unit;
    new_item->quantity = quantity;
    new_item->act = act;
    new_item->data_time = data_time;

    list.append(*new_item);
  }
  delete new_item;
}

size_t ListOper::GetSize() {
  return list.size();
}

void ListOper::Clear() {
  list.clear();
}

Item ListOper::GetItem(size_t i) {
  return list.at(i);
}

void ListOper::MakeModel(QStandardItemModel *model) {
  size_t size = list.size();

  for (size_t i = 0; i < size; i++) {
    Item temp = list.at(i);

    QStandardItem *art = new QStandardItem(temp.article);
    QStandardItem *name = new QStandardItem(temp.name);
    QStandardItem *unit = new QStandardItem(temp.unit);
    QString quantityToStr = QString::number(temp.quantity);
    QStandardItem *quantity = new QStandardItem(quantityToStr);
    QStandardItem *act = new QStandardItem(temp.act);
    QStandardItem *data_time = new QStandardItem(temp.data_time);

    model->setItem(i, 0, art);
    model->setItem(i, 1, name);
    model->setItem(i, 2, unit);
    model->setItem(i, 3, quantity);
    model->setItem(i, 4, act);
    model->setItem(i, 5, data_time);
  }
}

void ListOper::ShowTable(QStandardItemModel *model, QTableView *table) {
  model->setHorizontalHeaderLabels(QStringList() << "Артикул"
                                                 << "Наименование"
                                                 << "Ед. изм."
                                                 << "Кол."
                                                 << "Операция"
                                                 << "Дата, время");

  table->setModel(model);
  table->setColumnWidth(0, 140);
  table->setColumnWidth(1, 560);
  table->setColumnWidth(2, 70);
  table->setColumnWidth(3, 94);
  table->setColumnWidth(4, 70);
  table->setColumnWidth(5, 110);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  table->setSelectionMode(QAbstractItemView::SingleSelection);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->scrollToBottom();
}

void ListOper::AddItem(const QString &art, const QString &name,
                       const QString &unit, const unsigned int &quantity,
                       const QString &act, const QString &data_time) {

  Item *item = new Item;
  item->article = art;
  item->name = name;
  item->unit = unit;
  item->quantity = quantity;
  item->act = act;
  item->data_time = data_time;

  list.append(*item);

  delete item;
}

void ListOper::GroupByArt() {
  size_t size = list.size();
  for (size_t i = 0; i < list.size(); ++i) {
    int sum{0};
    for (size_t j = i + 1; j < size; ++j) {

      if (list.at(i).article == list.at(j).article) {
        if (list.at(i).act == "Расход") {
          sum -= list.at(i).quantity;
        } else {
          sum += list.at(i).quantity;
        }

        if (list.at(j).act == "Расход") {
          sum -= list.at(j).quantity;
        } else {
          sum += list.at(j).quantity;
        }
        list[i].quantity = sum;
        list.remove(j);
        size--;
      }
    }
  }
}
