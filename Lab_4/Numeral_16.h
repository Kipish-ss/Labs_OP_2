#ifndef LAB_4_NUMERAL_16_H
#define LAB_4_NUMERAL_16_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Numeral_16 {
    string num_16_str;
public:
    Numeral_16() = default;
    explicit Numeral_16(const string& num_16_str) { this -> num_16_str = num_16_str; }
    explicit Numeral_16(int);
    string get_num_16_str() const { return  num_16_str; }
    Numeral_16 operator ++();
    const Numeral_16 operator +(const Numeral_16& obj);
    const Numeral_16 operator += (const Numeral_16& obj);
    string convert_to_binary_short();
    string convert_to_binary_long();
};
#endif
