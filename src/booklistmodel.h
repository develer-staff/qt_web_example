#pragma once

#include <QAbstractListModel>

#include "utils.h"

// This class keeps the list of books that the user currently has on loan, i.e.
// the books in the user's bookshelf.
class BookListModel : public QAbstractListModel {
  Q_OBJECT

public:
  explicit BookListModel(QObject *parent = nullptr);

  // A book is added when it is loaned to the user.
  void addBook(Book newBook);

  // A book is removed when it is returned to the library.
  void removeBook(Book book);

  QVariant data(const QModelIndex &index, int role) const override;
  int rowCount(const QModelIndex &parent) const override;

private:
  QList<Book> books{};
};
