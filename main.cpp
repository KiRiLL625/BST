#include <iostream>
#include "Set.h"

bool menu(Set<int>& set1, Set<int>& set2){
    std::cout << "1. Insert element" << std::endl;
    std::cout << "2. Remove element" << std::endl;
    std::cout << "3. Check if element exists" << std::endl;
    std::cout << "4. Union" << std::endl;
    std::cout << "5. Intersection" << std::endl;
    std::cout << "6. Difference" << std::endl;
    std::cout << "7. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            set1.insert(element);
            std::cout << set1;
            break;
        }
        case 2: {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            set1.remove(element);
            std::cout << set1;
            break;
        }
        case 3: {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;
            if (set1.contains(element)) {
                std::cout << "Element exists" << std::endl;
            } else {
                std::cout << "Element does not exist" << std::endl;
            }
            break;
        }
        case 4: {
            std::cin >> set2;
            std::cout << set1 + set2;
            break;
        }
        case 5: {
            std::cin >> set2;
            std::cout << set1 * set2;
            break;
        }
        case 6: {
            std::cin >> set2;
            std::cout << set1 - set2;
            break;
        }
        case 7: {
            return false;
        }
        default: {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    return true;
}

int main() {
    Set<int> set1, set2;
    while(menu(set1, set2));
    return 0;
}
