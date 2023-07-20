#pragma once

#include <QString>

struct Book {
  QString title{};
  QString author{};

  bool operator==(const Book &other) const {
    return title == other.title && author == other.author;
  }
};
