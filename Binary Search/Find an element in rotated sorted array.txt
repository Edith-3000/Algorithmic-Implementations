/*The main concept behind the algorithm is in an rotated sorted array -
     * The subarray from start to min_index-1 is sorted.
     * The subarray from min_index-1 to end is sorted.

 Therefore - 1. Find the index of minimum element in the rotated sorted array.
             2. Find the element either in start to min_index-1 or min_index-1 to end.
*/

long long bin_search_iterative(vector<long long> &v, long long k, long long start, long long end)
{
	//the vector v must be sorted in order 
   //to perform binary search

   while(start<=end)
   {
      long long mid=start+(end-start)/2; //to avoid overflow

      if(v[mid]==k) return mid;
      else if(k>v[mid]) start=mid+1;
      else end=mid-1;
   }
   return -1; //if element not found
}

long long find_min_index(vector<long long> &v)
{
	long long start=0, end=v.size()-1, n=v.size();

	if(v[start]<v[end]) //if the array is not rotated at all
	   return 0;

	while(start<=end)
	{
	   long long mid=start+(end-start)/2; //to avoid overflow
       long long next=(mid+1)%n; //modulo is done to avoid segmentation fault
       long long prev=(mid-1+n)%n;

	   if((v[mid]<=v[prev]) && (v[mid]<=v[next]))
	      return mid;

	   else if(v[start]<=v[mid]) //i.e. if the left subarray is sorted 
	       start=mid+1;         //then move to the unsorted right subarray
	     
       else                 //for v[mid]<=v[end]
          end=mid-1;       //i.e. if the right subarray is sorted 
	                      //then move to the unsorted right subarray
	}
}

long long find_in_rotated(vector<long long> &v, long long k)
{
	long long min_index=find_min_index(v); //to find the index of the minimum
	                                      //element in the rotated sorted array

	long long left=bin_search_iterative(v, long long k, 0, min_index-1);
	long long right=bin_search_iterative(v, long long k, min_index, v.size()-1);

	if(left!=-1) return left;
	else if(right!=-1) return right;
	else return -1; //if element not found
}