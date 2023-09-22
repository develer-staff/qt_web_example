#include "bookshelfwidget.h"

#include <QGroupBox>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>

#include "booklistmodel.h"

BookshelfWidget::BookshelfWidget(BookListModel *books, QWidget *parent)
    : QWidget(parent) {
  // Init widgets.
  input = new QLineEdit(this);
  input->setPlaceholderText("Enter a title or an author");

  requestButton = new QPushButton("Request Book", this);
  requestButton->setEnabled(false);

  booksView = new QListView(this);
  booksView->setModel(books);

  returnButton = new QPushButton("Return Book", this);
  returnButton->setEnabled(false);

  auto requestGroup = new QGroupBox("Request book", this);
  auto bookshelfGroup = new QGroupBox("My bookshelf", this);

  // Init layout.
  auto requestLayout = new QVBoxLayout(requestGroup);
  requestLayout->addWidget(input);
  requestLayout->addWidget(requestButton);
  auto bookshelfLayout = new QVBoxLayout(bookshelfGroup);
  bookshelfLayout->addWidget(booksView);
  bookshelfLayout->addWidget(returnButton);

  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(30);
  layout->addWidget(requestGroup);
  layout->addWidget(bookshelfGroup);

  // Do connections.
  // Request a book.
  connect(requestButton, &QPushButton::clicked, this,
          &BookshelfWidget::onRequestClicked);

  // Return a book.
  connect(returnButton, &QPushButton::clicked, this,
          &BookshelfWidget::onReturnClicked);

  // Handle request button enabled state on input text changed.
  connect(input, &QLineEdit::textChanged, this,
          &BookshelfWidget::onInputTextChanged);

  // Handle return button enabled state on book selection changed.
  connect(booksView->selectionModel(), &QItemSelectionModel::selectionChanged,
          this, &BookshelfWidget::onBookSelectionChanged);
}

void BookshelfWidget::onRequestClicked() {
  emit lendingRequested(input->text().trimmed());

  input->clear();
}

void BookshelfWidget::onReturnClicked() {
  const auto book = booksView->currentIndex().data().toString();
  const auto title = book.split("-").first().trimmed();

  emit returnRequested(title);

  booksView->clearSelection();
}

void BookshelfWidget::onInputTextChanged(const QString &text) {
  requestButton->setEnabled(!text.trimmed().isEmpty());
}

void BookshelfWidget::onBookSelectionChanged(const QItemSelection &selected,
                                             const QItemSelection &deselected) {
  Q_UNUSED(deselected)

  if (selected.isEmpty()) {
    returnButton->setEnabled(false);
    return;
  }

  const auto index = selected.first().indexes().first();
  returnButton->setEnabled(index.isValid());
}
