#include <iostream>
#include <string>

using namespace std;

struct list {
	void* value;
	list* next, * prev;
};

/*struct list_int {
	int value;
	list_int* next, * prev;
};

struct list_char {
	char* name;
	list_char* next, * prev;
};
*/

//добавление очередного элемента в целочисленный список
void add(list*& ph, int v) {
	list* p = ph;//
	list* q = new list;
	q->next = NULL;

	if (v == 0) {//инт
		q->value = new int;

		if (ph == NULL) {
			cin >> q->value;
			ph = q;
			ph->next = NULL;
		}
		else {
			for (; p->next != NULL; p = p->next);
			cin >> q->value;
			q->prev = p;
			p->next = q;
		}
	}
	else if (v == 1) {//символы
		q->value = new string;
		string c;
		cin >> c;

		if (ph == NULL) {

			ph = q;
			ph->next = NULL;
		}
		else {
			q->prev = p;
			p->next = q;
		}

	}
	else { cout << "ERROR\n"; }

}

void show(list* p) {
	for (; p != NULL; p = p->next) {
		cout << p->value << " ";
	}
}

/*void iterator(list* pl, void (*pf)(void*)) {

}*/

int main()
{
	list* list1 = NULL;
	//list_char* list2 = NULL;
	int n, vv;
	cin >> n >> vv;
	for (int i = 0; i < n; i++) {
		add(list1, vv);
	}
	show(list1);
	return 0;
}
