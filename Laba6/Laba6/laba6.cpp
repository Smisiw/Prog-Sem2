#include <iostream>
using namespace std;

struct btree {
    int n;
    int A[4];
    struct btree* left;
    struct btree* right;
};

struct btree* add(int x, btree* tree) {
    if (tree != NULL) {
        if (tree->n < 4) {
            cin >> x;
            int k = 0;//кол-во элементов, больших введенного числа
            for (int i = 0; i < tree->n && k < 4; i++) {
                if (x >= tree->A[i]) {
                    k++;
                }
                else if (k == 3) {
                    tree->A[3] = x;
                }
                else if (k == 2) {
                    tree->A[3] = tree->A[2];
                    tree->A[2] = x;
                }
                else if (k == 1) {
                    tree->A[3] = tree->A[2];
                    tree->A[2] = tree->A[1];
                    tree->A[1] = x;
                }
                else if (k == 0) {
                    tree->A[3] = tree->A[2];
                    tree->A[2] = tree->A[1];
                    tree->A[1] = tree->A[0];
                    tree->A[0] = x;
                }
            }
        }
        else if (tree->left != NULL) {
            tree->left = add(x, tree->left);
        }
        else tree->right = add(x, tree->right);
    } 
    return(tree);
}

void tree_print(btree *tr1) {
    if (tr1 != NULL) {
        for (int i = 0; i < tr1->n; i++) {
            cout << tr1->A[i];
        }
        tree_print(tr1->left);
        tree_print(tr1->right);
    }
}

int main()
{

    return 0;
}

