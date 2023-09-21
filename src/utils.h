#pragma once

#include <QString>

// This structure holds the main info of a Book.
struct Book {
  QString title{};
  QString author{};

  bool operator==(const Book &other) const {
    return title == other.title && author == other.author;
  }
};
