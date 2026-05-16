#include "Student.h"
#include <iostream>
#include <random>

int main(int, char **)
{   
    std::random_device rd;
    std::mt19937 gen(rd()); // Генератор случайных чисел представляющий алгоритм Вихрь Мерсенна
    std::uniform_int_distribution<> distrib(1, 100);

    std::cout << "Create student Oleg Tink id=37" << std::endl;
    Student student1("Oleg", "Tink", 37);

    std::cout << "Add grade 2 to student1" << std::endl;
    student1.addGrade(2);

    std::cout << "Student 1 info" << std::endl;
    student1.printInfo();

    std::cout << std::endl;

    std::cout << "Create student Artem Makurin id=21" << std::endl;
    Student student2("Artem", "Makurin", 27);

    std::cout << "Add 100 random grades for student2 in range (1, 100)" << std::endl;

    for (unsigned int i = 0; i < 100; i++) student2.addGrade(distrib(gen));

    std::cout << "Student 2 info" << std::endl;
    student2.printInfo();

    return 0;
}