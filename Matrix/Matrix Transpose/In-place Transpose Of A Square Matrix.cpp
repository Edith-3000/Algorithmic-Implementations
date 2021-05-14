// Ref: https://www.geeksforgeeks.org/program-to-find-transpose-of-a-matrix/
/********************************************************************************************************/

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

// Function to find in-place transpose of a square matrix
void transpose(vvi &v) {
    int n = (int)v.size();
    if(n == 0) return;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) swap(v[i][j], v[j][i]);
    }
}

void solve()
{
    int n; cin >> n;
    vvi v(n, vi(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> v[i][j];
    }
    
    transpose(v);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << v[i][j] << " ";
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