// Ref: https://www.youtube.com/watch?v=8YXQ68oHjAs
/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void insert_last(stack<int> &s, int key) {
	// base ondition
	if(s.size() == 0) {
		s.push(key);
		return;
	}
	
	int y = s.top();
	s.pop();
	
	// hypothesis
	insert_last(s, key);
	
	// induction
	s.push(y);
}

void rev_stack(stack<int> &s) {
	// base condition
	if(s.size() <= 1) return;
	
	int x = s.top();
	s.pop();
	
	// hypothesis
	rev_stack(s);
	
	// induction
	insert_last(s, x);
}

void solve()
{
  	int n; cin >> n;
  	stack<int> s;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		s.push(x);	
  	}
  	
  	rev_stack(s);
  	
  	cout << "Content of stack after reversing:-->\n";
  	
  	while(!s.empty()) {
  		cout << s.top() << " ";
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

// Time complexity: O(n^2) (worst case)