/* Problem description ---->

Vivek takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control 
on the die (singular), and could get it to generate any number (in the range 1-6 ) he desired, what would 
be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number 
100) after having started at the base square (Square Number 1)?

RULES -->

1. Vivek has total control over the die and the face which shows up every time he tosses it.
   You need to help him figure out the minimum number of moves in which he can reach the target square (100) 
   after starting at the base (Square 1).

2. A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the 
   player remains at his original square. Such as a case when the player is at Square Number 99, rolls 
   the die, and ends up with a 5.

3. If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he 
   cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go 
   down the snake and come out through the tail - there is no way to climb down a ladder or to go up through 
   a snake.

Input Format ---->
The first line contains the number of tests, T. T testcases follow.

For each testcase, the first line contain N(Number of ladders) and after that N line follow. 
Each of the N line contain 2 integer representing the starting point and the ending point of a ladder 
respectively.

The next line contain integer M(Number of snakes) and after that M line follow. Each of the M line contain 
2 integer representing the starting point and the ending point of a snake respectively.

Constraints----->
The board is always of the size 10 X 10 and Squares are always numbered 1 to 100 .
1 <= T <= 10
1 <= No. of ladder <= 15
1 <= No. of Snakes <= 15
Square number 1 and 100 will not be the starting point of a ladder or a snake. 
No square will have more than one of the starting or ending point of a snake or ladder (e.g. snake 56 to 44 
and ladder 44 to 97 is not possible because 44 has both ending of a snake and a starting of a ladder).

Output Format
For each of the T test cases, output one integer, each in a new line, which is the least number of moves 
(or rolls of the die) in which the player can reach the target square (Square Number 100) after starting 
at the base (Square Number 1). This corresponds to the ideal sequence of faces which show up when the 
die is rolled.

If there is no solution, print -1.

Sample Input ---->
2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 

Sample Output --->
3
5

Explanation ---->
For the first test: To traverse the board via the shortest route, the player first rolls the die to get 
a 5, and ends up at square 6. He then rolls the die to get 6. He ends up at square 12, from where he climbs
the ladder to square 98. He then rolls the die to get '2', and ends up at square 100, which is the target 
square. So, the player required 3 rolls of the die for this shortest and best case scenario. So the answer 
for the first test is 3.

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 101;

vvi g;
vi dis;
vi board;
int n, m;

void sssp_by_bfs() {
	dis.clear();
	dis.resize(N);
	dis.assign(N, -1);
	dis[1] = 0;
	
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		if(curr == 100) break;
		
		for(auto x: g[curr]) {
			if(dis[x] == -1) {
				dis[x] = dis[curr] + 1;
				q.push(x);
			}
		}
	}
}

void solve()
{	
	board.clear();
  	board.resize(N, 0);
  	
  	cin >> n;
  	for(int i = 0; i < n; i++) {
  		int ls, le; cin >> ls >> le;
  		board[ls] = le - ls;
  	}
  	
  	cin >> m;
  	for(int i = 0; i < m; i++) {
  		int ss, se; cin >> ss >> se;
  		board[ss] = -(ss - se);
  	}
  	
  	g.clear();
  	g.resize(N);
  	for(int v = 1; v < N; v++) {
  		for(int dice = 1; dice <= 6; dice++) {
  			int j = v + dice;
  			j += board[j];
  			if(j < N) g[v].pb(j);
  		}
  	}
  	
  	sssp_by_bfs();
  	cout << dis[100] << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}