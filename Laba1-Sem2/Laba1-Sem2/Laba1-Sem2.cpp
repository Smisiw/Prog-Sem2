#include <iostream>
using namespace std;

int* min(int A[], int n) { //Возвращает указатель на минимальный элемент
    int* pmin, i;
    for (i = 1, pmin = A; i < n; i++)
        if (A[i] < *pmin) pmin = &A[i];
    return(pmin);
}

int main()
{
    int A[100], B[100], n;
    int* p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        p = min(A, n); //указатель на минимальный
        B[i] = *p; //копирование значения во второй массив
        *p = INT32_MAX; //присваивание максимально возможного
        cout << B[i] << " ";
    }
}
