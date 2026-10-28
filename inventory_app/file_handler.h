#ifndef FILEHANDLER_H
#define FILEHANDLER_H

//#include "list_operations.h"
#include <QObject>
#include <QStringConverter>
#include <QVector>

class FileHandler {
private:
  QString file_name;

public:
  explicit FileHandler();
  ~FileHandler();

  void ShowWarning(const QString &msg);

  void SelectFile(const char *txt);

  const QVector<QString> ReadFile();

  QString GetFileName();

  void AddLineToEndFile(const QString &file_path, const QString &file_name,
                        const QString &art, const QString &name,
                        const QString &unit, const unsigned int &quant,
                        const QString &act, const QString &data_time);
};

#endif // FILEHANDLER_H
