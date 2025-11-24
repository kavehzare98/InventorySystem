#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QTableWidget;
class QPushButton;
class Inventory;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
    explicit MainWindow(Inventory* inventory, QWidget* parent = nullptr);

private slots:
  void onDeposit();
  void onWithdraw();

private:
  void setupUi();
  void refreshTable();
  int currentMetalType() const;

  Inventory* m_inventory;
  QTableWidget* m_table;
  QPushButton* m_depositButton;
  QPushButton* m_withdrawButton;
};


#endif
