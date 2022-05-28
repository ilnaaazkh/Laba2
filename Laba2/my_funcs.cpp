#include <iostream>
#include <istream>
#include <fstream>
#include <limits>
#include <vector>
using namespace std;


bool getNext()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Хотите повторить ввод данных? (Да - 1, Нет - 0)\n";
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Попробуйте еще раз. \n";
        std::cin >> n;
    }
    return n == '1';
}

char getWay()
{
    setlocale(LC_ALL, "Russian");
    char n{};
    std::cin >> n;
    while (n != '1' && n != '0') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Попробуйте еще раз. \n";
        std::cin >> n;
    }
    return n;
}

int getValue()
{
    while (true)
    {
        double a{};
        std::cin >> a;
        if (std::cin.fail() || a != round(a)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введенные числа должны быть натуральными. Попробуйте еще раз. \n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return (int)a;
        }
    }
}

void maxOfSquares(std::vector <unsigned int> v, std::ostream& f) {
    f << "Входные данные: ";
    for (int i = 0; i < v.size(); i++) {
        f << v[i] << " ";
    }
    f << "\n";
    unsigned int max{ 0 };
    for (int i = 0; i < v.size(); i++) {
        max = (max < v[i] ? v[i] : max);
    }
    f << "Наибольший квадрат у числа: " << max << " : " << max * max << "\n";
}
