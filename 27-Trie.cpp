//TRIE 

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    // INSERTION
    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assume word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    // SEARCHING
    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // REMOVE / DELETE WORD
    bool removeUtil(TrieNode* root, string word, int index) {
        // Base case
        if (index == word.length()) {
            if (!root->isTerminal) {
                return false; // Word doesn't exist
            }
            root->isTerminal = false; // Mark as non-terminal
            // Check if the current node has no children, i.e., it's safe to delete
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false; // Word has prefixes, can't delete
                }
            }
            delete root;
            return true; // Word is deleted
        }

        int childIndex = word[index] - 'A';
        TrieNode* child = root->children[childIndex];

        if (child == NULL) {
            return false; // Word doesn't exist
        }

        bool shouldDeleteChild = removeUtil(child, word, index + 1);
        if (shouldDeleteChild) {
            root->children[childIndex] = NULL; // Remove the reference to the child node
            delete child; // Delete the child node
            // Check if the current node has no other children or is a terminal node, i.e., it's safe to delete
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Word has prefixes, can't delete
                    }
                }
                delete root;
                return true; // Word is deleted
            }
        }
        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word, 0);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << "Present or Not: " << t->searchWord("TIME") << endl;

    cout<<"After remove word "<<endl;
    t->removeWord("TIME");
    cout << "Present or Not: " << t->searchWord("TIME") << endl;
    return 0;
}

/*
OUTPUT
Present or Not: 1
After remove word
Present or Not: 0
*/


//IMPLEMENT TRIE
class TrieNode{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i]  = NULL;
        }
        isTerminal = false;
    }
};
class Trie {

public:
    TrieNode*root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        //assume word will be in CAPS
        int index = word[0] - 'a';
        TrieNode * child;

        //present
        if(root->children[index] != 0){
            child = root->children[index];
        }
        //absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));

    }
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode*root, string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode*child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursion
        return searchUtil(child , word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode *root , string word) {
         //base case
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode*child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursion
        return prefixUtil(child , word.substr(1));
    }
    bool startsWith(string prefix){
        return prefixUtil(root,prefix);
    }
};
/*
Sample Input 1 :
5
1 hello
1 help
2 help
3 hel
2 hel 
Sample Output 1 :
true
true
false
*/