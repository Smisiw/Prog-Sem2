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

long long recursia(long long a, long long &min) {
	long long v = a;
	if (a < 100000000000000000) {
		a *= 10;
		a += 3;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		v = recursia(a, min);
		if (v != -1) a = v;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			if (min == 0) min = a;
			else if (a < min) min = a;
		}
		a /= 10;
		a *= 10;
		a += 7;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			return a;
		}
		v = recursia(a, min);
		if (v != -1) a = v;
		if (a % 21 == 0 && sum_num(a) % 21 == 0) {
			if (min == 0) min = a;
			else if (a < min) min = a;
		}
		return -1;
	}
	else {
		return -1;
	}
}


int main() {
	long long answer = 0;
	recursia(0, answer);
	cout << answer;
	return 0;
}