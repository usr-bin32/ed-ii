#include <string>

class book {
   public:
    std::string isbn;

    // unused attributes
    // std::string title;
    // std::string author;
    // int year;
    // std::string publisher;
    // std::string blurb;

    bool operator>(const book &b2);
    bool operator>=(const book &b2);

    bool operator<(const book &b2);
    bool operator<=(const book &b2);

    bool operator==(const book &b2);
    bool operator!=(const book &b2);
};
