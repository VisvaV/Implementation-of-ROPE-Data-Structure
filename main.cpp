#include "rope.h"

void display(const Rope& rope) {
    if (rope.isEmpty()) {
        cout << "Rope is empty." << endl;
    } else {
        cout << "Rope contents: " << rope << endl;
    }
}

ostream& operator<<(ostream& os, const Rope& rope) {
    if (rope.root == nullptr) {
        return os << "";
    }

    Node* current = rope.root;
    while (current != nullptr) {
        os << current->str;
        current = current->right;
    }

    return os;
}

void printMenu() {
    cout << "ROPE DATA STRUCTURE MENU\n";
    cout << "1. Split\n";
    cout << "2. Concat\n";
    cout << "3. Insert\n";
    cout << "4. Delete\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";
}

int main() {
    Rope rope("");

    int choice;
    string str;
    int index;

    while (true) {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter index: ";
            cin >> index;
            Rope left, right;
            rope.split(index, left, right);
            cout << "Left: " << left << "\n";
            cout << "Right: " << right << "\n";
        }
        else if (choice == 2) {
            string st;
            cout << "Enter string: ";
            cin >> st;
            Rope other(st);

            rope.concat(other);
            cout << "New Rope: " << rope << "\n";
        }
        else if (choice == 3) {
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter string: ";
            cin.ignore();
            getline(cin, str);
            rope.insert(index, str);
            cout << "New Rope: " << rope << "\n";
        }
        else if (choice == 4) {
            cout << "Enter index: ";
            cin >> index;
            rope.deleteAt(index);
            cout << "New Rope: " << rope << "\n";
        }
        else if (choice == 5) {
            cout << "Rope: " << rope << endl;
        }
        else if (choice == 6){
            exit(0);
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
