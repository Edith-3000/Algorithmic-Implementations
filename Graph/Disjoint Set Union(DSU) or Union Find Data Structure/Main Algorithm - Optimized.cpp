// Ref: https://cp-algorithms.com/data_structures/disjoint_set_union.html
//      https://www.youtube.com/watch?v=3gbO7FDYNFQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=23&ab_channel=takeUforward

//      https://chatgpt.com/share/69ed7220-99d0-8321-bc82-e00cd22adbac - [https://chatgpt.com/c/69ecf29e-cadc-8321-a1cc-2dcd0c48af71]

/*************************************************************************************************************************************************************/

/* # Opmimization done :--->

     1. PATH COMPRESSION OPTIMIZATION ===>

        • This optimization is designed for speeding up find_set().
        • Pseudocode of the optimisation:
    
          int find_set(int v) {
              if(v == parent[v]) return v;
              return parent[v] = find_set(parent[v]);
          }

        • Time complexity: O(log(n)) per call on average.

     2. UNION BY RANK/SIZE ===>

        • This optimization is designed for speeding up union_sets().
        • Pseudocode of the optimisation:

          void union_sets(int a, int b) {
              int s1 = find_set(a);
              int s2 = find_set(b);

              if(s1 != s2) {
                  if(siz[s1] < siz[s2]) swap(s1, s2);
                  parent[s2] = s1;
                  siz[s1] += siz[s2];
              }
          }          
        
        • DSU with union by size / rank, but without path compression works in O(log(n)) time per query.

   # 𝑰𝒇 𝒘𝒆 𝒄𝒐𝒎𝒃𝒊𝒏𝒆 𝒃𝒐𝒕𝒉 𝒐𝒑𝒕𝒊𝒎𝒊𝒛𝒂𝒕𝒊𝒐𝒏𝒔 - 𝒑𝒂𝒕𝒉 𝒄𝒐𝒎𝒑𝒓𝒆𝒔𝒔𝒊𝒐𝒏 𝒘𝒊𝒕𝒉 𝒖𝒏𝒊𝒐𝒏 𝒃𝒚 𝒔𝒊𝒛𝒆 / 𝒓𝒂𝒏𝒌 - 𝒘𝒆 𝒘𝒊𝒍𝒍 𝒓𝒆𝒂𝒄𝒉 𝒏𝒆𝒂𝒓𝒍𝒚 𝑪𝑶𝑵𝑺𝑻𝑨𝑵𝑻 𝑶(1) 
     𝒕𝒊𝒎𝒆 𝒒𝒖𝒆𝒓𝒊𝒆𝒔.
*/

// METHOD - 1 (IMPLEMENTATION WITHOUT MAKING struct for DSU)

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

vi parent, siz;

void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    int s1 = find_set(a);
    int s2 = find_set(b);

    if(s1 != s2) {
    	if(siz[s1] < siz[s2]) swap(s1, s2);
        parent[s2] = s1;
        siz[s1] += siz[s2];
    }
}

void solve()
{
  	int n; cin >> n;
  	
  	parent.clear(); parent.resize(n + 1);
  	siz.clear(); siz.resize(n + 1);
  	
  	for(int i = 1; i <= n; i++) make_set(i); 
  	
  	int q; cin >> q;

  	while(q--) {
  		int type; cin >> type;

  		if(type == 1) {
  			int x, y; cin >> x >> y;
  			union_sets(x, y);
  		}
  		
  		else {
  			int x; cin >> x;
  			cout << find_set(x) << "\n";
  		}
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

/*******************************************************************************************************/

// METHOD - 2 (IMPLEMENTATION BY MAKING struct for DSU)

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
#define vset(v, n, val) v.clear(); v.resize(n, val)

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

// CAUTION : use 0-based indexing for the nodes
struct dsu {
    vi parent, siz;
    
    dsu(int n) {
        parent.clear(); parent.resize(n);
        siz.clear(); siz.resize(n);
    }
    
    void make_set(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            siz[i] = 1; 
        }
    }

    int find_set(int v) {
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        int s1 = find_set(a);
        int s2 = find_set(b);

        if(s1 != s2) {
            if(siz[s1] < siz[s2]) swap(s1, s2);
            parent[s2] = s1;
            siz[s1] += siz[s2];
        }
    }
};

void solve()
{
    int n; cin >> n;
    
    // initialising DSU structure
    struct dsu d(n);
    d.make_set(n);
    
    int q; cin >> q;

    while(q--) {
        int type; cin >> type;

        if(type == 1) {
            int x, y; cin >> x >> y;
            d.union_sets(x, y);
        }
        
        else {
            int x; cin >> x;
            cout << d.find_set(x) << "\n";
        }
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

/* # In case there is a need to find the total count of sets in the DSU data structure :--->
     Add a new member sets_count in the struct and use it in following manner :--->

    // CAUTION : use 0-based indexing for the nodes
    struct dsu {
        vector<int> parent, siz;
        int sets_count;

        dsu(int n) {
            parent.clear(); parent.resize(n);
            siz.clear(); siz.resize(n);
            sets_count = n;
        }

        void make_set(int n) {
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                siz[i] = 1; 
            }
        }

        int find_set(int v) {
            if(v == parent[v]) return v;
            return parent[v] = find_set(parent[v]);
        }

        void union_sets(int a, int b) {
            int s1 = find_set(a);
            int s2 = find_set(b);

            if(s1 != s2) {
                sets_count -= 1;
                if(siz[s1] < siz[s2]) swap(s1, s2);
                parent[s2] = s1;
                siz[s1] += siz[s2];
            }
        }
    };

*/