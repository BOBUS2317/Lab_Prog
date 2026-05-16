#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string firstName;
    std::string lastName;
    int recordBook;
    std::vector<int> grades;

public:
    Student(std::string fName, std::string lName, int rbNum);

    ~Student();

    void addGrade(int grade);
    double getAverage() const;
    void printInfo() const;
};

#endif