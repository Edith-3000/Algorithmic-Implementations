// Problem: https://www.pepcoding.com/resources/online-java-foundation/2d-arrays/ring-rotate-official/ojquestion
// Ref: https://www.youtube.com/watch?v=atMK9aA-s7Y'
/****************************************************************************************************************/

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

// vector should be passed by reference
void reverse(int i, int j, vi &v) {
    if(i >= j) return;
    while(i < j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        i++; j--;
    }
}

// vector should be passed by reference
void rotate(vi &v, int k) {
    int n = (int)v.size();
    k = k % n;
    if(k < 0) k = n + k;
    
    // reverse part 1
    reverse(0, n - k - 1, v);
    
    // reverse part 2
    reverse(n - k, n - 1, v);
    
    // reverse entire array
    reverse(0, n - 1, v);
}

vi extraxt_shell(vvi &v, int shell) {
	int mnr = shell - 1;
	int mnc = shell - 1;
	int mxr = (int)v.size() - shell;
	int mxc = (int)v[0].size() - shell;
	
	// total #elements in the shell
	int sz;
	if(mxr == mnr) sz = mxc - mnc + 1;
	else if(mxc == mnc) sz = mxr - mnr + 1;
	else sz = 2 * (mxr - mnr + 1) + 2 * (mxc - mnc + 1) - 4;
	
	vi tmp(sz);
	int idx = 0;
	
	// left wall
	for(int i = mnr, j = mnc; i <= mxr and idx < sz; i++) tmp[idx++] = v[i][j];
	mnc += 1;
	
	// bottom wall
	for(int i = mxr, j = mnc; j <= mxc and idx < sz; j++) tmp[idx++] = v[i][j];
	mxr -= 1;
	
	// right wall
	for(int i = mxr, j = mxc; i >= mnr and idx < sz; i--) tmp[idx++] = v[i][j];
	mxc -= 1;
	
	// up wall
	for(int i = mnr, j = mxc; j >= mnc and idx < sz; j--) tmp[idx++] = v[i][j];
	
	return tmp;
}

void fill_shell(vvi &v, int shell, vi &tmp) {
	int mnr = shell - 1;
	int mnc = shell - 1;
	int mxr = (int)v.size() - shell;
	int mxc = (int)v[0].size() - shell;
	
	int idx = 0;
	
	if(mxr == mnr) {
		for(int i = mnr, j = mnc; j <= mxc; j++) v[i][j] = tmp[idx++];
		return;
	}
	
	else if(mxc == mnc) {
		for(int i = mnr, j = mnc; i <= mxr; i++) v[i][j] = tmp[idx++];
		return;
	}
	
	// fill left wall
	for(int i = mnr, j = mnc; i <= mxr; i++) v[i][j] = tmp[idx++];
	mnc += 1;
	
	// fill bottom wall
	for(int i = mxr, j = mnc; j <= mxc; j++) v[i][j] = tmp[idx++];
	mxr -= 1;
	
	// fill right wall
	for(int i = mxr, j = mxc; i >= mnr; i--) v[i][j] = tmp[idx++];
	mxc -= 1;
	
	// fill up wall
	for(int i = mnr, j = mxc; j >= mnc; j--) v[i][j] = tmp[idx++];
}

void shell_rotate(vvi &v, int shell, int rotations) {
	// base case
	if((int)v.size() == 0) return;
	
	// extracting the required shell elements into a vector
	vi tmp = extraxt_shell(v, shell);
	
	// performing rotation of the shell elements extracted
	rotate(tmp, rotations);
	
	// fill back the shell with the rotated elements
	fill_shell(v, shell, tmp);
}

void solve()
{
  	int n, m; cin >> n >> m;
  	
  	// shell is 1-based indexed
  	int shell, rotations; cin >> shell >> rotations;
  	
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	shell_rotate(v, shell, rotations);
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cout << v[i][j] << " ";
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