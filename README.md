# Trabalho de Estrutura de Dados II: Parte 1
Primeira parte do trabalho da disciplina de Esturutra de Dados II (2020.1-B).

## Compilação
O projeto foi testado com o compilador GCC (G++) tanto no Linux quanto sua versão no Windows (MinGW) e é compatível com C++ 11 ou mais novo. Para compilar o projeto, basta executar o makefile ou rodar o seguinte comando:
```
g++ ./src/main.cpp ./src/parsing/csv_parser.cpp ./src/structures/book.cpp -Ofast -std=c++11 -o ./project.out
```

## Modo de Uso
Para usar o programa, basta executá-lo a partir do diretório raiz do projeto, que contém o arquivo de entrada `entrada.txt`. Além disso, o arquivo .csv deve ser colocado no caminho `./res/data.csv`. O programa fará a leitura da entrada automaticamente e sua será impressa na saída padrão (terminal). Para redirecionar a saída para um arquivo, basta executar o seguinte comando:
```sh
./project.out > saida.txt
```

A saída do programa será exibida no seguinte formato:
```
N = 1000
Shell Sort:
    Comparações: 14512
    Trocas: 14512
    Tempo: 0.0009102s
Quick Sort:
    Comparações: 14289
    Trocas: 2328
    Tempo: 0.0007154s

N = 5000
...
```
