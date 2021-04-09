// Problem: https://www.interviewbit.com/problems/simplify-directory-path/
// Ref: https://www.youtube.com/watch?v=h1KVmq2oGhE
//      https://www.geeksforgeeks.org/simplify-directory-path-unix-like/
/****************************************************************************************************/

// Method 1 (Using Stack)

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

string simplify(string &s) {
    int n = (int)s.size();
    stack<string> stk;
    string dir;
    string res = "/";
    
    for(int i = 0; i < n; i++) {
        dir.clear();
        
        while(i < n and s[i] == '/') i++;
        while(i < n and s[i] != '/') dir += s[i], i++;
        
        if(dir.compare("..") == 0) {
            if(!stk.empty()) stk.pop();
        }
        
        else if(dir.compare(".") == 0) continue;
        else if(dir.size() != 0) stk.push(dir);
    }
    
    stack<string> stk1;
    while(!stk.empty()) {
        stk1.push(stk.top());
        stk.pop();
    }
    
    while(!stk1.empty()) {
        string tmp = stk1.top();
        if(stk1.size() != 1) res += tmp + "/";
        else res += tmp;
        stk1.pop();
    }
    
    return res;
}

void solve()
{
  	string s; cin >> s;
  	cout << simplify(s);
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

/************************************************************************************************/

// Method 2 (Using vector)

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

string simplify(string &s) {
    int n = (int)s.size();
    vector<string> v;
    string dir;
    
    for(int i = 0; i < n; i++) {
        dir.clear();
        
        while(i < n and s[i] == '/') i++;
        while(i < n and s[i] != '/') dir += s[i], i++;
        
        if(dir.compare("..") == 0) {
            if(v.size() != 0) v.pop_back();
        }
        
        else if(dir.compare(".") == 0) continue;
        else if(dir.size() != 0) v.push_back(dir);
    }
    
    string res = "/";
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) res += "/" + v[i];
        else res += v[i];
    }
    
    return res;
}

void solve()
{
  	string s; cin >> s;
  	cout << simplify(s);
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