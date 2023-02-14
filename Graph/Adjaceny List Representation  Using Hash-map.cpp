#include<iostream>

#include<unordered_map>

#include<list>

#include<cstring>

using namespace std;

class graph {
    private: unordered_map < string,
    list < pair < string,
    int >>> mp;

    public: void addEdge(string x, string y, int wt, bool bidir) {
        mp[x].push_back(make_pair(y, wt));
        if (bidir) mp[y].push_back(make_pair(x, wt));
    }

    void print() {
        //iterate over all the (key, value) pairs in the map
        for (auto p: mp) //p is of type pair<string, list<pair<string, int>>
        {
            cout << p.first << " --> ";
            list < pair < string, int >> l = p.second;
            for (auto n: l)
                cout << "(" << n.first << "," << n.second << ")" << " ";

            cout << "\n";
        }
    }
};

int main(int argc, char
    const * argv[]) {
    graph g;
    g.addEdge("A", "B", 20, true);
    g.addEdge("A", "D", 50, false);
    g.addEdge("A", "C", 10, true);
    g.addEdge("B", "D", 40, true);
    g.addEdge("C", "D", 30, true);
    g.print();
    return 0;
}