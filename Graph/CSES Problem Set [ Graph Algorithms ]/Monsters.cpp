/* # The problem is similar to lava simulation out of volcanoes.
   # Basically there are 2 main parts of the below algorithm --->
     1. BFS all the volcanoes (monsters).
     2. BFS our player.

   # Very fine explanation: https://www.youtube.com/watch?v=hB59dxdDLII&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=9
 */

// Accepted code --->

// Problem: Monsters
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 28-02-2021 17:52:33 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

// g[i][j] = the minimum contamination time of the cell (i, j) with lava by any 
// of the volcanic eruption point (monster)
vector<vector<int>> g;

// key = child cell coordinate, value = parent cell coordinate 
map<pair<int, int>, pair<int, int>> par_map;

// to store the coordinates of monsters (volcanic eruption points)
vector<pair<int, int>> monsters;

// to visit the neighbouring cells
vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// st stores the coordiantes of 'A', ed stores the coordinates of
// escape cell (if found)
pair<int, int> st, ed;

int n, m;

bool is_valid(int x, int y, int timer) {
	// checking for out of bounds
	if(x < 0 || x >= n or y < 0 or y >= m) return false;
	
	// if the current minimum contamination time is less or
	// equal than the time which we want to set, then return false
	if(g[x][y] <= timer) return false;
	
	return true;
}

bool is_escape_cell(int x, int y, int timer) {
	if(!is_valid(x, y, timer)) return false;
	
	if(x == 0 or x == (n - 1) or y == 0 or y == (m - 1)) {
		return true;
	}
	
	return false;
}

bool bfs_escape() {
	queue<pair<pair<int, int>, int>> q;
	
	// we start BFS from 'A' (from where the player will start)
	q.push(make_pair(st, 0));
	
	// assigning parent cell to start
	par_map[st] = make_pair(-1, -1);
	
	while(!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int timer = q.front().second;
		timer++;
		
		// popping out this source
		q.pop();
		
		for(auto mv: moves) {
			int nx = cur_x + mv.first;
			int ny = cur_y + mv.second;
			
			if(is_escape_cell(nx, ny, timer)) {
				par_map[make_pair(nx, ny)] = make_pair(cur_x, cur_y);
				ed = make_pair(nx, ny);
				return true;
			}
			
			if(is_valid(nx, ny, timer)) {
				par_map[make_pair(nx, ny)] = make_pair(cur_x, cur_y);
				g[nx][ny] = timer;
				q.push(make_pair(make_pair(nx, ny), timer));
			}
		}
	}
	
	return false;
}

// function to calculate the minimum possible contamination time of each
// cell. Here multisource BFS is used (as using single source BFS multiple
// time will get TLE)
void preprocess_lava_flow() {
	queue<pair<pair<int, int>, int>> q;
	
	// inserting all the sources (monsters) in the queue
	for(auto mons: monsters) {
		q.push(make_pair(mons, 0));
	}
	
	while(!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int timer = q.front().second;
		timer++;
		
		// popping out this source
		q.pop();
		
		for(auto mv: moves) {
			int nx = cur_x + mv.first;
			int ny = cur_y + mv.second;
			
			if(is_valid(nx, ny, timer)) {
				// update the minimum contamination time of this cell
				g[nx][ny] = timer;
				q.push(make_pair(make_pair(nx, ny), timer));
			}
		}
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n);
  	for(int i = 0; i < n; i++) {
  		g[i].resize(m);
  	}
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			char ch; cin >> ch;
  			if(ch == '#') g[i][j] = 0;
  			
  			else if(ch == 'M') {
  				g[i][j] = 0;
  				monsters.push_back(make_pair(i, j));
  			}
  			
  			else if(ch == 'A') {
  				g[i][j] = 0;
  				st = make_pair(i, j);
  			}
  			
  			else g[i][j] = INT_MAX;
  		}
  	}
  	
  	if(st.first == 0 or st.first == (n - 1) or st.second == 0 or st.second == (m - 1)) {
  		cout << "YES\n";
  		cout << 0 << "\n";
  		return;
  	}
  	
  	preprocess_lava_flow();
  	
  	if(!bfs_escape()) {
  		cout << "NO\n";
  		return;
  	}
  	
  	cout << "YES\n";
  	pair<int, int> cur = ed;
  	pair<int, int> cur_par = par_map[cur];
  	pair<int, int> last = make_pair(-1, -1);
  	
  	// to store the path
  	string path = "";
  	
  	while(cur_par != last) {
  		if((cur.first - cur_par.first) == -1 and (cur.second - cur_par.second) == 0) {
  			path += "U";
  		}
  		
  		if((cur.first - cur_par.first) == 0 and (cur.second - cur_par.second) == 1) {
  			path += "R";
  		}
  		
  		if((cur.first - cur_par.first) == 1 and (cur.second - cur_par.second) == 0) {
  			path += "D";
  		}
  		
  		if((cur.first - cur_par.first) == 0 and (cur.second - cur_par.second) == -1) {
  			path += "L";
  		}
  		
  		cur = par_map[cur];
  		cur_par = par_map[cur];
  	}
  	
  	reverse(path.begin(), path.end());
  	
  	cout << path.length() << "\n";
  	cout << path << "\n";
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
    while(t--) {
      solve();
    }

    return 0;
}

/*****************************************************************************************************/

// Code which got TLE in one test case because of not using multisource BFS and instead using
// single source BFS multiple times in the preprocess_lava_flow() function --->

// Problem: Monsters
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 28-02-2021 17:52:33 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

// g[i][j] = the minimum contamination time of the cell (i, j) with lava
vector<vector<int>> g;

// key = child cell coordinate, value = parent cell coordinate 
map<pair<int, int>, pair<int, int>> par_map;

// to store the coordinates of monsters (volcanic eruption points)
vector<pair<int, int>> monsters;

// to visit the neighbouring cells
vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// st stores the coordiantes of 'A', ed stores the coordinates of
// escape cell (if found)
pair<int, int> st, ed;

int n, m;

bool is_valid(int x, int y, int timer) {
	// checking for out of bounds
	if(x < 0 || x >= n or y < 0 or y >= m) return false;
	
	// if the current minimum contamination time is less or
	// equal than the time which we want to set, then return false
	if(g[x][y] <= timer) return false;
	
	return true;
}

bool is_escape_cell(int x, int y, int timer) {
	if(!is_valid(x, y, timer)) return false;
	
	if(x == 0 or x == (n - 1) or y == 0 or y == (m - 1)) {
		return true;
	}
	
	return false;
}

bool bfs_escape() {
	queue<pair<pair<int, int>, int>> q;
	
	// we start BFS from 'A' (from where the player will start)
	q.push(make_pair(st, 0));
	
	// assigning parent cell to start
	par_map[st] = make_pair(-1, -1);
	
	while(!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int timer = q.front().second;
		timer++;
		
		// popping out this source
		q.pop();
		
		for(auto mv: moves) {
			int nx = cur_x + mv.first;
			int ny = cur_y + mv.second;
			
			if(is_escape_cell(nx, ny, timer)) {
				par_map[make_pair(nx, ny)] = make_pair(cur_x, cur_y);
				ed = make_pair(nx, ny);
				return true;
			}
			
			if(is_valid(nx, ny, timer)) {
				par_map[make_pair(nx, ny)] = make_pair(cur_x, cur_y);
				g[nx][ny] = timer;
				q.push(make_pair(make_pair(nx, ny), timer));
			}
		}
	}
	
	return false;
}

// function to calculate the minimum possible contamination time of each
// cell. Here single source BFS is used multiple times WHICH WILL GET TLE
// IN SOME OF THE TEST CASES.
void preprocess_lava_flow() {
	queue<pair<pair<int, int>, int>> q;
	
	// inserting all the sources one by one in the queue
	// i.e. performing single sorce BFS multiple times
	for(auto mons: monsters) {
		q.push(make_pair(mons, 0));
		
		while(!q.empty()) {
			int cur_x = q.front().first.first;
			int cur_y = q.front().first.second;
			int timer = q.front().second;
			timer++;
			
			// popping out this source
			q.pop();
			
			for(auto mv: moves) {
				int nx = cur_x + mv.first;
				int ny = cur_y + mv.second;
				
				if(is_valid(nx, ny, timer)) {
					// update the minimum contamination time of this cell
					g[nx][ny] = timer;
					q.push(make_pair(make_pair(nx, ny), timer));
				}
			}
	    }
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n);
  	for(int i = 0; i < n; i++) {
  		g[i].resize(m);
  	}
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			char ch; cin >> ch;
  			if(ch == '#') g[i][j] = 0;
  			
  			else if(ch == 'M') {
  				g[i][j] = 0;
  				monsters.push_back(make_pair(i, j));
  			}
  			
  			else if(ch == 'A') {
  				g[i][j] = 0;
  				st = make_pair(i, j);
  			}
  			
  			else g[i][j] = INT_MAX;
  		}
  	}
  	
  	if(st.first == 0 or st.first == (n - 1) or st.second == 0 or st.second == (m - 1)) {
  		cout << "YES\n";
  		cout << 0 << "\n";
  		return;
  	}
  	
  	preprocess_lava_flow();
  	
  	if(!bfs_escape()) {
  		cout << "NO\n";
  		return;
  	}
  	
  	cout << "YES\n";
  	pair<int, int> cur = ed;
  	pair<int, int> cur_par = par_map[cur];
  	pair<int, int> last = make_pair(-1, -1);
  	
  	// to store the path
  	string path = "";
  	
  	while(cur_par != last) {
  		if((cur.first - cur_par.first) == -1 and (cur.second - cur_par.second) == 0) {
  			path += "U";
  		}
  		
  		if((cur.first - cur_par.first) == 0 and (cur.second - cur_par.second) == 1) {
  			path += "R";
  		}
  		
  		if((cur.first - cur_par.first) == 1 and (cur.second - cur_par.second) == 0) {
  			path += "D";
  		}
  		
  		if((cur.first - cur_par.first) == 0 and (cur.second - cur_par.second) == -1) {
  			path += "L";
  		}
  		
  		cur = par_map[cur];
  		cur_par = par_map[cur];
  	}
  	
  	reverse(path.begin(), path.end());
  	
  	cout << path.length() << "\n";
  	cout << path << "\n";
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
    while(t--) {
      solve();
    }

    return 0;
}