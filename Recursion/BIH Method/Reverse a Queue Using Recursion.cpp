// Problem: https://www.geeksforgeeks.org/reversing-queue-using-recursion/
/******************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void rev_queue(queue<int> &q) {
	// base condition
	if(q.size() <= 1) return;
	
	int x = q.front();
	q.pop();
	
	// hypothesis
	rev_queue(q);
	
	// induction
	q.push(x);
}

void solve()
{
  	int n; cin >> n;
  	queue<int> q;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		q.push(x);	
  	}
  	
  	rev_queue(q);
  	
  	cout << "Content of queue after sorting:-->\n";
    
  	while(!q.empty()) {
  		cout << q.front() << " ";
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