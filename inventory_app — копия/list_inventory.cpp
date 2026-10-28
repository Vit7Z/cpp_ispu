//#include <QtGlobal>
#include "list_inventory.h"
#include <qmessagebox.h>

Node *ListInv::GetHead() {
    return head;
}

void ListInv::Clear() {
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
}

void ListInv::AddNodeToEnd(const QString &art,
                           const QString &name,
                           const QString &unit,
                           const unsigned int &quant) {
    Node *new_node = new Node(art, name, unit, quant);
    if (!head) {
      head = new_node;
      return;
    }
    Node *tmp = head;
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = new_node;
}

void ListInv::AddNodeFromInput(const QString &art,
                           const QString &name,
                           const QString &unit,
                           const unsigned int &quant,
                           const QString &act) {
  Node *current = head;
  bool found {false};
  while (current != nullptr) {
    if (current->article == art &&
        current->name == name &&
        current->unit == unit) {
      found = true;
      if (act == "Расход") {
        current->quantity -= quant;
      } else {
        current->quantity += quant;
      }
    }
    current = current->next;
  }

  if (found == false) {
    AddNodeToEnd(art, name, unit, quant);
  }
}

void ListInv::GetListFromFile(const QVector<QString> &vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
      QStringList string = vector[i].split(";");
      QString article = string.at(0);
      QString name = string.at(1);
      QString unit = string.at(2);
      unsigned int quantity = string.at(3).toInt();
      AddNodeToEnd(article, name, unit, quantity);
    }
}

void ListInv::PrintList() {
    Node *tmp = head;
    while (tmp != nullptr) {
      qDebug() << tmp->article << " " << tmp->name << " " << tmp->unit << " " << tmp->quantity;
      tmp = tmp->next;
    }
}

void ListInv::SetField(const QString &key) {
  field = key;
}

void ListInv::MakeModel(QStandardItemModel *model) {
  Node *current = head;
  int count{0};
  while (current != nullptr) {
    QStandardItem *art = new QStandardItem(current->article);
    QStandardItem *name = new QStandardItem(current->name);
    QStandardItem *unit = new QStandardItem(current->unit);
    QString quantityToStr = QString::number(current->quantity);
    QStandardItem *quantity = new QStandardItem(quantityToStr);

    model->setItem(count, 0, art);
    model->setItem(count, 1, name);
    model->setItem(count, 2, unit);
    model->setItem(count, 3, quantity);

    count++;
    current = current->next;
  }
}

void ListInv::ShowTable(QStandardItemModel *model, QTableView *table) {
  model->setHorizontalHeaderLabels(QStringList() << "Артикул"
                                   << "Наименование"
                                   << "Ед. изм."
                                   << "Кол.");
  table->setModel(model);

  table->setColumnWidth(0, 140);
  table->setColumnWidth(1, 744);
  table->setColumnWidth(2, 70);
  table->setColumnWidth(3, 94);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void ListInv::Sort() {
  head = MergeSort(head);
}

Node * ListInv::MergeSort(Node *head_ref) {
  if (head_ref == nullptr || head_ref->next == nullptr) {
    return head_ref;
  }

  Node *middle = SplitList(head_ref);
  Node *next_middle = middle->next;
  middle->next = nullptr;

  Node *left = MergeSort(head_ref);
  Node *right = MergeSort(next_middle);

  return SortedMerge(left, right);
}

Node *ListInv::SplitList(Node *head_ref) {
  if (head_ref == nullptr) {
    return head_ref;
  }

  Node *slow = head_ref;
  Node *fast = head_ref->next;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

Node *ListInv::SortedMerge(Node *a, Node *b) {
  Node dummy("art", "name", "unit", 0);
  Node *tail = &dummy;

  if (field == "name") {
    while (a != nullptr && b != nullptr) {
      if (a->name <= b->name) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }

      tail = tail->next;
    }
  }

  if (field == "art") {
    while (a != nullptr && b != nullptr) {
      if (a->article <= b->article) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }

      tail = tail->next;
    }
  }

  tail->next = (a != nullptr) ? a : b;

  return dummy.next;
}

void ListInv::ShowWarning(const QString &msg) {
  QMessageBox msgBox;
  msgBox.setWindowTitle("Инвентаризация");
  msgBox.setIcon(QMessageBox::Warning);
  msgBox.setText(msg);
  msgBox.exec();
}

bool ListInv::CheckInputData(const QString &art,
                             const QString &name,
                             const QString &unit,
                             const unsigned int &quant,
                             const QString &act) {
  bool result {true};

  if (art.isEmpty() || art.size() <= 3) {
    ShowWarning("Заполните АРТИКУЛ!");
    result = false;
  }

  if (name.isEmpty() || name.size() <= 3) {
    ShowWarning("Заполните НАИМЕНОВАНИЕ!");
    result = false;
  }

  if (unit.isEmpty()) {
    ShowWarning("Заполните ЕД. ИЗМ.!");
    result = false;
  }

  if (quant == 0) {
    ShowWarning("Заполните КОЛИЧЕСТВО!");
    result = false;
  }

  if (act == "-") {
    ShowWarning("Выберите ПРИХОД или РАСХОД!");
    result = false;
  }
  return result;
}

bool ListInv::ConfirmInputData(const QString &art,
                               const QString &name,
                               const QString &unit,
                               const unsigned int &quant,
                               const QString &act) {
  bool result {true};
  bool found {false};
  QString msg;
  Node *current = head;

  while (current != nullptr) {
    if (current->article == art) {
      found = true;
      if (current->name != name) {
        msg = "Для " + current->article + " должно быть " + current->name + "!";
        ShowWarning(msg);
        result = false;
      }

      if (current->unit != unit) {
        msg = "ЕД. ИЗМ. должно быть " + current->unit + "!";
        ShowWarning(msg);
        result = false;
      }

      if (act == "Расход" && current->quantity < quant) {
        msg = "КОЛИЧЕСТВО должно быть меньше/равно " + QString::number(current->quantity) + "!";
        ShowWarning(msg);
        result = false;
      }
    }
    current = current->next;
  }

  if (!found && act == "Расход" ) {
    msg = "Первое вхождение, только ПРИХОД!";
    ShowWarning(msg);
    result = false;
  }

  return result;
}
