#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "algorithms/quick_sort.h"
#include "algorithms/shell_sort.h"
#include "parsing/csv_parser.h"
#include "structures/book.h"

using sort_function = void (*)(book *, size_t, int &, int &);

const int NUM_TESTS = 5;

void read_input(std::vector<unsigned int> &sizes);
void read_books(std::vector<book> &books);
void randomize(std::vector<book> &books);

void test_sort(sort_function sort_function, std::vector<book> &vector, size_t size);

int main() {
    std::vector<unsigned int> sizes;
    read_input(sizes);

    if (sizes.empty()) {
        return 0;
    }

    std::vector<book> books;
    read_books(books);

    for (auto size : sizes) {
        std::cout << "N = " << size << std::endl;

        std::cout << "Shell Sort:" << std::endl;
        test_sort(static_cast<sort_function>(&shell_sort), books, size);

        std::cout << "Quick Sort" << std::endl;
        test_sort(static_cast<sort_function>(&quick_sort), books, size);
    }
}

void read_input(std::vector<unsigned int> &sizes) {
    std::ifstream input_file("./entrada.txt");

    if (!input_file.is_open())
    {
        std::cerr << "Failed to open `entrada.txt`!" << std::endl;
        return;
    }

    unsigned int len = 0;
    input_file >> len;

    sizes.reserve(len);
    for (int i = 0; i < len; i++)
    {
        unsigned int size = 0;
        input_file >> size;

        sizes.push_back(size);
    }
}

void read_books(std::vector<book> &books) {
    csv_parser parser("./res/data.csv");

    if (!parser.is_open())
    {
        std::cerr << "Failed to open the `data.csv` file!" << std::endl;
        return;
    }

    parser.read_line(); // pula o cabeçalho
    while (parser.read_line())
    {
        book book;
        parser.get(9, book.name);

        books.push_back(std::move(book));
    }
}

void randomize(std::vector<book> &books)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(books.begin(), books.end(), std::default_random_engine(seed));
}

void test_sort(sort_function sort, std::vector<book> &vector, size_t size) {
    int total_comparisons = 0;
    int total_swaps = 0;
    double total_time = 0;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        randomize(vector);

        int comparisons;
        int swaps;

        double t0 = double(clock()) / CLOCKS_PER_SEC;
        sort(vector.data(), size, comparisons, swaps);
        double t1 = double(clock()) / CLOCKS_PER_SEC;

        total_comparisons += comparisons;
        total_swaps += swaps;
        total_time += t1 - t0;
    }

    std::cout << "    Comparações: " << total_comparisons / NUM_TESTS << std::endl;
    std::cout << "    Trocas: " << total_swaps / NUM_TESTS << std::endl;
    std::cout << "    Tempo: " << total_time / NUM_TESTS << " s" << std::endl;
}
