#include "Libraries.h"

struct TrieNode {
    TrieNode *children[38];
    bool IsLeaf;
    vector <string> files;
    string word;
    int no;
    //char word [20];
};

class Trie {
private:
    TrieNode *root;
    TrieNode *newNode();
    int char_to_index(char c);
public:
    Trie();
    void push (const char *keyword,string filename);
    bool searchkey (const char *keyword);
    vector<string> searchfile(const char *keyword);
    void print ();
};
