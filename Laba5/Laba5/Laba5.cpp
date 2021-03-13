#include <iostream>
using namespace std;

long long N = ULONG_MAX;

//сумма цифр числа
long long sum_num(unsigned long long x) {
	long long sum = 0;
	for (; x > 0; x /= 10) {
		sum += x % 10;
	}
	return sum;
}

long long recursia(long long a) {
	long long v = a;
	if (a < 100000000000000000) {
		long long sum_a = sum_num(v);
		a *= 10;
		a += 3;
		if (a % 21 == 0 && sum_a % 21 == 0) {
			return a;
		}
		v = recursia(a);
		if (v == -1) return v;
		else a = v;
		a += 4;
		if (a % 21 == 0 && sum_a % 21 == 0) {
			return a;
		}
		v = recursia(a);
		if (v == -1) return v;
		else a = v;
		return a;
	}
	else {
		return -1;

	}
}


int main() {
	cout << recursia(0);
	return 0;
}