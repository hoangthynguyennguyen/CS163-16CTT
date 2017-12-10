#include "Trie.h"

void FilesInit(Trie &T);
void TitleInit(Trie &T);


/*General functions */

vector<string> listFile(const char* path);
bool isStopword(vector<string> stopwords, string key);
void normalize(string &key);
bool compare(const string &a, const string &b);
bool checkinlist(vector<string> target, string file);
void normalizestring(string &key);
vector<string> splitkeywords(string searchword, vector<string> stopwords);
void rmspaceandlwr(string &key);
bool checksubstr(string file, string searchword);
string readfile(string filename);

/*Menu functions*/

int querytype(string &key);
/*
Return 1 for "-" type
2 for exact search
0 for normal
3 for intitle:
-1 for invalid search type
*/
void mainmenu (vector<string> stopwords, Trie FilesTrie, Trie TitleTrie);
void searchcommand(string &searchword, vector<string> stopwords, Trie FilesTrie, Trie TitleTrie);
void DisplayRes(vector<string> res);
void DisplayFile(string filename);


/*Main search functions */
vector<string> m_NormalSearch(string searchword, vector<string> stopwords, Trie T);
vector<string> m_TitleExactSearch(string searchword, vector<string> stopwords, Trie T);
vector<string> m_MinusSearch(string searchword, vector<string> stopwords, Trie T);
vector<string> m_ExactSearch(string searchword, vector<string> stopwords, Trie T);
