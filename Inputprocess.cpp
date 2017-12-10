#include "Headers.h"

/*int main() {
  vector<string> stopwords;
  ifstream fin;
  fin.open("./Ref/stopword.txt");
  string temp;
  fin>>temp;
  while (!fin.eof()){
    stopwords.push_back(temp);
    fin>>temp;
  }
  string command, searchword;
  vector<string> querykeywords;
  cin>>command;
  getline(cin,searchword);
  normalizestring(searchword);
  cout<<command<<endl<<searchword<<endl;
  querykeywords = splitkeywords(searchword,stopwords);
  for (int i=0 ; i<querykeywords.size(); i++){
    cout<<querykeywords[i]<<endl;
  }
  return 0;
}*/



vector<string> splitkeywords(string searchword, vector<string> stopwords){
  int l=0, r, i;
  vector<string> split;
  string temp;
  int length = searchword.length();
  for (i=0; i<length; i++){
    if (searchword[i] == ' '){
      r=i;
      temp = searchword.substr(l,(r-l));
      l=i+1;
      if (!isStopword(stopwords,temp)){
        split.push_back(temp);
      }
    }
  }
  temp = searchword.substr(l,(i-l));
  if (!isStopword(stopwords,temp)){
    split.push_back(temp);
  }
  return split;
}

void rmspaceandlwr(string &key){
    int bot = key.size();
  string nKey;
  //cout<<bot<<endl;
  for (int i= 0 ; i<bot; i++){
    if ((key[i]>='A') && (key[i]<='Z')){
      nKey += key[i]+('z'-'Z');
    } else if ((key[i]==' ')&&(i != 0)&&(key[i-1] != ' ')){
      nKey += key[i];
    } else if (key[i] != ' '){
      nKey += key[i];
    }
  }
  key = nKey;
}

/*
Return 1 for "-" type
2 for exact search
0 for normal
3 for intitle:
-1 for invalid search type
*/
int querytype(string &key){
    rmspaceandlwr(key);
    //cout<<key<<endl;
    if (key[0]=='-') {
        normalizestring(key);
        return -1;
    }
    if ((key[0]=='"')||(key[0]=='#')){
        //normalizestring(key);
        return 2;
    }
    string first7;
    first7 = key.substr(0,7);
    if (first7=="intitle") {
        key.erase(0,8);
        return 3;
    }
    for (int i=0; i<key.size(); i++){
        if ((key[i]=='-')&&(key[i-1]==' ')){
            return 1;
        }
    }
    normalizestring(key);
    return 0;
}
