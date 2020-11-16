#include<bits/stdc++.h>
using namespace std;

void build_seg_tree(vector<int> &v, vector<int> &t, int tl, int tr, int ind)
{
	// base case
	if(tl == tr){
		t[ind] = v[tl];
		return;
	}
	
	// similar to postorder traversal
	
	// segment representing [tl....mid]
	build_seg_tree(v, t, tl, (tl + tr)/2, 2 * ind); 
	// segment representing [(mid+1)....tr]
	build_seg_tree(v, t, (tl + tr)/2 + 1, tr, 2 * ind + 1);
	
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	return;
}

int query_seg_tree(vector<int> &t, int tl, int tr, int ql, int qr, int ind)
{
	// Case 1: complete overlap
	if((tl >= ql) && (tr <= qr)){
		return t[ind];
	}
	
	// Case 2: no overlap
	if((qr < tl) || (ql > tr)){
		return INT_MAX;
	}
	
	// Case 3: partial overlap
	int mid = (tl + tr)/2;
	int left = query_seg_tree(t, tl, mid, ql, qr, 2 * ind);
	int right = query_seg_tree(t, mid + 1, tr, ql, qr, 2 * ind + 1);
	return min(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the size of array for which Segment Tree is to be constructed: ---> ";
    int n; cin >> n; cout << n << "\n";
    
    vector<int> v(n);
    cout << "Enter the elements: ---> ";
    for(int  i = 0; i < n; i++){
    	cin >> v[i];
    }
    
    for(auto x: v) cout << x << " ";
    cout << "\n";
    
    // underlying vector used for representing segment tree in 
    // linear space. An array of size n can have approx. around
    // (4 * n + 1) nodes in the corresponding sement tree
    vector<int> t(4 * n + 1);
    
    // ind = the index of the current vertex (starting from 1 
    //       & can go upto (4 * n + 1))
    // tl = left boundary of the current segment
    // tr = right boundary of the current segment
    build_seg_tree(v, t, 0, n-1, 1);
    
    cout << "\nLinear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
    
    cout << "\n\nEnter the #queries ---> ";
    int q; cin >> q; cout << q << "\n";
    
    cout << "Enter left and right indices for the queries(0-based indexing) --->\n";
    while(q--){
    	int ql, qr; cin >> ql >> qr;
    	cout << "Min ele in the range [" << ql << ", " << qr << "] = ";
    	cout << query_seg_tree(t, 0, n - 1, ql, qr, 1) << "\n";
    }
    
    return 0;
}

// Time Complexity of query_seg_tree():

/* Sample i/p: 6
               1 3 2 -5 6 4
               5
               0 5
               1 3
               4 4
               2 4
               4 5

   Sample o/p: Enter the size of array for which Segment Tree is to be constructed: ---> 6
               Enter the elements: ---> 1 3 2 -5 6 4 

               Linear representation of Segment Tree --->
               0 -5 1 -5 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 

               Enter the #queries ---> 5
               Enter left and right indices for the queries(0-based indexing) --->
               Min ele in the range [0, 5] = -5
               Min ele in the range [1, 3] = -5
               Min ele in the range [4, 4] = 6
               Min ele in the range [2, 4] = -5
               Min ele in the range [4, 5] = 4
*/