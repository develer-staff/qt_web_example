#pragma once

#include <QMainWindow>

class BookListModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* p_pParent = nullptr);

private slots:
    void showMessage(const QString& message);

private:
    BookListModel* books {};
};
