#include "histogram.h"
#include <QVBoxLayout>
#include <QBarSet>

HistogramOper::HistogramOper(QWidget *parent)
  : QMainWindow{parent}
{
  m_chart = new QChart();
  m_chart->setTitle("Гистограмма изменения количества продукта.");

  //Помещаем график в представление и выводим на форму
  chart_view = new QChartView(m_chart);
  chart_view->setRenderHint(QPainter::Antialiasing);

  setCentralWidget(chart_view);
  resize(900, 600);
}

HistogramOper::~HistogramOper() {}

void HistogramOper::SetArticle(const QString& article) {
  if (!article.isEmpty()) {
    art = article;
  }
}

void HistogramOper::SetName(const QString& n) {
  if (!n.isEmpty()) {
    name = n;
  }
}

void HistogramOper::AddDataFromListOper(const QString& data_time, const unsigned int quant, const QString& act) {
  if (act == "Расход") {
    total -= quant;
  } else {
    total += quant;
  }
  std::pair<QString, unsigned int> row = std::make_pair(data_time, total);
  vect.push_back(row);
}

void HistogramOper::SetMaxLimit() {
  max_limit = vect.at(0).second;

  for (size_t i = 0; i < vect.size(); i++) {
    if (vect.at(i).second > max_limit) {
      max_limit = vect.at(i).second;
    }
  }
}

void HistogramOper::CreateChart() {
  SetMaxLimit();

  // Создаём набор данных
  QBarSet *set = new QBarSet(art + ", " + name);
  for (size_t i = 0; i < vect.size(); i++) {
    *set << vect.at(i).second;
  }
  set->setLabelColor(Qt::black);

  // Создаём серию и добавляем набор
  QBarSeries *series = new QBarSeries();
  series->append(set);
  series->setLabelsFormat("@value");
  series->setLabelsVisible(true);
  series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
  m_chart->addSeries(series);

  //Заполняем ось и серию
  QBarCategoryAxis *axis_x = new QBarCategoryAxis();
  QStringList categories;
  for (size_t i = 0; i < vect.size(); i++) {
    categories << vect.at(i).first;
  }
  axis_x->append(categories);

  //Настраиваем ось Y
  QValueAxis *axis_y = new QValueAxis;
  axis_y->setRange(0, max_limit);

  m_chart->addAxis(axis_y, Qt::AlignLeft);
  m_chart->addAxis(axis_x, Qt::AlignBottom);

  series->attachAxis(axis_x);
  series->attachAxis(axis_y);
}