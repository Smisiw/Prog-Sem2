#include <iostream>
#include <string>

using namespace std;

//двусвязный список с динамическим типом данных
struct list {
	void* value;
	list* next, * prev;
};

//добавление очередного элемента в целочисленный список
void add(list*& ph, int v) {
	list* p = ph;
	list* q = new list;
	q->next = NULL;
	q->prev = NULL;
	if (v == 0) {//инт

		int *a = new int;
		cin >> *a;
		q->value = a;

		if (ph == NULL) {
			ph = q;
			ph->next = NULL;
		}
		else {
			for (; p->next != NULL; p = p->next);
			q->prev = p;
			p->next = q;
		}
	}
	else if (v == 1) {//символы

		string *c = new string;
		cin >> *c;
		q->value = c;
		
		if (ph == NULL) {
			ph = q;
			ph->next = NULL;
		}
		else {
			for (; p->next != NULL; p = p->next);
			q->prev = p;
			p->next = q;
		}

	}
	else { cout << "ERROR\n"; }
}

//минимум из чисел
bool mint(void* a, void* b) {
	if (*(int*)a > *(int*)b) return true;
	else return false;
}
//минимум из строк
bool mstr(void* a, void* b) {
	if (*(string*)a > *(string*)b) return true;
	else return false;
}
//поиск минимального 
list* min(list* p, bool (*f)(void*, void*)) {
	list* q = p;
	for (; p != NULL; p = p->next) 
		if ((*f)(q->value, p->value)) q = p;
	return q;
}


//сортировка 
void sort(list* &ph, bool (*f)(void*, void*)) {
	list *p, *q;
	p = ph;
	while (p != NULL) {
		q = min(p, (*f));
		if (p == ph) ph = q;
		if (q == p) {
			p = p->next;
			continue;
		}
		if (q->next != NULL) q->next->prev = q->prev;
		q->prev->next = q->next;
		q->next = p;
		q->prev = p->prev;
		if (p->prev != NULL) p->prev->next = q;
		p->prev = q;
	}
}

//итератор выводов
void show(list* p, void (*f)(void*)) {
	cout << "Отсортированный список: ";
	for (; p != NULL; p = p->next) {
		(*f)(p->value);
	}
}
void showint(void* p) { cout << *(int*)p << " "; }
void showstr(void* p) {	cout << *(string*)p << " "; }

int main()
{
	setlocale(LC_ALL, "Russian");
	list* list1 = NULL;
	int n, vv;
	//кол-во элементов и параматр ввода
	cout << "Введите количество и тип элементов([0]-int, [1]-string) : ";
	cin >> n >> vv;
	cout << "Заполните список: ";
	for (int i = 0; i < n; i++) {
		add(list1, vv);
	}
	if (vv == 0) {//целочисленный список
		sort(list1, mint);
		show(list1, showint); 
	}
	else if (vv == 1) {//строчный список
		sort(list1, mstr);
		show(list1, showstr);
	}
	return 0;
}