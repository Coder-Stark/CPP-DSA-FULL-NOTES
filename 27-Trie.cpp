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

 
//LONGEST COMMON PREFIX                                              {T.C = O(M*N) M = lenght of string , n = no. of strings}
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    //traverse each character of 1 string
    for(int i = 0 ; i < arr[0].length() ; i++){
        char ch = arr[0][i];
        bool match = true;

        //comparing another strings 
        for(int j = 1 ; j < n ; j++){
            //not match
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
/*
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni
*/


//IMPLEMENT A PHONE DIRECTORY
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

        //assume word will be in small
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
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode * curr, vector<string>&temp,string prefix){
        if(curr -> isTerminal){
            temp.push_back(prefix);
        }
        for(char ch = 'a';ch <= 'z' ; ch++){

            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>>getSuggestions(string str){
        TrieNode * prev = root;
        vector<vector<string>>output;
        string prefix = "";

        for(int i = 0 ; i < str.length() ; i++){
            char lastCh = str[i];

            prefix.push_back(lastCh);

            //check for lastch is exit or not
            TrieNode*curr = prev->children[lastCh - 'a'];

            //if not found
            if(curr == NULL){
                break;
            }

            //if found
            vector<string>temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie* t = new Trie();

    //insert all contact in trie
    for(int i = 0 ; i < contactList.size(); i++){
        string str = contactList[i];
        t-> insertWord(str);
    }

    //return ans
    return t->getSuggestions(queryStr);
    
}
/*

Sample Input 1 :
2
5
cod coding codding code coly
coding
2
ninjas coding
ninja
Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
ninjas
ninjas
ninjas
ninjas
ninjas
*/