// Ref: https://www.geeksforgeeks.org/implement-stack-queue-using-deque/
/*****************************************************************************************************/

// NOTE: With queue, stack has also been implemented in the below algorithm.

#include <bits/stdc++.h>
using namespace std;

// structure for a node of deque
// internally a deque is implemented using doubly linked list
struct DQueNode {
	DQueNode* next;
	int value;
	DQueNode* prev;
};

// Implementation of deque class
class Deque {
	private:
		// pointers to head and tail of deque
		DQueNode* head;
		DQueNode* tail;

	public:
		// constructor
		Deque() {
			head = tail = NULL;
	   }

		// if list is empty
		bool isEmpty() {
			if (head == NULL) return true;
			return false;
	    }

		// count the number of nodes in list
		int size() {
			// if list is not empty
			if (!isEmpty()) {
				DQueNode* temp = head;
				int len = 0;
				while (temp != NULL) {
					len++;
					temp = temp->next;
			    }
			    
				return len;
		    }
		    
			return 0;
	    }

		// insert at the first position
		void insert_first(int element) {
			// allocating node of DQueNode type
			DQueNode* temp = new DQueNode;
			temp->value = element;

			// if the element is first element
			if (head == NULL) {
				head = tail = temp;
				temp->next = temp->prev = NULL;
		    }
		    
			else {
				head->prev = temp;
				temp->next = head;
				temp->prev = NULL;
				head = temp;
		    }
	    }

		// insert at last position of deque
		void insert_last(int element)  {
			// allocating node of DQueNode type
			DQueNode* temp = new DQueNode;
			temp->value = element;

			// if element is the first element
			if (head == NULL) {
				head = tail = temp;
				temp->next = temp->prev = NULL;
		    }
		    
			else {
				tail->next = temp;
				temp->next = NULL;
				temp->prev = tail;
				tail = temp;
		    }
	    }

		// remove element at the first position
		void remove_first() {
			// if list is not empty
			if (!isEmpty()) {
				DQueNode* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
				return;
		    }
		    
			cout << "List is Empty" << endl;
	    }

		// remove element at the last position
		void remove_last() {
			// if list is not empty
			if (!isEmpty()) {
				DQueNode* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				return;
		    }
		    
			cout << "List is Empty" << endl;
	    }

		// displays the elements in deque
		void display() {
			// if list is not empty
			if (!isEmpty()) {
				DQueNode* temp = head;
				while (temp != NULL) {
					cout << temp->value << " ";
					temp = temp->next;
			    }
			    
				cout << "\n";
				return;
		    }
		
			cout << "List is Empty" << endl;
	    }
};

// Class to implement stack using Deque
// "Stack" is child class inherited from "deque" base class
class Stack : public Deque {
	public:
		// push to push element at top of stack
		// using insert at last function of deque
		void push(int element) {
			insert_last(element);
	    }

		// pop to remove element at top of stack
		// using remove at last function of deque
		void pop() {
			remove_last();
	   }
};

// class to implement queue using deque
// "Queue" is child class inherited from "deque" base class
class Queue : public Deque {
	public:
		// enqueue to insert element at last
		// using insert at last function of deque
		void enqueue(int element) {
			insert_last(element);
	    }

		// dequeue to remove element from first
		// using remove at first function of deque
		void dequeue() {
			remove_first();
	    }
};

int solve()
{
	// object of Stack
	Stack stk;

	// push 7 and 8 at top of stack
	stk.push(7);
	stk.push(8);
	cout << "Stack: ";
	stk.display();

	// pop an element
	stk.pop();
	cout << "Stack: ";
	stk.display();
	
	// object of Queue
	Queue que;

	// insert 12 and 13 in queue
	que.enqueue(12);
	que.enqueue(13);
	cout << "Queue: ";
	que.display();

	// delete an element from queue
	que.dequeue();
	cout << "Queue: ";
	que.display();

	cout << "Size of Stack is " << stk.size() << endl;
	cout << "Size of Queue is " << que.size() << endl;
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}