// Ref: https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
//      https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
//      https://leetcode.com/problems/find-median-from-data-stream/
/********************************************************************************************************************************************/

/* PROBLEM STATEMENT: Design a class to calculate the median of a number stream. 
   The class should have the following two methods:
   1. insertNum(int num): stores the number in the class
   2. findMedian(): returns the median of all numbers inserted in the class
   If the count of numbers inserted in the class is even, the median will be the average of the middle 
   two numbers.

Example:

1. insertNum(3)
2. insertNum(1)
3. findMedian() -> output: 2
4. insertNum(5)
5. findMedian() -> output: 3
6. insertNum(4)
7. findMedian() -> output: 3.5
*/

/*

UNDERLYING CONCEPT(s) ---->
  # As we know, the median is the middle value in an ordered integer list. 

  # So a brute force solution could be to maintain a sorted list of all numbers inserted in the class so that 
    we can efficiently return the median whenever required. 

  # Inserting a number in a sorted list will take O(n) time if there are 'n' numbers in the list.

  # This insertion will be similar to the Insertion sort. 

  # But we can utilize the fact that we don’t need the fully sorted list - we are only interested in finding 
    the middle element.

  # Assume ‘x’ is the median of a list. This means that half of the numbers in the list will be smaller than 
    (or equal to) ‘x’ and half will be greater than (or equal to) ‘x’. 

  # This leads us to an approach where we can divide the list into two halves: 
    one half to store all the smaller numbers (let’s call it smallNumList) and 
    one half to store the larger numbers (let’s call it largNumList).

  # The median of all the numbers will either be the largest number in the smallNumList or the smallest number 
    in the largNumList. 
    If the total number of elements is even, the median will be the average of these two numbers.

  # The best data structure that comes to mind to find the smallest or largest number among a list of numbers 
    is a Heap. Let’s see how we can use a heap to find a better algorithm.

    1. We can store the first half of numbers (i.e., smallNumList) in a Max Heap. 
       We should use a Max Heap as we are interested in knowing the largest number in the first half.

    2. We can store the second half of numbers (i.e., largeNumList) in a Min Heap, as we are interested 
       in knowing the smallest number in the second half.

    3. Inserting a number in a heap will take O(log(n)), which is better than the brute force approach.

    4. At any time, the median of the current list of numbers can be calculated from the top element of the 
       two heaps.

  # We can insert a number in the Max Heap (i.e. first half) if the number is smaller than the top 
    (largest) number of the heap. After every insertion, we will balance the number of elements in 
    both heaps, so that they have an equal number of elements. 

    IF THE COUNT OF NUMBERS IS ODD, LET’S DECIDE TO HAVE MORE NUMBERS IN MAX-HEAP THAN THE MIN HEAP.
    
*/

#include<bits/stdc++.h>
using namespace std;

class Median {
    // data members

    // contains first half of numbers
    priority_queue<int> maxHeap;
    
    // contains second half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    public:
        // member functions
        void insertNum(int num) {
            if((maxHeap.size() == 0) or (maxHeap.top() >= num)) maxHeap.push(num);
            else minHeap.push(num);
            
            // either both the heaps will have equal number of elements or 
            // max-heap will have one more element than the min-heap
            if(maxHeap.size() > (minHeap.size()+1)) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            
            else if(maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        
        double findMedian() {
            // we have even number of elements take avg of middle 2 elements
            if((maxHeap.size() == minHeap.size()) && (maxHeap.size() != 0)) {
                return maxHeap.top()/2.0 + minHeap.top()/2.0;
            }
            
            // because max-heap will have 1 one more element than the minHeap   
            else return maxHeap.top();
        }
};

void solve()
{
    Median m;
    
    // #queries
    int q; cin >> q;
    
    for(int i = 0; i < q; i++) {
        // 1. insertNum(), 2. findMedian()
        int type; cin >> type;
        
        if(type == 1) {
            int x; cin >> x;
            m.insertNum(x);
        }
        
        else {
            cout << "Median: " << m.findMedian();
            cout << "\n";
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

/* # Time complexity:--->
     * The time complexity of the insert() fⁿ will be O(log(n)) due to the insertion in the heap. 
       The time complexity of the findMedian() will be O(1) as we can find the median from the top elements 
       of the heaps.

   # Space complexity:--->
     * The space complexity will be O(n) because, as at any time, we will be storing all the numbers.
*/