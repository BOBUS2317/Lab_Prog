#include <iostream>
#include <string>
using namespace std;

struct Book {
    string name;
    string author;
    int year;

};
struct Library{
    int years[5];
};
void output_books(Book books[]){
    for (int i=0; i<5; i++){
        cout<<i+1<<". "<<books[i].name<<" - "<<books[i].author<<"("<<
        books[i].year<<")"<<endl;
    }
}
void output_books_with_Library(Book books[], Library arr_years){
    for (int i=0; i<5; i++){
        cout<<i+1<<". "<<books[i].name<<" - "<<books[i].author<<"("<<
        arr_years.years[i]<<")"<<endl;
    }
}
void author_search(Book books[]){
    string name;
    int i=0;
    bool flag_search=false;
    while(!flag_search){
        cout<<"напишите автора: ";
        getline(cin, name);
        for(i=0;i<5;i++){
            if (books[i].author==name){
                flag_search=true;
                cout<<books[i].name<<" - "<<books[i].author<<"("<<books[i].year<<")"<<endl;
             
            }
        
        }
        if(!flag_search){cout<<"такой автор не найден"<<endl;}
    

    }
}
int main(){
    Book books[5]={{"Отверженные", "Виктор Гюго",1862},
    {"Преступление и наказание","Фёдор Михайлович Достоевский", 1866},
    {"Мёртвые души", "Николай Васильевич Гоголь", 1835},
    {"Гранатовый браслет","Александр Иванович Куприн", 1910},
    {"Борис Годунов","Александр Сергеевич Пушкин",1825}};
    cout<<"список книг:"<<endl;
    output_books(books);
    author_search(books);

    Library arr_years;
    for(int i=0;i<5;i++){
        arr_years.years[i]=books[i].year;
    }
    cout<<"вывод с использованием структуры Library с массивом годов:"<<endl;
    output_books_with_Library(books, arr_years);

}
