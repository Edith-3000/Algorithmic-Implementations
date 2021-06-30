// Ref: https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;

class twoStacks {
	int idx1, idx2;
	int a[MAX];
	
	public: 
		twoStacks();
		void push1(int num);
		void push2(int num);
		int pop1();
		int pop2();
};

twoStacks::twoStacks() {
	idx1 = -1;
	idx2 = MAX;
}

void twoStacks::push1(int num) {
	if(idx2 - idx1 > 1) a[++idx1] = num;
	else cout << "Stack overflow!\n";
}

void twoStacks::push2(int num) {
	if(idx2 - idx1 > 1) a[--idx2] = num;
	else cout << "Stack overflow!\n";
}

int twoStacks::pop1() {
	if(idx1 >= 0) {
		int x = a[idx1];
		idx1--;
		return x;
	}
	
	else {
		cout << "Stack empty!\n";
		exit(1);
	}
}

int twoStacks::pop2() {
	if(idx2 < MAX) {
		int x = a[idx2];
		idx2++;
		return x;
	}
	
	else {
		cout << "Stack empty!\n";
		exit(1);
	}
}

void solve()
{
  	twoStacks ts;
  	
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    
    cout << "Popped element from stack1 is " << ts.pop1() << "\n";
    ts.push2(40);
    
    cout << "Popped element from stack2 is " << ts.pop2() << "\n";
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