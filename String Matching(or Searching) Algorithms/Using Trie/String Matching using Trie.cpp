#include<bits/stdc++.h>
using namespace std;

// trie structure for inserting string consisting of lowercase
// latin alphabets
struct trie
{
	// everything is by-default "public" in a struct
	// every trie node will contain an array/vector of 
	// pointers each pointing to a similar trie 
	// here we're taking size of the array as 26
	trie *nxt[26];
		
	// constructor
	trie(){
		for(int i = 0; i < 26; i++){
			nxt[i] = nullptr;
		}
	}
};

// root node of the trie structure
trie *root;

void insert(string s)
{
	trie *curr = root;
	
	for(int i = 0; i < s.size(); i++){
		// if character not found create a new trie node
		if(curr->nxt[s[i] - 'a'] == nullptr){
			curr->nxt[s[i] - 'a'] = new trie();
		}
		
		// move forward
		curr = curr->nxt[s[i] - 'a'];
	}
}

bool search(string s)
{
	trie *curr = root;
	
	for(int i = 0; i < s.size(); i++){
		if(curr->nxt[s[i] - 'a'] == nullptr){
			return false;
		}
		
		curr = curr->nxt[s[i] - 'a'];
	}
	
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	cout << "Enter the text(haystack): ";
    string text; cin >> text; cout << text <<"\n";
    cout << "Enter the pattern to be searched(needle): ";
    string pat; cin >> pat; cout << pat <<"\n";
    
    if(pat.length() > text.length()){
        cout << "Pattern length > Text length" << "\n";
        return 0;
    }
	
    root = new trie();
    
    int n = text.size(), m = pat.size();
    for(int i = 0; i < n; i++){
    	insert(text.substr(i, m));
    }
    
    if(search(pat)){
    	cout << "Found" << "\n";
    }
    
    return 0;
}