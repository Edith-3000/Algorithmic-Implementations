/* # A Segment Tree is build up in a bottom-up manner
   # It can be represented using an array like data strucutre.
*/

// In the below algorithm segment tree vertex stores the min element in the segment which is represented 
// by that vertex

// The height of the segment tree build will be O(log(n) to base 2), where n are #elements in the array.

#include<bits/stdc++.h>
using namespace std;

// t[ind] is resposnible for storing the result of the segment v[tl......tr]
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
    // (4 * n + 1) nodes in the corresponding segment tree
    vector<int> t(4 * n + 1);
    
    // ind = the index of the current vertex (starting from 1 
    //       & can go upto (4 * n + 1))
    // tl = left boundary of the current segment
    // tr = right boundary of the current segment
    build_seg_tree(v, t, 0, n-1, 1);
    
    cout << "\nLinear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
    
    return 0;
}

// Time Complexity of build_seg_tree(): O(n), where n are #elements in the array.

/* Sample i/p: 6
			   1 3 2 -5 6 4 

   Sample o/p: Enter the size of array for which Segment Tree is to be constructed: ---> 6
		       Enter the elements: ---> 1 3 2 -5 6 4 

		       Linear representation of Segment Tree --->
		       0 -5 1 -5 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 
*/