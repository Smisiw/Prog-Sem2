#include <iostream>
using namespace std;
typedef unsigned char uchar;

//сумма
void add(uchar in1[], uchar in2[], int n)
{
    int i, carry;                                 // Разряд переноса
    unsigned w;                              // Рабочая переменная для сложения двух байтов
    for (i = 0, carry = 0; i < n; i++) {
        in1[i] = w = in1[i] + in2[i] + carry;
        carry = (w & 0x0100) >> 8;    // Разряд переноса сдвинуть вправо на 8
    }
}

//отрицательное 
void neg(uchar in[], int n)
{
    int i, carry;                                           // Разряд переноса
    unsigned w;                              // Рабочая переменная для сложения двух байтов
    for (i = 0; i < n; i++) in[i] = ~in[i];      // Инвертированин всех разрядов
    for (i = 0, carry = 1; i < n; i++) {         // Добавление 1 (инкремент) с первоначальной
        in[i] = w = in[i] + carry;          // установкой переноса в 1
        carry = (w & 0x0100) >> 8;
    }
}

//проверка на отр
bool is_neg(uchar c[], int n) {
    if (c[n - 1] >= 0x80)
        return true;
    else return false;
}

//деление
void del() {
    long a, b;
    cout << "Введите делимое: ";
    cin >> a;
    cout << "Введите делитель: ";
    cin >> b;
    long a1 = a, b1 = b;
    neg((uchar*)&b, sizeof(long));
    int v = -1;
    while (!is_neg((uchar*)&a, sizeof(long))) {
        add((uchar*)&a, (uchar*)&b, sizeof(long));
        v++;
    }
    cout << a1 << " / " << b1 << " = " << v;
}

int main()
{
    setlocale(LC_ALL, "ru");
    del();
    return 0;
}