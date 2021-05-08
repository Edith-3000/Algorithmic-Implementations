/* Link: https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
         https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
   
   PROBLEM: You are given an array of 0's and 1's in random order. Segregate 0's on left side and 1's on 
            right side of the array. 
            TRAVERSE ARRAY ONLY ONCE.
            
            The below algorithm is based on Dutch National Flag Algorithm or 2-way partitioning.
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

// Pass the elements by reference
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Function to sort the input array, the array is assumed  
// to have values in {0, 1}  
void segregate_0_1(vi &v) {
    int n = (int)v.size();
    if(n == 0) return;
    
    int low = 0, high = n - 1;
    
    // Iterate till all the elements are sorted  
    while(low < high) {
        if(v[low] == 1) {
            swap(v[low], v[high]);
            high--;
        }
        
        else low++;
    }
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    segregate_0_1(v);
    for(auto x: v) cout << x << " ";
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

// TIme complexity: O(n)
// Space complexity: O(1)