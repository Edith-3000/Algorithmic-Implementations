#include<bits/stdc++.h>
using namespace std;

// header files for pbds

// common file
#include<ext/pb_ds/assoc_container.hpp> 
// including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp> 

// namespace for pbds
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> pbds;
		
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	pbds st;
	st.insert(4);
	st.insert(3);
	st.insert(1);
	st.insert(10);
	st.insert(15);
	st.insert(3); // only unique elements will be inserted
	
	for(int i = 0; i < st.size(); i++){
		cout << "Element at index " << i << " = " << *st.find_by_order(i) << "\n";
	}
	
	cout << st.order_of_key(5) << "\n";
	cout << st.order_of_key(15) << "\n";
	
	return 0;
}

/* Sample o/p: Element at index 0 = 1
		       Element at index 1 = 3
		       Element at index 2 = 4
		       Element at index 3 = 10
		       Element at index 4 = 15
		       3
		       4
*/