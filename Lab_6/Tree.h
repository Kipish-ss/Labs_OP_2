#ifndef LAB_6_TREE_H
#define LAB_6_TREE_H
#include <iostream>
using namespace std;
class Tree
{
    string key;
    Tree* left, * right;
public:
    explicit Tree(string key) { this -> key = key; left = nullptr; right = nullptr; }
    void insert_left_child(const string&);
    void insert_right_child(const string&);
    Tree* get_left_child() { return left; }
    Tree* get_right_child() { return right; }
    void set_right_child(Tree* node) { right = node; }
    void set_left_child(Tree* node) { left = node; }
    string get_root() { return key; }
    void set_root(string key) { this -> key = key; }
    bool is_leaf();
};
#endif
