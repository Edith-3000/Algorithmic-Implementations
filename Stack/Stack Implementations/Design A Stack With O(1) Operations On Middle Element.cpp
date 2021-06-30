// Problem: https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
/***************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class DLLnode {
	public:
		DLLnode *prev;
		int data;
		DLLnode *next;
};

class MyStack {
	DLLnode *head, *mid;
	int cnt;
	
	public: 
		MyStack();
		void push(int num);
		int pop();
		int find_middle();
		void delete_middle();
};

MyStack::MyStack() {
	head = NULL; mid = NULL;
	cnt = 0;
}

void MyStack::push(int num) {
	DLLnode *tmp = new DLLnode;
	tmp->data = num;
	tmp->prev = tmp->next = NULL;
	
	if(cnt == 0) {
		head = tmp;
		mid = tmp;
	}
	
	else {
		head->next = tmp;
		tmp->prev = head;
		
		if(cnt & 1) mid = mid->next;
		head = head->next;
	}
	
	cnt += 1;
}

int MyStack::pop() {
	if(cnt == 0) cout << "Stack empty!\n";
	else {
		DLLnode *tmp = head;
		head = head->prev;
		if(head != NULL) head->next = NULL;
		else mid = NULL;
		cnt -= 1;
		if(cnt & 1) mid = mid->prev;
		int x = tmp->data;
		delete tmp;
		return x;
	}
	
}

int MyStack::find_middle() {
	if(cnt == 0) cout << "Stack empty!\n";
	else return mid->data;
}

void MyStack::delete_middle() {
	if(cnt == 0) cout << "Stack empty!\n";
	
	else if(cnt == 1) {
		DLLnode *tmp = mid;
		mid = head = NULL;
		delete tmp;	
		cnt -= 1;
	}
	
	else {
		DLLnode *tmp = mid;
		mid->prev->next = mid->next;
		if(mid->next->prev) mid->next->prev = mid->prev;
		if(cnt & 1) mid = mid->next;
		else mid = mid->prev;
		cnt -= 1;
		if(cnt == 1) head = mid;
		delete tmp;
	}
}

void solve()
{
  	MyStack s;
  	s.push(11);
  	s.push(12);
  	s.push(145);
  	s.push(-40);
  	s.push(7);
  	s.push(10);
  	
  	cout << "Mid element: " << s.find_middle() << "\n";
  	s.delete_middle();
  	
  	cout << "Element popped: " << s.pop() << "\n";
  	cout << "Element popped: " << s.pop() << "\n";
  	
  	cout << "Mid element: " << s.find_middle() << "\n";
  	s.delete_middle();
  	
  	s.push(9);
  	cout << "Mid element: " << s.find_middle() << "\n";
  	
  	cout << "Element popped: " << s.pop() << "\n";
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