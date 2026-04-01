#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum VehicleType { Car, Truck, Motorcycle };

struct Engine {
    int power;
    double volume;
};

struct Vehicle {
    VehicleType type;
    string model;
    Engine engine;
};

struct Vehicle_without_nesting_structures {
    string type;
    string model;
    int power;
    double volume;
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

string type_to_string(VehicleType type) {  
    if (type == Car) return "Car";
    if (type == Truck) return "Truck";
    if (type == Motorcycle) return "Motorcycle";
    return "";
}

void input_vehicles(Vehicle vehicles[]) {
    for (int i = 0; i < 5; i++) {
        int type_input;
        while (true) {
            cout << "введите данные для транспорта " << i + 1 << endl;
            cout << "тип (0-Car, 1-Truck, 2-Motorcycle): ";
            
            if (cin >> type_input) {
                if (type_input >= 0 && type_input <= 2) {
                    break;
                } else {
                    cout << "неправильно. введите 0, 1 или 2" << endl;
                }
            } 
            else {
                cout << "неправильно. введите число 0, 1 или 2" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        
        vehicles[i].type = (VehicleType)type_input;
        
        cout << "модель: ";
        cin >> vehicles[i].model;
        
        cout << "мощность двигателя: ";
        vehicles[i].engine.power = get_number();
        
        cout << "объем двигателя: ";
        vehicles[i].engine.volume = get_number();
    }
}

void print_vehicles(Vehicle vehicles[]) {
    cout << "список транспорта:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << type_to_string(vehicles[i].type) << " " << vehicles[i].model
             << ", мощность: " << vehicles[i].engine.power
             << ", объем: " << vehicles[i].engine.volume << " л" << endl;
    }
}



void print_by_type(Vehicle vehicles[]) {
    bool flag_found = false;
    int type; 
    while (true) {
        cout << "введите тип транспорта (0-Car, 1-Truck, 2-Motorcycle): ";
        type = get_number();
        if (type >= 0 && type <= 2) {
            break;
        }
        cout << "неправильно" << endl;
    }
    
    cout << "транспорт типа " << type_to_string((VehicleType)type) << ":" << endl;
    for (int i = 0; i < 5; i++) {
        if (vehicles[i].type == (VehicleType)type) {
            cout << vehicles[i].model << ", мощность: " << vehicles[i].engine.power
                 << ", объем: " << vehicles[i].engine.volume << " л" << endl;
            flag_found = true;
        }
    }
    if (!flag_found) {
        cout << "нет транспорта этого типа" << endl;
    }
}

void input_simple_vehicles(Vehicle_without_nesting_structures simple_vehicles[], int size) {
    string type_names[3] = {"Car", "Truck", "Motorcycle"};
    for (int i = 0; i < size; i++) {
        simple_vehicles[i].type = type_names[i % 3];
        simple_vehicles[i].model = "Model" + to_string(i + 1);
        simple_vehicles[i].power = rand() % 600;
        simple_vehicles[i].volume = (rand() % 300) / 10.0;
    }
}

void sort_simple_vehicles(Vehicle_without_nesting_structures simple_vehicles[], int size) {
    Vehicle_without_nesting_structures temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (simple_vehicles[j].power > simple_vehicles[j + 1].power) {
                temp = simple_vehicles[j];
                simple_vehicles[j] = simple_vehicles[j + 1];
                simple_vehicles[j + 1] = temp;
            }
        }
    }
}

void print_simple_vehicles(Vehicle_without_nesting_structures simple_vehicles[], int size) {
    cout << "список транспорта:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << simple_vehicles[i].type << " " << simple_vehicles[i].model
             << ", мощность: " << simple_vehicles[i].power
             << ", объем: " << simple_vehicles[i].volume << " л" << endl;
    }
}

void sort_vehicles_by_power(Vehicle vehicles_rand[], int size) { //одна функция для сортровки вместо двух
    Vehicle temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vehicles_rand[j].engine.power > vehicles_rand[j + 1].engine.power) {
                temp = vehicles_rand[j];
                vehicles_rand[j] = vehicles_rand[j + 1];
                vehicles_rand[j + 1] = temp;
            }
        }
    }
    cout<<"транспорт отсортирован"<<endl;
   
}


void input_vehicles_random(Vehicle vehicles_rand[], int size) {
    for (int i = 0; i < size; i++) {
        vehicles_rand[i].model = "Model" + to_string(i + 1);
        vehicles_rand[i].engine.power = rand() % 600;
        vehicles_rand[i].engine.volume = (rand() % 300) / 10.0;
    }


}

void  time_of_sort_struct_Vehicle(Vehicle vehicles[], int size){//добавлена функция расчета времени сортировки массива Vehicle
    clock_t start=clock();
    sort_vehicles_by_power(vehicles,size);
    clock_t stop=clock();
    double time = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"время сортировки массива структур Vehicle: "<<time<<"миллисекунд"<<endl;
}
void time_of_sort_struct_Vehicle_without_nesting(Vehicle_without_nesting_structures vehicles[], int size){//добавлена функция расчета времени сортировки массива Vehicle_without_nesting_structures
    clock_t start=clock();
    sort_simple_vehicles(vehicles,size);
    clock_t stop=clock();
    double time = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"время сортировки массива структур Vehicle_without_nesting_structures: "<<time<<"миллисекунд"<<endl;
}
int main() {

    int size_arr_for_struct=5;
    Vehicle vehicles[5];

    input_vehicles(vehicles);
    sort_vehicles_by_power(vehicles,size_arr_for_struct);
    print_vehicles(vehicles);
    
    cout << "поиск по типу:" << endl;
    print_by_type(vehicles);

    const int SIZE = 2000;
    Vehicle vehicles_rand[SIZE];
    input_vehicles_random(vehicles_rand,SIZE);

    Vehicle_without_nesting_structures simple_vehicles[SIZE];
    input_simple_vehicles(simple_vehicles, SIZE);
    //print_simple_vehicles(simple_vehicles, SIZE);

    //добавлена функция расчета времени сортировки массива Vehicle
    time_of_sort_struct_Vehicle(vehicles_rand,SIZE);
    
    //добавлена функция расчета времени сортировки массива Vehicle_without_nesting_structures
    time_of_sort_struct_Vehicle_without_nesting(simple_vehicles, SIZE);


    cout<<"размер структуры Vehicle: "<<sizeof(Vehicle)<<endl;
    cout<<"размер массива vehicles_rand[2000]"<<sizeof(vehicles_rand)<<endl;
    cout<<"размер структуры Vehicle_without_nesting_structures: "<<sizeof(Vehicle_without_nesting_structures)<<endl;
    cout<<"размер массива simple_vehicles[2000]"<<sizeof(simple_vehicles)<<endl;



    
    return 0;
}