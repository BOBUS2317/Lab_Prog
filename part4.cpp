#include <iostream>
#include <string>
using namespace std;


struct Student {
    int number_record_book;
    string name;
    enum Status { Excellent, Good, Satisfactory, Unsatisfactory };
    Status student_status; 
};

Student::Status get_status() {
    string status="";
    
    while(true){
        cout << "введите статус успеваемости (Excellent, Good, Satisfactory, Unsatisfactory): ";
        cin >> status;
        if (status == "Excellent") return Student::Excellent;
        if (status == "Good") return Student::Good;
        if (status == "Satisfactory") return Student::Satisfactory;
        if (status == "Unsatisfactory") return Student::Unsatisfactory;
        
    }
    
}

int get_number_record_book() {
    int number;
    while (!(cin >> number)) {
        cout << "введено не число. введите еще раз: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    
    return number;
}

int main() {
    string all_status[4]={"Excellent", "Good", "Satisfactory", "Unsatisfactory"};
    Student person;
    cout << "введите имя: ";
    cin >> person.name;
    cout << "введите номер зачетной книжки: ";
    person.number_record_book=get_number_record_book();
    person.student_status = get_status();
    cout << "name: " << person.name << endl;
    cout << "number record book: " << person.number_record_book << endl;
    cout << "status: " << all_status[person.student_status] << endl;
    cout << "сравнение размера памяти:"<< endl;
    size_t size_struct = sizeof(person);
    cout << "размер структуры Student: " << size_struct << " байт" << endl;
    int test_arr_int[4];
    size_t size_array = sizeof(test_arr_int);
    cout << "размер массива из 4 int: " << size_array << " байт" << endl;

    return 0;
}