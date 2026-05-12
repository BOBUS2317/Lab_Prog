#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

// Структура Sale согласно заданию
struct Sale {
    std::string date;
    int buyer;
    double sum;
    std::string category;
};

bool parseLine(const std::string& line, Sale& s) {
    std::stringstream ss(line);
    std::string tempSum, tempBuyer;

    if (!std::getline(ss, s.date, ',')) return false;

    ss >> s.buyer;
    ss.ignore(); 

    std::getline(ss, tempSum, ',');
    try {
        s.sum = std::stod(tempSum);
    } catch (...) { s.sum = 0.0; }

    std::getline(ss, s.category);

    return true;
}

// Функция подсчёта общей суммы продаж
void calculateTotalSales(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Файл " << filename << " не найден!" << std::endl;
        return;
    }

    std::string line;
    double total = 0.0;
    while (std::getline(fin, line)) {
        Sale s;
        if (parseLine(line, s)) {
            total += s.sum;
        }
    }
    std::cout << "Общая сумма продаж в файле: " << total << std::endl;
    fin.close();
}

// Функция фильтрации по дате и записи в новый CSV файл
void filterSalesByDate(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream fin(inputFilename);
    std::ofstream fout(outputFilename);

    if (!fin.is_open() || !fout.is_open()) {
        std::cerr << "Ошибка при работе с файлами!" << std::endl;
        return;
    }

    std::string targetDate;
    std::cout << "Введите дату для фильтрации (например, 2023-10-25): ";
    std::cin >> targetDate;

    std::string line;
    int count = 0;
    while (std::getline(fin, line)) {
        Sale s;
        if (parseLine(line, s)) {
            if (s.date == targetDate) {
                fout << s.date << "," << s.buyer << "," << s.sum << "," << s.category << "\n";
                count++;
            }
        }
    }

    std::cout << "Фильтрация завершена. Найдено записей: " << count << std::endl;
    std::cout << "Результаты сохранены в " << outputFilename << std::endl;

    fin.close();
    fout.close();
}

int main() {
    const std::string inputCSV = "sales.csv";
    const std::string outputCSV = "filtered_sales.csv";
    std::ofstream testFile(inputCSV);
    testFile << "2023-10-25,101,550.50,Electronics\n";
    testFile << "2023-10-26,102,1200.00,Home\n";
    testFile << "2023-10-25,103,300.25,Electronics\n";
    testFile.close();

    int choice;
    while (true) {
        std::cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "--- Продажи ---" << std::endl;
        std::cout << "1. Подсчитать общую сумму продаж" << std::endl;
        std::cout << "2. Фильтровать продажи по дате" << std::endl;
        std::cout << "3. Выход" << std::endl;
        std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            calculateTotalSales(inputCSV);
        } else if (choice == 2) {
            filterSalesByDate(inputCSV, outputCSV);
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}