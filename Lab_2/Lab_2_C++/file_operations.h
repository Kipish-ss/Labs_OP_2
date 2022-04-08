#ifndef LAB_2_C___FILE_OPERATIONS_H
#define LAB_2_C___FILE_OPERATIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Car {
    string model;
    string release_date;
    string sell_date;
};
string enter_file_mode();
void create_fist_file(string, int, string);
void output_file(string);
void create_list_recent_cars(string, string, int, int);
void output_worn_cars(string);
void output_car(Car);
vector<string> split_date(string);
#endif
