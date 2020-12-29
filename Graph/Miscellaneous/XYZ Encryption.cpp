/* Problem description --->

Mike has a string, s of length n and it consists of only 3 characters 'x', 'y' and 'z'. Now he wants to encrypt 
the string in the form of a graph. To convert the string into a graph, he considers n nodes numbered from 1 to n. 
There is an edge between node u and node v, if and only if:

1. *s[u]* and *s[v]* are same.
2. *s[u]* and *s[v]* are neighboring characters, i.e. "x"-"y" or "y"-"z".

Now he has lost the string, but he has a graph. He wants to check whether there is a string corresponding to 
this graph or not.
You can observe that a string will form only one graph, but a graph can represent multiple strings.

Input Format --->
First line contains two integers, n and m, denoting the number of nodes and the number of edges in the graph.
Next m lines contains two integers each, u and v, denoting that there is an edge between them.

Constraints --->
1<=n<=500 0<=m<=n(n-1)/2 1<=u,v<=n, u is not equal to v. All the edges are unique.

Output Format --->
Print "Yes" if the given graph can represent a string(or strings). Print "No" otherwise.

Sample Input --->

3 1
1 2

Sample Output --->

Yes

Explanation --->
String "xxz" is one of the strings that will form the given graph.

*/ 

/* Approach --->
   First observation is that, if two nodes, u and v are not connected, then one of them is “x” and another one 
   is “z”. Second observation is that if is a set of nodes with value “x”, and set is a set of nodes with 
   value “z”, then interchanging them will not change the encrypted graph, i.e. assign value “z” to set and 
   value “x” to set . So first we will search for a pair of nodes, u and v , which are not connected, assign 
   one of them to “x” and another to “z”. Now for the rest of the nodes, if a node, w is connected to both 
   u and v , assign value “y” to it. If a node, w is connected to node u only, then assign value “x” to it. 
   If a node, w is connected to node v only, then assign value “z” to it. Now since you have assigned values to 
   all of the nodes, for every pair of nodes, check whether it satisfies the rules of encryption. If it does 
   not, then answer is NO.
*/

// Below is the link for another implementation of the same idea other than code in this file --->
// https://ide.codingblocks.com/s/340582?_ga=2.100303254.922549758.1608786049-317025203.1608553080

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
// #define mp make_pair
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

char g[501][501];
unordered_map<int, char> mp;
int n, m, v1, v2;

void solve()
{
  	cin >> n >> m;
  	for(int i = 1; i <= n; i++) {
  		for(int j = 1; j <= n; j++) g[i][j] = '0';
  	}
  	
  	for(int i = 1; i <= m; i++) {
  		int u, v; cin >> u >> v;
  		g[u][v] = '1';
  		g[v][u] = '1';
  	}
  	
  	v1 = -1, v2 = -1;
  	for(int i = 1; i <= n; i++) {
  		for(int j = 1; j <= n; j++) {
  			if(i != j && g[i][j] == '0') {
  				v1 = i; v2 = j;
  				break; 
  			}
  		}
  		
  		if(v1 != -1) break;
  	}
  	
  	// if all the nodes are pairwise connected, then you cn assign 
  	// same value to all the nodes or (x & y) or (y & z)
  	if(v1 == -1) {
  		cout << "Yes\n";
  	}
  	
  	else {
  		mp[v1] = 'x'; mp[v2] = 'z';
  		
  		// assigning values to nodes
  		for(int i = 1; i <= n; i++) {
  			// node is connected to both v1 and v2
  			if(g[i][v1] == '1' && g[i][v2] == '1') mp[i] = 'y';
  			
  			// connected to only v1
  			else if(g[i][v1] == '1' && g[i][v2] == '0') mp[i] = 'x';
  			
  			// connected to only v2
  			else if(g[i][v1] == '0' && g[i][v2] == '1') mp[i] = 'z';
  		}
  		
  		// case in which there was atleast 1 node which was
  		// neither connected to v1 nor to v2 (i.e. #connected components
  		// are > 2)
  		if(mp.size() != n) cout << "No\n";
  		
  		// verifying the encryption
  		else {
  			bool res = true;
  			for(int i = 1; i <= n; i++) {
  				for(int j = 1; j <= n; j++) {
  					if(i == j) continue;
  					
  					// "x"-"x", "x-y", "y"-"y", "y"-"z", "z"-"z" should be connected, otherwise answer is No.
  					if((mp[i] == mp[j]) || (mp[i] == 'x' && mp[j] == 'y') || (mp[i] == 'y' && mp[j] == 'x') || 
  				   	   (mp[i] == 'y' && mp[j] == 'z') || (mp[i] == 'z' && mp[j] == 'y')) {
  						if(g[i][j] != '1') {
  							res = false;
  							break;
  					    }
  				    }
  				    
  				    // "x"-"z" should not be connected.
  				    else {
  				    	if(g[i][j] == '1') {
  				    		res = false;
  				    		break;
  				    	}
  				    }
  			    }  
  			
  				if(!res) break;
  		     }
  		
  			 cout << (res ? "Yes\n" : "No\n"); 
  		} 		
  	}
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