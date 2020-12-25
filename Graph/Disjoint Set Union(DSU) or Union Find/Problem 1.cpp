/* Problem description ---->

There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first 
city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format --->
The first line contains two integers, N and M separated by a single space. M lines follow. 
Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints --->
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format --->
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input --->
5 3
0 1
2 3
0 4

Sample Output --->
6

Explanation --->
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) 
hence 6 ways.

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

const int mod = 1e9+7;

ll find_set(ll v, vector<ll> &parent)
{
	if(parent[v]==-1)
		return v;
		
	return parent[v] = find_set(parent[v], parent);
}

void union_sets(ll a, ll b, vector<ll> &parent, vector<ll> &size)
{
	a = find_set(a, parent);
	b = find_set(b, parent);
	
	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
			
		parent[b] = a;
		size[a] += size[b]; 
	}
}

void solve()
{
  	ll n, m; cin>>n>>m;
  	vector<ll> parent(n, -1);
  	vector<ll> size(n, 1);
  	
  	for(ll i=0; i<n; i++)
  	{
  		ll x, y; cin>>x>>y;
  		union_sets(x, y, parent, size);
  	}
  	
  	ll res=0, sum=0;
  	for(ll i=0; i<n; i++)
  	{
  		if(parent[i]==-1)
  		{
  			res += (sum*size[i]);
  			sum += size[i];
  		}
  	}
  	
  	cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}