// Run all these 4 programs 1 by 1 through the Command prompt, to get a clear picture.

// For compiling this file and running it through the Command prompt, follow the steps:
// 1). Go to the directory where this file is located
// 2). then, g++ file_name.extension -o object_file_name.exe 
//     for eg. g++ Demo.cpp -o Sample.exe
// 3). then, object_file_name.exe
// 	   for eg. Sample.exe

/***********************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		cout << "n is --> " << n << "\n";
	}

	return 0;
}

// This type of code is suitable for Interactive problems.

/**************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		cout << "n is --> " << n << "\n";
	}

	return 0;
}

// This type of code is NOT suitable for Interactive problems.

// ios_base::sync_with_stdio(false);
// cin.tie(nullptr); cout.tie(nullptr);
// the above 2 lines help to buffer the i/p and o/p (which we've to avoid in an interavtive problem),
// because we shiould flush the o/p in such type of problem.

/**************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		cout << "n is --> " << n << "\n";
		cout << flush;
	}

	return 0;
}

// This type of code is suitable for Interactive problems.

/****************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		cout << "n is --> " << n << endl; 
	}

	return 0;
}

// This type of code is suitable for Interactive problems.
// cout << endl; works similar to cout << "\n" << flush;

/****************************************************************************************************************/