// Ref: https://www.geeksforgeeks.org/painters-partition-problem/
/******************************************************************************************************/

// NOTE: Problem almost similar to "Allocate Minimum #Pages.cpp"

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

bool is_valid(vi &v, int k, ll mid) {
	// for storing #painters
	int painters = 1;
	
	// for storing units of board which can be painted by each painter 
	// under given circumstances that every painter can be 
	// assigned at most mid #total units to be painted
	ll sum = 0LL; 

	for(int i = 0; i < (int)v.size(); i++) {
	   sum += v[i];
	   
	   // no paintert can be assigned total units > mid
	   if(sum > mid) {
	       painters++; // start assigning pages to next painter
	       sum = v[i]; // 1st book assigned to the new painter
	   }
	   
	   // scheme of assigning units of board to a painter not more than mid 
	   // fails bcoz under given scheme we require more #painters
	   if(painters > k) return false; 
	}
	
	return true; 
}

ll painters_partition(vi &v, int k) {
	// #borads
	int n = (int)v.size(); 
	
    ll sum = 0LL; 
	for(int i = 0; i < n; i++) sum += v[i];

	ll start = *max_element(v.begin(), v.end());
    ll end = sum;
	ll res = -1; // for storing the result   

	while(start <= end) {
	   ll mid = start + (end - start) / 2;

	   if(is_valid(v, k, mid)) {
	      res = mid; // i.e. mid can be a possible answer
	      end = mid - 1; // to search for a more minimum value, if possible
	   }
		
	   // i.e. the mid found was much lower than required & burden on 
	   // each painter needs to be increased
	   else start = mid + 1; 
	}
	
	// -1 is returned if scheme not possible
	return res; 
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << painters_partition(v, k) << "\n";
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

// Time complexity: O(n x log(s)), where s is the summation of all vector elements.