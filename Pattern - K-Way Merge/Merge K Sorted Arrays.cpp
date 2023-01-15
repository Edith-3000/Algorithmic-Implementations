// Problem Statement: Given a list of 'k' sorted arrays, merge them into one sorted list.

/* UNDERLYING CONCEPT ------>

   This problem is similar to Merge K Sorted Lists except that the input is a list of arrays compared 
   to LinkedLists. To handle this, we can use a similar approach as discussed in our parent problem by 
   keeping a track of the array and the element indices.
*/

// Ref: https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/
/******************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

// A pair of pairs, first element is going to store value, second element index 
// of array to which the value belongs and third element index of value in the array.
struct cmp {
	bool operator()(const pair<int, pii> &p1, const pair<int, pii> &p2) {
		if(p1.F == p2.F) return p1.S.F > p2.S.F;
		return p1.F > p2.F;
    }
};

vi merge_k_sorted_arrays(vvi &v) {
	int k = (int)v.size();
	
	// Create a min heap with k heap nodes. Every heap node has first 
	// element of an array
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> q;
	
	for(int i = 0; i < k; i++) {
		q.push({v[i][0], {i, 0}});
	}
	
	// to store the final result
	vi res;
	
	// Now one by one get the minimum elementfrom min heap and replace 
	// it with next element of its array
	while(!q.empty()) {
		pair<int, pii> cur = q.top();
		q.pop();
		
		// i ==> Array Number
        // j ==> Index in the array number
		int i = cur.S.F;
		int j = cur.S.S;
		
		res.pb(cur.F);
		
		// The next element belongs to same array as current.
		if((j + 1) < (int)v[i].size()) {
			int next = v[i][j+1];
			q.push({next, {i, j + 1}});
		}
	}
	
	return res;
}

void solve()
{
  	int k; cin >> k;

  	vvi v(k);

  	for(int i = 0; i < k; i++) {
  		int n; cin >> n;
  		v[i].resize(n);
  		for(int j = 0; j < n; j++) cin >> v[i][j];
  	}
  	
  	vi res = merge_k_sorted_arrays(v);

  	for(auto x: res) cout << x << " ";
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

// Time complexity: O(n x log(k)), where n = count of all elements in all the vectors.