/* # Ref: https://github.com/kartik8800/segTree
          https://github.com/kartik8800/segTree/blob/master/SegmentTree.h
          https://codeforces.com/blog/entry/71101
          https://www.youtube.com/watch?v=K-86mKNAsmU
*/

// This template can be used to solve problems involving "Point updates and Range queries", the 
// updates work in log2(n) time and build works in O(n) time.
// WARNING: This is not a robustly tested library (however, easier segment tree problems can be 
//          solved by it pretty well.)

/*****************************************************************************************************************/

/*

1. include SegmentTree.h

2. to construct a segment tree you need to specify the following:
   a. The datatype of array for which the tree is being constructed.
   b. an array or vector for which the tree is to be constructed.
   c. a value that can be used to fill the extra nodes of the tree.
      this value is the identity value such that combine(something, value) = something
   d. a function combine that specifies how the result of left and right child of a node
      should be used to generate the value of current node.

3. Example usage:
   int small(int x,int y){return min(x,y);}
   SegmentTree < int > rangeMinQueries(dataVector,INT_MAX,small);

   int sum(int x,int y){return x+y;}
   SegmentTree < int > rangeSumQueries(dataVector,0,sum);

   long long product(long long x,long long y){return x*y;}
   SegmentTree < long long > rangeProductQueries(dataVector,1,product);

# NOTE: * THE QUERY & UPDATE INDICES ARE 0-BASED INDEXED IN THIS LIBRARY.
        * THE "update()" Fn. SETS THE ELEMENT AT INDEX "idx" TO "val", THEREFORE THE FINAL VALUE WHICH
          IS TO BE STORED AT THE INDEX "idx" SHOULD BE PASSED IN THE "update()" Fn. AND NOT THE CHANGE
          WHICH IS TO BE MADE.
*/

///author : kartik8800
#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>

template<class T>
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        void update(int idx, T val);
        ///TODO lazy propagation
    private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n);
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

#endif // SEGMENTTREE_H