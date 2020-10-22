#include <string>

class book {
   public:
    std::string name;

    // implementa operações de comparação para os algoritmos de ordenação

    bool operator>(const book &b2);
    bool operator>=(const book &b2);

    bool operator<(const book &b2);
    bool operator<=(const book &b2);

    bool operator==(const book &b2);
    bool operator!=(const book &b2);
};
