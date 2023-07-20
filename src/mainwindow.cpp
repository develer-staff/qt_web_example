#include "mainwindow.h"

#include <QFrame>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QWebChannel>
#include <QWebEngineView>

#include "booklending.h"
#include "booklistmodel.h"
#include "bookshelfwidget.h"

MainWindow::MainWindow(QWidget *p_pParent) : QMainWindow(p_pParent) {
  // Init data model.
  books = new BookListModel(this);
  books->addBook(Book{"Romeo and Juliet", "William Shakespeare"});

  // Init web channel.
  auto bookLending = new BookLending(this);
  auto webChannel = new QWebChannel(this);
  webChannel->registerObject("bookLending", bookLending);

  // Init widgets.
  auto webViewGroup = new QGroupBox("Library web view", this);
  auto bookshelfWidget = new BookshelfWidget(books, this);
  auto webView = new QWebEngineView(this);
  webView->page()->setWebChannel(webChannel);
  webView->setUrl(QUrl("qrc:/web_pages/library.html"));

  // Init layout.
  auto groupLayout = new QHBoxLayout(webViewGroup);
  groupLayout->addWidget(webView);
  auto frame = new QFrame(this);
  auto layout = new QHBoxLayout(frame);
  layout->setSpacing(20);
  layout->addWidget(bookshelfWidget, 1);
  layout->addWidget(webViewGroup, 2);

  setCentralWidget(frame);
  setStyleSheet(" QGroupBox { font: bold }");
  setMinimumSize(900, 600);

  // Do connections.
  //
  // Add a book to the bookshelf.
  connect(bookLending, &BookLending::bookReceived, books,
          &BookListModel::addBook);

  // Remove a book from the bookshelf.
  connect(bookLending, &BookLending::bookReturned, books,
          &BookListModel::removeBook);

  // Show messages from the library.
  connect(bookLending, &BookLending::messageReceived, this,
          &MainWindow::showMessage);

  // Request a book from the library.
  connect(bookshelfWidget, &BookshelfWidget::requestLending, bookLending,
          &BookLending::requestLending);

  // Return a book to the library.
  connect(bookshelfWidget, &BookshelfWidget::requestReturn, bookLending,
          &BookLending::requestReturn);
}

void MainWindow::showMessage(const QString &message) {
  QMessageBox messageBox;
  messageBox.setWindowTitle("Message from the library");
  messageBox.setIcon(QMessageBox::Information);
  messageBox.setText(message);
  messageBox.exec();
}
