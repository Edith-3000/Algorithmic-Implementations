/* # Heapify is a method related to creation of a heap.
     Basically it is a faster method for creating a heap.

	 OR

   # The process of rearranging the heap by comparing the parent with it's left and right child RECURSIVELY
     so as to maintain the heap property is called heapify.

   # We can heapify an index 'i' only if the all the elements in the left and right subtree are following 
     the heap property i.e. left and right subtree are already a heap.

   # Considering 0-based indexing, if heap size is of 'n', the the leaf nodes will be in the range
     [floor(n/2), n - 1] and internal nodes will be in the range [0, floor(n/2) - 1].

   # Considering 0-based indexing, if parent at index 'i', the left and right child will be at indices
     (2 * i + 1) and (2 * i + 2) respectively.

     If a child (either left or right) is at index 'i', then it's parent will be at index ceil(i/2) - 1.

   # Heapify algorithm takes O(log(n)), where n are the #nodes in the heap.
*/

// Ref: https://www.youtube.com/watch?v=VkKmmwzfIG4
//      https://www.youtube.com/watch?v=cuL8gXCSA58
//      https://www.youtube.com/watch?v=qQkfUKer3LU&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=4