#pragma once

#include <QWidget>

class BookListModel;
class QItemSelection;
class QLineEdit;
class QListView;
class QPushButton;

// This widget represents the user's bookshelf, i.e. it shows the list of books
// that the user got from the library.
class BookshelfWidget : public QWidget {
  Q_OBJECT

public:
  explicit BookshelfWidget(BookListModel *books, QWidget *parent = nullptr);

signals:
  // The following signals will be forwarder to the web channel's registered
  // object, so that the library can receive the requests.
  void requestLending(const QString &book);
  void requestReturn(const QString &book);

private:
  QLineEdit *input{};
  QPushButton *requestButton{};
  QListView *booksView{};
  QPushButton *returnButton{};

private slots:
  // This slot is called after the user selects a book from the bookshelf and
  // then clicks on "Request book" button.
  void onRequestClicked();

  // This slot is called after the user types the book title and/or author and
  // then clicks on "Return book" button.
  void onReturnClicked();

  // The following slots handle the buttons behavior.
  void onInputTextChanged(const QString &text);
  void onBookSelectionChanged(const QItemSelection &selected,
                              const QItemSelection &deselected);
};
