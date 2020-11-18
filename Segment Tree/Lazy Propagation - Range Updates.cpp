/* # Lazy Propagation is basically optimization to perform 'range updates' in Segment Tree in O(log(n)) instead
     of O(n) time.
   # Idea behind Lazy Propagation is to postpone the updates to the descendents of a node until the descendents
     themselves need to be accessed.
*/

#include<bits/stdc++.h>
using namespace std;

void build_seg_tree(vector<int> &t, vector<int> &v, int tl, int tr, int ind)
{
	if(tl == tr){
		t[ind] = v[tl];
		return;
	}
	
	int mid = (tl + tr)/2;
	build_seg_tree(t, v, tl, mid, 2 * ind);
	build_seg_tree(t, v, mid + 1, tr, 2 * ind + 1);
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	return;
}

void lazy_range_update_seg_tree(vector<int> &t, vector<int> &lazy, int tl, int tr, int l, int r, int change, int ind)
{
	// before going down resolve the lazy value of the current
	// node if it exists
	if(lazy[ind] != 0){
		t[ind] += lazy[ind];
		
		// if this node is non-leaf node
		// pass it's lazy value to it's children
		if(tl != tr){
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] +=lazy[ind];
	    }
	    
	    // clear the lazy value of current node
	    lazy[ind] = 0;
	}
		
	// bases cases
	
	// Case 1: no overlap
	if((r < tl) || (l > tr)){
		return;
	}
	
	// Case 2: complete overlap (this is the case where code 
	//         is being optimized as we are returning from here
	//         w/o actually updating the children in the segment tree,
	//         instead their changed value is just being stored in the lazy array)
	if((tl >= l) && (tr <= r)){
		t[ind] += change;
		
		// if children node(s) exist then create a new lazy
		// value for the children
		if(tl != tr){
			lazy[2 * ind] += change;
			lazy[2 * ind + 1] += change;
		}
		
		return;
	}
	
	// recursive case (Case 3: partial overlap)
	int mid = (tl + tr)/2;
	lazy_range_updates_seg_tree(t, lazy, tl, mid, l, r, change, 2 * ind);
	lazy_range_updates_seg_tree(t, lazy, mid + 1, tr, l, r, change, 2 * ind + 1);
	
	// update t[ind] in the returning phase
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
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
    
    build_seg_tree(t, v, 0, n - 1, 1);
    
    cout << "\nLinear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
    
    cout << "\n\nEnter the range i.e. l, r(0-based indexing) to be updated ---> ";
    int l, r; cin >> l >> r; 
    cout << "[" << l << ", " << r << "]" << "\n";
    cout << "Value by which the increment/decrement to be done ---> ";
    int change; cin >> change; cout << change << "\n";
    
    // vector to store the lazy values for all the Segment Tree nodes
    vector<int> lazy(4 * n + 1);
    lazy_range_updates_seg_tree(t, lazy, 0, n - 1, l, r, change, 1);
    
    cout << "\nUpdated linear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";  
}

// Time complexity: O(log(n))

/* Sample i/p: 6
               1 3 2 -5 6 4
               3 5
               +20

   Sample o/p: Enter the size of array for which Segment Tree is to be constructed: ---> 6
               Enter the elements: ---> 1 3 2 -5 6 4 

               Linear representation of Segment Tree --->
               0 -5 1 -5 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 

               Enter the range i.e. l, r(0-based indexing) to be updated ---> [3, 5]
               Value by which the increment/decrement to be done ---> 20

               Updated linear representation of Segment Tree --->
               0 1 1 15 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 
*/