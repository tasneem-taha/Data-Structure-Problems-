// assignment 4 question 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<class t>
struct nodde {
	nodde<t>* prev;
	nodde<t>* next;
	t data;
};
template<class t>
class doublylinkedlist {
private:
	nodde<t>* head;
public:
	doublylinkedlist();
	~doublylinkedlist();
	void makeempty2();
	void print2();
	void insert2(t, int);
	bool empty2();
	bool fall2();
	int counter2();
	void delette1withindex2(int);
	void delette1withitem2(t);
	nodde<t>* gethead2();
	nodde<t>* kthNodeFromEnd(int);

	void split1(doublylinkedlist<t>*, doublylinkedlist<t>*);
	void merge1(doublylinkedlist<t>*, doublylinkedlist<t>*, doublylinkedlist<t>*);
	nodde<t>* rotate1(int n);
	void reverse2();
	int search1();

};
template<class t>
int doublylinkedlist<t>::counter2() {
	if (fall2()) {
		cout << "invalid\n";
		return -1;
	}
	nodde<t>* curr = head;
	int count = 0;
	while (curr != nullptr) {

		curr = curr->next;
		count++;
	}
	return count;
}
template<class t>
nodde<t>* doublylinkedlist<t>::gethead2() {
	return head;
}
template<class t>
void doublylinkedlist<t>::print2() {
	if (fall2()) {
		cout << "invalid\n";
		return;
	}
	nodde<t>* curr = head;
	while (curr != nullptr) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << '\n';
}
template<class t>
void doublylinkedlist<t>::insert2(t item, int pos) {
	if (fall2()) {
		cout << "invlalid ,the heap is fall\n";
		return;
	}
	else if (pos < 0 || pos >counter2()) {
		cout << "the position is invalid \n";
		return;
	}
	nodde<t>* newnode = new nodde<t>;
	newnode->data = item;
	/*if (empty2())
	{
		newnode->prev = newnode->next = nullptr;
		head = newnode;
		return;

	}*/
	if (pos == 0) {
		newnode->prev = nullptr;
		newnode->next = head;
		if (head != nullptr)
			head->prev = newnode;

		head = newnode;
		return;
	}
	nodde<t>* curr = head;
	for (int i = 0; i < pos - 1 && curr; i++) {
		curr = curr->next;
	}
	if (curr == nullptr) {

		delete newnode;
		return;
	}

	newnode->next = curr->next;
	newnode->prev = curr;
	if (curr->next)
		curr->next->prev = newnode;

	curr->next = newnode;

}
template<class t>
void doublylinkedlist<t>::makeempty2() {

}
template<class t>
bool doublylinkedlist<t>::empty2() {
	return head == nullptr;
}
template<class t>
bool doublylinkedlist<t>::fall2() {
	nodde<t>* newnode = new nodde<t>;
	if (newnode) {
		return 0;
	}
	return 1;
}
template<class t>
void doublylinkedlist<t>::delette1withindex2(int pos) {
	if (empty2()) {
		cout << "the list isempty\n";
		return;
	}
	nodde<t>curr = head;

	if (pos == 1) {
		head = head->next;
		head->prev = nullptr;
		delete curr;
		return;
	}
	for (int i = 0; i < pos - 1 && curr; i++) {
		curr = curr->next;
	}
	if (curr == nullptr) {
		cout << "invalid \n";
		return;
	}
	curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	delete curr;
}
template<class t>
void doublylinkedlist<t>::delette1withitem2(t item) {

}
template<class t>
doublylinkedlist<t>::doublylinkedlist() {
	head = nullptr;
}
template<class t>
doublylinkedlist<t>::~doublylinkedlist() {

}
template<class t>
void doublylinkedlist<t>::reverse2() {
	if (empty2() || head->next == nullptr) {
		return;
	}
	nodde<t>* curr = head;
	nodde<t>* temp = nullptr;


	while (curr != nullptr) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}


	if (temp != nullptr) {
		head = temp->prev;
	}
}
template<class t>
nodde<t>* doublylinkedlist<t>::kthNodeFromEnd(int k) {
	if (empty2() || k <= 0) {
		return nullptr;
	}

	nodde<t>* slow = head;
	nodde<t>* fast = head;


	for (int i = 0; i < k; ++i) {
		if (fast == nullptr) {
			return nullptr;
		}
		fast = fast->next;
	}


	while (fast != nullptr) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{

	/*CircularWithRear<int>* ob1 = new CircularWithRear<int>();
	CircularWithRear<int>* ob2 = new CircularWithRear<int>();
	CircularWithRear<int>* ob3 = new CircularWithRear<int>();
	CircularWithRear<int>* ob4 = new CircularWithRear<int>();
	CircularWithRear<int>* ob5 = new CircularWithRear<int>();
	CircularWithRear<int>* ob6 = new CircularWithRear<int>();


	cout<<ob1->empty1()<<"\n";
	 ob1->insert1(5);
	 ob1->insert1(7);
	 ob1->insert1(0);
	 ob1->insert1(33);
	 ob1->insert1(100);
	 ob1->insert1(11);
	 ob1->print1();
	 cout << "///////////\n";

	ob1->delette1withindex(8);
	ob1->delette1withindex(0);
	ob1->delette1withindex(9);
	cout << "///////////\n";
	ob1->print1();
	ob1->delette1withindex(1);
	ob1->delette1withindex(0);
	ob1->delette1withindex(-1);
	ob1->delette1withindex(100);
	cout << "///////////\n";
	ob1->print1();
	cout << "///////////\n";
	cout << "///////////\n";
	ob1->split1(ob2, ob3);
	ob2->print1();

	cout << "///////////\n";
	ob3->print1();
	cout << "///////////\n";
	ob4->merge1(ob2, ob3, ob4);
	ob4->print1();
	cout << "ikkk\n";*/
	doublylinkedlist<int>* ob1 = new doublylinkedlist<int>();
	ob1->insert2(5, 0);
	ob1->insert2(6, 1);
	ob1->insert2(54, 2);
	ob1->insert2(0, 3);
	ob1->insert2(1, 3);
	ob1->reverse2();
	ob1->print2();


}
