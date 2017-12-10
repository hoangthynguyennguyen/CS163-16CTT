#include "Headers.h"

  void ClearScreen()
    {
    cout << string( 150, '\n' );
    }

void DisplayRes(vector<string> res){
    ifstream fin;
    for (int i=0; i<res.size(); i++){
      string fname ("./Raw Data/");
      fname += res[i];
      fin.open(fname.c_str());
      string title;
      getline (fin,title);
      cout<<res[i]<<"-"<<title<<endl;
      fin.close();
    }
}


void searchcommand(string &searchword, vector<string> stopwords, Trie FilesTrie, Trie TitleTrie){
    int searchtype = querytype(searchword) ;
    //cout<<searchtype<<endl;
    //cout<<searchword<<endl;
    vector <string> finalres;
    if (searchtype == 0){
        finalres = m_NormalSearch(searchword,stopwords,FilesTrie);
    } else if (searchtype == 1){
        finalres = m_MinusSearch(searchword,stopwords,FilesTrie);
    } else if (searchtype == 2){
        finalres = m_ExactSearch(searchword,stopwords,FilesTrie);
    }else if (searchtype == 3){
        int titletype = querytype(searchword);
        //cout<<searchword<<endl;
        if (titletype == 0){
            finalres = m_NormalSearch(searchword,stopwords,TitleTrie);
        } else if (titletype == 1){
            finalres = m_MinusSearch(searchword,stopwords,TitleTrie);
        } else if (titletype == 2){
            finalres = m_TitleExactSearch(searchword,stopwords,TitleTrie);
        }
    }
    if (finalres.empty()){
        cout<<"No result found"<<endl;
    } else {
            ClearScreen();
            DisplayRes(finalres);
    }
    cout<<endl<<endl<<endl;
}


void DisplayFile(string filename){
    string fname ("./Raw Data/");
    string temp;
    ClearScreen();
    for (int i=0 ; i<filename.length(); i++){
        if (filename[i] != ' '){
            temp+=filename[i];
        }
    }
    fname += temp;
    ifstream fin;
    fin.open(fname.c_str());
    if (fin.is_open()){
        string filein((istreambuf_iterator<char> (fin)),istreambuf_iterator<char>());
        cout<<filein;
    } else {
        cout<<"Wrong file name"<<endl;
    }
    cout<<endl<<endl<<endl;

}

void mainmenu (vector<string> stopwords, Trie FilesTrie, Trie TitleTrie){
    ClearScreen();
    string command;
    string input;
    int flag = 0;
    cout<<"\033[1;32mWelcome to the search program.\033[0m"<<endl;
    cout<<"\033[4;31mCommand list:\033[0m"<<endl;
    cout<<"search <content> to search"<<endl;
    cout<<"quit to end the program"<<endl;
    cout<<"man to display this list"<<endl;
    cout<<"open <filename> to open a file" <<endl;
    cout<<endl;
    do {
        cin>>command;
        normalize(command);
        getline(cin,input);
        if (command == "search"){
            searchcommand(input,stopwords,FilesTrie,TitleTrie);
        } else if (command == "quit"){
            break;
        } else if (command == "man"){
            ClearScreen();
            cout<<"\033[4;31mCommand list:\033[0m"<<endl;
            cout<<"search <content> to search"<<endl;
            cout<<"quit to end the program"<<endl;
            cout<<"man to display this list"<<endl;
            cout<<"open <filename> to open a file" <<endl;
        } else if (command == "open"){
            DisplayFile(input);
        } else {
            cout<<"Command not found, please enter again or enter \"man\" to display list of command"<<endl;
        }
    }while (flag == 0);
}
