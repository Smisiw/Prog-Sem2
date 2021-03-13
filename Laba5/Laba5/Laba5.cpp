#include <iostream>
using namespace std;

//сумма цифр числа
long long sum_num(long long x) {
	long long sum = 0;
	for (; x > 0; x /= 10) {
		sum += x % 10;
	}
	return sum;
}

void recursia(long long a, long long &min) {
	if (a < 100000000000000000) { //ограничение поиска
		a *= 10;
		a += 3;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) { //проверка условий
			if (min == 0) min = a;
			else if (a < min) min = a;
		}
		recursia(a, min); //вызов функции с добавленной тройкой в конец
		a /= 10;
		a *= 10;
		a += 7;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) { //проверка условий
			if (min == 0) min = a;
			else if (a < min) min = a;
		}
		recursia(a, min); //вызов функции с добавленной семеркой в конец
	}
}

int main() {
	long long answer = 0;
	recursia(0, answer);
	cout << answer;
	return 0;
}