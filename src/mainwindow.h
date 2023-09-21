#pragma once

#include <QMainWindow>

class BookListModel;

// This is the Qt app main window.
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *p_pParent = nullptr);

private slots:
  // This slot is called when we receive a text message from the library.
  void showMessage(const QString &message);

private:
  BookListModel *books{};
};
