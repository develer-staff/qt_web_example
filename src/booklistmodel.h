#pragma once

#include <QAbstractListModel>

#include "utils.h"

class BookListModel : public QAbstractListModel {
  Q_OBJECT

public:
  explicit BookListModel(QObject *parent = nullptr);

  void addBook(Book newBook);
  void removeBook(Book book);

  QVariant data(const QModelIndex &index, int role) const override;
  int rowCount(const QModelIndex &parent) const override;

private:
  QList<Book> books{};
};
