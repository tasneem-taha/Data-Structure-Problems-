#include <iostream>
#include <algorithm>
using namespace std;

template<class q>
class priorityqueue {
    long long length;
    long long size;
    q* queue;
public:
    priorityqueue();
    priorityqueue(int);
    bool isempty();
    bool isfull();
    void enqueue(q item);
    void dequeue();
    void print();
    ~priorityqueue();
};

template<class q>
priorityqueue<q>::priorityqueue() {
    length = 0;
    cout << "size by default equal 10\n";
    size = 10;
    queue = new     q[size];
}

template<class q>
priorityqueue<q>::priorityqueue(int x) : size(x) {
    queue = new q[size];
}

template<class q>
bool priorityqueue<q>::isempty() {
    return length == 0;
}

template<class q>
bool priorityqueue<q>::isfull() {
    return length == size-1;
}

template<class q>
void priorityqueue<q>::enqueue(q item) {
    if (isfull()) {
        cout << "Queue is full\n";
        return;
    }
    queue[length++] = item;
    sort(queue, queue + length);
}

template<class q>
void priorityqueue<q>::dequeue() {
    if (isempty()) {
        cout << "Queue is empty\n";
        return;
    }
 
    length--;
}

template<class q>
void priorityqueue<q>::print() {
    for (int i = length - 1; i >= 0; i--) {
        cout << queue[i] << ' ';
    }
    cout << '\n';
}

template<class q>
priorityqueue<q>::~priorityqueue() {
    delete[]queue;
}

int main() {
    priorityqueue<int> pq;
    pq.enqueue(10);
    pq.enqueue(90);
    pq.enqueue(0);
    pq.enqueue(9);
    pq.enqueue(100);
    pq.print();

    return 0;
}
