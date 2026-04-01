
#include <iostream>
#include <cstdlib>
using namespace std;
class player {
public:
    int shadowField[10][10];
    int field[10][10];
    int shipCount=0;
    void setGame() {
        setlocale(LC_ALL, "ru"); 
        cout << "Расставьте корабли: 0 - пусто, 1 - корабль" << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                shadowField[i][j] = 2;
                cin >> field[i][j];
                shipCount += field[i][j];
            }
        }
    }
    void showField() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (shadowField[i][j] == 2) {
                    cout << "_\t";
                }
                else {
                    cout << shadowField[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }
    void fire(player &enemy) {
        setlocale(LC_ALL, "ru"); 
        int x, y;
        enemy.showField();
        cout << "Введите клетку выстрела: ";
        cin >> x >> y;
        while (enemy.shadowField[y - 1][x - 1] != 2) {
            cout << "Вы уже стреляли сюда. Введите другое: " << endl;
            cin >> x >> y;
        }
        int cell = enemy.field[y - 1][x - 1];
        if (cell == 1) {
            cout << "ПОПАДАНИЕ!" << endl;
            enemy.shipCount--;
            cout << "Осталось " << enemy.shipCount << " попаданий" << endl;
        }
        else {
            cout << "ПРОМАХ!" << endl;
        }
        enemy.shadowField[y - 1][x - 1] = cell;
        enemy.showField();

    }
};

void clearMap() {
    setlocale(LC_ALL, "ru"); 
    int inp;
    cout << "Передать ход? Введите 1: ";
    do {
        cin >> inp;
    } while (inp != 1);
    system("cls");
}

int main(int, char**) {
    setlocale(LC_ALL, "ru");
    player pl[2];
    unsigned int turn = 0;

    pl[0].setGame();
    clearMap();
    pl[1].setGame();
    clearMap();
    while (true) {
        cout << "ХОД ИГРОКА " << (int)turn+1 << endl;
        pl[turn].fire(pl[!turn]);
        if (pl[!turn].shipCount == 0) {
            cout << "Игрок N" << turn + 1 << " выиграл!";
            break;
        }
        clearMap();
        turn = (turn == 1) ? 0:1;

    
    }
}