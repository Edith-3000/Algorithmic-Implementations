/*PROBLEM STATEMENT: Given an array, print the Nearest Greater Element to left for every element. 
                     Nearest Greater Element to left for an element x is the first greater element on 
                     the left side of x in array. 
                     Elements for which no greater element exist, consider next greater element as -1. 
*/

#include<bits/stdc++.h>
using namespace std;

// Function which return the NGL elements for every array element
vector<int> ngl_elements(vector<int> &v) {
    int n = (int)v.size();
    if(n <= 0) return v;

    // to store the final result
    vector<int> res(n);

    stack<int> st; 

    for(int i = 0; i < n; i++) {
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
    
    vector<int> res = ngl_elements(v);
    
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

/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

// Function which return the 0-based indices of the NGL elements 
// for every array element
vector<int> ngl_indices(vector<int> &v) {
    int n = (int)v.size();
    if(n <= 0) return v;

    // to store the final result
    vector<int> res(n);

    stack<pair<int, int>> st; 

    for(int i = 0; i < n; i++) {
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
    
    vector<int> res = ngl_indices(v);
    
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