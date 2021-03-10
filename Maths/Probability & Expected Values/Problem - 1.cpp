// Ref: https://www.youtube.com/watch?v=Lhdv9bPTulo
/**************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int roll_3_coins() {
	int coin1 = rand() % 2;
	int coin2 = rand() % 2;
	int coin3 = rand() % 2;
	return coin1 + coin2 + coin3;
}

int roll_dice() {
	int outcome = rand() % 6 + 1;
	return outcome;
}

double conduct_experiment(int times) {
	double total = 0.0;
	for(int exp_no = 0; exp_no < times; exp_no++) {
		// total += roll_dice();
		total += roll_3_coins();
	}
	
	return total / times;
}

void solve()
{
  	int times; cin >> times;
  	cout << conduct_experiment(times) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
	srand(time(0));
	
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}