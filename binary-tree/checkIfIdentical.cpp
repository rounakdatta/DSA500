#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

bool checkIfIdentical(Node *ref1, Node *ref2) {

    if (ref1 == NULL || ref2 == NULL) {
        if (ref1 != ref2) {
            return false;
        }
        return true;
    }

    if (ref1->data != ref2->data) {
        return false;
    }
    if (!checkIfIdentical(ref1->left, ref2->left) || !checkIfIdentical(ref1->right, ref2->right)) {
        return false;
    }
    return true;
}

void insertIntoTree(Node *ref, int data) {
    ref->data = data;
    ref->left = NULL;
    ref->right = NULL;

    return;
}

int main() {

    Node *treeHead1 = NULL;
    Node *treeHead2 = NULL;

    insertIntoTree(treeHead1, 2);
    insertIntoTree(treeHead1->left, 7);
    insertIntoTree(treeHead1->right, 5);
    insertIntoTree(treeHead1->left->left, 2);
    insertIntoTree(treeHead1->left->right, 6);
    insertIntoTree(treeHead1->left->right->left, 5);
    insertIntoTree(treeHead1->left->right->right, 11);
    insertIntoTree(treeHead1->right->right, 9);
    insertIntoTree(treeHead1->right->right->left, 4);

    insertIntoTree(treeHead2, 2);
    insertIntoTree(treeHead2->left, 7);
    insertIntoTree(treeHead2->right, 5);
    insertIntoTree(treeHead2->left->left, 2);
    insertIntoTree(treeHead2->left->right, 6);
    insertIntoTree(treeHead2->left->right->left, 5);
    insertIntoTree(treeHead2->left->right->right, 11);
    insertIntoTree(treeHead2->right->right, 9);
    insertIntoTree(treeHead2->right->right->left, 4);

    bool identicalOrNot = checkIfIdentical(treeHead1, treeHead2);
    if (identicalOrNot) {
        cout << "Identical";
    } else {
        cout << "Not identical";
    }

    return 0;

}