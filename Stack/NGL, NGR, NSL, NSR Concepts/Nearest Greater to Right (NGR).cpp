/* PROBLEM STATEMENT: Given an array, print the Next Greater Element (NGE) for every element. The Next
                      greater Element for an element x is the first greater element on the right side of x 
                      in array. Elements for which no greater element exist, consider next greater element 
                      as -1. 
*/

// BRUTE FORCE APPROACH = O(n²)

/******************************************************************************************************************************************************/

// EFFICENT APPROACH

/* UNDERLYING CONCEPT ----->
   # There are 3 conditions which are to be checked ->
       1. If stack.size() == 0, push -1 in the result vector res.
       2. If stack.top() > v[i], push stack.top() in the resul vector res.
       3. If stack.top() <= v[i], perform stack.pop() until the stack is empty or stack.top()>v[i],
           if stack.top() > v[i], push stack.top() in the result vector res
           else push -1 in the result vector res.
*/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

// Function which return the NGR elements for every array element
vector<int> ngr_elements(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<int> st; 

	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) res[i] = -1;
		else if(st.top() > v[i]) res[i] = st.top();

		else {
			while(!st.empty() && st.top() <= v[i]) st.pop();

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
  	
  	vector<int> res = ngr_elements(v);

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

/******************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

// Function which return the 0-based indices of the NGR elements 
// for every array element
vector<int> ngr_indices(vector<int> &v) {
    int n = (int)v.size();
    if(n <= 0) return v;

    // to store the final result
    vector<int> res(n);
  
    stack<pair<int, int>> st; 

    for(int i = n - 1; i >= 0; i--) {
        if(st.empty()) res[i] = -1;
        else if(st.top().F > v[i]) res[i] = st.top().S;

        else {
            while(!st.empty() && st.top().F <= v[i]) st.pop();

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
    
    vector<int> res = ngr_indices(v);
    
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