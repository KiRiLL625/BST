//
// Created by Admin on 29.05.2024.
//

#ifndef BST2_SET_H
#define BST2_SET_H

#include "BST.h"

template <typename T>
class Set {
private:
    AVLTree<T> tree;
public:
    Set() {
        tree = AVLTree<T>();
    }

    Set(const Set<T>& other) {
        tree = other.tree;
    }

    Set<T>& operator=(const Set<T>& other) {
        tree = other.tree;
        return *this;
    }

    void insert(T key) {
        if (!tree.contains(key)) {
            tree.insert(key);
        }
    }

    void remove(T key) {
        tree.remove(key);
    }

    bool contains(T key) {
        return tree.contains(key);
    }

    Set<T> operator+(Set<T>& other) { // Union
        Set<T> result;
        for (T key : this->tree) {
            result.insert(key);
        }
        for (T key : other.tree) {
            result.insert(key);
        }
        return result;
    }

    Set<T> operator*(Set<T>& other) { // Intersection
        Set<T> result;
        for (T key : this->tree) {
            if (other.contains(key)) {
                result.insert(key);
            }
        }
        return result;
    }

    Set<T> operator-(Set<T>& other) { // Difference
        Set<T> result;
        for (T key : this->tree) {
            if (!other.contains(key)) {
                result.insert(key);
            }
        }
        return result;
    }

    bool operator==(Set<T>& other) {
        return this->tree == other.tree;
    }

    bool operator!=(Set<T>& other) {
        return this->tree != other.tree;
    }

    bool findSubSet(Set<T>& other) {
        for (T key : other.tree) {
            if (!this->contains(key)) {
                return false;
            }
        }
        return true;
    }

    int size() {
        return tree.size();
    }

    friend std::ostream& operator<<(std::ostream& out, Set<T>& set) {
        out << "{";
        auto it = set.tree.begin();
        while (it != set.tree.end()) {
            out << *it;
            ++it;
            if (it != set.tree.end()) {
                out << " ";
            }
        }
        out << "}" << std::endl;
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, Set<T>&& set) {
        out << "{";
        auto it = set.tree.begin();
        while (it != set.tree.end()) {
            out << *it;
            ++it;
            if (it != set.tree.end()) {
                out << " ";
            }
        }
        out << "}" << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Set<T>& set) {
        T key;
        while (in >> key && key != -1) {
            set.insert(key);
        }
        return in;
    }
};

#endif //BST2_SET_H
