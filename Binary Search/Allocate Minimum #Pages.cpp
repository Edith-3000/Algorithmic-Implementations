/* # Link: https://www.geeksforgeeks.org/allocate-minimum-number-pages/

   Problem: Given number of pages in n different books and m students. The books are arranged in any order
		    (not necessarily in asc or desc. order). Every student is assigned to read some consecutive books. 
            The task is to assign books in such a way that the maximum number of pages assigned to a student 
            are minimum.
            Restrictions: 1). One book can be read by one student only.
                          2). Every student is to be assigned atleast one book.
                          3). No book can be left unassigned.
                          4). A student is to be assigned only those books which are consecutive.

   # Ref: https://www.youtube.com/watch?v=2JSQIhPcHQg&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=21
*/

/* # This problem is very famous & in it's variants you just have to modify the is_valid() function.
     Here k are the #students among whom books are to be assigned.
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

bool is_valid(vi &v, int k, ll mid) {
	// for storing # students
	int students = 1;
	
	// for storing #pages which can be read by each student 
	// under given circumstances that every student can be 
	// assigned at most mid #pages
	ll sum = 0LL; 

	for(int i = 0; i < (int)v.size(); i++) {
		sum += v[i];
	   
	    // no student can be assigned pages > mid
	    if(sum > mid) {
	        students++; // start assigning pages to next student
	        sum = v[i]; // 1st book assigned to the new student
	    }
	   
	    // scheme of assigning pages to a student not more than mid 
	    // fails bcoz under given scheme we require more #students
	    if(students > k) return false; 
	}
	
	return true; 
}

ll allocate_min_pages(vi &v, int k) {
	// #books
	int n = (int)v.size(); 
	
	// since every student is to be assigned at least 1 book
	if(n < k) return -1; 
    
    ll sum = 0LL; 
	for(int i = 0; i < n; i++) sum += v[i];

	ll start = *max_element(v.begin(), v.end());
    ll end = sum;
	ll res = -1; // for storing the result   

	while(start <= end) {
	    ll mid = start + (end - start) / 2;

	    if(is_valid(v, k, mid)) {
	       res = mid; // i.e. mid can be a possible answer
	       end = mid - 1; // to search for a more minimum value, if possible
	    }
		
	    // i.e. the mid found was much lower than required & burden on 
	    // each student needs to be increased
	    else start = mid + 1; 
	}
	
	// -1 is returned if scheme not possible
	return res; 
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << allocate_min_pages(v, k) << "\n";
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

// Time complexity: O(n x log(s)), where s is the summation of all vector elements.