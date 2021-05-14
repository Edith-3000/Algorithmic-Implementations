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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

vvi rotate_clock(vvi &v) {
    int n1 = (int)v.size();
    if(n1 == 0) return vvi();
    int m1 = (int)v[0].size();
    
    int n2 = m1, m2 = n1;
    vvi res(n2, vi(m2));
    
    int i2 = 0, j2 = m2 - 1;
    for(int i1 = 0; i1 < n1; i1++) {
        for(int j1 = 0; j1 < m1; j1++) {
            res[i2++][j2] = v[i1][j1];
        }
        
        i2 = 0;
        j2 -= 1;
    }
    
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    vvi v(n, vi(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    vvi res = rotate_clock(v);
    
    for(int i = 0; i < (int)res.size(); i++) {
        for(int j = 0; j < (int)res[i].size(); j++) cout << res[i][j] << " ";
        cout << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}