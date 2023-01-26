// Problem: https://leetcode.com/problems/valid-anagram/

/**************************************************************************************************************************************************************/

// METHOD 1 (Using 2 hash data structures)

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

bool valid_anagrams(string &text, string &pattern) {
	int n = (int)text.size();
	int k = (int)pattern.size();
	
	vi v1(26, 0);
	vi v2(26, 0);
	
	for(int i = 0; i < n; i++) {
		v1[text[i] - 'a']++;
	}
	
	for(int i = 0; i < k; i++) {
		v2[pattern[i] - 'a']++;
	}
	
	bool ok = 1;

	for(int i = 0; i < 26; i++) {
		ok &= (v1[i] == v2[i]);
	}
	
	return ok;
}

void solve()
{
  	string text, pattern;
  	cin >> text >> pattern;
  	
  	if(valid_anagrams(text, pattern)) cout << "YES\n";
  	else cout << "NO\n";
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

// TC: O(n + k)

/******************************************************************************************************/

// METHOD 2 (Using only a single hash data structure)

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

bool valid_anagrams(string &text, string &pattern) {
  int n = (int)text.size();
  int k = (int)pattern.size();
  
  vi v(26, 0);
  
  for(int i = 0; i < n; i++) {
    v[text[i] - 'a']++;
  }
  
  for(int i = 0; i < k; i++) {
    v[pattern[i] - 'a']--;
  }
  
  bool ok = 1;
  
  for(int i = 0; i < 26; i++) {
    ok &= (v[i] == 0);
  }
  
  return ok;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;
    
    if(valid_anagrams(text, pattern)) cout << "YES\n";
    else cout << "NO\n";
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

// TC: O(n + k)