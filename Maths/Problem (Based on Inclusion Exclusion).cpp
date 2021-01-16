/* Problem description --->

After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the 
number of numbers between 1 and n which are divisible by any of the prime numbers less than 20. Ironman being 
great at maths quickly answered the question but then Thor asked him to write a program for it. Ironman however
found it quite difficult as he did not wanted to write so many lines of code. he knows that you are smart and 
can code this up easily. Can you do it?

Input Format
The first line consists of number of test cases t. then follow t lines which consists of number n for each test case.

Constraints
1 <= test cases <= 10 
1 <= n <= 10^18

Output Format
the answer to each test case each in different line

Sample Input
5
5
10
12
15
18

Sample Output
4
9
11
14
17

Explanation
for n = 5 2 and 4 are divisible by 2 and 3 is divisible by 3 and 5 by 5. hence ans = 4.

*/

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

vi v {2, 3, 5, 7, 11, 13, 17, 19};

ll GCD(ll a, ll b) {
	return (b == 0) ? a : GCD(b, a % b);
}

void solve()
{
  	ll n; cin >> n;
  	ll res = 0;
  	for(ll mask = 1; mask < (1 << v.size()); mask++) {
  		ll lcm = 1; ll cnt = __builtin_popcountll(mask);
  		for(ll i = 0; i < v.size(); i++) {
  			if(mask & (1 << i)) lcm = (lcm * v[i]) / GCD(lcm, v[i]);
  		}
  		
  		if(cnt & 1) res += (n / lcm);
  		else res -= (n / lcm);
  	}
  	
  	cout << res << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}