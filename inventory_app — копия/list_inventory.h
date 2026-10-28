#ifndef LIST_INVENTORY_H
#define LIST_INVENTORY_H

#include <QObject>
#include <QDebug>
#include <QStandardItemModel>
#include <QTableView>

struct Node
{
    QString article;
    QString name;
    QString unit;
    unsigned int quantity;
    Node *next;

    Node(const QString &art_,
         const QString &name_,
         const QString &unit_,
         const unsigned int &quantity_)
        : article(art_)
        , name(name_)
        , unit(unit_)
        , quantity(quantity_)
        , next(nullptr)
    {}
};

class ListInv {
private:
    Node *head;
    QString field;

public:
    ListInv()
        : head(nullptr)
    {}

    ~ListInv() { Clear(); }

    Node *GetHead();

    void Clear();

    void GetListFromFile(const QVector<QString> &list);

    void AddNodeToEnd(const QString &art,
                      const QString &name,
                      const QString &unit,
                      const unsigned int &quant);

    void AddNodeFromInput(const QString &art,
                          const QString &name,
                          const QString &unit,
                          const unsigned int &quant,
                          const QString &act);

    void PrintList();

    void MakeModel(QStandardItemModel *model);

    void ShowTable(QStandardItemModel *model, QTableView *table);

    void SetField(const QString &key);

    void Sort();

    Node *MergeSort(Node *headRef);

    Node *SplitList(Node *headRef);

    Node *SortedMerge(Node *a, Node *b);

    void ShowWarning(const QString &msg);

    bool CheckInputData(const QString &art,
                        const QString &name,
                        const QString &unit,
                        const unsigned int &quant,
                        const QString &act);

    bool ConfirmInputData(const QString &art,
                        const QString &name,
                        const QString &unit,
                        const unsigned int &quant,
                        const QString &act);

};

#endif // LIST_INVENTORY_H
