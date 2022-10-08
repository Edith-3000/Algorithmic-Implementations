// Prob: https://leetcode.com/problems/design-twitter/

/******************************************************************************************************************************************************/

// METHOD - 1
// Ref: https://www.youtube.com/watch?v=pNichitDD2E&ab_channel=NeetCode

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

struct node {
	int tweetTimestamp;
	int tweetId;
	int userId;
	int tweetIndex;
};

class myComparator {
	public:
		bool operator() (const node &node1, const node &node2) {
			return node1.tweetTimestamp < node2.tweetTimestamp;
		}
};

class Twitter {
	private:
			int timestamp; // to put timestamp on each tweet
	        map<int, set<int>> followMap; // userId -> set of all followeeId
	        map<int, vpii> tweetMap; // userId -> vector of pair(timestamp of tweet, tweetId)
	
	public:
	    Twitter() {
	        timestamp = 0;
	        followMap.clear();
	        tweetMap.clear();
	    }
	    
	    void postTweet(int userId, int tweetId) {
	        tweetMap[userId].pb({timestamp, tweetId});
	        timestamp += 1;
	    }
	    
	    vector<int> getNewsFeed(int userId) {
	        priority_queue<node, vector<node>, myComparator> max_heap;
	        
	        if(sz(tweetMap[userId]) != 0) {
	        	int len = sz(tweetMap[userId]);
	        	
	        	node x;
	        	
	        	x.tweetTimestamp = tweetMap[userId][len - 1].F;
	        	x.tweetId = tweetMap[userId][len - 1].S;
	        	x.userId = userId;
	        	x.tweetIndex = len - 1;
	        	
	        	max_heap.push(x);
	        }
	        
	        for(int followeeId: followMap[userId]) {
	        	int len = sz(tweetMap[followeeId]);
	        	
	        	if(len == 0) continue;
	        	
	        	node x;
	        	
	        	x.tweetTimestamp = tweetMap[followeeId][len - 1].F;
	        	x.tweetId = tweetMap[followeeId][len - 1].S;
	        	x.userId = followeeId;
	        	x.tweetIndex = len - 1;
	        	
	        	max_heap.push(x);
	        }
	        
	        vi res;
	        
	        while(!max_heap.empty() and (sz(res) < 10)) {
	        	node top_node = max_heap.top();
	        	max_heap.pop();
	        	
	        	res.pb(top_node.tweetId);
	        	
	        	if(top_node.tweetIndex == 0) continue;
	        	
	        	node x;
	        	
	        	x.tweetTimestamp = tweetMap[top_node.userId][top_node.tweetIndex - 1].F;
	        	x.tweetId = tweetMap[top_node.userId][top_node.tweetIndex - 1].S;
	        	x.userId = top_node.userId;
	        	x.tweetIndex = top_node.tweetIndex - 1;
	        	
	        	max_heap.push(x);
	        }
	        
	        return res;
	    }
	    
	    void follow(int followerId, int followeeId) {
	        followMap[followerId].insert(followeeId);
	    }
	    
	    void unfollow(int followerId, int followeeId) {
	        set<int> &followeeIds = followMap[followerId];
	        
	        if(followeeIds.find(followeeId) != followeeIds.end()) {
	        	followeeIds.erase(followeeId);
	        }
	    }
};

void solve()
{
  	class Twitter T;
  	
  	int q; cin >> q;
  	
  	// 0 - postTweet(), 1 = getNewsFeed(), 2 = follow(), 3 = unfollow()
  	while(q--) {
  		int typ; cin >> typ;
  		
  		if(typ == 0) {
  			int userId, tweetId; 
  			cin >> userId >> tweetId;
  			
  			T.postTweet(userId, tweetId);
  		}
  		
  		else if(typ == 1) {
  			int userId; cin >> userId;
  			vi res = T.getNewsFeed(userId);
  			
  			for(auto x: res) {
  				cout << x << " ";
  			}
  			
  			cout << "\n";
  		}
  		
  		else if(typ == 2) {
  			int followerId, followeeId;
  			cin >> followerId >> followeeId;
  			
  			T.follow(followerId, followeeId);
  		}
  		
  		else {
  			int followerId, followeeId;
  			cin >> followerId >> followeeId;
  			
  			T.unfollow(followerId, followeeId);
  		}
  	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

/******************************************************************************************************************************************************/

// METHOD - 2 (MORE OBJECT ORIENTED APPROACH)
// Ref: https://leetcode.com/problems/design-twitter/discuss/82825/Java-OO-Design-with-most-efficient-function-getNewsFeed