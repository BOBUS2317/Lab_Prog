#include <iostream>
#include <string>
using namespace std;

enum Day {Monday=1, Tuesday=2, Wednesday=3, 
    Thursday=4, Friday=5, Saturday=6, Sunday=7 };
struct Weather{
    Day day;
    int temperature;
    bool precipitation;
};
string day_string_type(Day day) {
    switch(day) {
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        case Sunday: return "Sunday";
    }
}
void search_hot_day(Weather forecast[]){
    int max_temperature=forecast[0].temperature;
    int index_day=0;
    for (int i=1;i<7;i++){
        if (max_temperature<forecast[i].temperature){
            max_temperature=forecast[i].temperature;
            index_day=i;

        }
        
    }
    string word_precipitation=forecast[index_day].precipitation?"есть":"нет";
    cout<<"самый жаркий день - "<<day_string_type(forecast[index_day].day)<<endl;
    cout<<"температура - "<<forecast[index_day].temperature<<endl;
    cout<<"осадки - "<<word_precipitation<<endl;

}

void search_hot_day_with_different_arrs(string weekday[], int temperatures[], bool precipitation[]){
    int max_temperature=temperatures[0];
    int index_day=0;
    for (int i=1;i<7;i++){
        if ( max_temperature<temperatures[i]){
            index_day=i;
            max_temperature=temperatures[i];
        }
    }
    string word_precipitation=precipitation[index_day]?"есть":"нет";
    cout<<"самый жаркий день - "<<weekday[index_day]<<endl;
    cout<<"температура - "<<temperatures[index_day]<<endl;
    cout<<"осадки - "<<word_precipitation<<endl;
}
int main(){
    Weather forecast[7]={{Monday, -124, false}, {Tuesday, 2,true},
    {Wednesday,-10,true},{Thursday,10,false},{Friday,12,true},
    {Saturday,-3,false},{Sunday,5,true}};
    search_hot_day(forecast);

    cout<<"вывод без использования структуры: "<<endl;
    string weekday[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int temperatures[7]={-124,2,-10,10,12,-3,5};
    bool precipitation[7]={false,true,true,false,true,false,true};
    search_hot_day_with_different_arrs(weekday, temperatures, precipitation);


    return 0;
}
