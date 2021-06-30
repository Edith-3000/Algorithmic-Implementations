// Ref: https://www.geeksforgeeks.org/evaluation-prefix-expressions/
/********************************************************************************************************/

// Prefix notation is also known as Polish notation.
// https://www.geeksforgeeks.org/arithmetic-expression-evalution/

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

bool is_operator(string s) {
    return (s == "+") or (s == "-") or (s == "*") or (s == "/");
}

ll eval_prefix(vector<string> &v) {
	int n = (int)v.size();
	stack<ll> stk;
	
	for(int i = n - 1; i >= 0; i--) {
		if(is_operator(v[i])) {
            ll opnd1 = stk.top(); stk.pop();
            ll opnd2 = stk.top(); stk.pop();
            ll tmp;
            
            if(v[i] == "+") tmp = opnd1 + opnd2;
            else if(v[i] == "-") tmp = opnd1 - opnd2;
            else if(v[i] == "*") tmp = opnd1 * opnd2;
            else tmp = opnd1 / opnd2;
            
            stk.push(tmp);
        }
        
        else {
            stk.push(stoll(v[i]));
        }
	}
	
	return stk.top();
}

void solve()
{
  	int n; cin >> n;
  	vector<string> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << eval_prefix(v) << "\n";
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