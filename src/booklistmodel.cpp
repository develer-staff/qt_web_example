#include "booklistmodel.h"

BookListModel::BookListModel(QObject *parent) : QAbstractListModel(parent) {}

void BookListModel::addBook(Book newBook) {
  beginInsertRows(QModelIndex(), books.count(), books.count() + 1);

  books.append(newBook);

  endInsertRows();
}

void BookListModel::removeBook(Book book) {
  const auto rowIndex = books.indexOf(book);
  if (rowIndex == -1)
    return;

  beginRemoveRows(QModelIndex(), rowIndex, rowIndex);

  books.removeAt(rowIndex);

  endRemoveRows();
}

QVariant BookListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || index.row() >= books.count())
    return {};

  if (role == Qt::DisplayRole) {
    const auto book = books.at(index.row());
    return QString("%1 - %2").arg(book.title, book.author);
  }

  return {};
}

int BookListModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid())
    return 0;

  return books.count();
}
