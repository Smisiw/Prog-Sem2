#include <iostream>
using namespace std;

struct btree {
    int n;
    int A[4];
    struct btree* left;
    struct btree* right;
};

void tree_print(btree* tr1) {
    if (tr1 != NULL) {
        tree_print(tr1->left);
        for (int i = 0; i < tr1->n; i++) {
            cout << tr1->A[i] << " ";
        }
        tree_print(tr1->right);
    }
}

void add(int b, btree*& tree) {
    if (tree == NULL) { //если нет узла
        tree = new btree();
        tree->A[0] = b;
        tree->n++;
    }
    else if (tree->n < 4) { //если узел не заполнен
        tree->A[tree->n] = b;
        tree->n++;
        for (int i = 0; i < tree->n - 1; i++) //сортировка
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
    btree* tree = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        add(x, tree);
    }
    tree_print(tree);
    return 0;
}

