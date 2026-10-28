#include "file_handler.h"

#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <qmessagebox.h>

FileHandler::FileHandler()
//: QObject(parent)
{}
FileHandler::~FileHandler() {}

void FileHandler::ShowWarning(const QString &msg)
{
  QMessageBox msgBox;
  msgBox.setWindowTitle("Операции с файлами");
  msgBox.setIcon(QMessageBox::Warning);
  msgBox.setText(msg);
  msgBox.exec();
}

void FileHandler::SelectFile(const char *txt) {
  QString caption = "Выберите файл";
  QString dir = "";
  QString filter = txt;

  file_name = QFileDialog::getOpenFileName(nullptr, caption, dir, filter);

  if (file_name.isEmpty()) {
    ShowWarning("Файл не выбран!");
    return;
  }
}

const QVector<QString> FileHandler::ReadFile() {
  QFile file(file_name);

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    ShowWarning("Не удалось открыть файл!");
  }

  QTextStream in(&file);
  QVector<QString> vector;

  while (!in.atEnd()) {
    QString line = in.readLine();
    vector.append(line);
  }
  file.close();

  return vector;
}

QString FileHandler::GetFileName() { return file_name; }

void FileHandler::AddLineToEndFile(const QString &file_path,
                                   const QString &file_name, const QString &art,
                                   const QString &name, const QString &unit,
                                   const unsigned int &quant,
                                   const QString &act,
                                   const QString &data_time) {
  QString full_file_name = file_path + "/" + file_name;

  QString string{""};

  QFile file(full_file_name);
  if (!file.open(QIODevice::Append | QIODevice::Text)) {
    ShowWarning("Не удалось открыть файл!");
    return;
  } else {
    string = art + ";";
    string += name + ";";
    string += unit + ";";
    string += QString::number(quant) + ";";
    string += act + ";";
    string += data_time;
    QByteArray string_in_bytes = string.toUtf8();
    string.clear();
    QTextStream out(&file);
    out << string_in_bytes << Qt::endl;
    file.close();
  }
}
