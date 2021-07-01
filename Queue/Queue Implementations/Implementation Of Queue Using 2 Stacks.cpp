// Ref: https://www.geeksforgeeks.org/queue-using-stacks/
//      https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=4
/***************************************************************************************************/

// BY MAKING THE enqueue() OPERATION COSTLY

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
	stack<int> s1, s2;
	int cap;
	
	public: 
		MyQueue();
		void enqueue(int num);
		int dequeue();
        int size();
		bool is_empty();
};

MyQueue::MyQueue() {
	while(!s1.empty()) s1.pop();
	while(!s2.empty()) s2.pop();
	cap = 0;
}

void MyQueue::enqueue(int num) {
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	
	s1.push(num);
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	
	cap += 1;
}

int MyQueue::dequeue() {
	if(cap == 0) {
		cout << "Queue empty!";
		return INT_MAX;
	}

	else {
		int x = s1.top();
		s1.pop(), cap -= 1;
		return x;
	}
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
  	q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(49);
    q.enqueue(-107);
    q.enqueue(13);
    
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
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

/**************************************************************************************************/

// NOTE: This can also be implemented BY MAKING THE dequeue() OPERATION COSTLY in which the 
//       time complexity of enqueue() is O(1) and amortized time complexity of dequeue is O(1).
//       For more details refer GfG article. 