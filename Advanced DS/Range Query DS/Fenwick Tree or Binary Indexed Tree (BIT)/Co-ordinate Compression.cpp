/* # 𝑨 𝒗𝒆𝒓𝒚 𝒔𝒎𝒂𝒍𝒍 𝒃𝒖𝒕 𝒖𝒔𝒆𝒇𝒖𝒍 𝒕𝒓𝒊𝒄𝒌.

   # Resources: https://www.youtube.com/watch?v=s9oXy-fZUzg
                https://codeforces.com/blog/entry/23180
                https://codeforces.com/blog/entry/84164

   # P.S. - This small trick could've been used in the "Inversion Count - Spoj" Question, if the i/p array 
            numbers were larger than 10⁷ (or so) or if there were -ve inputs.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second

typedef vector<ll> vll;

// structure for co-ordinate compression technique
// NOTE: ids are 0-based indexed
template<typename T>
struct coordinate_compression {
    // id[u] = v ==> compressed co-ordinate of u is v
    // rid[v] = u ==> v is the compressed co-ordinate of u 
    map<T, T> id, rid;
    
    coordinate_compression() {
        id.clear();
        rid.clear();
    }
    
    void compress(vector<T> &v) {
        for(auto x: v) id[x];
        int order = -1;
        for(auto &x: id) x.S = ++order, rid[x.S] = x.F;
    }   
};

void solve()
{
    int n; cin >> n;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    struct coordinate_compression<ll> cc;
    cc.compress(v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

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