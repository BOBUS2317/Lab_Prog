
#include <iostream>
using namespace std;
void numInput(unsigned int &n) {
    n = -1;
    do {
        cin >> n;
    } while (n <= 0);
}

int main(int, char**){
    setlocale(LC_ALL, "ru");
    unsigned int n, m, sum, maxi=0;
    int* sumOfRow;
    int** matrix;
    int** matrixT;
    cout << "Введите количество строк: ";
    numInput(m);
    cout << "Введите количество столбцов: ";
    numInput(n);

    sumOfRow = new int[n];
    matrix = new int*[m];

    cout << "Элементы массива: " << endl;
    for (int i=0; i<m; i++) {
        matrix[i] = new int[n];
        sumOfRow[i] = 0;
        for (int j=0; j<n; j++) {
            matrix[i][j] = i * n + j + 1;
            cout << matrix[i][j] << " ";
            sumOfRow[i] += matrix[i][j];
        }
        cout << endl;
    }


    cout << "Сумма элементов строк: " << endl;
    for (int i=0; i<m; i++) {
        cout << sumOfRow[i] << " " << endl;
    }
    cout << endl;

    cout << "Сумма элементов столбцов: " << endl;
    for (int i=0; i<n; i++) {
        sum = 0;
        for (int j=0; j<m; j++) {
            sum+=matrix[j][i];
        }
        cout << sum << endl;
    }
    cout << endl;

    cout << "Максимальный элемент массива: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > maxi) {
                maxi = matrix[i][j];
            }
        }
    }
    cout << maxi << endl;

    matrixT = new int*[n];
    cout << "Транспонированная матрица:" << endl;
    for (int i=0; i<n; i++) {
        matrixT[i] = new int[m];
        for (int j=0; j<m; j++) {
            matrixT[i][j] = matrix[j][i];
            cout << matrixT[i][j] << " ";
        }
        cout << endl;
    }


    for (int i=0; i<m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i=0; i<n; i++) {
        delete[] matrixT[i];
    }
    delete[] matrixT;
}
