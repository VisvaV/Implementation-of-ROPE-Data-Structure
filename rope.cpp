#include "rope.h"

void Rope::split(int index, Rope& left, Rope& right) {
    left.root = split(root, index);
    right.root = left.root->right;
    left.root->right = nullptr;
}

void Rope::concat(const Rope& other) {
    if (isEmpty()) {
        root = other.root;
    }
    else if (other.isEmpty()) {
        cout << "EMPTY" << endl;
    }
    else {
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        current->right = other.root;
    }
}

void Rope::insert(int index, const string& str) {
    if (index == 0) {
        Node* newNode = new Node(str);
        newNode->right = root;
        root = newNode;
    }
    else {
        Rope left, right;
        split(index - 1, left, right);
        Node* newNode = new Node(str);
        newNode->right = right.root;
        left.root->right = newNode;
        root = left.root;
    }
}

void Rope::deleteAt(int index) {
    if (index < 0 || index >= length()) {
        cout << "Invalid index\n";
        return;
    }

    if (index == 0) {
        Node* temp = root;
        root = root->right;
        delete temp;
    } else {
        Rope left, right;
        split(index - 1, left, right);
        Node* temp = right.root;
        right.root = right.root->right;
        delete temp;
        left.root->right = right.root;
        root = left.root;
    }
}

Node* Rope::split(Node* node, int index) {
    if (node == nullptr) {
        return nullptr;
    }

    if (index == 0) {
        Node* newNode = node->right;
        node->right = nullptr;
        return newNode;
    }

    Node* secondHalf = split(node->right, index - 1);
    node->right = secondHalf;
    return node;
}

int Rope::privateLength(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->str.length() + privateLength(node->right);
}
