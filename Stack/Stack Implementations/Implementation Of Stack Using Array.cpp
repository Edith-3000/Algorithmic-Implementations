// Ref: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//      https://www.youtube.com/watch?v=GYptUgnIM_I&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=1
/**********************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;

class MyStack {
	int idx;
	int a[MAX];
	
	public: 
		MyStack();
		void push(int num);
		void pop();
		int top();
        int size();
		bool is_empty();
};

MyStack::MyStack() {
	idx = -1;
}

void MyStack::push(int num) {
	if(idx >= MAX - 1) cout << "Stack overflow!\n";
	else a[++idx] = num;
}

void MyStack::pop() {
	if(idx >= 0) idx--;
}

int MyStack::top() {
	if(idx < 0) cout << "Stack empty!\n";
	else return a[idx];
}

int MyStack::size() {
    return idx + 1;
}

bool MyStack::is_empty() {
	return idx == -1;
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