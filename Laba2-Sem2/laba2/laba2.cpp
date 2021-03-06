#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cmath>
using namespace std;

char filename[] = "list.txt";

const int N = 100;

struct date {
	int dd, mm, yy;
	void setDate(int dd0, int mm0, int yy0) {
		dd = dd0; mm = mm0; yy = yy0;
	}
	void getDate() {
		printf("\nдень: "); scanf_s("%d", &dd);
		printf("месяц: "); scanf_s("%d", &mm);
		printf("год: "); scanf_s("%d", &yy);
	}
	int cmpDate(date& T) {
		if (yy != T.yy) return yy - T.yy;
		if (mm != T.mm) return mm - T.mm;
		return dd - T.dd;
	}
	void loadDate(FILE* fd) { fscanf_s(fd, "%d%d%d", &dd, &mm, &yy); }
	void saveDate(FILE* fd) { fprintf(fd, "%d %d %d", dd, mm, yy); }
	void showDate() { printf("            %02d.%02d.%04d           ", dd, mm, yy); }
};

struct person {
	char Surname[30];
	unsigned int Card_number;
	int Money;
	date last_modification;
	date SS;
	void setPerson(char sn[], unsigned int cn, int m, date b0) {
		strcpy_s(Surname, sn); Card_number = cn; Money = m; last_modification = b0;
	}

	void showPerson() {
		printf("%30s %14u %10d", Surname, Card_number, Money);
		last_modification.showDate();
		printf("\n");
	}
	void showDate() {
		SS.showDate(); printf("\n");
	}
	int cmpPerson(person& T, int mode) {
		switch (mode) {
		case 1: return strcmp(Surname, T.Surname);
		case 2: return Card_number - T.Card_number;
		case 3: return Money - T.Money;
		case 4: return last_modification.cmpDate(T.last_modification);
		default: return 1;
		}
	}
};

struct table {
	person TBL[N];
	int nn;
	void addPerson(char sn[], unsigned int cn, int m, date b0) {
		if (nn != N) { TBL[nn].setPerson(sn, cn, m, b0); nn++; }
	}
	void loadTable(char sn[]) {
		int i;
		char c[200];
		ifstream file;
		file.open(filename);
		for (i = 0; !file.eof(); i++) file >> TBL[i].Surname >> TBL[i].Card_number >> TBL[i].Money >> TBL[i].last_modification.dd >> TBL[i].last_modification.mm >> TBL[i].last_modification.yy;
		file.close();
		nn = i - 1;
	}
	void saveTable(char sn[]) {
		int i;
		ofstream file;
		file.open(filename);
		for (i = 0; i < nn; i++) {
			file << TBL[i].Surname << " " << TBL[i].Card_number << " " << TBL[i].Money << " " << TBL[i].last_modification.dd << " " << TBL[i].last_modification.mm << " " << TBL[i].last_modification.yy << endl;
		}
		file.close();
	}
	void sortTable() {
		int mode;
		cin >> mode;
		int i, j, m;
		for (i = 0; i < nn; i++) {
			for (j = m = i; j < nn; j++) {
				if (TBL[j].cmpPerson(TBL[m], mode) < 0) m = j;
			}
			person cc = TBL[i]; TBL[i] = TBL[m]; TBL[m] = cc;
		}
	}
	void deleteTable() {
		int p;
		printf("Номер человека: "); scanf_s("%d", &p);
		for (int i = p; i < nn - 1; i++)
			TBL[i] = TBL[i + 1];
		nn--;
	}
	void rewriteTable() {
		cout << "Введите номер пользователя: ";
		int k;
		cin >> k;
		cout << endl << "Изменение поля: \n[1] - Фамилия\n[2] - Номер счёта\n[3] - Сумма на счёте\n[4] - Дата последнего изменения\nВведите поле, которое хотите изменить: ";
		int kk;
		cin >> kk;
		switch (kk) {
		case 1:
			cout << "Введите новую Фамилию: ";
			cin >> TBL[k].Surname;
			break;
		case 2:
			cout << "Введите новый Номер счёта: ";
			cin >> TBL[k].Card_number;
			break;
		case 3:
			cout << "Введите новую Сумму на счёте: ";
			cin >> TBL[k].Money;
			break;
		case 4:
			cout << "Введите новую Дату последнего изменения: ";
			date new_modification;
			new_modification.getDate();
			TBL[k].last_modification = new_modification;
			break;
		}
	}
	int countMoney() {
		int allMoney = 0;
		for (int i = 0; i < nn; i++) {
			allMoney += TBL[i].Money;
		}
		return allMoney;
	}
	int length(char c[]) {
		int count=0;
		for (int i = 0; c[i] != '\0' ; i++)
		{
			count++;
		}
		return count;
	}
	int minimum(int a, int b, int c) {
		if (a < b && a < c) return a;
		if (b < a && b < c) return b;
		if (c < a && c < b) return c;
	}
	void search() {
		int search_mode;
		int index = 0;
		int delta1 = INT32_MAX;
		unsigned int delta2 = UINT32_MAX;
		int delta3 = INT32_MAX;
		date delta4 = { INT32_MAX,INT32_MAX,INT32_MAX };
		cout << endl << "Поиск поля: \n[1] - Фамилия\n[2] - Номер счёта\n[3] - Сумма на счёте\n[4] - Дата последнего изменения\n";
		cin >> search_mode;
		switch (search_mode) {
		case 1:
			int D[30][30];
			char Sname[30];
			cin >> Sname;
			int M;
			M = length(Sname);
			for (int k = 0; k < nn; k++)
			{
				int N = length(TBL[k].Surname);
				for (int i = 0; i < N + 1; i++)
				{
					for (int j = 0; j < M + 1; j++)
					{

						if (i == 0 && j >= 0)
						{
							D[i][j] = j;
						}
						if (i > 0 && j == 0)
						{
							D[i][j] = i;
						}
						if (i > 0 && j > 0)
						{
							int m;
							TBL[k].Surname[i - 1] == Sname[j - 1] ? m = 0 : m = 1;
							D[i][j] = minimum(D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1][j - 1] + m);
						}
					}
				}
				if (D[N][M] < delta1) {
					delta1 = D[N][M];
					index = k;
				}
			}
			TBL[index].showPerson();
			break;
		case 2:
			unsigned int num;
			cin >> num;
			for (int i = 0; i < nn; i++)
			{
				unsigned int delta0;
				num > TBL[i].Card_number ? delta0 = num - TBL[i].Card_number : delta0 = TBL[i].Card_number - num;
				if (delta0 < delta2) {
					delta2 = delta0;
					index = i;
				}
			}
			TBL[index].showPerson();
			break;
		case 3:
			int mon;
			cin >> mon;
			for (int i = 0; i < nn; i++)
			{
				int delta0;
				mon > TBL[i].Money ? delta0 = mon - TBL[i].Money : delta0 = TBL[i].Money - mon;
				if (delta0 < delta3) {
					delta3 = delta0;
					index = i;
				}
			}
			TBL[index].showPerson();
			break;
		case 4:
			date l_m;
			l_m.getDate();
			for (int i = 0; i < nn; i++)
			{
				if (abs(l_m.yy - TBL[i].last_modification.yy) < delta4.yy) {
					delta4.yy = abs(l_m.yy - TBL[i].last_modification.yy);
					index = i;
				}
				else {
					if (abs(l_m.yy - TBL[i].last_modification.yy) == delta4.yy) {
						if (abs(l_m.mm - TBL[i].last_modification.mm) < delta4.mm) {
							delta4.mm = abs(l_m.mm - TBL[i].last_modification.mm);
							index = i;
						}
						else {
							if (abs(l_m.mm - TBL[i].last_modification.mm) == delta4.mm) {
								if (abs(l_m.dd - TBL[i].last_modification.dd) < delta4.dd) {
									delta4.dd = abs(l_m.dd - TBL[i].last_modification.dd);
									index = i;
								}
							}
						}
					}
				}
			}
			TBL[index].showPerson();
			break;
		default: break;
		}
	}
};

table TT;

int main() {
	system("chcp 1251");
	setlocale(0, "Rus");
	TT.nn = 0;
	char c[30];
	unsigned int card;
	int i, k, money;
	date d0;
	do {
		cout << "Доступные функции:" << endl;
		cout << "[1] - ввод записи таблицы с клавиатуры;" << endl;
		cout << "[2] - загрузка и сохранение  таблицы в текстовом файле;" << endl;
		cout << "[3] - просмотр таблицы;" << endl;
		cout << "[4] - сортировка таблицы в порядке возрастания заданного поля;" << endl;
		cout << "[5] - поиск в таблице элемента с заданным значением поля или с наиболее близким к нему по значению;" << endl;
		cout << "[6] - удаление записи;" << endl;
		cout << "[7] - изменение (редактирование) записи;" << endl;
		cout << "[8] - вычисление с проверкой и использованием всех записей по заданному условию и формуле (например, общая сумма на всех счетах)." << endl << endl;
		cout << "Введите номер функции: ";
		cin >> k;
		switch (k) {
		case 1:
			cout << endl;
			cout << "Введите Ваши даные" << endl;
			cout << "Фамилия: "; cin >> c;
			cout << "Номер счёта: "; cin >> card;
			cout << "Сумма на счёте: "; cin >> money;
			d0.getDate();
			TT.addPerson(c, card, money, d0);
			break;
		case 2:
			int p;
			cout << endl << "[1] - Сохранить в файл\n[2] - Загрузить из файла\n";
			cin >> p;
			if (p == 1) TT.saveTable(filename);
			else if (p == 2) TT.loadTable(filename);
			break;
		case 3:
			printf("\nnn                        Фамилия    Номер счёта     Деньги    Дата последнего изменения\n");
			for (i = 0; i < TT.nn; i++)
			{
				printf("%-2d ", i);
				TT.TBL[i].showPerson();
			}
			break;
		case 4:
			cout << endl << "Сортировать по: \n[1] - Фамилии\n[2] - Номеру счёта\n[3] - Сумме\n[4] - Дате\nВыберите поле сортировки: ";
			TT.sortTable();
			break;
		case 5:
			TT.search();
			break;
		case 6:
			TT.deleteTable();
			break;
		case 7:
			TT.rewriteTable();
			break;
		case 8:
			cout << "Сумма на всех счетах: " << TT.countMoney() << endl;
			break;
		}
		cout << endl;
	} while (k >= 1 && k <= 8);
	return 0;
}
