#include <iostream>
using namespace std;

struct btree {
    const int n;
    int A[1000];
    struct btree* left;
    struct btree* right;
};

void tree_print(btree *tr1) {
    if (tr1 != NULL) {
        for (int i = 0; i < 10; i++) {
            cout << tr1->A[i];
        }
        tree_print(tr1->left);
        tree_print(tr1->right);
    }
}

struct btree* add(int B[], btree* tree) {
    if (tree == NULL) {
        tree = new btree();
        for (int i = 0; i < 10; i++) {
            
            tree->A[i] = B[i];
        }
    }
    else if (B < tree->A) 
}

int main()
{

    return 0;
}

