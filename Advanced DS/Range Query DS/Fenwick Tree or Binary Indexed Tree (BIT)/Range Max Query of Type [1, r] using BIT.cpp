// NOTE: Using BIT we can answer only answer Range Max Queries of the type [1, r], where r 
// is from [1, n]

#include<bits/stdc++.h>
using namespace std;

void bit_update(vector<int> &bit, int i, int val)
{
	int n = bit.size();
	
	while(i <= n){
		bit[i] = max(bit[i], val);
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
	int res = INT_MIN;
	
	while(k > 0){
		res = max(res, bit[k]);
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
    vector<int> bit(n + 1, INT_MIN);
    bit_build(bit, v);
	
	cout << "\n\nEnter the number of queries: ";
	int q; cin >> q; cout << q << "\n";
	cout << "Enter the 1 to r of queries (1-based indexing)\n";
	while(q--){
		int l, r; cin >> l >> r;
		cout << "Sum of nums from index(1-based indexing) [" << l << ", " << r << "] = "; 
		cout << bit_query(bit, r) << "\n";
	}
	
    return 0;
}

/* Sample i/p: 5
		       2 3 1 4 7
		       3
		       1 2
		       1 4
		       1 5

   Sample o/p: Enter the number of elements in the array: 5
               Enter the array elements: 0 2 3 1 4 7 

               Enter the number of queries: 3
               Enter the 1 to r of queries (1-based indexing)
               Sum of nums from index(1-based indexing) [1, 2] = 3
               Sum of nums from index(1-based indexing) [1, 4] = 4
               Sum of nums from index(1-based indexing) [1, 5] = 7
*/