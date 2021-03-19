// Trie is basically an n-ary tree.

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
	
	// each trie structure will also contain a end marker
	// for indicating whether a string end on that trie node or nor
	bool ended; 
	
	// constructor
	trie(){
		for(int i = 0; i < 26; i++) nxt[i] = nullptr;
		ended = false;
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
	
	curr->ended = true;
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
	
	return curr->ended;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	root = new trie();
	
	// inserting different strings in the trie
    insert("kapil");
    insert("choudhary");
    insert("kalpana");
    insert("kapaar");
    
    // search for a string in the trie
    if(search("kapil")) cout << "String found." << "\n";
    else cout << "String not found." << "\n";
    
    if(search("chaudhary")) cout << "String found." << "\n";
    else cout << "String not found." << "\n";
    
    return 0;
}

/* Sample o/p: String found.
               String not found.
*/