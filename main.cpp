#include "Headers.h"

int main(){
    Trie FilesTrie, TitleTrie;
    cout<<"Initializing database, please wait a moment"<<endl;
    FilesInit(FilesTrie);
    TitleInit(TitleTrie);
    vector <string> res;
    vector <string> finalres;
    vector<string> stopwords;
    ifstream fin;
    fin.open("./Ref/stopword.txt");
    string temp;
    fin>>temp;
    while (!fin.eof()){
        stopwords.push_back(temp);
        fin>>temp;
    }
    fin.close();
    mainmenu(stopwords,FilesTrie,TitleTrie);

    //cout<<temp<<endl;


    //cout<<"Complete "<<files.size()<<endl;


    return 0;
}
