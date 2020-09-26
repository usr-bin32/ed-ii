#include "book.h"


bool book::operator>(const book &b2) {
    return this->isbn > b2.isbn;
}

bool book::operator>=(const book &b2) {
    return this->isbn >= b2.isbn;
}

bool book::operator<(const book &b2) {
    return this->isbn < b2.isbn;
}

bool book::operator<=(const book &b2) {
    return this->isbn <= b2.isbn;
}

bool book::operator==(const book &b2) {
    return this->isbn == b2.isbn;
}

bool book::operator!=(const book &b2) {
    return this->isbn != b2.isbn;
}
