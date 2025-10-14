// given input string suppose joker
// find all words starting from j,jo,jok,joke,joker


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



void storeString(TrieNode* root, vector<string>& ans,  string& s) {
  //base case
  if(root->isTerminal == true) {
    //ans store
    ans.push_back(s);
    //return ?
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



vector<vector<string> > getSuggestions(TrieNode* root, string input) {

  vector<vector<string> > output;
  TrieNode* prev = root;
  string s = "";

  for(int i=0; i<input.length(); i++) {
    char lastchar = input[i];
    int index = lastchar - 'a';
    TrieNode* curr = prev->children[index];

    if(curr == NULL) {
      break;
    }
    else {
      vector<string> nicheKaAns;
      s.push_back(lastchar);
      storeString(curr, nicheKaAns, s);
      output.push_back(nicheKaAns);
      //important
      prev = curr;
    }

  }
  return output;
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

  vector<vector<string> > ans = getSuggestions(root, "loa");
  //printing ans
  for(int i=0; i<ans.size(); i++) {
    cout << i << " -> ";
    for(auto str: ans[i]) {
      cout << str <<", ";
    }cout << endl;
  }


  




 


  return 0;
}
