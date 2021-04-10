// Problem: https://www.interviewbit.com/problems/fraction/
// Ref: https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
/******************************************************************************************************/

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

string fraction_to_decimal(ll A, ll B) {
    ll num = A;
    ll den = B;
    
    string res = "";
    if((num > 0 and den < 0) or (num < 0 and den > 0)) res += "-";
    
    num = abs(num);
    den = abs(den);
    
    res += to_string(num / den);
    ll rem = num % den;
    
    if(rem == 0) return res;
    
    res += '.';
    map<ll, ll> m;
    string last = "";
    
    while((rem != 0) and m.find(rem) == m.end()) {
        m[rem] = last.size();
        rem *= 10;
        last += to_string(rem / den);
        rem %= den;
    }
    
    if(rem == 0) res += last;
    else {
        res += last.substr(0, m[rem]);
        res += "(";
        res += last.substr(m[rem]);
        res += ")";
    }
    
    return res;
}


void solve()
{
  	int a, b; cin >> a >> b;
  	cout << fraction_to_decimal(a, b) << "\n";
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