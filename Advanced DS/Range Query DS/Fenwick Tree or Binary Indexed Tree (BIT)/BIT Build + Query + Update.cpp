// bit = binary indexed tree/fenwick tree
// basically BIT is used for Prefix Sum type of queries.

#include<bits/stdc++.h>
using namespace std;

void bit_update(vector<int> &bit, int i, int change)
{
	int n = bit.size();
	
	while(i <= n){
		bit[i] += change;
		i += (i & (-i));
	}
}

void bit_build(vector<int> &bit, vector<int> &v)
{
	int n = v.size();
	
	for(int  i = 1; i <= n; i++){
		bit_update(bit, i, v[i]);
	}
}

int bit_query(vector<int> &bit, int k)
{
	int res = 0;
	
	while(k > 0){
		res += bit[k];
		k -= (k & (-k));
	} 
	
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the number of elements in the array: ";
    int n; cin >> n; cout << n << "\n";
    
    cout << "Enter the array elements: ";
    
    // remember in BIT we always use 1 based indexing
    vector<int> v(n + 1); 
    for(int  i = 1; i <= n; i++){
    	cin >> v[i];
    }
    
    for(auto x: v) cout << x << " ";
    
    // the 0th index is not used in BIT 
    // therefore 1 based indexing is used
    vector<int> bit(n + 1, 0);
    bit_build(bit, v);
	
	cout << "\nEnter the number of queries: ";
	int q; cin >> q; cout << q << "\n";
	cout << "Enter the l, r of queries (1-based indexing)\n";
	while(q--){
		int l, r; cin >> l >> r;
		cout << "Sum of nums from index(1-based indexing) [" << l << ", " << r << "] = "; 
		cout << bit_query(bit, r) - bit_query(bit, l - 1) << "\n";
	}
	
    return 0;
}

// Time complexities: -----> 
// bit_update = O(log(n))
// bit_build = O(n x log(n)), since we're using bit_update function n times
// bit_query = O(log(n))

// Space complexity: O(n)
// in above statements n = v.size()

/* Sample i/p: 5
		       2 3 1 4 7
		       3
		       1 2
		       2 4
		       1 5

   Sample o/p: Enter the number of elements in the array: 5
			   Enter the array elements: 0 2 3 1 4 7 
			   Enter the number of queries: 3
			   Enter the l, r of queries (1-based indexing)
			   Sum of nums from index(1-based indexing) [1, 2] = 5
			   Sum of nums from index(1-based indexing) [2, 4] = 8
			   Sum of nums from index(1-based indexing) [1, 5] = 17
*/