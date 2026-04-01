
    #include <iostream>
    using namespace std;
    void numInput(unsigned int& n) {
        n = -1;
        do {
            cin >> n;
        } while (n <= 0);
    }
    int main(int, char**){
        setlocale(LC_ALL, "ru");
        int numOfElements, sum = 0, maxi = 0;
        int* numsArray;

        cout << "Введите n: ";
        cin >> numOfElements;

        numsArray = new int[numOfElements];
        cout << "Элементы массива: " << endl;
        for (int i=0; i< numOfElements; i++) {
            numsArray[i] = i*i;
            cout << numsArray[i] << endl;
            sum+= numsArray[i];
        }
        cout << "Сумма элементов: ";
        cout << sum << endl;
        cout << "Среднее арифметическое: ";
        cout << (float)(sum) / numOfElements << endl;
        cout << "Максимальный элемент массива: ";
        for (int i = 0; i < numOfElements; i++) {
            if (numsArray[i] > maxi) {
                maxi = numsArray[i];
            }
        }
        cout << maxi << endl;
        delete[] numsArray;
     }