#ifndef CSV_PARSER
#define CSV_PARSER

#include <array>
#include <string>
#include <vector>
#include <fstream>

struct csv_handle {
    // Posição da coluna na linha
    size_t position;
    // Comprimento em bytes do conteúdo da coluna
    size_t length;
};

class csv_parser {
   public:
    csv_parser(std::string path);

    bool is_open();

    // Lê e interpreta a próxima linha do arquivo .csv carregado usando
    // leitura "bufferizada"
    bool read_line();

    // Lê a n-ésima coluna da última linha lida e executa a conversão de tipo
    template <typename T>
    bool get(size_t index, T &out);

   private:
    std::ifstream file;

    size_t buffer_size = 0;
    // Não deve haver nenhuma linha maior que o tamanho do buffer!
    std::array<char, 32768> buffer;

    size_t index = 0;
    size_t characters_read = 0;

    // Armazena os dados das colunas da última linha lida
    std::vector<csv_handle> handles;

    // Interpreta a próxima linha de .csv presente no buffer
    bool read_buffer_line();

    template <typename T>
    inline bool get(size_t index, T &out, const char *format);
};

template <>
bool csv_parser::get<std::string>(size_t index, std::string &out);

template <>
bool csv_parser::get<char>(size_t index, char &out);

template <>
bool csv_parser::get<unsigned char>(size_t index, unsigned char &out);

template <>
bool csv_parser::get<short>(size_t index, short &out);

template <>
bool csv_parser::get<unsigned short>(size_t index, unsigned short &out);

template <>
bool csv_parser::get<int>(size_t index, int &out);

template <>
bool csv_parser::get<unsigned int>(size_t index, unsigned int &out);

template <>
bool csv_parser::get<long>(size_t index, long &out);

template <>
bool csv_parser::get<unsigned long>(size_t index, unsigned long &out);

template <>
bool csv_parser::get<float>(size_t index, float &out);

template <>
bool csv_parser::get<double>(size_t index, double &out);

template <typename T>
inline bool csv_parser::get(size_t index, T &out, const char *format) {
    if (index >= this->handles.size()) {
        return false;
    }

    csv_handle handle = this->handles[index];
    if (handle.length == 0) {
        return false;
    }

    sscanf(&this->buffer[handle.position], format, &out);

    return true;
}

#endif
