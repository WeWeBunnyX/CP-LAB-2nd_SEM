
#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void append(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    Node* search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void reverse() {
        Node* current = head;
        Node* prev = nullptr, *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    cout << "Before Reverse (initial list): ";
    list.print();
    list.reverse();
    cout << "After Reversing the list: ";
    list.print();

    Node* foundNode = list.search(2);
    if (foundNode) {
        cout << "Node found: " << foundNode->data << endl;
    } else {
        cout << "Node not found" << endl;
    }
    
    return 0;
}
