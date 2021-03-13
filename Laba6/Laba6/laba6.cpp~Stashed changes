#include <iostream>
using namespace std;

struct btree {
    int n;
    int A[4];
    struct btree* left;
    struct btree* right;
};

void tree_print(btree *tr1) {
    if (tr1 != NULL) {
        for (int i = 0; i < tr1->n; i++) {
            cout << tr1->A[i];
        }
        tree_print(tr1->left);
        tree_print(tr1->right);
    }
}

struct btree* add(int b, btree* tree) {
    if (tree == NULL) {
        tree = new btree();
        for (int i = 0; i < 10; i++) {
            
            tree->A[i] = b[i];
        }
    }
    else if (b < tree->A) 
}

int main()
{

    return 0;
}

