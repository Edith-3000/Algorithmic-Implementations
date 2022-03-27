// If we want to sort a vector using custom comparator "class", then use below snippet --->
// NOTE: It's onlt for reference, the value stored in vector can be changed acc. to the need.

class cmp {
	public: 
		bool operator() (const pair<int, pii> &p1, const pair<int, pii> &p2) {
			if(p1.S.F == p2.S.F) return p1.S.S < p2.S.S;
			return p1.S.F > p2.S.F;
	    }
};

sort(t.begin(), t.end(), cmp());	

// Remember to make the member function as "public"
// NOTE: cmp is passed with brackets "()" in the sort function.

/******************************************************************************************************/

// If we want to sort a vector using custom comparator "struct", then use below snippet --->

struct cmp {
	bool operator() (const pair<int, pii> &p1, const pair<int, pii> &p2) {
		if(p1.S.F == p2.S.F) return p1.S.S < p2.S.S;
			return p1.S.F > p2.S.F;
	}
};

sort(t.begin(), t.end(), cmp());	

// No need to make anything "public" in struct as by-default things are in "public" mode only in a struct.
// NOTE: cmp is passed with brackets "()" in the sort function.

/*********************************************************************************************************/

// Sorting using binary function

bool cmp(const pair<int, pii> &p1, const pair<int, pii> &p2) {
	if(p1.S.F == p2.S.F) return p1.S.S < p2.S.S;
	return p1.S.F > p2.S.F;
}

sort(t.begin(), t.end(), cmp);	

// NOTE: cmp is passed without brackets "()" in the sort function.

/**********************************************************************************************************/

/* # Sometimes while using a custom comparator function, en error may be thrown similar to this --->
     
     error: reference to non-static member function must be called
        	  sort(v.begin(), v.end(), cmp);
                              ^~~

	# In order to resolve this situation make the cmp function as static i.e.
	  static bool cmp(const pair<int, pii> &p1, const pair<int, pii> &p2) {
           if(p1.S.F == p2.S.F) return p1.F > p2.F;
           return p1.S.F < p2.S.F;
       }

    # Ref: https://www.programmersought.com/article/5922553195/
*/