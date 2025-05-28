#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

// Fonctions de test
void printInt(const int &e) { std::cout << e << " "; }
void incr(int &e) { ++e; }
void setZero(int &e) { e = 0; }
void printDouble(const double &e) { std::cout << e << " "; }
void doubleValue(double &e) { e *= 2; }
void printString(const std::string &s) { std::cout << s << " "; }
void toUpper(std::string &s) {
    for (size_t i = 0; i < s.size(); ++i)
        s[i] = std::toupper(s[i]);
}

int main(void)
{
    // Test avec int
    int intArray[] = {1,2,3,4,5};
    size_t len = sizeof(intArray)/sizeof(intArray[0]);
    std::cout << "Original intArray: ";
    iter(intArray, len, printInt);
    std::cout << std::endl;

    iter(intArray, len, incr);
    std::cout << "After incr: ";
    iter(intArray, len, printInt);
    std::cout << std::endl;

    iter(intArray, len, setZero);
    std::cout << "After setZero: ";
    iter(intArray, len, printInt);
    std::cout << std::endl;

    // Test avec double
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t lenD = sizeof(doubleArray)/sizeof(doubleArray[0]);
    std::cout << "Original doubleArray: ";
    iter(doubleArray, lenD, printDouble);
    std::cout << std::endl;

    iter(doubleArray, lenD, doubleValue);
    std::cout << "After doubleValue: ";
    iter(doubleArray, lenD, printDouble);
    std::cout << std::endl;

    // Test avec string
    std::string strArray[] = {"hello", "world"};
    size_t lenS = sizeof(strArray)/sizeof(strArray[0]);
    std::cout << "Original strArray: ";
    iter(strArray, lenS, printString);
    std::cout << std::endl;

    iter(strArray, lenS, toUpper);
    std::cout << "After toUpper: ";
    iter(strArray, lenS, printString);
    std::cout << std::endl;

    return 0;
}
