#include <string>

class book {
   public:
    std::string name;

    bool operator>(const book &b2);
    bool operator>=(const book &b2);

    bool operator<(const book &b2);
    bool operator<=(const book &b2);

    bool operator==(const book &b2);
    bool operator!=(const book &b2);
};
