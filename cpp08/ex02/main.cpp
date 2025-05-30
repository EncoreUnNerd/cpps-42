#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

void testBasicOperations() {
    printSeparator("BASIC OPERATIONS TEST");

    MutantStack<int> mstack;
    std::list<int> list;

    // Test push operations
    std::cout << "Push operations: 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    list.push_back(5);
    list.push_back(17);

    // Test top/back
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    std::cout << "List back: " << list.back() << std::endl;

    // Test pop
    std::cout << "After pop:" << std::endl;
    mstack.pop();
    list.pop_back();

    std::cout << "MutantStack size: " << mstack.size() << std::endl;
    std::cout << "List size: " << list.size() << std::endl;

    // Add more elements
    std::cout << "\nAdding elements: 3, 5, 737, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::cout << "Final size - MutantStack: " << mstack.size() << ", List: " << list.size() << std::endl;
}

void testIterators() {
    printSeparator("ITERATOR COMPARISON TEST");

    MutantStack<int> mstack;
    std::list<int> list;

    // Add same elements
    int values[] = {5, 3, 737, 0, 42, 100};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        mstack.push(values[i]);
        list.push_back(values[i]);
    }

    std::cout << "Forward iteration comparison:" << std::endl;
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List:        ";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "\nReverse iteration comparison:" << std::endl;
    std::cout << "MutantStack: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List:        ";
    for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    printSeparator("COPY & ASSIGNMENT TEST");

    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    std::cout << "Original stack contents: ";
    for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    MutantStack<int> copy(original);
    std::cout << "Copy constructor - Copy contents: ";
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    MutantStack<int> assigned;
    assigned.push(999);
    assigned = original;
    std::cout << "Assignment operator - Assigned contents: ";
    for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test independence
    copy.push(4);
    assigned.push(5);
    original.push(6);

    std::cout << "\nAfter adding different elements:" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
}

void testConstIterators() {
    printSeparator("CONST ITERATOR TEST");

    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    const MutantStack<int>& const_ref = mstack;

    std::cout << "Const forward iteration: ";
    for (MutantStack<int>::const_iterator it = const_ref.begin(); it != const_ref.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Const reverse iteration: ";
    for (MutantStack<int>::const_reverse_iterator it = const_ref.rbegin(); it != const_ref.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testOriginalMain() {
    printSeparator("ORIGINAL MAIN TEST");

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test conversion to std::stack
    std::stack<int> s(mstack);
    std::cout << "Converted to std::stack, size: " << s.size() << std::endl;
}

void testEmptyStack() {
    printSeparator("EMPTY STACK TEST");

    MutantStack<int> empty_stack;

    std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
    std::cout << "Empty stack is empty: " << (empty_stack.empty() ? "true" : "false") << std::endl;

    std::cout << "Empty stack iteration: ";
    for (MutantStack<int>::iterator it = empty_stack.begin(); it != empty_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "(should be empty)" << std::endl;
}

int main()
{
    std::cout << "=== MUTANTSTACK COMPREHENSIVE TEST SUITE ===" << std::endl;

    testBasicOperations();
    testIterators();
    testCopyAndAssignment();
    testConstIterators();
    testEmptyStack();
    testOriginalMain();

    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;

    return 0;
}
