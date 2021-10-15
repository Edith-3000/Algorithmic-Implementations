// Ref: https://unacademy.com/class/descent-in-segment-tree-problems/T2M5NK9L

// Raw code of below algorithm: https://pastebin.com/gUu5ugbL
// Prob. based on this concept: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D

/***************************************************************************************************************

# This technique is generally used when we make use of binary search on a segment tree, thus this technique
  reduces the time complexity from O((log(n)) ^ 2) to O(log(n)).

/***************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
KEYNOTES:
------------------------------------------------------------------------------------------
merge(X,identity_element) = X
------------------------------------------------------------------------------------------
// (i.e no transformation at all or if we combine any new update with the identity update
// it should give the newer update)
identity_transformation.combine(X) = X
------------------------------------------------------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------------------------------------------------------
*/

// this structure depends on the nature of query 
struct node {
	// 1. change(s) required
	// use more variables if you want more information
	// these default values should be identity_element
	
		
	node() {}
	node(int ) {
		// 2. change(s) required
		
	}
	
	// associative merging function, store the thing you wanna query
	void merge(node &l, node &r){ 
		// 3. change(s) required
		
	}
	
	bool check(int x) {
		// 4. change(s) required
		
	}
};

// this structure depends on the nature of update
struct update {
	// 5. change(s) required
	// use more variables if you want more information
	// these default values should be identity_transformation or identity_update
	
	
	update() {}
	update(int ) {
		// 6. change(s) required
		
	}
	
	// combine the current update with the other update (see keynotes)
	// basically combine older lazy value(s) (if exist) with newer one(s).
	// for this function, you can be sure that the "other" is newer than current
	void combine(update &other, int &tl, int &tr) {
		// 7. change(s) required
		
	}
	
	// store the correct information in the node x
	void apply(node &x, int &tl, int &tr) {
		// 8. change(s) required
		
	}
};

template<typename node, typename update>
struct segtree {
	int len;
	bool built;
	node zero;
	update noop;
	vector<node> t;
	vector<update> upds;
	vector<int> tl, tr;
	vector<bool> lazy;
	
	segtree(int l) {
		len = l;
		built = false;
		zero = node();
		noop = update();
		t.clear(); t.resize(4 * len, zero);
		upds.clear(); upds.resize(4 * len, noop);
		tl.clear(); tl.resize(4 * len);
		tr.clear(); tr.resize(4 * len);
		lazy.clear(); lazy.resize(4 * len, false);
	}
	
	inline void pushdown(int v) {
		if(!lazy[v]) return;
		apply(v * 2, upds[v]);
		apply(v * 2 + 1, upds[v]);
		lazy[v] = 0;
		upds[v] = noop;
	}
	
	inline void apply(int v, update &val) {
		if(tl[v] != tr[v]) {
			lazy[v] = 1;
			upds[v].combine(val, tl[v], tr[v]);
		}
		
		val.apply(t[v], tl[v], tr[v]);
	}
	
	template<typename T>
	void build(T &a, int v, int l, int r) {
		tl[v] = l;
		tr[v] = r;
        
		if(l == r) {
			t[v] = a[l];
			return;
		}
		
		int tm = (l + r) / 2;
		build(a, v * 2, l, tm);
		build(a, v * 2 + 1, tm + 1, r);
		t[v].merge(t[v * 2], t[v * 2 + 1]);
	}
	
	node query(int v, int l, int r) {
		if(l > tr[v] || r < tl[v]) return zero;
		if(l <= tl[v] && tr[v] <= r) return t[v];
		
		pushdown(v);
		node a, b, ans;
		a = query(v * 2, l, r);
		b = query(v * 2 + 1, l, r);
		ans.merge(a, b);
		return ans;
	}
	
	void rupd(int v, int l, int r, update &val) {
		if(l > tr[v] || r < tl[v]) return;
		if(l <= tl[v] && tr[v] <= r) {
			apply(v,val);
			return;
		}
        
        pushdown(v);
        rupd(v * 2, l, r, val);
        rupd(v * 2 + 1, l, r, val);
        t[v].merge(t[v * 2], t[v * 2 + 1]);
    }
	
	template<typename T>
	int descent_right(int l, T x, int v, node &prev) {
		// node is completely out of range
		if(l > tr[v]) return len;
		
		// node is completely in range
		if(l <= tl[v]) {
    		node cur;
    		cur.merge(prev, t[v]);
            
            // go further right than this node
            if(!cur.check(x)) { 
            	// merging this node's contribution
            	swap(prev,cur); 
            	return len;
            }
            
            if(tl[v] == tr[v]) {
                return tr[v];
            }
        }
        
        pushdown(v);
        int ans = descent_right(l, x, v * 2, prev); // trying to find in left child
        if(ans != len) return ans; // found in left child
        return descent_right(l, x, v * 2 + 1, prev); // finding in right child
    }
    
    template<typename T>
    int descent_left(int r, T x, int v, node &prev) {
    	// node is completely out of range
        if(r < tl[v]) return -1;
        
        // node is completely in range
        if(r >= tr[v]) { 
            node cur;
            cur.merge(t[v], prev);
            
            // go further left than this node
            if(!cur.check(x)){ 
            	// merging this node's contribution
                swap(cur,prev); 
                return -1;
            }
            
            if(tl[v] == tr[v]) {
                return tl[v];
            }
        }
        
        pushdown(v);
        int ans = descent_left(r, x, v * 2 + 1, prev); // trying to find in right child
        if(ans != -1) return ans; // found in right child
        return descent_left(r, x, v * 2, prev); // finding in left child
    }
	
	public:
	template<typename T>
	void build(T &a) {
		build(a, 1, 0, len - 1);
		built = true;
	}
	
	template<typename T>
	// minimum r such that [l...r].check(x) == true, returns segtree.len if not found
	int descent_right(int l, T x) { 
		node prev = zero;
		return descent_right(l, x, 1, prev);
    }
    
    // maximum l such that [l...r].check(x) == true, returns -1 if not found
    template<typename T>
    int descent_left(int r, T x) { 
    	node prev = zero;
    	return descent_left(r, x, 1, prev);
    }
    
    node query(int l, int r) {
		if(!built) build(t);
		return query(1, l, r);
	}
	
	void rupd(int l, int r, update val) {
		if(!built) build(t);
		rupd(1, l, r, val);
	}
};

void solve() 
{
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
	// if want to have different segment trees supporting different node & update structure
	// in the same program, just create the required node & update structs and pass those 
	// structures while defining the segtree
	struct segtree<node, update> s(n); 
	
	s.build(v);	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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