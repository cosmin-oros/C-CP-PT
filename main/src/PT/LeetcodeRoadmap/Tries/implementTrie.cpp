#include <iostream>

/*
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
    There are various applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
    

    Example 1:

    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]

    Explanation
    Trie trie = new Trie();
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True
*/

struct Node {
	Node *links[26];
	bool flag = false;
	// checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	// creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	// to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	// setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	// checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(std::string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                // does not contain the key
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            
        }
        node->setEnd();
    }
    
    bool search(std::string word) {
        Node* node = root;

        for(int i = 0; i < word.length(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(std::string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True

    return 0;
}