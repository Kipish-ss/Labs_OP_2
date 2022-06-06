#ifndef LAB_6_TREE_OPERATIONS_H
#define LAB_6_TREE_OPERATIONS_H
#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;
vector<string> split(string);
Tree* create_tree(const vector<string>&);
void display_tree(const string&, Tree*, bool);
void create_final_tree(Tree*);
void modify_tree(Tree*);
#endif
