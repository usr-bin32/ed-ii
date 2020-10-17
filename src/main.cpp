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
#include "algorithms/quick_sort.h"
#include "algorithms/shell_sort.h"

void read_input(std::vector<unsigned int> &sizes);
void read_books(std::vector<book> &books);
void randomize(std::vector<book> &books);

int main()
{
    int changesCounter = 0;
    int comparisonsCounter = 0;

    std::vector<unsigned int> sizes;
    read_input(sizes);

    if (sizes.empty())
    {
        return 0;
    }

    std::vector<book> books;
    read_books(books);

    for (auto size : sizes)
    {
        std::cout << std::endl;
        std::cout << "Testando N: " << size << std::endl;
        int totalComparisons = 0;
        int totalChanges = 0;
        double totalTimes = 0;

        for (int i = 0; i < 5; i++)
        {

            randomize(books);
            double t0 = double(clock()) / CLOCKS_PER_SEC;
            shell_sort(books.data(), size, comparisonsCounter, changesCounter);
            double t1 = double(clock()) / CLOCKS_PER_SEC;

            totalComparisons += comparisonsCounter;
            totalChanges += changesCounter;
            totalTimes += t1 - t0;

            changesCounter = 0;
            comparisonsCounter = 0;
        }

        std::cout << std::endl;
        std::cout << "Shell comparacoes: " << totalComparisons / 5 << std::endl;
        std::cout << "Shell trocas: " << totalChanges / 5 << std::endl;
        std::cout << "Shell tempo: " << totalTimes / 5 << std::endl;

        totalComparisons = 0;
        totalChanges = 0;
        totalTimes = 0;
        
        for (int i = 0; i < 5; i++)
        {

            randomize(books);

            double t0 = double(clock()) / CLOCKS_PER_SEC;
            quick_sort(books.data(), 0, size - 1, comparisonsCounter, changesCounter);
            double t1 = double(clock()) / CLOCKS_PER_SEC;

            totalComparisons += comparisonsCounter;
            totalChanges += changesCounter;
            totalTimes += t1 - t0;

            changesCounter = 0;
            comparisonsCounter = 0;
        }

        std::cout << std::endl;
        std::cout << "Quick comparacoes: " << totalComparisons / 5 << std::endl;
        std::cout << "Quick trocas: " << totalChanges / 5 << std::endl;
        std::cout << "Quick tempo: " << totalTimes / 5 << std::endl;
    }
}

void read_input(std::vector<unsigned int> &sizes)
{
    std::ifstream input_file("./entrada.txt");

    if (!input_file.is_open())
    {
        std::cerr << "Failed to open `entrada.txt`!" << std::endl;
        return;
    }

    std::string line;
    std::getline(input_file, line);

    unsigned int len = 0;
    std::istringstream iss(line);
    iss >> len;

    sizes.reserve(len);
    for (int i = 0; i < len; i++)
    {
        std::getline(input_file, line);
        std::istringstream iss(line);

        unsigned int size = 0;
        iss >> size;

        sizes.push_back(size);
    }
}

void read_books(std::vector<book> &books)
{
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
