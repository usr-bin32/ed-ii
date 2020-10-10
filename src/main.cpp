#include <algorithm>
#include <array>
#include <cstring>
#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "structures/book.h"
#include "parsing/csv_parser.h"
#include "algorithms/merge_sort.h"

void read_input(std::vector<unsigned int> &sizes);
void read_books(std::vector<book> &books);
void randomize(std::vector<book> &books);

int main() {
    std::vector<unsigned int> sizes;
    read_input(sizes);

    if (sizes.empty()) {
        return 0;
    }

    std::vector<book> books;
    read_books(books);
    
    for (auto size : sizes) {
        for (int i = 0; i < 5; i++) {
            randomize(books);
            merge_sort(books.data(), size);
        }
        // TODO: adicionar outros métodos de ordenação
    }
}

void read_input(std::vector<unsigned int> &sizes) {
    std::ifstream input_file("./entrada.txt");

    if (!input_file.is_open()) {
        std::cerr << "Failed to open `entrada.txt`!" << std::endl;
        return;
    }

    std::string line;
    std::getline(input_file, line);

    unsigned int len = 0;
    std::cin >> len;

    sizes.reserve(len);
    for (int i = 0; i < len; i++) {
        std::getline(input_file, line);
        unsigned int size = 0;
        std::cin >> size;

        sizes.push_back(size);
    }
}

void read_books(std::vector<book> &books) {
    csv_parser parser("./res/data.csv");

    if (!parser.is_open()) {
        std::cerr << "Failed to open the `data.csv` file!" << std::endl;
        return;
    }

    parser.read_line(); // pula o cabeçalho
    while (parser.read_line()) {
        book book;
        parser.get(9, book.name);

        books.push_back(std::move(book));
    }
}

void randomize(std::vector<book> &books) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(books.begin(), books.end(), std::default_random_engine(seed));
}
