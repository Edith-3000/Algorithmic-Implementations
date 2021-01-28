// Approach explanation: https://www.youtube.com/watch?v=TSr0x3EBWSg&list=PLb3g_Z8nEv1i26KO3g9Hw-taqgIejXH49&index=1

/*********************************************************************************************************/

// Problem: C2. Prefix Flip (Hard Version)
// Contest: Codeforces - Codeforces Round #658 (Div. 2)
// URL: https://codeforces.com/contest/1382/problem/C2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 28-01-2021 18:50:18 IST (UTC+05:30)
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

struct node {
	bool num;
	node *prev, *next;
	node(bool x) {
		num = x;
		prev = NULL;
		next = NULL;
	}
};

class DLL {
	node *head, *tail;
	int num_of_nodes; // currently the #nodes in DLL
	// currently if head is on left side & tail on right, then side = 1
	// if vice versa, then side = 0;
	bool side; 
	
	public:
		// constructor for DLL class
		DLL(string &s) {
			// initially the head will be on left & tail on right
			side = 1;
			num_of_nodes = s.length() - 1;
			head = new node(s[1] - '0');
			tail = head;
			for(int i = 2; i < s.length(); i++) {
				node *tmp = new node(s[i] - '0');
				tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
			}
		}
		
		void quick_reverse() {
			node *tmp = tail;
			tail = head;
			head = tmp;
			// sides of tail & head reverses, when DLL is reversed
			side = !side; 
		}
		
		void pop_back() {
			if(num_of_nodes == 1) return;
			if(side) {
				tail = tail->prev;
				tail->next = NULL;
			}
			
			else {
				tail = tail->next;
				tail->prev = NULL;
			}
			
			num_of_nodes--;
		}
		
		bool last_value() {
			return tail->num;
		}
};

void solve()
{
  	int n; cin >> n;
  	string s1, s2; cin >> s1 >> s2;
  	
  	DLL dll(s1);
  	vi res;
  	int inverts = 0;
  	for(int i = (n - 1); i > 0; i--) {
  		bool x = dll.last_value();
  		dll.pop_back();
  		if(inverts & 1) x = !x;
  		if(x != (s2[i] - '0')) {
  			if((s1[0] - '0') != x) res.pb(1);
  			else s1[0] = '0' + !(s1[0] - '0');
  			inverts++;
  			res.pb(i + 1);
  			dll.quick_reverse();
  		}
  	}
  	
  	if(s1[0] != s2[0]) res.pb(1);
  	cout << res.size() << " ";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}