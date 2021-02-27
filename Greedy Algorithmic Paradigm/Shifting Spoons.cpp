// Problem: Shifting Spoons
// Contest: CodeChef - January Lunchtime 2021 Division 2 (Unrated)
// URL: https://www.codechef.com/LTIME92B/problems/SHSPOONS
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 27-02-2021 10:08:11 IST (UTC+05:30)
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

struct Operation {
	ll p, q, x;
};

struct Pile {
	int id;
	ll spoons;
};

struct cmp {
	bool operator()(const Pile &p1, const Pile &p2) {
		if(p1.spoons == p2.spoons) return p1.id > p2.id;
		return p1.spoons > p2.spoons;
	}
};

void solve()
{
  	int n; cin >> n;
  	priority_queue<Pile, vector<Pile>, cmp> q;
  	
  	Pile P1;
  	cin >> P1.spoons;
  	P1.id = 1;
  	
  	for(int i = 2; i <= n; i++) {
  		Pile P;
  		cin >> P.spoons;
  		P.id = i;
  		q.push(P);
  	}
  	
  	vector<Operation> res;
  	
  	while(!q.empty()) {
  		auto smallest = q.top();
  		q.pop();
  		
  		if(smallest.spoons <= P1.spoons) {
  			P1.spoons += smallest.spoons;
  			res.pb({smallest.id, 1, smallest.spoons});
  		}
  		
  		else {
  			if(q.empty()) { cout << -1 << "\n"; return; }
  			auto second_smallest = q.top();
  			q.pop();
  			
  			ll extra = smallest.spoons - P1.spoons;
  			second_smallest.spoons += extra;
  			smallest.spoons -= extra;
  			res.pb({smallest.id, second_smallest.id, extra});
  			q.push(second_smallest);
  			
  			P1.spoons += smallest.spoons;
  			res.pb({smallest.id, 1, smallest.spoons});
  		}
  	}
  	
  	cout << res.size() << "\n";
  	
  	for(int i = 0; i < (int)res.size(); i++) {
  		cout << res[i].p << " " << res[i].q << " " << res[i].x << "\n";
  	}
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

// Explanation: https://www.youtube.com/watch?v=85yhHWHch9A&list=PLQXZIFwMtjozOtuZ-yOIRt63w2QxhOBFj&index=8

/* WARNING: Don't use the below type of custom comparator function for the priority queue, as
            it will give compilation error.
   
   bool cmp(const Pile &p1, const Pile &p2) {
       if(p1.spoons == p2.spoons) return p1.id < p2.id;
       return p1.spoons < p2.spoons;
   }
*/