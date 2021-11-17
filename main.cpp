#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int compareArray(const void *value1, const void *value2);
void getValueMatrix();
int randNumber(int low,int high);

int matrix[10][10];

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            matrix[i][j] = randNumber(1, 10);
        }
    }
    cout << "\n";
    cout << "Starting Array :\n";
    cout << "\n";
    getValueMatrix();
    qsort(matrix, 100, sizeof(int), compareArray);

    cout << "\n";
    cout << "Quick Sorting Result :\n";
    cout << "\n";
    getValueMatrix();

    return 0;
}

int randNumber(int low,int high) {
    if (low == high) {
        return low;
    }
    else {
        return (rand()%(high - low + 1)+ low);
    }
}

int compareArray(const void *value1, const void *value2) {
    int resultValue1 = *((int*) value1);
    int resultValue2 = *((int*) value2);
    return resultValue1 - resultValue2;
}

void getValueMatrix() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}
