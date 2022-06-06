#include "tree_operations.h"
using namespace std;

int main() {
    string formula;
    cout << "Enter the formula, where each arithmetic operation is seperated with brackets and symbols are seperated with spaces:" << endl;
    getline(cin, formula);
    vector<string> formula_vector = split(formula);
    Tree* tree = create_tree(formula_vector);
    cout << "Initial tree:" << endl;
    display_tree("", tree, false);
    create_final_tree(tree);
    cout << "Final tree:" << endl;
    display_tree("", tree, false);
    delete tree;
    return 0;
}
