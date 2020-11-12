#include<bits/stdc++.h>
using namespace std;

class myComparator
{
	public:
		bool operator()(pair<string, int> p1, pair<string, int> p2){
			if(p1.second == p2.second){
				return p1.first < p2.first;
			}
			
			else{
				return p1.second < p2.second;
			}
		}
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int no_of_transactions;
    cin >> no_of_transactions;
    
    unordered_map<string, int> net;
    
    while(no_of_transactions--)
    {
    	// x is the person which have to give money = amount to y
    	string x, y; 
    	int amount;
    	cin >> x >> y >> amount;
    	
    	if(net.count(x) == 0) net[x] = 0;
    	if(net.count(y) == 0) net[y] = 0;
    	
    	net[x] -= amount;
    	net[y] += amount;
    }
    
    // instead of defining myComparator comparison class, we can
    // also inset pair in the form <int, string>
    multiset<pair<string, int>, myComparator> m;
    
    for(auto t: net){
    	if(t.second != 0)
    		m.insert(t);
    }
    
    // to store the min #transaction required
    int cnt = 0;
    
    // pop out the left most and right most persons and try to 
    // settle them
    while(!m.empty())
    {
    	cnt++;
    	
    	auto low = m.begin();
    	auto high = prev(m.end(), 1);
    	
    	int debit = low->second;
    	int credit = high->second;
    	
    	string debitor = low->first;
    	string creditor = high->first;
    	
    	m.erase(low);
    	m.erase(high);
    	    	
    	// can also be = settlement = min(abs(debit, credit));
    	int settlement = min(-debit, credit);
    	
    	cout<<debitor<<" will pay ₹"<<settlement<<" to "<<creditor<<"\n";
    	
    	debit += settlement;
    	credit -= settlement;
    	
    	if(debit != 0) m.insert({debitor, debit});
    	if(credit != 0) m.insert({creditor, credit});
    }

	cout<<"Minimum number of transaction required = "<<cnt<<"\n";

    return 0;
}

/*

Sample i/p:

3 3
Rahul Ajay 100
Ajay Neha 50
Neha Rahul 30

Sample o/p:

Rahul will pay ₹50 to Ajay
Rahul will pay ₹20 to Neha
Minimum number of transaction required = 2

*/

// Time Complexity: O(n x log(n)), where n = #frnds