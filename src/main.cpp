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
        for (int i = 0; i < 1; i++)
        {

            randomize(books);

            for (int j = 0; j < size; j++)
            {
                std::cout << books[j].name << std::endl;
            }

            shell_sort(books.data(), size, comparisonsCounter, changesCounter);
            std::cout << "ShellComparisonsCounter iteracao " << i << " : " << comparisonsCounter << std::endl;
            std::cout << "ShellChangesCounter iteracao " << i << " : " << changesCounter << std::endl;

            for (int j = 0; j < size; j++)
            {
                std::cout << books[j].name << std::endl;
            }
        }
        std::cout << std::endl;
        //TODO: adicionar outros métodos de ordenação

        int changesCounter = 0;
        int comparisonsCounter = 0;

        for (int i = 0; i < 1; i++)
        {

            randomize(books);

            for (int j = 0; j < size; j++)
            {
                std::cout << books[j].name << std::endl;
            }
            
            std::cout << "Passei pela batata" << std::endl;
            quick_sort(books.data(), 0, size, comparisonsCounter, changesCounter);
            std::cout << "Passei pela batata de novo" << std::endl;
            std::cout << "QuickComparisonsCounter " << i << " : " << comparisonsCounter << std::endl;
            std::cout << "QuickChangesCounter " << i << " : " << changesCounter << std::endl;

            for (int j = 0; j < size; j++)
            {
                std::cout << books[j].name << std::endl;
            }
        }
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
