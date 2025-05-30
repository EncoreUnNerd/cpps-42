#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <climits>
#include "easyfind.hpp"

// Fonction helper pour les tests
void print_test_result(const std::string& test_name, bool success) {
    std::cout << (success ? "✓ " : "✗ ") << test_name << std::endl;
}

// ========== TESTS QUI MARCHENT ==========

void test_basic_functionality() {
    std::cout << "\n=== TESTS DE BASE (qui doivent marcher) ===" << std::endl;

    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }

    // Test normal
    std::vector<int>::iterator it = easyfind(vec, 3);
    print_test_result("Élément présent", it != vec.end() && *it == 3);

    // Test élément absent
    it = easyfind(vec, 99);
    print_test_result("Élément absent", it == vec.end());
}

void test_edge_cases() {
    std::cout << "\n=== TESTS LIMITES (qui doivent marcher) ===" << std::endl;

    // Conteneur vide
    std::vector<int> empty;
    std::vector<int>::iterator it = easyfind(empty, 42);
    print_test_result("Conteneur vide", it == empty.end());

    // Valeurs extrêmes
    std::vector<int> extreme;
    extreme.push_back(INT_MAX);
    extreme.push_back(INT_MIN);
    extreme.push_back(0);

    it = easyfind(extreme, INT_MAX);
    print_test_result("INT_MAX", it != extreme.end() && *it == INT_MAX);

    it = easyfind(extreme, INT_MIN);
    print_test_result("INT_MIN", it != extreme.end() && *it == INT_MIN);
}

void test_different_containers() {
    std::cout << "\n=== TESTS DIFFÉRENTS CONTENEURS ===" << std::endl;

    // std::list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    std::list<int>::iterator list_it = easyfind(lst, 20);
    print_test_result("std::list", list_it != lst.end());

    // std::deque
    std::deque<int> dq;
    dq.push_back(100);
    std::deque<int>::iterator deque_it = easyfind(dq, 100);
    print_test_result("std::deque", deque_it != dq.end());

    // std::multiset (conteneur ordonné)
    std::multiset<int> mset;
    mset.insert(5);
    mset.insert(10);
    mset.insert(5); // doublon
    std::multiset<int>::iterator set_it = easyfind(mset, 5);
    print_test_result("std::multiset", set_it != mset.end());
}

void test_performance() {
    std::cout << "\n=== TEST PERFORMANCE (gros conteneur) ===" << std::endl;

    std::vector<int> big_vec;
    const int SIZE = 100000;

    // Remplir avec des nombres de 0 à SIZE-1
    for (int i = 0; i < SIZE; ++i) {
        big_vec.push_back(i);
    }

    // Chercher un élément au milieu
    std::vector<int>::iterator it = easyfind(big_vec, SIZE/2);
    print_test_result("Gros conteneur (100k éléments)", it != big_vec.end());

    // Chercher un élément qui n'existe pas
    it = easyfind(big_vec, SIZE + 1000);
    print_test_result("Élément absent dans gros conteneur", it == big_vec.end());
}

// ========== TESTS QUI NE MARCHENT PAS ==========

void test_compilation_failures() {
    std::cout << "\n=== TESTS QUI NE COMPILENT PAS ===" << std::endl;
    std::cout << "Les tests suivants ne compileront pas si décommentés:" << std::endl;

    // TEST 1: std::stack n'a pas d'itérateurs
    std::cout << "✗ std::stack (pas d'itérateurs)" << std::endl;
    /*
    std::stack<int> stk;
    stk.push(42);
    auto it = easyfind(stk, 42); // ERREUR: stack n'a pas begin()/end()
    */

    // TEST 2: std::queue n'a pas d'itérateurs
    std::cout << "✗ std::queue (pas d'itérateurs)" << std::endl;
    /*
    std::queue<int> q;
    q.push(42);
    auto it = easyfind(q, 42); // ERREUR: queue n'a pas begin()/end()
    */

    // TEST 3: std::priority_queue n'a pas d'itérateurs
    std::cout << "✗ std::priority_queue (pas d'itérateurs)" << std::endl;
    /*
    std::priority_queue<int> pq;
    pq.push(42);
    auto it = easyfind(pq, 42); // ERREUR: priority_queue n'a pas begin()/end()
    */
}

void test_type_mismatches() {
    std::cout << "\n=== TESTS AVEC MAUVAIS TYPES ===" << std::endl;

    // TEST: Conteneur de strings (ne compile pas car on compare string avec int)
    std::cout << "✗ std::vector<string> avec int (ne compile pas)" << std::endl;
    /*
    std::vector<std::string> str_vec;
    str_vec.push_back("hello");
    auto it = easyfind(str_vec, 42); // ERREUR: impossible de comparer string avec int
    */

    // TEST: Conteneur de doubles
    std::cout << "⚠️ std::vector<double> avec int (comportement inattendu)" << std::endl;
    std::vector<double> double_vec;
    double_vec.push_back(3.14);
    double_vec.push_back(2.0);
    double_vec.push_back(42.0);

    // Ceci compile mais peut avoir un comportement inattendu
    std::vector<double>::iterator it = easyfind(double_vec, 42);
    bool found_42 = (it != double_vec.end());
    print_test_result("vector<double> trouve 42 (conversion implicite)", found_42);

    // Mais ne trouvera pas 3 car 3.14 != 3
    it = easyfind(double_vec, 3);
    bool not_found_3 = (it == double_vec.end());
    print_test_result("vector<double> ne trouve pas 3 (3.14 != 3)", not_found_3);
}

void test_custom_types() {
    std::cout << "\n=== TESTS AVEC TYPES PERSONNALISÉS ===" << std::endl;

    std::cout << "✗ Classe sans opérateur== avec int (ne compile pas)" << std::endl;
    /*
    class NonComparable {
    public:
        int value;
        NonComparable(int v) : value(v) {}
        // Pas d'opérateur== avec int défini
    };

    std::vector<NonComparable> custom_vec;
    custom_vec.push_back(NonComparable(42));
    auto it = easyfind(custom_vec, 42); // ERREUR: pas d'opérateur== entre NonComparable et int
    */
}

void test_const_containers() {
    std::cout << "\n=== TESTS AVEC CONTENEURS CONST ===" << std::endl;

    std::cout << "✗ Conteneur const avec fonction non-const (ne compile pas)" << std::endl;
    /*
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    const std::vector<int>& const_vec = vec;
    auto it = easyfind(const_vec, 2); // ERREUR: votre fonction prend T& non const
    */

    std::cout << "Solution: Il faudrait une surcharge const:" << std::endl;
    std::cout << "template<typename T>" << std::endl;
    std::cout << "typename T::const_iterator easyfind(const T &v, int value)" << std::endl;
}

void test_memory_issues() {
    std::cout << "\n=== TESTS POTENTIELS PROBLÈMES MÉMOIRE ===" << std::endl;

    std::cout << "⚠️ Attention aux itérateurs invalidés après modification du conteneur" << std::endl;
    std::cout << "Exemple: après clear(), resize(), push_back() sur vector plein..." << std::endl;
}

int main() {
    std::cout << "TESTS AVANCÉS DE easyfind" << std::endl;
    std::cout << "=========================" << std::endl;

    // Tests qui marchent
    test_basic_functionality();
    test_edge_cases();
    test_different_containers();
    test_performance();

    // Tests qui ne marchent pas
    test_compilation_failures();
    test_type_mismatches();
    test_custom_types();
    test_const_containers();
    test_memory_issues();

    std::cout << "\n=== RÉSUMÉ ===" << std::endl;
    std::cout << "Votre implémentation est correcte pour:" << std::endl;
    std::cout << "✓ Tous les conteneurs STL avec itérateurs" << std::endl;
    std::cout << "✓ Conteneurs d'entiers" << std::endl;
    std::cout << "✓ Cas limites (vide, extrêmes)" << std::endl;
    std::cout << "\nLimitations identifiées:" << std::endl;
    std::cout << "✗ Pas de support pour conteneurs const" << std::endl;
    std::cout << "✗ Ne marche qu'avec conteneurs ayant des itérateurs" << std::endl;
    std::cout << "✗ Types doivent être comparables avec int" << std::endl;

    return 0;
}
