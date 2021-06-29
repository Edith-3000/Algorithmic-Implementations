// Problem: https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
/******************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

class myComparator {
    public:
        bool operator()(const pair<string, int> &p1, const pair<string, int> &p2){
            if(p1.S == p2.S) return p1.F < p2.F;
            else return p1.S < p2.S;
        }
};

void settle() {
    int no_of_transactions;
    cin >> no_of_transactions;
    
    unordered_map<string, int> net;
    
    while(no_of_transactions--) {
        // x is the person which have to give money = amount to y
        string x, y; 
        int amount;
        cin >> x >> y >> amount;
        
        if(net.count(x) == 0) net[x] = 0;
        if(net.count(y) == 0) net[y] = 0;
        
        net[x] -= amount;
        net[y] += amount;
    }
    
    // instead of defining myComparator comparison class, we can
    // also insret pair in the form <int, string>
    multiset<pair<string, int>, myComparator> m;
    
    for(auto x: net) {
        if(x.S != 0) m.insert(x);
    }
    
    // to store the min #transaction required
    int cnt = 0;
    
    // pop out the left most (highest debitor) and right most (highest creditor)
    // persons and try to settle them
    while(!m.empty()) {
        cnt++;
        
        auto low = m.begin();
        auto high = prev(m.end(), 1);
        
        int debit = low->S;
        int credit = high->S;
        
        string debitor = low->F;
        string creditor = high->F;
        
        m.erase(low);
        m.erase(high);
                
        // can also be => settlement = min(abs(debit, credit));
        int settlement = min(-debit, credit);
        
        cout << debitor << " will pay ₹" <<settlement<< " to " <<creditor << "\n";
        
        debit += settlement;
        credit -= settlement;
        
        if(debit != 0) m.insert({debitor, debit});
        if(credit != 0) m.insert({creditor, credit});
    }

    cout << "Minimum #transaction required = " <<cnt << "\n";
}

void solve() {
    settle();
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

/*

Sample i/p:

3
Rahul Ajay 100
Ajay Neha 50
Neha Rahul 30

Sample o/p:

Rahul will pay ₹50 to Ajay
Rahul will pay ₹20 to Neha
Minimum number of transaction required = 2

*/

// Time Complexity: O(n x log(n)), where n = #frnds