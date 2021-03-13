#include <iostream>
using namespace std;

struct btree {
    int n;
    int A[4];
    struct btree* left;
    struct btree* right;
};

struct queue {
    btree* tree;
    int lvl;
    queue* next;
};

void tree_print(queue *pb, queue *pe) {
    if (pb != NULL) {
        queue* q = pb;
        cout << q->lvl << ") ";
        for (int i = 0; i < q->tree->n; i++)
            cout << q->tree->A[i] << " ";
        cout << endl;
        if (q->tree->left != NULL) {
            pe->next = new queue;
            pe->next->tree = q->tree->left;
            pe = pe->next;
            pe->lvl = q->lvl + 1;
        }
        if (q->tree->right != NULL) {
            pe->next = new queue;
            pe->next->tree = q->tree->right;
            pe->next->next = NULL;
            pe = pe->next;
            pe->lvl = q->lvl + 1;
        }
        pb = q->next;
        delete q;
        tree_print(pb, pe);
    }
}

void add(int b, btree* &tree) {
    if (tree == NULL) { //если нет узла
        tree = new btree();
        tree->A[0] = b;
        tree->n++;
    }
    else if (tree->n < 4) { //если узел не заполнен
        tree->A[tree->n] = b;
        tree->n++;
        for (int i = 0; i < tree->n-1; i++) //сортировка
            for (int j = 0; j < tree->n - i - 1; j++)
                if (tree->A[j] > tree->A[j + 1]) {
                    int c = tree->A[j]; tree->A[j] = tree->A[j + 1]; tree->A[j + 1] = c;
                }
    }
    else if (tree->n == 4) { //если узел заполнен
        if (b >= tree->A[3]) add(b, tree->right); //если больше правого элемента узла
        else if (b <= tree->A[0]) add(b, tree->left); //если меньше левого элемента узла
        else if (b > tree->A[1]) { //если правее центра узла
            int c = tree->A[3]; tree->A[3] = b; b = c; //замена
            for (int i = 0; i < tree->n - 1; i++) //сортировка
                for (int j = 0; j < tree->n - i - 1; j++)
                    if (tree->A[j] > tree->A[j + 1]) {
                        int c = tree->A[j]; tree->A[j] = tree->A[j + 1]; tree->A[j + 1] = c;
                    }
            add(b, tree->right);
        }
        else if (b <= tree->A[1]) { //если левее центра узла
            int c = tree->A[0]; tree->A[0] = b; b = c; //замена
            for (int i = 0; i < tree->n - 1; i++) //сортировка
                for (int j = 0; j < tree->n - i - 1; j++)
                    if (tree->A[j] > tree->A[j + 1]) {
                        int c = tree->A[j]; tree->A[j] = tree->A[j + 1]; tree->A[j + 1] = c;
                    }
            add(b, tree->left);
        }
    }
}

int main()
{
    queue* pb, * pe;
    btree *tree=NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        add(x, tree);
    }
    pb = new queue;
    pe = pb;
    pb->tree = tree;
    pb->next = NULL;
    pb->lvl = 1;
    tree_print(pb, pe);
    return 0;
}

