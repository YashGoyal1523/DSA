// given a string . print all words starting from that string

// traverse to last char of input string
//iske aage se saare words uthalo
#include <iostream>
#include<vector>
using namespace std;

class TrieNode{
  public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
      this->value = val;
      for(int i=0; i<26; i++) {
        children[i] = NULL;
      }
      this->isTerminal = false;
    }
};
//insertion
void insertWord(TrieNode* root, string word) {
  //cout << "recieved word: " << word << " for insertion " << endl;
  //base case
  if(word.length() == 0) {
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch - 'a';
  TrieNode* child;
  if(root->children[index] != NULL) {
    //present
      child = root->children[index];
  }
  else {
    //absent
     child = new TrieNode(ch);
     root->children[index] = child;
  }

  //recursion
  insertWord(child, word.substr(1));

}



void storeString(TrieNode* root, vector<string>& ans, string& s) {
  //base case
  if(root->isTerminal == true) {
    //ans store
    ans.push_back(s);
    //return ?  // nhi krna 
  }

  for(char ch='a'; ch<='z'; ch++) {
    int index = ch - 'a';
    TrieNode* next = root->children[index];
    if(next != NULL) {
      //child exist
      s.push_back(ch);
      //baaaki recursion
      storeString(next, ans, s);
      //backtrack
      s.pop_back();
    }
  }
}

void findPrefixString(TrieNode* root, string input, vector<string>& ans, string &prefix) {
  //base case
  if(input.length() == 0) {
    TrieNode* lastchar = root;
    storeString(lastchar, ans, prefix);
    return;
  }
  char ch = input[0];
  int index = ch - 'a';
  TrieNode* child;
  if(root->children[index] != NULL) {
    //child present
    child = root->children[index];
  }
  else {
    return;
  }
  //recursive call
  findPrefixString(child, input.substr(1), ans, prefix);
}




int main() {
  TrieNode* root = new TrieNode('-');

  insertWord(root, "cater");
  insertWord(root, "care");
  insertWord(root, "com");
  insertWord(root, "lover");
  insertWord(root, "loved");
  insertWord(root, "load");
  insertWord(root, "lov");
  insertWord(root, "bat");
  insertWord(root, "cat");
  insertWord(root, "car");

 


  string input = "ca";
  string prefix = input;
  vector<string> ans;

  findPrefixString(root, input, ans, prefix);

  for(auto i: ans) {
    cout << i << " ";
  }
  cout << endl;




 


  return 0;
}
