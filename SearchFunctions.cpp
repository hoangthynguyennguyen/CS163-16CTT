#include "Headers.h"

vector<string> m_NormalSearch(string searchword, vector<string> stopwords, Trie T){
    vector<string> querykeywords;
    querykeywords = splitkeywords(searchword, stopwords);
    vector <string> finalres, curres, exactres;
    finalres = T.searchfile(querykeywords[0].c_str());
    int n = finalres.size();
    for (int i=0; i<n ; i++){
        string currfile = readfile(finalres[i]);
        if (checksubstr(currfile,searchword)){
            exactres.push_back(finalres[i]);
        } else {
            curres.push_back(finalres[i]);
        }
    }
    finalres=curres;
    for (int i=1; i<querykeywords.size(); i++){
        curres = T.searchfile(querykeywords[i].c_str());
        vector<string> tempres;
        for(int j=0; j<finalres.size(); j++){
            if (checkinlist(curres,finalres[j])) {
                tempres.push_back(finalres[j]);
            }
        }
        finalres = tempres;
    }
    exactres.insert(exactres.end(),finalres.begin(),finalres.end());
    if (exactres.empty()){
        exactres = T.searchfile(querykeywords[0].c_str());
        for (int i=1; i<n; i++){
            curres = T.searchfile(querykeywords[i].c_str());
            for(int j=0; j<curres.size(); j++){
                exactres.push_back(curres[j]);
            }
        }
    }
    return exactres;
}


vector<string> m_MinusSearch(string searchword, vector<string> stopwords, Trie T){
    vector<string> querykeywords;
    querykeywords = splitkeywords(searchword, stopwords);
    vector <string> finalres, curres;
    finalres = T.searchfile(querykeywords[0].c_str());
    for (int i=1; i<querykeywords.size(); i++){
        vector<string> tempres;
        if (querykeywords[i].at(0) == '-'){
            string key;
            key = querykeywords[i].substr(1);
            curres = T.searchfile(key.c_str());
            for(int j=0; j<finalres.size(); j++){
                if (!checkinlist(curres,finalres[j])) {
                    tempres.push_back(finalres[j]);
                }
            }
        } else {
            curres = T.searchfile(querykeywords[i].c_str());
            for(int j=0; j<finalres.size(); j++){
                if (checkinlist(curres,finalres[j])) {
                    tempres.push_back(finalres[j]);
                }
            }
        }
        finalres = tempres;
    }
    return finalres;
}

vector<string> m_ExactSearch(string searchword, vector<string> stopwords, Trie T){
    vector<string> querykeywords;
    if (searchword[0]=='#'){
        searchword = searchword.substr(1,searchword.length()-1);
    } else {
        searchword = searchword.substr(1,searchword.length()-2);
    }
    string subsearchword = searchword;
    normalizestring(subsearchword);
    querykeywords = splitkeywords(subsearchword, stopwords);
    vector <string> finalres, exactres;
    finalres = T.searchfile(querykeywords[0].c_str());
    int n = finalres.size();
    //cout<<n<<endl;
    for (int i=0; i<n ; i++){
        string currfile = readfile(finalres[i]);
        if (checksubstr(currfile,searchword)){
            exactres.push_back(finalres[i]);
        }
    }
    return exactres;
}

vector<string> m_TitleExactSearch(string searchword, vector<string> stopwords, Trie T){
    vector<string> querykeywords;
    searchword = searchword.substr(1,searchword.length()-2);
    cout<<searchword<<endl;
    string subsearchword = searchword;
    normalizestring(subsearchword);
    cout<<subsearchword<<endl;
    querykeywords = splitkeywords(subsearchword, stopwords);
    vector <string> finalres, exactres;
    finalres = T.searchfile(querykeywords[0].c_str());
    int n = finalres.size();
    for (int i=0; i<n ; i++){
        string currfile;
        ifstream fin;
        string fname ("./Raw Data/");
        fname += finalres[i];
        fin.open(fname.c_str());
        string title;
        getline(fin,title);
        rmspaceandlwr(title);
        if (checksubstr(title,searchword)){
            exactres.push_back(finalres[i]);
        }
        fin.close();
    }
    return exactres;
}
