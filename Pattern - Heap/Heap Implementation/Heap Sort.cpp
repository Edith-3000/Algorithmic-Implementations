/* Ref: https://www.geeksforgeeks.org/heap-sort/
        https://www.youtube.com/watch?v=kU4KBD4NFtw

   # Heap Sort algorithm (for sorting in ascending order)--->
     * Create a binary max heap of n elements.
     * Starting deleting the elements of heap one-by-one and simultaneously insert the deleted element at
       the end of the array.

   # Heap Sort algorithm (for sorting in descending order)--->
     * Create a binary min heap of n elements.
     * Starting deleting the elements of heap one-by-one and simultaneously insert the deleted element at
       the end of the array.
*/

// In the below algorithm heap can also be created by the operations mentioned in the file, 
// "Max Heap Algorithm.cpp" but here heapify() method has been used to create heap.

/**********************************************************************************************************/

// NOTE: Building a heap from the heapify() concept doesn't take O(n x log(n)) time but O(n) time.
//       For proof refer: https://www.youtube.com/watch?v=VkKmmwzfIG4

/**********************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define sz(x) ((int)(x).size())

// To heapify a subtree rooted with node i which is
// an index in v[] and n is size of heap
void heapify(vi &v, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left child = 2 * i + 1
    int r = 2 * i + 2; // right = 2 * i + 2
 
    // If left child is larger than root
    if (l < n and v[l] > v[largest]) largest = l;
 
    // If right child is larger than largest so far
    if (r < n and v[r] > v[largest]) largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(v[i], v[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}

void heap_sort(vi &v) {
	int n = sz(v);
	
	// build heap using heapify concept
    for (int i = (n / 2 - 1); i >= 0; i--) {
    	heapify(v, n, i);
    }
 
    // One by one extract (delete) an element from heap and 
    // put them at back of the array for obtaining sorted array
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(v[0], v[i]);
		
        // call max heapify on the reduced heap
        heapify(v, i, 0);
    }
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	heap_sort(v);
  	for(auto x: v) cout << x << " ";
  	
  	cout << "\n";
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