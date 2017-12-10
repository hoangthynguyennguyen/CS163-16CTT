#include "Headers.h"




string readfile(string filename){
    ifstream fin;
    string fname ("./Raw Data/");
    fname += filename;
    fin.open(fname.c_str());
    string filein((istreambuf_iterator<char> (fin)),istreambuf_iterator<char>());
    rmspaceandlwr(filein);
    return filein;
}

void normalizestring (string &key){
  int bot = key.size();
  string nKey;
  //cout<<bot<<endl;
  for (int i= 0 ; i<bot; i++){
    if (((key[i]>='a') && (key[i]<='z'))||(key[i]=='$')||(key[i]==39)||((key[i]=='-')&&(key[i-1] == ' '))){
      nKey += key[i] ;
    } else if ((key[i]>='A') && (key[i]<='Z')){
      nKey += key[i]+('z'-'Z');
    } else if ((key[i]>='0') && (key[i]<='9')) {
      nKey += key[i];
    } else if ((key[i]==' ')&&(i != 0)&&(key[i-1] != ' ')){
      nKey += key[i];
    } else if ((key[i]=='-')||(key[i]=='/')) {
      nKey += ' ';
    }
  }
  key = nKey;
}


bool checksubstr(string file, string searchword){
    int *Z;
    string S;
    S = searchword + file;
    int length = S.size();
    Z = new int [length+1];
    int L = 0, R = 0;
    Z[0] = length;
    for (int i = 1; i < length; i++){
        if (i > R){
            L = R = i;
            while ((R < length) && (S[R] == S[R - L])) {
                    R++;
            }
            Z[i] = R - L; R--;
        } else{
            int k = i - L;
            if (Z[k] < R - i + 1) {
                    Z[i] = Z[k];
            }
            else{
                L = i;
                while ((R < length) && (S[R] == S[R - L])) {
                        R++;
                }
                Z[i] = R - L; R--;
            }
        }
    }
    int start = searchword.size();
    for (int i = start; i<length; i++){
        if (Z[i] >= start){
            return true;
        }
    }
    return false;
}
