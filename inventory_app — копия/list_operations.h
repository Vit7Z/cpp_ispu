#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include <QDateTime>
#include <QDoubleValidator>
#include <QObject>
#include <QStandardItemModel>
#include <QString>
#include <QTableView>

struct Item {
  QString article;
  QString name;
  QString unit;
  unsigned int quantity;
  QString act;
  QString data_time;
};

class ListOper : public QObject {
  Q_OBJECT

private:
  QVector<Item> list;

public:
  explicit ListOper(QObject *parent = nullptr) {}

  ~ListOper();

  void ReadListFromFile(const QVector<QString> &list);

  size_t GetSize();

  void Clear();

  Item GetItem(size_t i);

  void MakeModel(QStandardItemModel *model);

  void ShowTable(QStandardItemModel *model, QTableView *table);

  void AddItem(const QString &art, const QString &name, const QString &unit,
               const unsigned int &quantity, const QString &act,
               const QString &data_time);

  void GroupByArt();
};

#endif // LIST_OPERATIONS_H
