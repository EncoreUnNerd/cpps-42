#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <climits>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void testBasicFunctionality() {
    std::cout << BLUE << "\n=== TEST: Basic Functionality ===" << RESET << std::endl;

    try {
        Span sp(5);

        // Test addNumber
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << GREEN << "✓ Added 5 numbers successfully" << RESET << std::endl;

        // Test shortestSpan and longestSpan
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: 2 (9-11 or 6-3)
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Expected: 14 (17-3)

    } catch (std::exception& e) {
        std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
    }
}

void testExceptions() {
    std::cout << BLUE << "\n=== TEST: Exceptions ===" << RESET << std::endl;

    // Test TooManyElement exception
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << GREEN << "✓ Added 3 numbers (max capacity)" << RESET << std::endl;

        sp.addNumber(4); // Should throw
        std::cout << RED << "❌ Should have thrown TooManyElement" << RESET << std::endl;
    } catch (Span::TooManyElement& e) {
        std::cout << GREEN << "✓ TooManyElement caught: " << e.what() << RESET << std::endl;
    }

    // Test NotEnoughElement for shortestSpan
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.shortestSpan(); // Should throw (only 1 element)
        std::cout << RED << "❌ Should have thrown NotEnoughElement" << RESET << std::endl;
    } catch (Span::NotEnoughElement& e) {
        std::cout << GREEN << "✓ NotEnoughElement (shortestSpan): " << e.what() << RESET << std::endl;
    }

    // Test NotEnoughElement for longestSpan
    try {
        Span sp(5);
        // Empty span
        sp.longestSpan(); // Should throw (0 elements)
        std::cout << RED << "❌ Should have thrown NotEnoughElement" << RESET << std::endl;
    } catch (Span::NotEnoughElement& e) {
        std::cout << GREEN << "✓ NotEnoughElement (longestSpan): " << e.what() << RESET << std::endl;
    }
}

void testCopyAndAssignment() {
    std::cout << BLUE << "\n=== TEST: Copy Constructor & Assignment ===" << RESET << std::endl;

    try {
        // Original span
        Span sp1(4);
        sp1.addNumber(10);
        sp1.addNumber(5);
        sp1.addNumber(20);

        // Test copy constructor
        Span sp2(sp1);
        std::cout << GREEN << "✓ Copy constructor" << RESET << std::endl;
        std::cout << "sp2 shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "sp2 longest span: " << sp2.longestSpan() << std::endl;

        // Test assignment operator
        Span sp3(10);
        sp3 = sp1;
        std::cout << GREEN << "✓ Assignment operator" << RESET << std::endl;
        std::cout << "sp3 shortest span: " << sp3.shortestSpan() << std::endl;

        // Test self-assignment (suppress warning)
        Span* ptr = &sp3;
        sp3 = *ptr;
        std::cout << GREEN << "✓ Self-assignment handled" << RESET << std::endl;

    } catch (std::exception& e) {
        std::cout << RED << "❌ Error: " << e.what() << RESET << std::endl;
    }
}

void testRangeIterator() {
    std::cout << BLUE << "\n=== TEST: Range Iterator ===" << RESET << std::endl;

    try {
        Span sp(15);

        // Test with vector (C++98 way)
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(5);
        vec.push_back(9);
        vec.push_back(13);
        sp.addNumberRange(vec.begin(), vec.end());
        std::cout << GREEN << "✓ Added vector range" << RESET << std::endl;

        // Test with list (C++98 way)
        std::list<int> lst;
        lst.push_back(2);
        lst.push_back(6);
        lst.push_back(10);
        sp.addNumberRange(lst.begin(), lst.end());
        std::cout << GREEN << "✓ Added list range" << RESET << std::endl;

        // Test with C array
        int arr[] = {3, 7, 11, 15};
        sp.addNumberRange(arr, arr + 4);
        std::cout << GREEN << "✓ Added C array range" << RESET << std::endl;

        std::cout << "Final shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Final longest span: " << sp.longestSpan() << std::endl;

        // Test range overflow
        std::vector<int> big_vec;
        big_vec.push_back(100);
        big_vec.push_back(200);
        big_vec.push_back(300);
        big_vec.push_back(400);
        big_vec.push_back(500);
        sp.addNumberRange(big_vec.begin(), big_vec.end()); // Should throw
        std::cout << RED << "❌ Should have thrown TooManyElement" << RESET << std::endl;

    } catch (Span::TooManyElement& e) {
        std::cout << GREEN << "✓ Range overflow caught: " << e.what() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "❌ Unexpected error: " << e.what() << RESET << std::endl;
    }
}

void testEdgeCases() {
    std::cout << BLUE << "\n=== TEST: Edge Cases ===" << RESET << std::endl;

    // Test with identical numbers
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.addNumber(42);
        sp.addNumber(42);
        std::cout << "Identical numbers - shortest span: " << sp.shortestSpan() << std::endl; // Should be 0
        std::cout << "Identical numbers - longest span: " << sp.longestSpan() << std::endl;   // Should be 0
    } catch (std::exception& e) {
        std::cout << RED << "❌ Error with identical numbers: " << e.what() << RESET << std::endl;
    }

    // Test with negative numbers
    try {
        Span sp(4);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        std::cout << "Negative numbers - shortest span: " << sp.shortestSpan() << std::endl; // Should be 5
        std::cout << "Negative numbers - longest span: " << sp.longestSpan() << std::endl;   // Should be 15
    } catch (std::exception& e) {
        std::cout << RED << "❌ Error with negative numbers: " << e.what() << RESET << std::endl;
    }

    // Test with large numbers
    try {
        Span sp(3);
        sp.addNumber(INT_MAX - 1);
        sp.addNumber(INT_MAX);
        std::cout << "Large numbers - shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << GREEN << "✓ Large numbers handled" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "❌ Error with large numbers: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << YELLOW << "🧪 COMPREHENSIVE SPAN TESTING 🧪" << RESET << std::endl;

    testBasicFunctionality();
    testExceptions();
    testCopyAndAssignment();
    testRangeIterator();
    testEdgeCases();

    std::cout << YELLOW << "\n🎉 All tests completed! 🎉" << RESET << std::endl;
    return 0;
}



// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }
