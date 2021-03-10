
#include <iostream>
using namespace std;

int addlinedm(int** &p, int k, int l, int d) {
	int **p1 = NULL;
	p1 = new int* [k]; //создаем буферный двумерный массив
	for (int j = 0; j < k; j++) p1[j] = new int[d];

	for (int j1 = 0; j1 < k; j1++) //копируем значения в буферный массив
	{
		for (int j2 = 0; j2 < p[j1][0] + 1; j2++) {
			p1[j1][j2] = p[j1][j2];
		}
	}
	k++;

	for (int j = 0; j < k - 1; j++) delete[]p[j]; //удаление двумерного массива
	delete[]p;

	p = new int* [k]; //пересоздаем основной массив
	for (int j = 0; j < k - 1; j++) p[j] = new int[p1[j][0] + 1];
	p[k - 1] = new int[l + 1];

	for (int j1 = 0; j1 < k - 1; j1++) //копируем значения в основной массив
	{
		for (int j2 = 0; j2 < p1[j1][0] + 1; j2++) {
			p[j1][j2] = p1[j1][j2];
		}
	}

	for (int j = 0; j < k - 1; j++) delete[]p1[j]; //удаление двумерного массива
	delete[]p1;
	return k;
}

void addlinem(int* &q) {
	int* q1 = NULL;
	q1 = new int[q[0] + 1];
	for (int j = 0; j < q[0] + 1; j++) q1[j] = q[j];
	q1[0]++;
	delete[]q;
	q = new int[q1[0] + 1];
	for (int j = 0; j < q1[0]; j++) q[j] = q1[j];
	delete[]q1;
}

int main()
{
	setlocale(0, "ru");
	const int N = 50;
	int d = 1, l = 1, k = 0, v = 1, A[N];
	int** p = NULL;
	int* q = NULL;
	cout << "Входной массив\n";
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 201 - 100;
		cout << A[i] << " ";
	}
	cout << "\nВыходной массив\n";
	q = new int[1];
	q[0] = 0;

	for (int i = 0; i < N-1; i++)
	{
		if (A[i] < A[i + 1]) { //считает возрастающую последовательность
			v = 0;
			l++;
		}
		else if (v==0){ //при конце возрастающей последовательности
			v = 1;
			if (l + 1 > d) d = l + 1;
			k = addlinedm(p, k, l, d);

			p[k-1][0] = l;
			for (int j = 1; j < l + 1; j++)
			{
				p[k-1][j] = A[i - l + j];
			}
			l = 1;
		}
		else if(v == 1) { //массив невозрастающих последовательностей
			addlinem(q);
			q[q[0]] = A[i];
		}
	}

	//Добавление строки под невозрастающие последовательности
	k = addlinedm(p, k, q[0] + 1, d);
	
	for (int i = 0; i < q[0] + 1; i++) p[k - 1][i] = q[i]; //Вставка в двумерный массив невозрастающей последовательности

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < p[i][0] + 1; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}

}
