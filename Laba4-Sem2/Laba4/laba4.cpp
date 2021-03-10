#include <iostream>
#include <Windows.h>
using namespace std;

struct list {
	int val;
	list* next;
};

//вывод элементов списка
void show(list* p) {
	for (; p != NULL; p = p->next) cout << p->val << " ";
	cout << endl;
}

//добавление очередного элемента в список
list* l(list* ph) {
	list* q = new list;
	cin >> q->val;
	q->next = ph;
	ph = q;
	return ph;
}

int main() {
	setlocale(LC_ALL, "ru");
	list *list1 = NULL; 
	list *list2 = NULL;
	cout << "Введите количество элементов в первом списке: ";
	int n1; cin >> n1;
	cout << "Первый список: ";
	//ввод элементов первого списка
	for (int i = 0; i < n1; i++) {
		list1 = l(list1);
	}
	cout << "Введите количество элементов во втором списке: ";
	int n2; cin >> n2;
	cout << "Второй список: ";
	//ввод элементов второго списка
	for (int i = 0; i < n2; i++) {
		list2 = l(list2);
	}
	//сравнение элементов списков
	list* q = NULL;
	int v;
	while (list2->next != NULL) {
		v = 0; 
		for (q = list1; q->next != NULL; q = q->next) {
			if (q->val == list2->val) { v = 1; break; }
		}
		if (v == 0) {
			q = list2;
			list2 = list2->next;
			q->next = list1;
			list1 = q;
		}
		else {
			q = list2;
			list2 = list2->next;
			delete q;
		}
		
	}
	cout << "Объединение двух односвязных списков: ";
	show(list1);
	return 0;
}