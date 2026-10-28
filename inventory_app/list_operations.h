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

  bool operator==(const Item &other) const {
    return article == other.article && name == other.name && unit == other.unit;
  }
};

class ListOper : public QObject {
  Q_OBJECT

private:
  QVector<Item> list;

public:
  explicit ListOper(QObject *parent = nullptr) {}

  ~ListOper();

  void ReadListFromFile(const QVector<QString> &list);

  void CopyList(const ListOper &source);

  size_t GetSize() const;

  void Clear();

  Item GetItem(size_t i) const;

  void MakeModel(QStandardItemModel *model);

  void ShowTable(QStandardItemModel *model, QTableView *table);

  void AddItem(const QString &art, const QString &name, const QString &unit,
               const unsigned int &quantity, const QString &act,
               const QString &data_time);

  void RemoveDublicates(const ListOper &source);

  void CountQuant(const ListOper &source);
};

#endif // LIST_OPERATIONS_H
