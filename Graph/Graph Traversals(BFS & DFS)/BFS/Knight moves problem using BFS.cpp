// PROBLEM LINK: https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

/***********************************************************************************************************/

// NOTE: Both the below codes ARE CORRECT and got AC on UVa OJ
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380

/**********************************************************************************************************/

// METHOD - 1 (Using std::set as visited in BFS)

// Problem: 439 - Knight Moves
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// Parsed on: 04-12-2020 16:07:30 IST (UTC+05:30)
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

vi dx{2, 2, -2, -2, 1, 1, -1, -1};
vi dy{-1, 1, 1, -1, 2, -2, 2, -2};

struct Node{
	int x, y, dist;
	Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
	bool operator < (const Node &n) const{
		return (x < n.x) || ((x == n.x) && (y < n.y));
	}
};

bool is_valid(int i, int j){
	if(i < 1 || i > 8 || j < 1 || j > 8) return false;
	return true;
}

 inline size_t key(int i,int j){
 	return (size_t) i << 32 | (unsigned int) j;
}

int bfs(Node start, Node end){
	unordered_map<size_t, bool> visited;
	queue<Node> q;
	q.push(start);
	visited[key(start.x, start.y)] = true;
	
	while(!q.empty()){
		Node curr = q.front();
		int x = curr.x, y = curr.y, dist = curr.dist;
		q.pop();
		
		if((x == end.x) && (y == end.y)) return dist;
		
		for(int i = 0; i < 8; i++){
			int x1 = x + dx[i], y1 = y + dy[i];
			if(is_valid(x1, y1)){
				if(visited.find(key(x1, y1)) == visited.end()){
					visited[key(x1, y1)] = true;;
					q.push({x1, y1, dist+1});
				}
			}
		}
	}
	
	return INT_MAX;
}

void solve(string s, string e)
{
  	int si = s[1] - '0'; 
  	int sj = s[0] - 'a' + 1;
  	Node start = {si, sj};
  	
  	int ei = e[1] - '0';
  	int ej = e[0] - 'a' + 1;
  	Node end = {ei, ej};
  
  	cout << "To get from " << s << " to " << e << " takes ";
  	cout << bfs(start, end) << " knight moves.\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // int t = 1;
    // cin >> t;
    string s, e;
    while(cin >> s >> e) {
      solve(s, e);
    }

    return 0;
}

/***********************************************************************************************************/

// METHOD - 2 (Using custom made unordered_map as visited in BFS)
// For the custom hash function used below visit --->
// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key

// Problem: 439 - Knight Moves
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// Parsed on: 04-12-2020 16:07:30 IST (UTC+05:30)
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

vi dx{2, 2, -2, -2, 1, 1, -1, -1};
vi dy{-1, 1, 1, -1, 2, -2, 2, -2};

struct Node{
	int x, y, dist;
	Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
	bool operator < (const Node &n) const{
		return (x < n.x) || ((x == n.x) && (y < n.y));
	}
};

bool is_valid(int i, int j){
	if(i < 1 || i > 8 || j < 1 || j > 8) return false;
	return true;
}

int bfs(Node start, Node end){
	set<pii> visited;
	queue<Node> q;
	q.push(start);
	visited.insert({start.x, start.y});
	
	while(!q.empty()){
		Node curr = q.front();
		int x = curr.x, y = curr.y, dist = curr.dist;
		q.pop();
		
		if((x == end.x) && (y == end.y)) return dist;
		
		for(int i = 0; i < 8; i++){
			int x1 = x + dx[i], y1 = y + dy[i];
			if(is_valid(x1, y1)){
				if(visited.count({x1, y1}) == 0){
					visited.insert({x1, y1});
					q.push({x1, y1, dist+1});
				}
			}
		}
	}
	
	return INT_MAX;
}

void solve(string s, string e)
{
  	int si = s[1] - '0'; 
  	int sj = s[0] - 'a' + 1;
  	Node start = {si, sj};
  	
  	int ei = e[1] - '0';
  	int ej = e[0] - 'a' + 1;
  	Node end = {ei, ej};
  
  	cout << "To get from " << s << " to " << e << " takes ";
  	cout << bfs(start, end) << " knight moves.\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // int t = 1;
    // cin >> t;
    string s, e;
    while(cin >> s >> e) {
      solve(s, e);
    }

    return 0;
}

// For both the above methods ---->
// Time complexity: O(n^2).
// At worst case, all the cells will be visited so time complexity is O(n^2).

// Auxiliary Space: O(n^2).
// where n = size of chess board (here it is = 8)