#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class SingleLinklist {
public:
    Node* head;

    SingleLinklist() {
        head = NULL;
    }

    void InsertAtFront(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void InsertAtLast(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void DeleteAtFront() {
        if (head == NULL) {
            cout << "Error the list is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteAtLast() {
        if (head == NULL) {
            cout << "Error the list is empty" << endl;
            return;
        }

        
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void printLL() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    cout << "NULL";
    }
};

class DoubleNode {
public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinklist {
public:
    DoubleNode* head;

    DoubleLinklist() {
        head = NULL;
    }

    void InsertAtFront(int x) {
        DoubleNode* newNode = new DoubleNode(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void InsertAtLast(int x) {
        DoubleNode* newNode = new DoubleNode(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            DoubleNode* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void DeleteAtFront() {
        if (head == NULL) {
            cout << "Error the list is empty" << endl;
            return;
        }

        DoubleNode* temp = head;

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
    }

    void DeleteAtLast() {
        if (head == NULL) {
            cout << "Errorthe list is empty" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        DoubleNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        delete temp;
    }

    void printLL() {
        DoubleNode* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
    }
};



int main() {
    SingleLinklist l1;
    l1.InsertAtFront(12);
    l1.InsertAtFront(14);
    l1.InsertAtFront(15);
    l1.InsertAtLast(67);
    l1.InsertAtLast(69);
    l1.DeleteAtFront();
    l1.printLL();   
    return 0;
}
