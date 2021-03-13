#include <iostream>
using namespace std;

long long N = LONG_MAX;

//сумма цифр числа
long long sum_num(long long x) {
	long long sum = 0;
	for (; x > 0; x /= 10) {
		sum += x % 10;
	}
	return sum;
}

long long recursia(long long a) {
	long long v = a;
	if (a < 100000000000000000) {
		a *= 10;
		a += 3;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		v = recursia(a);
		if (v != -1) a = v;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		a /= 10;
		a *= 10;
		a += 7;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		v = recursia(a);
		if (v != -1) a = v;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		return -1;
	}
	else {
		return -1;
	}
}


int main() {
	cout << recursia(0);
	return 0;
}