#include "book.h"

bool book::operator>(const book &b2) {
    return this->name > b2.name;
}

bool book::operator>=(const book &b2) {
    return this->name >= b2.name;
}

bool book::operator<(const book &b2) {
    return this->name < b2.name;
}

bool book::operator<=(const book &b2) {
    return this->name <= b2.name;
}

bool book::operator==(const book &b2) {
    return this->name == b2.name;
}

bool book::operator!=(const book &b2) {
    return this->name != b2.name;
}
