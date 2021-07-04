// Problem: https://www.interviewbit.com/problems/simple-queries/
// Ref: https://www.algostreak.com/post/simple-queries-interviewbit-solution
//      https://github.com/black-shadows/InterviewBit-Topicwise-Solutions/blob/master/Codersbit/Simple%20Queries.cpp
/********************************************************************************************************************/

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
const ll mod = 1e9+7;
const int N = 1e5;

// To store product of divisor.
ll p[N+1];

void precompute() {
	// if function has already been called before.
	if(p[1] != 0) return;
	
	for(int i = 1; i <= N; i++) p[i] = i;
	
	for(int i = 2; i <= N; i++) {
		for(int j = (2 * i); j <= N; j += i) {
			p[j] = (p[j] * i) % mod;
		}
	}
}

void ngl_indices(vi &v, vi &ngl) {
	int n = (int)v.size();
  	for(int i = 0; i < n; i++) ngl[i] = 1;
  
  	vector<int> res(n);
  	stack<pair<int, int>> st; 

  	for(int i = 0; i < n; i++) {
    	if(st.empty()) res[i] = -1;
    	else if(st.top().F >= v[i]) res[i] = st.top().S;

    	else if(st.top().F < v[i]) {
      		while(!st.empty() && st.top().F < v[i]) st.pop();

      		if(st.empty()) res[i] = -1;
      		else res[i] = st.top().S;
        }

    	st.push({v[i], i});
    }
	
  	for(int i = 0; i < n; i++) {
  		if(res[i] == -1) ngl[i] += i;
  		else ngl[i] += i - res[i] - 1;
    } 
}

void ngr_indices(vi &v, vi &ngr) {
	int n = (int)v.size();
  	for(int i = 0; i < n; i++) ngr[i] = 1;
  
  	vector<int> res(n);
  	stack<pair<int, int>> st; 

  	for(int i = n - 1; i >= 0; i--) {
    	if(st.empty()) res[i] = -1;
    	else if(st.top().F > v[i]) res[i] = st.top().S;

    	else if(st.top().F <= v[i]) {
      		while(!st.empty() && st.top().F <= v[i]) st.pop();

      		if(st.empty()) res[i] = -1;
      		else res[i] = st.top().S;
        }

    	st.push({v[i], i}); 
    }
    
  	for(int i = 0; i < n; i++) {
  		if(res[i] == -1) ngr[i] += n - 1 - i;
  		else ngr[i] += res[i] - i - 1;
    }
}

vi find_ans(vi &v, vi &queries) {
	// To store poduct of divisors of each element.
	precompute();
	
	int n = (int)v.size();
	vi ngl(n), ngr(n);
	ngl_indices(v, ngl);
	ngr_indices(v, ngr);
	
	// The number of subarrays in which current element will be the greater
	vll g(n);
	for(int i = 0; i < n; i++) {
		g[i] = (ll)ngl[i] * ngr[i];
	}
	
	vpll store(n);
	for(int i = 0; i < n; i++) {
		ll x = p[v[i]];
		store[i] = {x, g[i]};
	}
	
	// Sort elements in descending order according to there value
	sort(store.begin(), store.end());
	reverse(store.begin(), store.end());
	
	// Take Prefix Sum of frequencies of elements
	for(int i = 1; i < n; i++) {
		store[i].S += store[i-1].S;
	}
	
	vi res(queries.size());
	
	// do binary search for each query
	for(int i = 0; i < (int)queries.size(); i++) {
		int L = 0, R = n;
		while((L + 1) < R) {
			int m = L + ((R - L) >> 1);
			if(queries[i] < store[m].S) R = m;
			else L = m;
		}
		
		if(queries[i] > store[L].S) L += 1; 
		res[i] = store[L].F;
	}
	
	// return the res array
	return res;
}

void solve()
{
  	int n, q; cin >> n >> q;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi queries(q);
  	for(int i = 0; i < q; i++) cin >> queries[i];
  	
  	vi res = find_ans(v, queries);
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