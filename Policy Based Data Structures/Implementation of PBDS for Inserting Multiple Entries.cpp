#include<bits/stdc++.h>
using namespace std;

// header files for pbds

// common file
#include<ext/pb_ds/assoc_container.hpp> 
// including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp> 

// namespace for pbds
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
		tree_order_statistics_node_update> pbds;
		
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	pbds st;
	
	// value, index
	st.insert({4, 0});
	st.insert({3, 1});
	st.insert({1, 2});
	st.insert({10, 3});
	st.insert({15, 4});
	st.insert({3, 5});
	
	for(int i = 0; i < st.size(); i++){
		cout << "Element at index " << i << " = " << st.find_by_order(i)->first << " " << st.find_by_order(i)->second << "\n";
	}
		
	return 0;
}

/* Sample o/p: Element at index 0 = 1 2
			   Element at index 1 = 3 1
			   Element at index 2 = 3 5
			   Element at index 3 = 4 0
			   Element at index 4 = 10 3
			   Element at index 5 = 15 4
*/