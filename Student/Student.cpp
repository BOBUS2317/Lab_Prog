#include "Student.h"
#include <iostream>

Student::Student(std::string fName, std::string lName, int rbNum)
    : firstName(fName), lastName(lName), recordBook(rbNum) {}
 
Student::~Student() {
    std::cout << "Memory for student: " << firstName << " clear" << std::endl;
}

void Student::addGrade(int grade) {
    if (grade >= 2 && grade <= 5) {
        grades.push_back(grade);
    }
}

double Student::getAverage() const {
    if (grades.empty()) return 0.0;
    double sum = 0;
    for (int g : grades) sum += g;
    return sum / grades.size();
}

void Student::printInfo() const {
    std::cout << "Student: " << firstName << " " << lastName 
              << " | ID: " << recordBook 
              << " | Average score: " << getAverage() << std::endl;
}