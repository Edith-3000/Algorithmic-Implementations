#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

void insert_last(vi &v, int lst) {
	// base condition(s)
	if(v.size() == 0 or v[v.size() - 1] <= lst) {
		v.push_back(lst);
		return;
	}
	
	int x = v[v.size() - 1];
	v.pop_back();
	
	// hypothesis
	insert_last(v, lst);
	
	// induction
	v.push_back(x);
}

void sort_array(vi &v) {
	// base condition(s)
	if(v.size() <= 1) return;
	
	int lst = v[v.size() - 1];
	v.pop_back();
	
	// hypothesis
	sort_array(v);
	
	// induction
	insert_last(v, lst);
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	sort_array(v);
  	
  	cout << v.size() << "\n";
  	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  	
  	cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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