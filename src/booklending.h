#pragma once

#include <QObject>

#include "utils.h"

class BookLending : public QObject {
  Q_OBJECT

public:
  BookLending(QObject *parent = nullptr) : QObject(parent) {}

public slots:
  void sendBook(const QString &title, const QString &author) {
    Book newBook{title, author};
    emit bookReceived(newBook);
  }

  void takeBackBook(const QString &title, const QString &author) {
    Book book{title, author};
    emit bookReturned(book);
  }

  void sendMessage(const QString &message) { emit messageReceived(message); }

signals:
  // Signals for Web app.
  void requestLending(const QString &bookData);
  void requestReturn(const QString &bookData);

  // Signals for Qt app.
  void bookReceived(Book newBook);
  void bookReturned(Book book);

  void messageReceived(const QString &message);
};
