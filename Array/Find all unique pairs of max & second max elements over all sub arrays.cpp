// Ref: https://www.geeksforgeeks.org/find-all-unique-pairs-of-maximum-and-second-maximum-elements-over-all-sub-arrays-in-onlogn/
// Similar ques based on this: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/
/**************************************************************************************************************************************************************/

// Problem: Sed Max
// Contest: CodeChef - February Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME93B/problems/SEDMAX
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 05-03-2021 21:57:52 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

set<pii> find_pairs(vi &v, int n) {
	set<pii> s;
	stack<int> stk;
	
	// Push first element into stack
	stk.push(v[0]);
	
	// For each element 'x' in v[], pop the stack while top element
    // is smaller than 'x' and form a pair.
    // If the stack is not empty after the previous operation, create
    // a pair. 
    // Push 'x' into the stack.
	for(int i = 1; i < n; i++) {
		while(!stk.empty() and v[i] > stk.top()) {
			s.insert({stk.top(), v[i]});
			stk.pop();
		}
		
		if(!stk.empty()) s.insert({v[i], stk.top()});
		stk.push(v[i]);
	}
	
	return s;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(auto &x: v) cin >> x;
  	
  	set<pii> s = find_pairs(v, n);
  	
  	set<int> res;
  	for(auto p: s) {
  		res.insert(p.S - p.F);
  	}
  	
  	cout << res.size() << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}