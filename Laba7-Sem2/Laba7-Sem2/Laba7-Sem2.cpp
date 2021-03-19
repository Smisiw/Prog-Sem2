#include <iostream>
using namespace std;

struct list_int {
	int value;
	list_int* next, * prev;
};

struct list_char {
	char *name;
	list_char* next, * prev;
};

//добавление очередного элемента в целочисленный список
void add_int(list_int* ph) {
	list_int* p = ph;
	list_int* q = new list_int;
	for (; p->next != NULL; p = p->next);
	cin >> q->value;
	q->prev = p;
	p->next = q;
}

//добавление символа в массив 
void addlinem(char*& q, int n) {
	char *q1 = NULL;
	q1 = new char[n];
	for (int j = 0; j < n-1; j++) q1[j] = q[j];
	delete[]q;
	q = new char[n];
	for (int j = 0; j < n-1; j++) q[j] = q1[j];
	delete[]q1;
}

//добавление очередного элемента в символьный список
void add_char(list_char* ph) {
	list_char* p = ph;
	list_char* q = new list_char;
	for (; p->next != NULL; p = p->next);
	int n = 0;
	char c = getchar();
	while(c != '\n') {
		n++;
		addlinem(q->name, n);
		q->name[n - 1] = c;
		c = getchar();
	}
	q->prev = p;
	p->next = q;
}



int main()
{
	list_int *list1 = NULL;
	list_char* list2 = NULL;

	return 0;
}
