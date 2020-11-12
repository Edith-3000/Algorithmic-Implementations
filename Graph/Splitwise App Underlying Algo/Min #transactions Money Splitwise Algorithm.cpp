// Given a number of friends who have to give or take some amount of money from one another. 
// Design an algorithm by which the total cash flow among all the friends is minimized (i.e. just output the 
// minimum number of transactions required).

// The algorithm is GREEDY based.
// Below is an implicit graph algorithm (a graph haven't been used explicitly)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int frnds, no_of_transactions;
    cin >> frnds >> no_of_transactions;
    
    // a vector to store the net amount that each person 
    // will either give(if -ve) or take(if +ve)
    // if 0 then do nothing
    vector<int> net(frnds, 0);
    
    while(no_of_transactions--)
    {
    	// x is the person which have to give money = amount to y
        int x, y, amount;
    	cin >> x >> y >> amount;
    	
    	net[x] -= amount;
    	net[y] += amount;
    }
    
    // can also use max heap (TC in that case = O(frnds x log(frnds)))
    // can also use normal method for finding the max debitor and creditor repeatedlt
    // but TC will be = O(frnds^2)
    // multiset will also have TC similar to max heap
    multiset<int> m;
    
    for(auto t: net){
    	if(t != 0)
    		m.insert(t);
    }
    
    // to store the result i.e. min #transaction required
    int cnt = 0;
    
    // pop out the left most and right most persons and try to 
    // settle them
    while(!m.empty())
    {
    	cnt++;
    	
    	auto low = m.begin();
    	auto high = prev(m.end(), 1);
    	
    	int debit = *low;
    	int credit = *high;
    	
    	m.erase(low);
    	m.erase(high);
    	    	
    	// can also be = settlement = min(abs(debit, credit));
    	int settlement = min(-debit, credit);
    	
    	debit += settlement;
    	credit -= settlement;
    	
    	if(debit != 0) m.insert(debit);
    	if(credit != 0) m.insert(credit);
    }

	cout<<"Minimum number of transactions required = "<<cnt<<"\n";

    return 0;
}

/*

Sample i/p:

3 3
0 1 100
1 2 50
2 0 30

Smaple o/p:

2

*/

// Time Complexity: O(n x log(n)), where n = #frnds