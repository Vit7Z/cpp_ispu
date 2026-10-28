#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QObject>
#include <QtCharts>
#include <QWidget>
#include <QVector>


#define FIRST_GRAPH 0

class HistogramOper : public QMainWindow {

  Q_OBJECT

public:
  explicit HistogramOper(QWidget *parent = nullptr);

  ~HistogramOper();

  void SetArticle(const QString& article);

  void SetName(const QString& n);

  void AddDataFromListOper(const QString& data_time, const unsigned int quant, const QString& act);

  void SetMaxLimit();

  void CreateChart(); // Создаём и настраиваем chart

protected:
  QChart *m_chart; // Указатель на chart для удобного управления

private:
  QString art;
  QString name;
  QVector<std::pair <QString, unsigned int>> vect;
  unsigned int max_limit;
  unsigned int total {0};

  QChartView *chart_view; // Виджет для отображения диаграммы
};

#endif // HISTOGRAM_H
