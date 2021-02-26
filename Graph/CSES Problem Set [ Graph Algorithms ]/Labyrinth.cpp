// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 11-12-2020 08:13:27 IST (UTC+05:30)
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
 
vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};
 
const int mod = 1e9+7;
char grid[1000][1000];
int d[1000][1000];
char par[1000][1000];
int n, m;
 
bool is_valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}
 
char set_par(int k){
	if(k == 0) return 'U';
	else if(k == 1) return 'R';
	else if(k == 2) return 'D';
	else return 'L';
}
 
void bfs(int sx, int sy){
	queue<pii> q;
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;
	
	while(!q.empty()){
		pii p = q.front();
		q.pop();
		
		if(grid[p.F][p.S] == 'B'){
			cout << "YES\n" << d[p.F][p.S] << "\n";
			string path = "";
			
			int i = p.F, j = p.S;
			while(grid[i][j] != 'A'){
				path.pb(par[i][j]);
				if(par[i][j] == 'U') i++;
				else if(par[i][j] == 'D') i--;
				else if(par[i][j] == 'L') j++;
				else j--; 
			}
			
			reverse(path.begin(), path.end());
			cout << path;
			exit(0);
		}
		
		for(int k = 0; k < 4; k++){
			int nx = p.F + dx[k], ny = p.S + dy[k];
			if(is_valid(nx, ny) && grid[nx][ny] != '#' && d[nx][ny] == INT_MAX){
				d[nx][ny] = d[p.F][p.S] + 1;
				par[nx][ny] = set_par(k);
				q.push({nx, ny});
			}
		}
	} 
}
 
void solve()
{
  	cin >> n >> m;
  	int sx, sy;
  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < m; j++){
  			cin >> grid[i][j];
  			grid[i][j] != 'A' ? d[i][j] = INT_MAX : (d[i][j] = 0, sx = i, sy = j);
  		}
  	}
  	
  	bfs(sx, sy);
  	
  	cout << "NO";
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