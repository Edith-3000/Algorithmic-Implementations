/*PROBLEM STATEMENT: Given an array of integers, find the nearest smaller number for every element such that 
                     the smaller element is on right side.
*/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

// Function which return the NSR elements for every array element
vector<int> nsr_elements(vector<int> &v)
{
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<int> st; 

	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) res[i] = -1;
		else if(st.top() < v[i]) res[i] = st.top();

		else if(st.top() >= v[i]) {
			while(!st.empty() && st.top() >= v[i]) st.pop();

			if(st.empty()) res[i] = -1;
			else res[i] = st.top();
		}

		st.push(v[i]);
	}

	// return the final res vector
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vector<int> res = nsr_elements(v);
  	
  	for(int i = 0; i < n; i++) {
  		cout << res[i] << " ";
  	}
  	
  	cout << "\n";
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

/*# Time Complexity: O(n), where n is v.size()
  # Space Complexity: O(n): The worst case occurs when all elements are sorted in increasing order,
   						    as in this case the stack size will be 'n'.
*/

/****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

// Function which return the 0-based indices of the NSR elements 
// for every array element
vector<int> nsr_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 

	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) res[i] = -1;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else if(st.top().F >= v[i]) {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = -1;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vector<int> res = nsr_indices(v);
  	
  	for(int i = 0; i < n; i++) {
  		cout << res[i] << " ";
  	}
  	
  	cout << "\n";
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