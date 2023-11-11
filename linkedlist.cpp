#include<iostream>
using namespace std;

// Define the Node class for a linked list
class Node {
    public:
        int data;
        Node* next;

        Node(int val): data(val), next(nullptr){}
};

// Define the linkedlist class
class Linkedlist {
    private:
        Node* head;

    public:
        Linkedlist(): head(nullptr) {}

        // Add a new node in the end of the list
        void append(int data) {
            Node* newNode = new Node(data);
            if (!head) {
                head = newNode;
            } else {
                Node* current = head;
                while(current->next) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        // Display the linked list
        void display() {
            Node* current = head;
            while(current) {
                cout<<current->data<<" -> ";
                current = current->next;
            }
            cout<<"nullptr"<<endl;
        }

        ~Linkedlist() {
            while(head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main() {
    Linkedlist myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);

    myList.display();
    return 0;
}