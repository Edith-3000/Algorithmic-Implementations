// In total 3 methods have been given for finding the Time in & Time out of each vertex, by means of which
// it can be easily find out if a given node is an ancestor of another node or not.
// Many other type of problems can also be solved using time-in, time-out concept by combining it
// with segment tree concept, for eg. https://codeforces.com/problemset/problem/620/E

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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
vi g[100005];
vi tin(100005, -1), tout(100005, -1);
int timer;

// total time will be = 2*(n-1) + 1
// since we visit each edge exactly twice
void euler_tour_1(int curr, int par) {
	cout << curr << " "; // visiting the node, print it
	tin[curr] = timer++;
	for(auto x: g[curr]) {
		if(x != par) {
			euler_tour_1(x, curr);
			tout[curr] = timer++;
			cout << curr << " "; // going back to the node, print it
		}
	}
	
	return;
}

// total time will be = 2*n
void euler_tour_2(int curr, int par) {
	cout << curr << " "; // visiting the node, print it
	tin[curr] = timer++;
	for(auto x: g[curr]) {
		if(x != par) {
			euler_tour_2(x, curr);
		}
	}
	
	tout[curr] = timer++;
	cout << curr << " "; // exiting the node, print it
	return;
}

// total time will be = n
void euler_tour_3(int curr, int par) {
	cout << curr << " "; // visiting the node, print it
	tin[curr] = ++timer; // whenever entering node increment timer
	for(auto x: g[curr]) {
		if(x != par){
			euler_tour_3(x, curr);
		}
	}
	
	tout[curr] = timer; // whenever exiting node do not increment
	return;
}

// to check if x is an ancestor of y or not
bool is_ancestor(int x, int y) {
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

void solve()
{
  	// #vertices in the UG (tree) (vertices are 1-based indexed)
  	int n; cin >> n; 
  	for(int i = 0; i < n - 1; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	// timer = 1; 
  	// euler_tour_1(1, 0);
  	
  	// timer = 1;
  	// euler_tour_2(1, 0);
  	
  	timer = 0;
  	euler_tour_3(1, 0);
  	
  	cout << "\n";
  	for(int i = 1; i <= n; i++) {
  		cout << i << " -- " << "Time in = " << tin[i] << ", ";
  		if(tout[i] == -1) tout[i] = tin[i];
  		cout << "Time out = " << tout[i] << "\n";
  	}
  	
  	cout << "\n";
  	if(is_ancestor(3, 8)) cout << "Yes\n";
  	else cout << "No\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}