#include <iostream>
#include <fstream>  // Для работы с файловыми потоками
#include <string>   // Для работы со строками
#include <limits>   // Для очистки буфера ввода

struct Student {
    std::string name;
    int age;
    double grade;
};

// Функция записи данных студента в текстовый файл
void addStudentToFile(const Student& s, const std::string& filename) {
    std::ofstream fout(filename, std::ios::app);
    
    // Проверка успешности открытия файла
    if (!fout.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    // Запись данных 
    fout << s.name << " " << s.age << " " << s.grade << std::endl;
    
    // Закрытие файла
    fout.close();
    std::cout << "Данные студента успешно добавлены в конец файла." << std::endl;
}

// Функция чтения данных из файла и вывода на экран
void printAllStudents(const std::string& filename) {
    // Используем ifstream для чтения
    std::ifstream fin(filename);
    
    if (!fin.is_open()) {
        std::cerr << "Файл не найден или не может быть открыт!" << std::endl;
        return;
    }

    Student s;
    std::cout << "\n--- Список всех студентов ---" << std::endl;
    
    while (fin >> s.name >> s.age >> s.grade) {
        std::cout << "Имя: " << s.name 
                  << ", Возраст: " << s.age 
                  << ", Средний балл: " << s.grade << std::endl;
    }

    fin.close();
}

// Вспомогательная функция для безопасного ввода чисел
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    const std::string filename = "students.txt";
    int choice;

    while (true) {
        std::cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "1. Добавить студента" << std::endl;
        std::cout << "2. Показать всех студентов" << std::endl;
        std::cout << "3. Выход" << std::endl;
        std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
        std::cout << "Выберите действие: ";

        // Проверка корректности ввода пункта меню
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка! Введите число (1-3)." << std::endl;
            clearInput();
            continue;
        }

        if (choice == 1) {
            Student newStudent;
            std::cout << "Введите имя: ";
            std::cin >> newStudent.name;

            std::cout << "Введите возраст: ";
            while (!(std::cin >> newStudent.age)) {
                std::cout << "Некорректный возраст. Введите целое число: ";
                clearInput();
            }

            std::cout << "Введите средний балл: ";
            while (!(std::cin >> newStudent.grade)) {
                std::cout << "Некорректный балл. Введите число (например, 4.5): ";
                clearInput();
            }

            addStudentToFile(newStudent, filename);
        } 
        else if (choice == 2) {
            printAllStudents(filename);
        } 
        else if (choice == 3) {
            std::cout << "Завершение работы." << std::endl;
            break;
        } 
        else {
            std::cout << "Неверный пункт меню. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}