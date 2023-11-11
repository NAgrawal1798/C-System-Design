#include<iostream>
#include<vector>
using namespace std;

class Queue {
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    vector<int>arr;

    public:
        Queue(int s) : front(-1), rear(-1), size(s), arr(s, -1) {}

        void enQueue(int value);
        int deQueue();
        void displayQueue();
};

// Function to create circular queue
void Queue ::enQueue(int value) {
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front)) {
        cout<<"\nQueue is full";
        return;
    } else if (front == -1) { // Insert first element
        front = rear = 0;
        arr[rear] = value;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
        arr[rear] = value;
    } else {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from circular queue
int Queue :: deQueue() {
    if (front == -1) {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

// Function displaying the elements of circular queue
void Queue::displayQueue() {
    if (front == -1) {
        cout<<"\nQueue is empty";
        return;
    }
    cout<<"\nElemement in Circular Queue are:";
    if (rear >= front) {
        for (int i= front; i<=rear; i++) {
            cout<<arr[i]<<" ";
        }
    } else {
        for (int i= front; i<size; i++) {
            cout<<arr[i]<<" ";
        }
        for (int i=0; i<rear; i++) {
            cout<<arr[i]<<" ";
        }
    }
}

// Driver of the program
int main() {
    Queue q(5);

    // Inserting elements in circular queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Displaying elements in circular queue
    q.displayQueue();

    // Deleting elements in circular queue
    cout<<"\n Deleted value = "<<q.deQueue();
    cout<<"\n Deleted value = "<<q.deQueue();

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}