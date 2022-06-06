#include "Tree.h"
void Tree::insert_left_child(const string& new_key) {
    if (left == nullptr)
        left = new Tree(new_key);
    else {
        Tree* p = new Tree(new_key);
        p -> left = this -> left;
        this-> left = p;
    }
}

void Tree::insert_right_child(const string& new_key) {
    if (right == nullptr)
        right = new Tree(new_key);
    else {
        Tree* p = new Tree(new_key);
        p -> right = this -> right;
        this-> right = p;
    }
}

bool Tree::is_leaf() {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    return false;
}
