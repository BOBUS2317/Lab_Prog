#include <iostream>
#include <string>
using namespace std;

struct Address {
    string street;
    int house;
    int flat;
};

struct Person {
    string fio;
    int age;
    Address address;
};

struct Simple_Person{
    string fio;
    int age;
    string street;
    int house;
    int flat;
};

int get_number() {
    int number;
    while (!(cin >> number)) {
        cout << "введено не число. введите еще раз: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    cin.ignore(10000, '\n');
    return number;
}

void input_people(Person people[]) {
    for (int i = 0; i < 3; i++) {
        cout << "введите данные для человека " << endl;
        cout << "ФИО: ";
        getline(cin, people[i].fio);
        cout << "возраст: ";
        people[i].age = get_number();
        cout << "улица: ";
        getline(cin, people[i].address.street); 
        cout << "дом: ";
        people[i].address.house = get_number();   
        cout << "квартира: ";
        people[i].address.flat = get_number();  
    }
}

void print_people(Person people[]) {
    cout << "список людей:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << people[i].fio << ", " << people[i].age 
             << " лет   адрес: ул. " << people[i].address.street << ", д. " 
             << people[i].address.house << ", кв. " << people[i].address.flat << endl;
    }
}

void search_street(Person people[]) {
    bool flag_found = false;
    string street_to_search = "";
    
    while (!flag_found) {
        cout << "введите название улицы для поиска: ";
        cin >> street_to_search;
        
        for (int i = 0; i < 3; i++) {
            if (people[i].address.street == street_to_search) {
                cout << people[i].fio << ", " << people[i].age << " лет, дом " 
                     << people[i].address.house << ", кв. " << people[i].address.flat << endl;
                flag_found = true;
            }
        }
        
        if (!flag_found) {
            cout << "никто не найден на этой улице" << endl;
        }
    }
}

void input_simple_people(Simple_Person simple_people[]) {
    for (int i = 0; i < 3; i++) {
        cout << "введите данные для человека " << endl;
        cout << "ФИО: ";
        getline(cin, simple_people[i].fio);
        cout << "возраст: ";
        simple_people[i].age = get_number();
        cout << "улица: ";
        getline(cin, simple_people[i].street); 
        cout << "дом: ";
        simple_people[i].house = get_number();   
        cout << "квартира: ";
        simple_people[i].flat = get_number();  
    }
}

void print_simple_people(Simple_Person simple_people[]) {
    cout << "список людей:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << simple_people[i].fio << ", " << simple_people[i].age 
             << " лет   адрес: ул. " << simple_people[i].street << ", д. " 
             << simple_people[i].house << ", кв. " << simple_people[i].flat << endl;
    }
}

void search_street_simple_people(Simple_Person simple_people[]) {
    bool flag_found = false;
    string street_to_search = "";
    
    cout << "введите название улицы для поиска: ";
    cin >> street_to_search;
    
    for (int i = 0; i < 3; i++) {
        if (simple_people[i].street == street_to_search) {
            cout << simple_people[i].fio << ", " << simple_people[i].age << " лет, дом " 
                 << simple_people[i].house << ", кв. " << simple_people[i].flat << endl;
            flag_found = true;
        }
    }
    
    if (!flag_found) {
        cout << "никто не найден на этой улице" << endl;
    }
}



int main() {
    Person people[3];
    input_people(people);
    print_people(people);
    
    search_street(people);
   
    cout << "демонстрация:" << endl;
    cout << "человек: " << people[0].fio << endl;
    cout << "улица: " << people[0].address.street << endl; 
    cout << "дом: " << people[0].address.house << endl;  
    cout << "квартира: " << people[0].address.flat << endl; 

    
    Simple_Person simple_people[3];
    cout<<"введите данные для плоской структуры: "<<endl;

    
    cin.ignore(10000, '\n');
    input_simple_people(simple_people);
    print_simple_people(simple_people);
    
    search_street_simple_people(simple_people);
    cout << "демонстрация использования плоской структуры:" << endl;
    cout << "человек: " << simple_people[0].fio << endl;
    cout << "улица: " <<simple_people[0].street << endl; 
    cout << "дом: " << simple_people[0].house << endl;  
    cout << "квартира: " << simple_people[0].flat << endl; 

    cout << "сравнение размера памяти:" << endl;
    cout << "размер структуры Person: " << sizeof(Person) << " байт" << endl;
    cout << "размер массива Person[3]: " << sizeof(people) << " байт" << endl;

    cout << "размер структуры Simple_Person: " << sizeof(Simple_Person) << " байт" << endl;
    cout << "размер массива Simple_Person[3]: " << sizeof(simple_people) << " байт" << endl;


   
    return 0;
}
