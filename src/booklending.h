#pragma once

#include <QObject>

#include "utils.h"

// This class can be registered to a web channel so that the properties,
// signals and public methods are published to the remote clients.
// In particular, this provides the API to exchange books and messages between
// the Qt app (user) and the web app (library).
class BookLending : public QObject {
  Q_OBJECT

public:
  BookLending(QObject *parent = nullptr) : QObject(parent) {}

public slots:
  // This slot can be called by the web app to send a book to the Qt app.
  void sendBook(const QString &title, const QString &author) {
    Book newBook{title, author};
    emit bookReceived(newBook);
  }

  // This slot can be called by the web app to take back a book from the Qt app.
  void takeBackBook(const QString &title, const QString &author) {
    Book book{title, author};
    emit bookReturned(book);
  }

  // This slot can be called by the web app to send a text message to the Qt app.
  void sendMessage(const QString &message) { emit messageReceived(message); }

signals:
  // Signals for web app.
  void lendingRequested(const QString &bookData);
  void returnRequested(const QString &bookData);

  // Signals for Qt app.
  void bookReceived(Book newBook);
  void bookReturned(Book book);

  void messageReceived(const QString &message);
};
