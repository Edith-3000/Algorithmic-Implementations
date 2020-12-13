// Problem: Expedition
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/EXPEDI/
// Memory Limit: 1536 MB
// Time Limit: 2307 ms
// Parsed on: 13-12-2020 16:12:31 IST (UTC+05:30)
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

void solve()
{
  	int n; cin >> n;
  	vpii v(n);
  	for(int i = 0; i < n; i++){
  		cin >> v[i].F >> v[i].S;
  	}
  	
  	int d, f; cin >> d >> f;
  	
  	sort(v.begin(), v.end(), greater<pii>()); 
  	for(int i = 0; i < n; i++) v[i].F = d - v[i].F; 
  	priority_queue<int> q;
  	bool flag = true;
  	int res = 0, i = 0, prev = 0;
  	
  	while(i < n){
  		if(f >= (v[i].F - prev)){
  			f -= (v[i].F - prev);
  			q.push(v[i].S);
  			prev = v[i].F;
  		}
  		
  		else{
  			if(!q.empty()){
  				res++;
  				f += q.top();
  				q.pop();
  				continue;
  			}
  			
  			else{
  				flag = false;
  				break;
  			}
  		}
  		
  		i++;
  	}
  	
  	if(!flag){
  		cout << -1 << "\n";
  		return;
  	}
  	
  	d -= v[n-1].F;
  	if(f >= d){
  		cout << res << "\n";
  		return;
  	}
  	
  	while(f < d){
  		if(q.empty()){
  			flag = false;
  			break;
  		}
  		
  		res++;
  		f += q.top();
  		q.pop();
  	}
  	
  	if(!flag) cout << -1 << "\n";
  	else cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}