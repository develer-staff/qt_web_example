#pragma once

#include <QWidget>

class BookListModel;
class QItemSelection;
class QLineEdit;
class QListView;
class QPushButton;

class BookshelfWidget : public QWidget {
  Q_OBJECT

public:
  explicit BookshelfWidget(BookListModel *books, QWidget *parent = nullptr);

signals:
  void requestLending(const QString &book);
  void requestReturn(const QString &book);

private:
  QLineEdit *input{};
  QPushButton *requestButton{};
  QListView *booksView{};
  QPushButton *returnButton{};

private slots:
  void onRequestClicked();
  void onReturnClicked();

  void onInputTextChanged(const QString &text);
  void onBookSelectionChanged(const QItemSelection &selected,
                              const QItemSelection &deselected);
};
