
#include "Headers.h"


void FilesInit(Trie &T){
    vector<string> files;
    files = listFile("./Data");
    sort(files.begin(),files.end(),compare);
    int e = files.size();
    ifstream fin;
    string temp;
    //fout.open("./CS163-Data/Ref/FileTrie.txt");
    for (int i=0 ; i<e; i++){
      //cout<<files[i]<<endl;
      string filename("./Data/");
      filename+=files[i];
      fin.open(filename.c_str());
      fin>>temp;
      while (!fin.eof()){
        T.push(temp.c_str(),files[i]);
        fin>>temp;
      }
      fin.close();
      if (i%200==0){
        cout<<"."<<endl;
      }
    }
    //cout<<"Load complete !";
}

void TitleInit(Trie &T){
    vector<string> files;
    files = listFile("./Title Data");
    sort(files.begin(),files.end(),compare);
    int e = files.size();
    ifstream fin;
    string temp;
    //fout.open("./CS163-Data/Ref/FileTrie.txt");
    for (int i=0 ; i<e; i++){
      //cout<<files[i]<<endl;
      string filename("./Title Data/");
      filename+=files[i];
      fin.open(filename.c_str());
      fin>>temp;
      while (!fin.eof()){
        T.push(temp.c_str(),files[i]);
        fin>>temp;
      }
      fin.close();
    }
    cout<<"Load complete !"<<endl;
}


vector<string> listFile(const char* path){
        vector<string> files;
        DIR *pDIR;
        struct dirent *entry;
        if(pDIR=opendir(path)){
                while(entry = readdir(pDIR)){
                        if( (strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0) )
                        files.push_back(entry->d_name);
                }
                closedir(pDIR);
        }
        return files;
}
bool isStopword(vector<string> stopwords, string key){
  for (int i=0; i<stopwords.size(); i++){
    if (key==stopwords[i]) {
      return true;
    }
  }
  return false;
}

void normalize (string &key){
  int bot = key.size();
  string nKey;
  //cout<<bot<<endl;
  for (int i= 0 ; i<bot; i++){
    if ((key[i]>='a') && (key[i]<='z')){
      nKey += key[i] ;
    } else if ((key[i]>='A') && (key[i]<='Z')){
      nKey += key[i]+('z'-'Z');
    } else if ((key[i]>='0') && (key[i]<='9')) {
      nKey += key[i];
    }
  }
  key = nKey;
}



bool compare(const string &a, const string &b){
  return (a<b) ;
}

bool checkinlist(vector<string> target, string file){
  int l=0, r=(target.size()-1);
  int mid ;
  while (l<=r){
    mid = (l+r)/2;
    if (target[mid]==file){
      return true;
    } else if (target[mid]<file){
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return false;
}
