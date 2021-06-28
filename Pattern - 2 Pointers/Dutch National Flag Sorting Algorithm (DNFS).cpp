/* Link: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
         https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/

   PROBLEM: Given an array of red, green and blue colors arrange them in groups of all red together, greens 
            together and blue together (Dutch National Flag Algorithm or 3-way Partitioning). 
                                             OR
            Array containing only '0's, '1's and '2's. Club same items together in single scan.

            NOTE - Do in a single scan of the array.
*/

// Another problem based on similar concept --->
// https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/

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
// to have values in {0, 1, 2}  
void DNFS(vi &v) {
    int n = (int)v.size();
    if(n == 0) return;
    
    int low = 0, mid = 0, high = n - 1;
    
    // Iterate till all the elements are sorted  
    while(mid <= high) {
        switch(v[mid]) {
            // If the element is 0
            case 0: swap(v[low], v[mid]);
                    low++; mid++;
                    break;
            
            // If the element is 1  
            case 1: mid++;
                    break;
            
            // If the element is 2
            case 2: swap(v[mid], v[high]);
                    high--;
                    break;
        }
    }
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    DNFS(v);
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

// Time Complexity: O(n), Only one traversal of the array is needed.
// Space Complexity: O(1), No extra space is required.