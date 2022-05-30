// If we want to sort a priority queue using custom comparator "class", then use below snippet --->
// NOTE: It's only for reference, the value stored in priority queue can be changed acc. to the need.

// Here a "min heap" type priority queue is being implemented
class cmp {
	public: 
		bool operator()(const pair<int, pii> &p1, const pair<int, pii> &p2) {
			if(p1.F == p2.F) return p1.S.F > p2.S.F;
			return p1.F > p2.F;
        }
};

priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> q;	

// Remember to make the member function as "public"
// NOTE: cmp is passed without brackets "()" in the declaration of the queue.

/******************************************************************************************************/

// If we want to sort a priority queue using custom comparator "struct", then use below snippet --->

struct cmp {
	bool operator()(const pair<int, pii> &p1, const pair<int, pii> &p2) {
		if(p1.F == p2.F) return p1.S.F > p2.S.F;
		return p1.F > p2.F;
    }
};

priority_queue<pair<int, pii>, vector<pair<int, pii>>, cmp> q;	

// Remember to keep the member function as "public"
// NOTE: cmp is passed without brackets "()" in the declaration of the queue.

/******************************************************************************************************/

// One other way using Lambdas:
// https://www.youtube.com/watch?v=WhIcVlkZ19s&t=542

// https://www.includehelp.com/stl/user-defined-comparator-for-priority-queue-in-cpp-stl.aspx
// https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

/*****************************************************************************************************/