// linked-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<class t>
struct node {
public:
    t data;
    node<t>* next; // Corrected template parameter
    node(t value) :data(value), next(nullptr) {}
};
template<class t>
class linked_list {
private:
    node<t>* head;
    int counter;
public:
    linked_list();
    bool isempty();
    node<t>* insert(int, t);
    void split(linked_list*, linked_list*, linked_list*);
    void print();
    node<t>* merge(linked_list* ob1, linked_list*);
    ~linked_list();

};
template<class t>
linked_list<t>::~linked_list() {
    node<t>* temp = head;
    while (temp != nullptr) {

        node<t>* nextNode = temp->next;
        delete temp;  // Delete the current node
        temp = nextNode;

    }
}
template<class t>
bool linked_list<t>::isempty() {
    return head == nullptr;
}
template<class t>
linked_list<t>::linked_list() :head(nullptr), counter(0) {}
template<class t>
node<t>* linked_list<t>::insert(int index, t item) {
    if (index < 0)
    {
        cout << "invaild index\n";
        return nullptr;
    }
    node<t>* temp = head;
    node<t>* newNode = new node<t>(item);
    //newNode -> data = item;
    if (index == 0) {
        newNode->next = nullptr;
        head = newNode;

    }
    else {
        for (int i = 0; i < index - 1 && temp; i++) {
            temp = temp->next;
        }
        if (temp) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else {
            cout << "invalid,index\n";
            delete newNode;
            return nullptr;
        }

    }
    counter++;
    return newNode;

    /*  int currentindex = 1;
      while (current && current < index) {
          current = current->next;
          currentindex++;
      }
      if (current == nullptr)
          return;
      if (index == 0) {
          newNode->next = head;
          head = newNode;
      }
      else {

      newNode->next = current->next;
      current->next = newNode;
      }

      return newNode;*/

}

template<class t>
void linked_list<t>::split(linked_list* ob1, linked_list* ob2, linked_list* ob3) {
    if (ob1->isempty() || ob1->counter == 1) {
        cout << "invald\n";
        return;
    }
    else {
        int c = ob1->counter;
        //  cout << "counter = " << counter << '\n';
        int ind = 0;
        node<t>* temp = ob1->head;
        int i;
        for (i = 0; i < c / 2; i++) {

            ob2->insert(ind++, temp->data);
            temp = temp->next;

        }

        ind = 0;
        //  cout << "i = " << i << '\n';
        for (i; i < c; i++) {
            ob3->insert(ind++, temp->data);
            temp = temp->next;

        }

    }
}
template<class t>
node<t>* linked_list<t>::merge(linked_list* ob1, linked_list* ob2) {
    linked_list<t>* mergee = new linked_list<int>();
    node<t>* newNode = new node<t>(item);
    node<t>* rear = newNode;
    while ()
}

template<class t>
void linked_list<t>::print() {
    if (isempty()) {
        cout << "the list is emplty\n";
        return;
    }
    else {
        node<t>* curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
}

int main()
{
    linked_list<int>* ob1 = new linked_list<int>();
    linked_list<int>* ob2 = new linked_list<int>();
    linked_list<int>* ob3 = new linked_list<int>();
    ob1->insert(0, 0);
    ob1->insert(1, 1);
    ob1->insert(2, 2);
    ob1->insert(3, 19);
    ob1->insert(-1, 8);
    ob1->insert(-1, 8);
    ob1->insert(3, 4);
    cout << "/////////after split////////////////\n";
    ob1->split(ob1, ob2, ob3);
    ob1->print();
    ob2->print();
    ob3->print();
   
    cout << "/////////////////////////\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
