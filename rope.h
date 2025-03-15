#ifndef ROPE_H
#define ROPE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    Node(const string& str) : str(str), left(nullptr), right(nullptr) {}
    string str;
    Node* left;
    Node* right;
};

class Rope {
public:
    Rope() : root(nullptr) {}

    Rope(const string& str) {
        root = new Node(str);
    }

    void split(int index, Rope& left, Rope& right);

    void concat(const Rope& other);

    void insert(int index, const string& str);

    void deleteAt(int index);

    bool isEmpty() const {
        return root == nullptr;
    }

    int length() const {
        return privateLength(root);
    }

    friend ostream& operator<<(ostream&, const Rope&);

private:
    Node* root;

    Node* split(Node* node, int index);

    int privateLength(Node* node) const;
};

#endif // ROPE_H
