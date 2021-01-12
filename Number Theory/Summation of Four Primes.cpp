// Useful links: https://www.geeksforgeeks.org/n-expressed-sum-4-prime-numbers/
//               https://www.geeksforgeeks.org/program-for-goldbachs-conjecture-two-primes-with-given-sum/

/***********************************************************************************************************/

// Problem: 10168 - Summation of Four Primes
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1109
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// Parsed on: 12-01-2021 11:42:08 IST (UTC+05:30)
// Author: kapil_choudhary

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
const int MAX = 1e7 + 1;

vector<bool> sieve(MAX, 0);
void SOE() {
	for(int i = 3; i < MAX; i += 2) sieve[i] = 1;
	sieve[2] = 1;
	for(int i = 3; (i * i) < MAX; i++) {
		if(sieve[i]) {
			for(int j = (i * i); j < MAX; j += i) sieve[j] = 0;
		}
	}
}

void driver(int n, int &c, int &d) {
	for(int i = 2; i < MAX; i++) {
		if(sieve[i] && sieve[n - i]) {
			c = i; d = n - i;
			return;
		}
	}
}

void solve(int n)
{
  	if(n <= 7) {
  		cout << "Impossible.\n";
  		return;
  	}
  	
  	int a, b, c, d;
  	if(n % 2 == 0) {
  		a = 2, b = 2;
  		n -= 4;
  		driver(n, c, d);
  	}
  	
  	else {
  		a = 2, b = 3;
  		n -= 5;
  		driver(n, c, d);
  	}
  	
  	cout << a << " " << b << " " << c << " " << d << "\n";
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
    // cin >> t;
    SOE();
    int n;
    while(cin >> n) {
      solve(n);
    }

    return 0;
}