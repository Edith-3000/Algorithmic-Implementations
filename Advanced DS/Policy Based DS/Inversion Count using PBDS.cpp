/* Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
   If array is already sorted then inversion count is 0. 
   If array is sorted in reverse order that inversion count is the maximum. 
   Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
*/

// Refer for more clarification: https://www.geeksforgeeks.org/counting-inversions/

// So basically for every index 'j' we've to find all the indices 'i' (from 0 to (j-1)), such that 
// a[i] > a[j]

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// pair<int, int> is taken so as to take care of array containing
// duplicate elements
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> PBDS;
        
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    PBDS st;
    
    int inversion_cnt = 0; // for storing the result
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        inversion_cnt += (st.size() - st.order_of_key({x, i}));
        st.insert({x, i});
    }
    
    cout << inversion_cnt;
}

// Time complexity: O(n x log(n))

/* Sample i/p: 5
               1 20 6 4 5
   
   Sample o/p: 5
*/