// Problem: https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
// Ref: https://www.youtube.com/watch?v=MT8zeLak_bI
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

int exp(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	
	return res;
}

int find_ans(vi &A, int B, int C) {
	int n = (int)A.size();
	if(n == 0) return 0;
	
	sort(A.begin(), A.end());
	
	int len = 0, x = C;
	while(x > 0) {
		len += 1;
		x /= 10;
	}
	
	int res = 0;
	
	// Case 1
	if(len < B) {
		res = 0;
		return res;
	}
	
	// Case 2
	else if(len > B) {
		if(A[0] == 0) res = (n - 1) * exp(n, B - 1);
		else res = exp(n, B);
		
		if(B == 1 and A[0] == 0) res++;
		return res;
	}
	
	// Case 3
	else {
		if(B == 1) {
			for(int i = 0; i < n; i++) {
				if(A[i] < C) res++;
			}
		}
		
		else {
			vi tmp(B);
			for(int i = B - 1; i >= 0; i--) {
				tmp[i] = C % 10;
				C /= 10;
			}
			
			int cnt = 0;
			
			for(int i = 0; i < n; i++) {
				if(A[i] == 0) continue;
				if(A[i] > tmp[0]) break;
				cnt++;
			}
			
			// this result contain some extra numbers
			res += cnt * exp(n, B - 1);
			
			bool flag = false;
			int j = 0;
			
			for(int i = 0; i < n; i++) {
				if(A[i] == tmp[j]) flag = true;
			}
			
			j++;
			
			while(flag == true and j <= (B - 1)) {
				flag = false;
				cnt = 0;
				
				for(int i = 0; i < n; i++) {
					if(A[i] > tmp[j]) cnt++;
					if(A[i] == tmp[j]) flag = true;
				}
				
				res -= cnt * exp(n, B - 1 - j);
				j++;
			}
			
			if(j == B and flag == true) res -= 1;
		}
		
		return res;
	}
}

void solve()
{
  	int n; cin >> n;
  	vi A(n);
  	for(int i = 0; i < n; i++) cin >> A[i];
  	
  	int B, C;
	cin >> B >> C;
	
	cout << find_ans(A, B, C);
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