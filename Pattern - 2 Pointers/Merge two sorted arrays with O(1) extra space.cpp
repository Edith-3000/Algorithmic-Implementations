// Ref: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
//      https://www.youtube.com/watch?v=hVl2b3bLzBw
/*******************************************************************************************************/

// Method 1 (Time complexity: O(n * m))

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

// Pass the vectors by reference
void merge_sorted(vi &v1, vi &v2) {
	int n = (int)v1.size();
	int m = (int)v2.size();
	
	// Now traverse the v1 and if first element of v2
    // is less than current element of v1 then swap
	for(int i = 0; i < n; i++) {
		if(v2[0] < v1[i]) {
			int tmp = v1[i];
			v1[i] = v2[0];
			v2[0] = tmp;
			
			// After swaping we have to place element v2[0]
            // in correct position
			
			// We will store the first element of v2 and left shift 
			// all the element and store the first element in v2[k-1]
			int element = v2[0];
			int k = 1;
			
			for(; k < m and v2[k] < element; k++) {
				v2[k-1] = v2[k];
			}
			
			v2[k-1] = element;
		}
	}
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vi v1(n), v2(m);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < m; i++) cin >> v2[i];
  	
  	merge_sorted(v1, v2);
  	
  	for(int i = 0; i < n; i++) cout << v1[i] << " ";
  	cout << "\n";
  	
  	for(int i = 0; i < m; i++) cout << v2[i] << " ";
  	cout << "\n";
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

// Worst case TC: O(n * m)
// Space complexity: O(1)

/***************************************************************************************************/

// Ref: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
// Method 2 (Time complexity: O(n + m) + nlogn + mlogm)

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

// Pass the vectors by reference
void merge_sorted(vi &v1, vi &v2) {
	int n = (int)v1.size();
	int m = (int)v2.size();
	
	int i = 0, j = 0, k = n - 1;
	while(i <= k and j < m) {
		if(v1[i] < v2[j]) i++;
		else swap(v2[j++], v1[k--]);
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vi v1(n), v2(m);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < m; i++) cin >> v2[i];
  	
  	merge_sorted(v1, v2);
  	
  	for(int i = 0; i < n; i++) cout << v1[i] << " ";
  	cout << "\n";
  	
  	for(int i = 0; i < m; i++) cout << v2[i] << " ";
  	cout << "\n";
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

/*************************************************************************************************/

// Ref: https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
//      https://medium.com/swlh/merge-two-sorted-arrays-without-extra-space-efficiently-o-1-gap-method-detailed-simplified-57a336146601
//      https://www.youtube.com/watch?v=hVl2b3bLzBw
// Method 3 (Using GAP method) (Time complexity: O((n + m) * log(n + m)))

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

int next_gap(int n) {
	if(n <= 1) return 0;
	return (n + 1) / 2;
}

// Pass the vectors by reference
void merge_sorted(vi &v1, vi &v2) {
	int n = (int)v1.size();
	int m = (int)v2.size();
	
	int i, j, gap = n + m;
	
	for(gap = next_gap(gap); gap > 0; gap = next_gap(gap)) {
		// comparing elements in the first vector
		for(i = 0; (i + gap) < n; i++) {
			if(v1[i] > v1[i+gap]) swap(v1[i], v1[i+gap]);
		}
		
		for(j = ((gap > n) ? (gap - n) : 0); i < n and j < m; i++, j++) {
			if(v1[i] > v2[j]) swap(v1[i], v2[j]);
		}
		
		if(j < m) {
			for(j = 0; (j + gap) < m; j++) {
				if(v2[j] > v2[j+gap]) swap(v2[j], v2[j+gap]);
		    }
		}
	}
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vi v1(n), v2(m);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < m; i++) cin >> v2[i];
  	
  	merge_sorted(v1, v2);
  	
  	for(int i = 0; i < n; i++) cout << v1[i] << " ";
  	cout << "\n";
  	
  	for(int i = 0; i < m; i++) cout << v2[i] << " ";
  	cout << "\n";
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

/**************************************************************************************************/

// NOTE1: A solution can also be viewed at: --->
// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

// ALthough it is not O(1) space solution

// NOTE2: For a similar kind of problem at LeetCode: --->
// https://leetcode.com/problems/merge-sorted-array/

// See the following approach:--->
// https://www.youtube.com/watch?v=C4oBXLr3zos