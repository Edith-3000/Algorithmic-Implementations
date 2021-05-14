// Problem: https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
// Ref: https://www.youtube.com/watch?v=O0xdijU9l-g
/*******************************************************************************************************/

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

vi dx = {-1, 0, 1, 0};
vi dy = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

vvi kth_manhattan(vvi &v, int k) {
    vvi cur = v, nxt = v;
    int n = v.size();
    if(n == 0) return cur;
    int m = v[0].size();
    
    for(int rep = 1; rep <= k; rep++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(is_valid(nx, ny, n, m)) nxt[i][j] = max(nxt[i][j], cur[nx][ny]);
                }   
            }
        }
        
        cur = nxt;
    }
    
    return cur;
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vvi v(n, vi(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    vvi res = kth_manhattan(v, k);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << res[i][j] << " ";
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

// TC: O(n x m x k)