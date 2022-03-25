/* Links: https://www.interviewbit.com/problems/min-stack/
   Ref: https://www.youtube.com/watch?v=Lc8LT_84ZwA&list=PL7JyMDSI2BfYpbzS3sbr1AxFImq8VzfTo&index=8
        https://www.youtube.com/watch?v=ZvaRHYYI0-4

   PROBLEM STATEMENT: Design a Data Structure MinStack that supports all the stack operation like push(),
                      pop(), getMin() (which should return minimum element from the MinStack), the operations
                      of MinStack can be O(n). To implement MinStack, you should only use standard stack data 
                      structure and no other data structure like arrays, list, .. etc.
*/

// METHOD - 1 
// In this method getMin() is implemented in O(1) time using O(n) space.

#include<bits/stdc++.h>
using namespace std;

class MinStack {
	private:
		// data members
		stack<int> s; // main stack
		stack<int> mn; // supporting stack for finding min in O(1) time
	
	public:
		// member functions
		Minstack();
		void push(int x);
		void pop();
		int top();
		int getMin();
};

MinStack::Minstack() {
	while(!s.empty()) s.pop();
	while(!mn.empty()) mn.pop();
}

void MinStack::push(int x) {
	s.push(x);
	if(mn.empty() or mn.top() >= x) mn.push(x);
}

void MinStack::pop() {
	if(s.empty()) return;
	if(mn.top() == s.top()) mn.pop();
	s.pop();
}

int MinStack::top() {
	if(s.empty()) return -1;
	return s.top();
}

int MinStack::getMin() {
	if(mn.empty()) return -1;
	return mn.top();
}

void solve()
{
	MinStack my;
	my.push(3);
    my.push(3);
    cout << my.getMin() << "\n"; 
    my.push(2);
    my.push(2);
    cout << my.getMin() << "\n"; 
    my.pop();
    cout << my.getMin() << "\n"; 
    my.pop();
    cout << my.top() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

/*****************************************************************************************************/

// METHOD - 2
// In this method getMin() is implemented in O(1) time using O(1) space.

// The intuition behind how the formula is being generated in the algorithm can be seen from the comment
// by "Sherwin Dsouza" in the video :--->
// https://www.youtube.com/watch?v=ZvaRHYYI0-4

#include<bits/stdc++.h>
using namespace std;

class MinStack {
	private:
		// data members
		stack<int> s; // main stack
		int mn; // for finding out the minimum value
	
	public:
		// member functions
		Minstack();
		void push(int x);
		void pop();
		int top();
		int getMin();
};

MinStack::Minstack() {
	while(!s.empty()) s.pop();
}

void MinStack::push(int x) {
	if(s.empty()) {
		s.push(x);
		mn = x;
	}
	
	else {
		if(x >= mn) s.push(x);
		else {
			s.push(2 * x - mn);
			mn = x;
		}
	}
}

void MinStack::pop() {
	if(s.empty()) return;
	if(s.top() < mn) mn = 2 * mn - s.top();
	s.pop();
}

int MinStack::top() {
	if(s.empty()) return -1;
	return (s.top() >= mn) ? s.top() : mn;
}

int MinStack::getMin() {
	if(s.empty()) return -1;
	return mn;
}

void solve()
{
	MinStack my;
	my.push(3);
    my.push(3);
    cout << my.getMin() << "\n"; 
    my.push(2);
    my.push(2);
    cout << my.getMin() << "\n"; 
    my.pop();
    cout << my.getMin() << "\n"; 
    my.pop();
    cout << my.top() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

/*  # How does this approach work?
    * When element(x) to be inserted is less than min, we insert “2*x – min”. 
    * The important thing to note is, 2*x – min will always be less than x (proved below), i.e., new min
      and while popping out this element we will see that something unusual has happened as the popped 
      element is less than the minEle. So we will be updating min.

    * How 2*x - minEle is less than x in push()? 
      x < min which means x - min < 0

      // Adding x on both sides
      x - min + x < 0 + x 

	  2*x - min < x 

      ∴ We can conclude 2*x - min < new min 
  ---------------------------------------------------------------------------
  # While popping out, if we find the element(y) less than the current min, we find the 
    new min = 2*min – y.
  # How previous minimum element, prevMin is, 2*min - y ?

    // We pushed y as 2*x - prevMin. Here 
    // prevMin is min before y was inserted
    y = 2*x - prevMin

    // Value of min was made equal to x
    min = x .
    
    new min = 2 * min - y 
            = 2*x - (2*x - prevMin)
            = prevMin // This is what we wanted
*/

/*******************************************************************************************************/

// ANOTHER APPROACH CAN ALSO BE FOUND OUT AT :--->
// https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/