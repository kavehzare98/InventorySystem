#include <QApplication>
#include "MainWindow.h"
#include "Inventory.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Inventory inventory(100, 200, 300);

  MainWindow w(&inventory);
  w.show();

  return app.exec();
}
