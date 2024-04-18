#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<class T>
class CircularLinkedList {
private:
    Node<T>* rear;

public:
    CircularLinkedList();
    bool isEmpty();
    void insert(T item);   ///time complexity O(n   space complexity O(1)
    void merge(CircularLinkedList<T>& list1, CircularLinkedList<T>& list2);// time compexity O(n+m)  where m is the number of elements in the first list and n is the number of elements in the second list.  space complexity O(1) 
    void display();
};

template<class T>
bool CircularLinkedList<T>::isEmpty() {
    return rear == nullptr;
}

template<class T>
void CircularLinkedList<T>::insert(T item) {
    Node<T>* newnode = new Node<T>(item);

    if (isEmpty()) {
        rear = newnode;
        rear->next = rear;
        return;
    }

    Node<T>* curr = rear->next;
    Node<T>* prev = rear;

    do {
        if (item <= curr->data)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != rear->next);

    newnode->next = curr;
    prev->next = newnode;

    if (item > rear->data)
        rear = newnode;
}

template<class T>
CircularLinkedList<T>::CircularLinkedList() {
    rear = nullptr;
}

template<class T>
void CircularLinkedList<T>::merge(CircularLinkedList<T>& list1, CircularLinkedList<T>& list2) {
    if (list1.isEmpty() && list2.isEmpty())
        return;

    Node<T>* curr1 = list1.rear->next;
    Node<T>* curr2 = list2.rear->next;

    do {
        insert(curr1->data);
        curr1 = curr1->next;
    } while (curr1 != list1.rear->next);

    do {
        insert(curr2->data);
        curr2 = curr2->next;
    } while (curr2 != list2.rear->next);
}

template<class T>
void CircularLinkedList<T>::display() {
    if (isEmpty()) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node<T>* curr = rear->next;

    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != rear->next);
}

int main() {
    CircularLinkedList<int> list1, list2, mergedList;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);

    list2.insert(1);
    list2.insert(10);
    list2.insert(20);

    cout << "List 1: ";
    list1.display();
    cout << endl;

    cout << "List 2: ";
    list2.display();
    cout << endl;

    mergedList.merge(list1, list2);

    cout << "Merged List: ";
    mergedList.display();
    cout << endl;

    return 0;
}
