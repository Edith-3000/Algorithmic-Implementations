// If we want to store values in a set using custom comparator "class", then use below snippet --->
// NOTE: It's only for reference, the value stored in set can be changed acc. to the need.

// EXAMPLE - 1 ===>

class cmp {
	public: 
		bool operator() (const pii &p1, const pii &p2) {
			if(p1.F == p2.F) return p1.S > p2.S;
			return p1.F > p2.F;
		}
};

set<pii, cmp> s;

// EXAMPLE - 2 ===>

struct node {
	int row, col, dist;
};

class cmp {
	public:
		bool operator() (const node &n1, const node &n2) {
			if(n1.dist == n2.dist) {
				if(n1.row != n2.row) return n1.row < n2.row;
				else return n1.col < n2.col;
			}
			
			else return n1.dist < n2.dist;
		}
};

set<node, cmp> st;

// Remember to make the member function as "public"

/* NOTES: 
   # cmp is passed without brackets "()"
   # Sometimes you may get a warning while writing in this manner, to remove the warning use 'const' keyword after arguement list, for eg. ===>
     https://github.com/Edith-3000/Algorithmic-Implementations/blob/f2415a437beb3e458dcd02646a2ed1c13bbbb380/Graph/Shortest%20Paths/SSSP%20Algorithms/Dijkstra's%20Algorithm/Dijkstra%20on%20Grid/Min%20Cost%20Path%20(MCP)%20(All%204%20Directions).cpp#L106
*/

/*****************************************************************************************************************************************************************/

// If we want to store values in a set using custom comparator "struct", then use below snippet --->

// EXAMPLE - 1 ===>

struct cmp {
	bool operator() (const pii &p1, const pii &p2) {
		if(p1.F == p2.F) return p1.S > p2.S;
		return p1.F > p2.F;
	}
};

set<pii, cmp> s;

// EXAMPLE - 2 ===>

struct node {
	int row, col, dist;
};

struct cmp {
	bool operator() (const node &n1, const node &n2) {
		if(n1.dist == n2.dist) {
			if(n1.row != n2.row) return n1.row < n2.row;
			else return n1.col < n2.col;
		}
		
		else return n1.dist < n2.dist;
	}
};

set<node, cmp> st;

// No need to make anything "public" in struct as by-default things are in "public" mode only in a struct.

/* NOTES: 
   # cmp is passed without brackets "()"
   # Sometimes you may get a warning while writing in this manner, to remove the warning use 'const' keyword after arguement list, for eg. ===>
     https://gist.github.com/Edith-3000/04f4ece8d5036bfcc457c9294bea2eda#file-min-cost-path-all-4-directions-cmp-struct-cpp-L3
*/

/*****************************************************************************************************************************************************************/

/* # BE CAUTIOUS WHILE WRITING CUSTOM COMPARATOR FUNCTIONS FOR std::set.

   # For eg. in the function mention at the link - https://gist.github.com/Edith-3000/c09c056ecbe8ba4788cb6d9c52d9d0bd
     If you give the below i/p ===>
     0 1 10
	 1 1 20
	 9 8 -10
	 7 8 20
	 
	 It will only display o/p as ===>
	 9 8 -10
	 0 1 10
	 1 1 20
   
   # The reason for this is mayber because in the function it is not clearly mention what to do when (x.w == y.w)

   # Ref: https://usaco.guide/silver/custom-cpp-stl?lang=cpp
          https://usaco.guide/silver/custom-cpp-stl?lang=cpp#functors
*/