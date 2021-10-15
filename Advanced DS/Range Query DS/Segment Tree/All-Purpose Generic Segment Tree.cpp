// Ref: https://unacademy.com/a/free-course-on-segment-trees-new

// Original codes: https://pastebin.com/hsikTRdD
//                 https://pastebin.com/HenNdx4h

// Raw code of below algorithm: https://pastebin.com/9eJShF82

// Example on how to use it: https://pastebin.com/ZHh28xxM
/*********************************************************************************************************/

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
	void merge(const node &l, const node &r){ 
		// 3. change(s) required
		
	}
};

// this structure depends on the nature of update
struct update {
	// 4. change(s) required
	// use more variables if you want more information
	// these default values should be identity_transformation or identity_update
	
	
	update() {}
	update(int ) {
		// 5. change(s) required
		
	}
	
	// combine the current update with the other update (see keynotes)
	// basically combine older lazy value(s) (if exist) with newer one(s).
	// for this function, you can be sure that the "other" is newer than current
	void combine(update &other, const int32_t &tl, const int32_t &tr) {
		// 6. change(s) required
		
	}
	
	// store the correct information in the node x
	void apply(node &x, const int32_t &tl, const int32_t &tr) {
		// 7. change(s) required
		
	}
};

template<typename node, typename update>
struct segtree {
    int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	
	segtree(int l) {
		len = l;
		t.clear(); t.resize(4 * len);
		u.clear(); u.resize(4 * len);
		lazy.clear(); lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}
	
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr) {
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v << 1, tl, tm, u[v]);
		apply((v << 1) | 1, tm + 1, tr, u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
	
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd) {
		if(tl != tr) {
			lazy[v] = 1;
			u[v].combine(upd, tl, tr);
		}
		
		upd.apply(t[v], tl, tr);
	}
	
	template<typename T>
	void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr) {
		if(tl == tr) {
			t[v] = arr[tl];
			return;
		}
		
		int32_t tm = (tl + tr) >> 1;
		build(arr, v << 1, tl, tm);
		build(arr, (v << 1) | 1, tm + 1, tr);
		t[v].merge(t[v << 1],t[(v << 1) | 1]);
	}
	
	node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r) {
		if(l > tr || r < tl) {
			return identity_element;
		}
		
		if(tl >= l && tr <= r){
			return t[v];
		}
		
		pushdown(v, tl, tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v << 1, tl, tm, l, r), b = query((v << 1) | 1, tm + 1, tr, l, r), ans;
		ans.merge(a, b);
		return ans;
	}
	
	void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd) {
		if(l > tr || r < tl){
			return;
		}
		
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		
		pushdown(v, tl, tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v << 1, tl, tm, l, r, upd);
		rupd((v << 1) | 1, tm + 1, tr, l, r, upd);
		t[v].merge(t[v << 1], t[(v << 1) | 1]);
	}
	
	public:
	template<typename T>
	void build(const T &arr) {
		build(arr, 1, 0, len - 1);
	}
	
	node query(const int32_t &l,const int32_t &r) {
		return query(1, 0, len - 1, l, r);
	}
	
	void rupd(const int32_t &l, const int32_t &r, const update &upd) {
		rupd(1, 0, len - 1, l, r, upd);
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