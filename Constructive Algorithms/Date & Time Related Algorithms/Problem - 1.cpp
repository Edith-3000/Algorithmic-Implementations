// Problem: Chef and Meetings
// Contest: CodeChef - February Challenge 2021 Division 3
// URL: https://www.codechef.com/FEB21C/problems/MEET
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 10-02-2021 11:10:50 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

struct Time {
	int HH, MM;
	bool operator<(const Time &T) {
		if(HH == T.HH) return MM <= T.MM;
		return HH < T.HH;
	}
	
	bool operator==(const Time &T) {
		return (HH == T.HH) && (MM == T.MM);
	}
};

// https://www.geeksforgeeks.org/program-convert-time-12-hour-24-hour-format/
struct Time convert_to_24(string s) { 
	int h0 = s[0] - '0'; 
	int h1 = s[1] - '0'; 
	int hh = (h0 * 10 + h1);
	
	int m3 = s[3] - '0'; 
	int m4 = s[4] - '0'; 
	int mm = (m3 * 10 + m4);
	
	struct Time res;
	res.MM = mm;
	
	// If time is in "AM"
	if(s[6] == 'A') {
		if(hh == 12) res.HH = 0;
		else res.HH = hh;
	}
	
	// If time is in "PM"
	else {
		if(hh == 12) res.HH = 12;
		else res.HH = hh + 12;
	}
	
	return res;
}

void solve()
{	
    string t;
  	getline(cin, t);
  	
  	struct Time P = convert_to_24(t);
  	
  	int n; cin >> n;
  	cin.ignore();
  	
  	string res = "";
  	
  	for(int i = 0; i < n; i++) {
  		string s;
  		getline(cin, s);
  		
  		struct Time L = convert_to_24(s.substr(0, 8));
  		struct Time R = convert_to_24(s.substr(9, 8));
  		
  		vector<Time> v;
  		v.pb(L); v.pb(P); v.pb(R);
  	
  		sort(v.begin(), v.end());
  		
  		if(v[1] == P) res += "1";
  		else res += "0";
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
  	// IMP. ==> getline() reads and discard delimiter, you have to use cin.ignore() 
  	//          only when you read your first integer.
  	// Refer: https://stackoverflow.com/questions/20970780/getline-cin-ignore-in-c
	
    int t = 1;
    cin >> t;
    cin.ignore();
    
    while(t--) {
      solve();
    }

    return 0;
}

/**********************************************************************************************************/

// The below code is exactly same as the above one, the only difference is that in the above code
// the struct is "Time", while in the below code struct is "time".
// In the above code vector<Time> v did not give error, while in the below code vector<time> v was giving
// error, that why when I used vector<struct time> v it passes all TC. 

/**********************************************************************************************************/

// Problem: Chef and Meetings
// Contest: CodeChef - February Challenge 2021 Division 3
// URL: https://www.codechef.com/FEB21C/problems/MEET
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 10-02-2021 11:10:50 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

struct time {
  int HH, MM;
  bool operator<(const time &T) {
    if(HH == T.HH) return MM <= T.MM;
    return HH < T.HH;
  }
  
  bool operator==(const time &T) {
    return (HH == T.HH) && (MM == T.MM);
  }
};

// https://www.geeksforgeeks.org/program-convert-time-12-hour-24-hour-format/
struct time convert_to_24(string s) { 
  int h0 = s[0] - '0'; 
  int h1 = s[1] - '0'; 
  int hh = (h0 * 10 + h1);
  
  int m3 = s[3] - '0'; 
  int m4 = s[4] - '0'; 
  int mm = (m3 * 10 + m4);
  
  struct time res;
  res.MM = mm;
  
  // If time is in "AM"
  if(s[6] == 'A') {
    if(hh == 12) res.HH = 0;
    else res.HH = hh;
  }
  
  // If time is in "PM"
  else {
    if(hh == 12) res.HH = 12;
    else res.HH = hh + 12;
  }
  
  return res;
}

void solve()
{ 
    string t;
    getline(cin, t);
    
    struct time P = convert_to_24(t);
    
    int n; cin >> n;
    cin.ignore();
    
    string res = "";
    
    for(int i = 0; i < n; i++) {
      string s;
      getline(cin, s);
      
      struct time L = convert_to_24(s.substr(0, 8));
      struct time R = convert_to_24(s.substr(9, 8));
      
      vector<struct time> v;
      v.pb(L); v.pb(P); v.pb(R);
    
      sort(v.begin(), v.end());
      
      if(v[1] == P) res += "1";
      else res += "0";
    }
    
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
  
  // IMP. ==> getline() reads and discard delimiter, you have to use cin.ignore() 
  //          only when you read your first integer.
  // Refer: https://stackoverflow.com/questions/20970780/getline-cin-ignore-in-c
  
    int t = 1;
    cin >> t;
    cin.ignore();
    
    while(t--) {
      solve();
    }

    return 0;
}