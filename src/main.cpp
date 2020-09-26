#include <array>
#include <cstring>
#include <iostream>
#include <vector>

#include "structures/book.h"
#include "parsing/csv_parser.h"
#include "algorithms/merge_sort.h"

int main() {
    csv_parser parser("./res/books_with_blurbs.csv");

    if (!parser.is_open()) {
        std::cout << "Failed to open the file!" << std::endl;
        return 0;
    }

    std::vector<book> books;

    parser.read_line(); // pula o título
    while (parser.read_line()) {
        book book;
        parser.get(0, book.isbn);
        books.push_back(std::move(book));
    }

    merge_sort(books.data(), books.size());

    std::cout << books.size() << "\n";
    for (auto &book : books) {
        std::cout << book.isbn << std::endl;
    }
}
