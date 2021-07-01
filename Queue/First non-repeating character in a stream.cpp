// Problem: https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
// Ref: https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/
//      https://www.youtube.com/watch?v=4kqz5e9kIuQ
/*********************************************************************************************************/

// Method 1 (Using Queue)

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

string non_repeat_chars(string s) {
    int n = s.size();

    // to store the frequency of each character
    vector<int> cnt(26, 0);

    // to store the potential candidates which can be our answer
    queue<char> q;
    
    string res = "";
    
    for(int i = 0; i < n; i++) {
    	int x = s[i] - 'a';
    	cnt[x]++;
    	q.push(s[i]);
    	
    	while(!q.empty() and cnt[q.front() - 'a'] > 1) q.pop();
    	if(q.empty()) res += '#';
    	else res += q.front();    	
    }
    
    return res;
}

void solve()
{
  	string s; cin >> s;
  	cout <<  non_repeat_chars(s) << "\n";
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

/*****************************************************************************************************/

// Method 2 (Using only hashing)

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

string non_repeat_chars(string s) {
    int n = s.size();
    vi first(26, -1);
    
    for(int i = 0; i < n; i++) {
        if(first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
    }
        
    vvi cs(n, vi(26, 0));
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        cs[i][x]++;
        if(i) {
            for(int j = 0; j < 26; j++) cs[i][j] += cs[i-1][j];
        }
    }
    
    string res = "";
    for(int i = 0; i < n; i++) {
        int can, pos = INT_MAX;
        for(int j = 0; j < 26; j++) {
            if(cs[i][j] == 1 and first[j] != -1 and first[j] < pos) {
            	pos = first[j];
                can = j;
            }
        }
        
        if(pos == INT_MAX) res += '#';
        else res += char(can + 'a');
    }
    
    return res;
}

void solve()
{
  	string s; cin >> s;
  	cout <<  non_repeat_chars(s) << "\n";
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