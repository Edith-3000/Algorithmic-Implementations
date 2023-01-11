// Ref: https://www.geeksforgeeks.org/implement-stack-using-queue/
//      http://stackoverflow.com/questions/688276/implement-stack-using-two-queues
//      https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=3
/************************************************************************************************************************************************/

// BY MAKING THE push() OPERATION COSTLY

#include<bits/stdc++.h>
using namespace std;

class MyStack {
	queue<int> q1, q2;
	int cap;
	
	public: 
		MyStack();
		void push(int num);
		void pop();
		int top();
        int size();
		bool is_empty();
};

MyStack::MyStack() {
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	cap = 0;
}

void MyStack::push(int num) {
	q2.push(num);
	while(!q1.empty()) {
		q2.push(q1.front());
		q1.pop();
	}
	
	queue<int> tmp = q1;
	q1 = q2;
	q2 = tmp;
	
	cap += 1;
}

void MyStack::pop() {
	if(cap == 0) cout << "Stack empty!\n";
	else q1.pop(), cap -= 1;
}

int MyStack::top() {
	if(cap == 0) {
		cout << "Stack empty!";
		return INT_MAX;
	}
	
	else return q1.front();
}

int MyStack::size() {
    return cap;
}

bool MyStack::is_empty() {
	return cap == 0;
}

void solve()
{
  	MyStack s;
  	s.push(10);
    s.push(20);
    s.push(30);
    s.push(49);
    s.push(-107);
    s.push(13);
    
    cout << s.top() << " is the top element of stack\n";
    
    // print all elements in stack :
    cout << "Elements present in stack : ";
    
    while(!s.is_empty()) {
        // print top element in stack
        cout << s.top() << " ";
        // remove top element in stack
        s.pop();
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