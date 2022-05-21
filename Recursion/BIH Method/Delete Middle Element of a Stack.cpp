#include<bits/stdc++.h>
using namespace std;

void del_mid(stack<int> &s, int k) {
	// base condition
	if(k == 0) return;
	if(k == 1) {
		s.pop();
		return;
	}
	
	int x = s.top();
	s.pop();
	
	// hypothesis
	del_mid(s, k - 1);
	
	// induction
	s.push(x);
}

void solve()
{
  	int n; cin >> n;
  	stack<int> s;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		s.push(x);	
  	}
  	
  	int k = (n & 1) ? (n / 2 + 1) : (n / 2);
  	
  	del_mid(s, k);
  	
  	cout << "Content of stack after deleting middle element :-->\n";
  	
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