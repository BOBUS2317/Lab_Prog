#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

struct Product {
    int code;
    char title[50];
    double price;
    int quantity;
};

// Функция записи товара в бинарный файл
void addProduct(const std::string& filename) {
    Product p;
    std::cout << "Введите код товара: ";
    std::cin >> p.code;
    std::cin.ignore();

    std::cout << "Введите название (до 50 симв.): ";
    std::cin.getline(p.title, 50);

    std::cout << "Введите цену (в долларах): ";
    std::cin >> p.price;

    std::cout << "Введите количество: ";
    std::cin >> p.quantity;

    // Открытие в бинарном режиме и режиме добавления
    std::ofstream fout(filename, std::ios::binary | std::ios::app);
    
    if (!fout.is_open()) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return;
    }

    // Записываем структуру целиком через приведение к char*
    fout.write(reinterpret_cast<char*>(&p), sizeof(Product));
    fout.close();
    std::cout << "Товар успешно сохранен в файл." << std::endl;
}

// Функция чтения всех товаров
void printAllProducts(const std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    
    if (!fin.is_open()) {
        std::cerr << "Файл не найден." << std::endl;
        return;
    }

    Product p;
    std::cout << "\n--- Список товаров на складе ---" << std::endl;
    while (fin.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        std::cout << "Код: " << p.code 
                  << " | Название: " << p.title 
                  << " | Цена: " << p.price 
                  << " | Кол-во: " << p.quantity << std::endl;
    }
    fin.close();
}

// Поиск товара по коду
void findProductByCode(const std::string& filename) {
    int searchCode;
    std::cout << "Введите код для поиска: ";
    std::cin >> searchCode;

    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) return;

    Product p;
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        if (p.code == searchCode) {
            std::cout << "По результатам поиска найдено: " << p.title << ", Цена: " << p.price << ", На складе: " << p.quantity << std::endl;
            found = true;
            break;
        }
    }
    if (!found) std::cout << "Товар с кодом " << searchCode << " не найден." << std::endl;
    fin.close();
}

// Подсчёт общей стоимости всех товаров
void calculateTotalValue(const std::string& filename) {
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) return;

    Product p;
    double total = 0;
    while (fin.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        total += p.price * p.quantity;
    }
    std::cout << "Общая стоимость всех товаров на складе: " << total << std::endl;
    fin.close();
}

int main() {
    const std::string filename = "products.bin";
    int choice;

    while (true) {
        std::cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "1. Добавить товар" << std::endl;
        std::cout << "2. Обзор товаров на складе" << std::endl;
        std::cout << "3. Поиск по коду" << std::endl;
        std::cout << "4. Общая стоимость товаров" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "Выберите действие: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) addProduct(filename);
        else if (choice == 2) printAllProducts(filename);
        else if (choice == 3) findProductByCode(filename);
        else if (choice == 4) calculateTotalValue(filename);
        else if (choice == 5) break;
    }
    return 0;
}