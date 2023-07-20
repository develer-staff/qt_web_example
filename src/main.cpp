#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QFile>

int main(int p_iArgc, char **p_pArgv) {
  QApplication l_app(p_iArgc, p_pArgv);
  QApplication::setApplicationName("qt_web_example");
  QApplication::setApplicationVersion("1.0");

  MainWindow l_win;
  l_win.show();

  return l_app.exec();
}
