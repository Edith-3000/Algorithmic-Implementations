// If we want to store values in a set using custom comparator "class", then use below snippet --->
// NOTE: It's onlt for reference, the value stored in set can be changed acc. to the need.

class cmp {
	public: 
		bool operator() (const pii &p1, const pii &p2) {
			if(p1.F == p2.F) return p1.S > p2.S;
			return p1.F > p2.F;
		}
};

set<pii, cmp> s;

// Remember to make the member function as "public"
// NOTE: cmp is passed without brackets "()"

/*********************************************************************************************************/

// If we want to store values in a set using custom comparator "struct", then use below snippet --->

struct cmp {
	bool operator() (const pii &p1, const pii &p2) {
		if(p1.F == p2.F) return p1.S > p2.S;
		return p1.F > p2.F;
	}
};

set<pii, cmp> s;

// No need to make anything "public" in struct as by-default things are in "public" mode only in a struct.
// NOTE: cmp is passed without brackets "()"

/*********************************************************************************************************/