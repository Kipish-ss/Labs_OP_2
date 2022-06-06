#include "tree_operations.h"
#include <stack>

vector<string> split(string formula) {
    vector<string> formula_vector;
    int pos;
    while (formula.find(' ') != string::npos) {
        pos = formula.find(' ');
        formula_vector.push_back(formula.substr(0, pos));
        formula = formula.substr(pos + 1);
    }
    formula_vector.push_back(formula);
    return formula_vector;
}

Tree* create_tree(const vector<string>& formula) {
    stack<Tree*> tree_stack;
    Tree *tree = new Tree("");
    tree_stack.push(tree);
    Tree* current_tree = tree;
    string signs = "+-*/";
    for (string i : formula) {
        if (i == "(") {
            current_tree -> insert_left_child("");
            tree_stack.push(current_tree);
            current_tree = current_tree -> get_left_child();
        }
        else if (i == ")")
        {
            current_tree = tree_stack.top();
            tree_stack.pop();
        }
        else if (signs.find(i) != string::npos) {
            current_tree -> set_root(i);
            current_tree -> insert_right_child("");
            tree_stack.push(current_tree);
            current_tree = current_tree -> get_right_child();
        }
        else if (signs.find(i) == string::npos) {
            current_tree -> set_root(i);
            current_tree = tree_stack.top();
            tree_stack.pop();
        }
    }
    return tree;
}

void display_tree(const string& prefix, Tree* tree, bool is_left) {
    if (tree != nullptr) {
        cout << prefix;
        cout << (is_left ? "├──" : "└──" );
        cout << tree -> get_root() << endl;
        display_tree( prefix + (is_left ? "│   " : "    "), tree -> get_left_child(), true);
        display_tree( prefix + (is_left ? "│   " : "    "), tree->get_right_child(), false);
    }
}

void create_final_tree(Tree* tree) {
    if (tree) {
        modify_tree(tree);
        create_final_tree(tree -> get_left_child());
        create_final_tree(tree -> get_right_child());
    }
}

void modify_tree(Tree* tree) {
    Tree* left = tree -> get_left_child();
    Tree* right = tree -> get_right_child();
    string plus1, plus2, mult, symb;
    if (tree -> get_root() == "*") {
        if (left -> is_leaf())
            mult = left-> get_root();
        if (right->is_leaf())
            mult = right-> get_root();
    }
    if (!mult.empty()) {
        if (left -> get_root() == "+" || left -> get_root() == "-") {
            symb = left -> get_root();
            if(left -> get_left_child() -> is_leaf())
                plus1 = left -> get_left_child() -> get_root();
            if (left -> get_right_child() -> is_leaf())
                plus2 = left -> get_right_child() -> get_root();
        }
        if (right -> get_root() == "+" || right -> get_root() == "-") {
            symb = right -> get_root();
            if (right -> get_left_child() -> is_leaf())
                plus1 = right -> get_left_child() -> get_root();
            if (right -> get_right_child() -> is_leaf())
                plus2 = right -> get_right_child() -> get_root();
        }
    }
    if (!mult.empty() && !plus1.empty() && !plus2.empty()) {
        string formula = "( ( " + plus1 + " * " + mult + " ) " + symb + " ( " + plus2 + " * " + mult + " ) )";
        string old_formula = "( ( " + plus1 + " " + symb + " " + plus2 + " ) * " + mult + " )";
        cout << old_formula << " = " << formula << endl;
        vector<string> formula_vector = split(formula);
        Tree* new_tree;
        new_tree = create_tree(formula_vector);
        tree -> set_root(symb);
        tree -> set_right_child(new_tree -> get_right_child());
        tree -> set_left_child(new_tree -> get_left_child());
    }
}
