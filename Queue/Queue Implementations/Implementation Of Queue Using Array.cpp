// Ref: https://www.youtube.com/watch?v=M6GnoUDpqEE&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=2

// Prob: https://leetcode.com/problems/design-circular-queue/
/****************************************************************************************************************************************************************/

// METHOD - 1

// Inefficient implementation ===>
// https://pastebin.com/E6cFtCYr

/****************************************************************************************************************************************************************/

// METHOD - 2

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;

class MyQueue {
	int L, R, cap;
	int a[MAX];
	
	public: 
		MyQueue();
		void push(int num);
		void pop();
		int front();
		int rear();
		int size();
		bool is_empty();
};

MyQueue::MyQueue() {
	L = R = 0;
	cap = 0;
}

void MyQueue::push(int num) {
	if(cap == MAX) {
		cout << "Queue overflow!\n";
		return;
	}
	
	a[R] = num;
	R = (R + 1) % MAX;
	cap++;
}

void MyQueue::pop() {
	if(cap == 0) {
		cout << "Queue empty!\n";
		return;	
	}
	
	L = (L + 1) % MAX;
	cap--;
}

int MyQueue::front() {
	if(cap == 0) cout << "Queue empty!\n";
	else return a[L];
}

int MyQueue::rear() {
	if(cap == 0) cout << "Queue empty!\n";
	else return a[(R - 1 + MAX) % MAX];
}

int MyQueue::size() {
	return cap;
}

bool MyQueue::is_empty() {
	return cap == 0;
}

void solve()
{
  	MyQueue q;
  	q.push(10);
    q.push(20);
    q.push(30);
    q.push(49);
    q.push(-107);
    q.push(13);
    
    cout << q.front() << " is the front element of queue\n";
    cout << q.rear() << " is the rear element of queue\n";
    
    q.pop();
    cout << "Size of queue: " << q.size() << "\n";
    
    // print all elements in stack :
    cout << "Elements present in queue: ";
    
    while(!q.is_empty()) {
        // print top element in stack
        cout << q.front() << " ";
        // remove top element in stack
        q.pop();
    }
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