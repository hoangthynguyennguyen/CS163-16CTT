#include "Trie.h"

int Trie::char_to_index(char c){
    if ((c>='a') && (c<='z')) {
      return (c-'a');
    } else {
      return ((c-'0')+27);
    }
}

Trie::Trie(){
    root = newNode();
    root->IsLeaf = false;
}

TrieNode *Trie::newNode(){
    TrieNode *curr;
    curr = new TrieNode;
    //curr->IsLeaf = true;
    curr->no = 0;
    //curr->word = "";
    for (int i=0; i<38; i++){
        curr->children[i] = NULL;
    }
    return curr;
}

void Trie::push(const char *keyword, string filename){
    TrieNode *curr = root;
    string c_word;
    int length = strlen(keyword);
    for (int i = 0 ; i<length; i++){
        c_word += keyword[i];
        int index = char_to_index(keyword[i]);
        if (curr->children[index]==NULL){
            curr->children[index] = newNode();
        }
        //curr->IsLeaf = false;
        if (curr->word.empty()) {
            curr->word=c_word;
        }
        curr = curr->children[index];
    }
    if (curr->word.empty()) {
      curr->word=c_word;
    }
    curr->no++;
        curr->files.push_back(filename);
}

bool Trie::searchkey(const char* keyword){
    int length = strlen(keyword);
    TrieNode *curr = root;
    int i;
    for (i= 0; i<length; i++){
      int index = char_to_index(keyword[i]);
      if (curr->children[index]==NULL){
        return false;
      }
      curr=curr->children[index];
    }
    if (curr->no>0) {
      return true;
    } else {
      return false;
    }
}

vector<string> Trie::searchfile(const char *keyword) {
  int length = strlen(keyword);
  TrieNode *curr = root;
  int i;
  vector <string> empty;
  for (i= 0; i<length; i++){
    int index = char_to_index(keyword[i]);
    if (curr->children[index]==NULL){
      return empty;
    }
    curr=curr->children[index];
  }
  if (curr->no>0) {
    return curr->files;
  } else {
    return empty;
  }
}
