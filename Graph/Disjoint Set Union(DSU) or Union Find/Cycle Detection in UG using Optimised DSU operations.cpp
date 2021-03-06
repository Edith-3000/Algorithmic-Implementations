#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int v;
	list<pair<int, int>> l;
	
	public:
		Graph(int v){
			this->v=v;
		}
		
		void addEdge(int x, int y){
			l.push_back({x, y});
		}
		
		int find_set(int v, int *parent)
		{
			// base condition
			if(parent[v]==-1) 
				return v;
				
			return parent[v] = find_set(parent[v], parent);
		}
		
		void union_sets(int a, int b, int parent [], int *size)
		{
			a=find_set(a, parent);
			b=find_set(b, parent);
			
			if(a!=b) 
			{
				if(size[a] < size[b])
					swap(a, b);
					
				parent[b] = a;
				size[a] += size[b];
			}
		}
		
		bool containsCycle()
		{
			int *parent = new int[v];
			int *size = new int[v];
			
			for(int i=0; i<v; i++){
				parent[i]=-1;
				size[i]=1;
			}
			
			for(auto p: l)
			{
				int s1=find_set(p.first, parent);
				int s2=find_set(p.second, parent);
				
				if(s1==s2) return true;
				else union_sets(p.first, p.second, parent, size);
			}
			
			delete [] parent;
			delete [] size;
			return false;
		}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    cout<<(g.containsCycle() ? "Cycle is present" : "Cycle isn't present");

    return 0;
}