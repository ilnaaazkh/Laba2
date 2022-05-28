#include <iostream>
#include <fstream>
#include "my_funcs.h"
#include "const.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    char inputWay{}, outputWay{};
    bool next{ true };
    std::ifstream fin(inputFile);
    std::ofstream fout(outputFile);
    std::vector <unsigned int> v;
    int num{ 0 };
    while (next) {
        std::cout << "Ввод с консоли (0) или из файла(1): " << std::endl;
        inputWay = getWay();
        std::cout << "Вывод в консоль (0) или в файл (1): " << std::endl;
        outputWay = getWay();
        if (outputWay == '0' && inputWay == '0') {
            std::cout << "Введите значения элементов: \n";
            while (num >= 0) {
                num = getValue();
                if (num >= 0) { v.push_back(num); }
            }
            num = 0;
            maxOfSquares(v, std::cout);
            next = getNext();
            v.clear();
        }
        else if (outputWay == '1' && inputWay == '0') {
            if (fout.is_open()) {
                std::cout << "Введите значения элементов: \n";
                while (num >= 0) {
                    num = getValue();
                    if (num >= 0) { v.push_back(num); }
                }
                num = 0;
                maxOfSquares(v, fout);
                next = getNext();
            }
            else { std::cout << "Ошибка открытия файла. \n"; next = false; }
            v.clear();
        }
        else if (outputWay == '0' && inputWay == '1') {
            if (fin.is_open()) {
                while (!fin.eof() && num >= 0) {
                    fin >> num;
                    if (num >= 0) { v.push_back(num); }
                }
                num = 0;
                maxOfSquares(v, std::cout);
                next = false;
            }
            else {
                std::cout << "Ошибка открытия файла \n";
                next = false;
            }
            v.clear();
        }
        else if (outputWay == '1' && inputWay == '1') {
            if (fin.is_open()) {
                while (!fin.eof() && num >= 0) {
                    fin >> num;
                    if (num >= 0) { v.push_back(num); }
                }
                num = 0;
                maxOfSquares(v, fout);
                next = false;
            }
            else {
                std::cout << "Ошибка открытия файла \n";
                next = false;
            }
            v.clear();
        }
    }
    fin.close();
    fout.close();
    return 0;
}

