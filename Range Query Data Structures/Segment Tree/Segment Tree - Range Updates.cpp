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

void point_update_seg_tree(vector<int> &t, int tl, int tr, int p, int change, int ind)
{
	// case to handle when p is out of bounds
	// of the current segment
	if((p < tl) || (p > tr)){
		return;
	}
	
	// when p == tl == tr, perform update 
	if(tl == tr){
		t[ind] += change;
		return;
	}
	
	int mid = (tl + tr)/2;
	point_update_seg_tree(t, tl, mid, p, change, 2 * ind);
	point_update_seg_tree(t, mid + 1, tr, p, change, 2 * ind + 1);
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
}

void range_update_seg_tree(vector<int> &t, int tl, int tr, int l, int r, int change_in_range, int ind)
{
	// base cases (ordering of the 2 bases cases is imp)
	
	// if no overlapping
	if((r < tl) || (l > tr)){
		return;
	}
	
	// if leaf node
	if(tl == tr){
		t[ind] += change_in_range;
		return;
	}
	
	int mid = (tl + tr)/2;
	range_update_seg_tree(t, tl, mid, l, r, change_in_range, 2 * ind);
	range_update_seg_tree(t, mid + 1, tr, l, r, change_in_range, 2 * ind + 1);
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	return;
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
    
    cout << "\nEnter the point(or index, 0-based indexing) to be updated ---> ";
    int p; cin >> p; cout << p << "\n";
    cout << "Value by which the increment/decrement to be done ---> ";
    int change; cin >> change; cout << change << "\n";
    
    point_update_seg_tree(t, 0, n-1, p, change, 1);
    cout << "\nUpdated linear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
    
    cout << "\nEnter the range i.e. l, r(0-based indexing) to be updated ---> ";
    int l, r; cin >> l >> r; 
    cout << "[" << l << ", " << r << "]" << "\n";
    cout << "Value by which the increment/decrement to be done ---> ";
    int change_in_range; cin >> change_in_range; cout << change_in_range << "\n";
    
    range_update_seg_tree(t, 0, n-1, l, r, change_in_range, 1);
    cout << "\nUpdated linear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";    
    
    return 0;
}

// Time Complexity of range_update_seg_tree(): O(n), since in the worst case we may be updating all (4 x n)
// vertices of the Segment Tree.

/* Sample i/p: 6
               1 3 2 -5 6 4
               5
               0 5
               1 3
               4 4
               2 4
               4 5
               2
               -20
               3 5
               -26

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

               Enter the point(or index, 0-based indexing) to be updated ---> 2
               Value by which the increment/decrement to be done ---> -20

               Updated linear representation of Segment Tree --->
               0 -18 -18 -5 1 -18 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 
               Enter the range i.e. l, r(0-based indexing) to be updated ---> [3, 5]
               Value by which the increment/decrement to be done ---> -26

               Updated linear representation of Segment Tree --->
               0 -31 -18 -31 1 -18 -31 -22 1 3 0 0 -31 -20 0 0 0 0 0 0 0 0 0 0 0 
*/