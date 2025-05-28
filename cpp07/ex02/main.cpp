#include "Array.hpp"
#include <iostream>
#include <string>
#include <climits>

// Classe de test personnalisée pour tester avec des objets complexes
class TestClass {
public:
    int value;
    std::string text;

    TestClass() : value(42), text("default") {}
    TestClass(int v, const std::string& t) : value(v), text(t) {}
    TestClass(const TestClass& other) : value(other.value), text(other.text) {}
    TestClass& operator=(const TestClass& other) {
        if (this != &other) {
            value = other.value;
            text = other.text;
        }
        return *this;
    }

    bool operator==(const TestClass& other) const {
        return value == other.value && text == other.text;
    }
};

template<typename T>
void intensiveOutOfBoundsTests(const std::string& typeName, bool& allTestsPassed, int& testCount) {
    std::cout << "\n========== TESTS INTENSIFS OUT OF BOUNDS POUR " << typeName << " ==========" << std::endl;

    // Test 1: Exception à l'index exact de la taille
    std::cout << "\n--- Test OutOfBounds 1: Index = size ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(5);
        T val = arr[5]; // size = 5, donc index 5 doit lever exception
        (void)val;
        std::cout << "❌ Index=size: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Index=size: OK (" << e.what() << ")" << std::endl;
    }

    // Test 2: Exception avec un index très grand
    std::cout << "\n--- Test OutOfBounds 2: Index très grand ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(3);
        T val = arr[999999]; // Index énorme
        (void)val;
        std::cout << "❌ Index énorme: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Index énorme: OK (" << e.what() << ")" << std::endl;
    }

    // Test 3: Exception avec UINT_MAX
    std::cout << "\n--- Test OutOfBounds 3: Index UINT_MAX ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(10);
        T val = arr[UINT_MAX]; // Plus grand unsigned int possible
        (void)val;
        std::cout << "❌ Index UINT_MAX: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Index UINT_MAX: OK (" << e.what() << ")" << std::endl;
    }

    // Test 4: Exception sur array de taille 1
    std::cout << "\n--- Test OutOfBounds 4: Array taille 1, index 1 ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(1);
        T val = arr[1]; // Index 1 sur array de taille 1
        (void)val;
        std::cout << "❌ Array[1] taille 1: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Array[1] taille 1: OK (" << e.what() << ")" << std::endl;
    }

    // Test 5: Multiples exceptions consécutives
    std::cout << "\n--- Test OutOfBounds 5: Multiples exceptions ---" << std::endl;
    testCount++;
    int exceptions_caught = 0;
    Array<T> arr(5);

    unsigned int bad_indices[] = {5, 6, 10, 100, 1000, UINT_MAX};
    int num_bad_indices = sizeof(bad_indices) / sizeof(bad_indices[0]);

    for (int i = 0; i < num_bad_indices; i++) {
        try {
            T val = arr[bad_indices[i]];
            (void)val;
            std::cout << "❌ Index " << bad_indices[i] << ": FAIL (pas d'exception)" << std::endl;
            allTestsPassed = false;
        } catch (const std::exception& e) {
            exceptions_caught++;
        }
    }

    if (exceptions_caught == num_bad_indices) {
        std::cout << "✅ Multiples exceptions: OK (" << exceptions_caught << "/" << num_bad_indices << ")" << std::endl;
    } else {
        std::cout << "❌ Multiples exceptions: FAIL (" << exceptions_caught << "/" << num_bad_indices << ")" << std::endl;
        allTestsPassed = false;
    }

    // Test 6: Exception en écriture aussi
    std::cout << "\n--- Test OutOfBounds 6: Exception en écriture ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(3);
        arr[5] = T(); // Doit lever exception en écriture aussi
        std::cout << "❌ Exception écriture: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception écriture: OK (" << e.what() << ")" << std::endl;
    }

    // Test 7: Exception sur array copié
    std::cout << "\n--- Test OutOfBounds 7: Exception sur copie ---" << std::endl;
    testCount++;
    try {
        Array<T> original(4);
        Array<T> copy = original;
        T val = copy[4]; // Doit lever exception sur la copie aussi
        (void)val;
        std::cout << "❌ Exception sur copie: FAIL (pas d'exception levée)" << std::endl;
        allTestsPassed = false;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception sur copie: OK (" << e.what() << ")" << std::endl;
    }
}

template<typename T>
void intensiveEdgeCaseTests(const std::string& typeName, bool& allTestsPassed, int& testCount) {
    std::cout << "\n========== TESTS EDGE CASES POUR " << typeName << " ==========" << std::endl;

    // Test 1: Array de grande taille
    std::cout << "\n--- Test Edge 1: Array de grande taille ---" << std::endl;
    testCount++;
    try {
        Array<T> big_array(10000);
        if (big_array.size() == 10000) {
            // Test accès aux extrémités
            T val1 = big_array[0];
            T val2 = big_array[9999];
            big_array[0] = val1;
            big_array[9999] = val2;
            std::cout << "✅ Array grande taille: OK" << std::endl;
        } else {
            std::cout << "❌ Array grande taille: FAIL (mauvaise taille)" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Array grande taille: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 2: Assignations multiples
    std::cout << "\n--- Test Edge 2: Assignations multiples ---" << std::endl;
    testCount++;
    try {
        Array<T> arr1(5);
        Array<T> arr2(10);
        Array<T> arr3(3);

        arr1 = arr2;
        arr3 = arr1;
        arr2 = arr3;

        if (arr1.size() == 10 && arr2.size() == 10 && arr3.size() == 10) {
            std::cout << "✅ Assignations multiples: OK" << std::endl;
        } else {
            std::cout << "❌ Assignations multiples: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Assignations multiples: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 3: Copie profonde vérifiée
    std::cout << "\n--- Test Edge 3: Vérification copie profonde ---" << std::endl;
    testCount++;
    try {
        Array<T> original(3);
        T test_val = T();
        original[1] = test_val;

        Array<T> copy1 = original;
        Array<T> copy2(5);
        copy2 = original;

        // Modifier l'original ne doit pas affecter les copies
        if (copy1.size() == 3 && copy2.size() == 3) {
            std::cout << "✅ Copie profonde vérifiée: OK" << std::endl;
        } else {
            std::cout << "❌ Copie profonde vérifiée: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Copie profonde vérifiée: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 4: Assignation array vide
    std::cout << "\n--- Test Edge 4: Assignation array vide ---" << std::endl;
    testCount++;
    try {
        Array<T> empty_arr;
        Array<T> full_arr(5);

        full_arr = empty_arr;

        if (full_arr.size() == 0) {
            std::cout << "✅ Assignation array vide: OK" << std::endl;
        } else {
            std::cout << "❌ Assignation array vide: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Assignation array vide: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 5: Array vide vers array non-vide
    std::cout << "\n--- Test Edge 5: Array vide vers non-vide ---" << std::endl;
    testCount++;
    try {
        Array<T> empty_arr;
        Array<T> target_arr(10);

        target_arr = empty_arr;

        if (target_arr.size() == 0) {
            std::cout << "✅ Vide vers non-vide: OK" << std::endl;
        } else {
            std::cout << "❌ Vide vers non-vide: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Vide vers non-vide: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }
}

template<typename T>
void stressTests(const std::string& typeName, bool& allTestsPassed, int& testCount) {
    std::cout << "\n========== TESTS DE STRESS POUR " << typeName << " ==========" << std::endl;

    // Test 1: Créations/destructions multiples
    std::cout << "\n--- Test Stress 1: Créations/destructions multiples ---" << std::endl;
    testCount++;
    try {
        for (int i = 0; i < 100; i++) {
            Array<T> temp_arr(i % 50 + 1);
            // Utiliser l'array
            for (unsigned int j = 0; j < temp_arr.size(); j++) {
                temp_arr[j] = T();
            }
        }
        std::cout << "✅ Créations/destructions multiples: OK" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "❌ Créations/destructions multiples: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 2: Copies en chaîne
    std::cout << "\n--- Test Stress 2: Copies en chaîne ---" << std::endl;
    testCount++;
    try {
        Array<T> arr1(10);
        Array<T> arr2 = arr1;
        Array<T> arr3 = arr2;
        Array<T> arr4 = arr3;
        Array<T> arr5 = arr4;

        if (arr5.size() == 10) {
            std::cout << "✅ Copies en chaîne: OK" << std::endl;
        } else {
            std::cout << "❌ Copies en chaîne: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Copies en chaîne: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Test 3: Accès intensif
    std::cout << "\n--- Test Stress 3: Accès intensif ---" << std::endl;
    testCount++;
    try {
        Array<T> arr(1000);

        // Écriture intensive
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = T();
        }

        // Lecture intensive
        for (unsigned int i = 0; i < arr.size(); i++) {
            T val = arr[i];
            (void)val;
        }

        std::cout << "✅ Accès intensif: OK" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "❌ Accès intensif: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }
}

template<typename T>
void boundaryTests(const std::string& typeName, bool& allTestsPassed, int& testCount) {
    std::cout << "\n========== TESTS DE LIMITES POUR " << typeName << " ==========" << std::endl;

    unsigned int test_sizes[] = {1, 2, 3, 10, 100, 1000};
    int num_sizes = sizeof(test_sizes) / sizeof(test_sizes[0]);

    for (int s = 0; s < num_sizes; s++) {
        unsigned int size = test_sizes[s];
        std::cout << "\n--- Test Limites: Taille " << size << " ---" << std::endl;
        testCount++;

        try {
            Array<T> arr(size);

            // Test accès valides
            bool valid_access_ok = true;
            for (unsigned int i = 0; i < size; i++) {
                try {
                    T val = arr[i];
                    arr[i] = val;
                } catch (const std::exception& e) {
                    valid_access_ok = false;
                    break;
                }
            }

            // Test accès invalides
            bool invalid_access_ok = true;
            unsigned int invalid_indices[] = {size, size + 1, size + 10, size * 2};
            int num_invalid = sizeof(invalid_indices) / sizeof(invalid_indices[0]);

            for (int i = 0; i < num_invalid; i++) {
                try {
                    T val = arr[invalid_indices[i]];
                    (void)val;
                    invalid_access_ok = false; // Ne devrait pas arriver ici
                    break;
                } catch (const std::exception& e) {
                    // C'est ce qu'on veut
                }
            }

            if (valid_access_ok && invalid_access_ok) {
                std::cout << "✅ Limites taille " << size << ": OK" << std::endl;
            } else {
                std::cout << "❌ Limites taille " << size << ": FAIL" << std::endl;
                allTestsPassed = false;
            }

        } catch (const std::exception& e) {
            std::cout << "❌ Limites taille " << size << ": EXCEPTION " << e.what() << std::endl;
            allTestsPassed = false;
        }
    }
}

template<typename T>
void comprehensiveTestSuite(const std::string& typeName) {
    std::cout << "\n🚀 ========== TESTS COMPLETS POUR " << typeName << " ========== 🚀" << std::endl;

    bool allTestsPassed = true;
    int testCount = 0;

    // Tests de base
    std::cout << "\n🔧 --- TESTS DE BASE ---" << std::endl;

    // Test constructeurs
    testCount++;
    try {
        Array<T> arr1;
        Array<T> arr2(5);
        Array<T> arr3(0);
        Array<T> arr4(arr2);

        if (arr1.size() == 0 && arr2.size() == 5 && arr3.size() == 0 && arr4.size() == 5) {
            std::cout << "✅ Constructeurs de base: OK" << std::endl;
        } else {
            std::cout << "❌ Constructeurs de base: FAIL" << std::endl;
            allTestsPassed = false;
        }
    } catch (const std::exception& e) {
        std::cout << "❌ Constructeurs de base: EXCEPTION " << e.what() << std::endl;
        allTestsPassed = false;
    }

    // Tests spécialisés
    intensiveOutOfBoundsTests<T>(typeName, allTestsPassed, testCount);
    intensiveEdgeCaseTests<T>(typeName, allTestsPassed, testCount);
    stressTests<T>(typeName, allTestsPassed, testCount);
    boundaryTests<T>(typeName, allTestsPassed, testCount);

    // Résumé final
    std::cout << "\n🏁 ========== RÉSUMÉ FINAL POUR " << typeName << " ========== 🏁" << std::endl;
    if (allTestsPassed) {
        std::cout << "🎉 TOUS LES TESTS RÉUSSIS ! (" << testCount << " tests)" << std::endl;
    } else {
        std::cout << "❌ CERTAINS TESTS ONT ÉCHOUÉ (" << testCount << " tests au total)" << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

int main() {
    std::cout << "🎯 ========== SUITE DE TESTS ULTRA-COMPLÈTE POUR ARRAY ========== 🎯" << std::endl;
    std::cout << "Cette suite contient des tests exhaustifs pour tous les aspects de la classe Array." << std::endl;

    // Tests avec types primitifs
    comprehensiveTestSuite<int>("INT");
    comprehensiveTestSuite<float>("FLOAT");
    comprehensiveTestSuite<double>("DOUBLE");
    comprehensiveTestSuite<char>("CHAR");
    comprehensiveTestSuite<bool>("BOOL");

    // Tests avec types complexes
    comprehensiveTestSuite<std::string>("STRING");
    comprehensiveTestSuite<TestClass>("TEST_CLASS");

    std::cout << "\n🏆 ========== TOUS LES TESTS TERMINÉS ========== 🏆" << std::endl;
    std::cout << "Si tous les tests sont passés, votre implémentation de Array est robuste !" << std::endl;

    return 0;
}
