#include<iostream>
// #include "data.cpp"
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode*root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode*root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //calculating index for inserting character in child
        int index = word[0] - 'a';
        TrieNode*child = NULL;

        if(root->children[index] != NULL){
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursive call
        insertUtils(child, word.substr(1));

    }
    void insertWord(string word){
        insertUtils(root,word);
    }
//=====================================================================
    void printSuggestions(TrieNode*curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a';ch <= 'z';ch++){

            TrieNode*next = curr->children[ch-'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
//=====================================================================
    vector<vector<string> >getSuggestions(string str){
        TrieNode*prev = root;
        vector<vector<string> > output;
        string prefix = "";

        for(int i =0;i<str.length();i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for last character
            TrieNode*curr = prev->children[lastch - 'a'];
             
            //if not found
            if (curr == NULL){
                break;
            }

            // if present
            vector<string> temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie*t = new Trie();

    for(int i =0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}
int main(){
    vector<string> contactList ={
        "person","hello","aeroboat","hashtable","hero","world"
        };
    string query;
    cout<<"Enter something to get suggestions : ";
    cin>>query;
    vector<vector<string>> ans = phoneDirectory(contactList,query);
    set<vector<string> >data;

    for(auto i:ans){
        data.insert(i);
    }

    for(auto i:data){
        for(auto j:i){
            cout<<j<<endl;
        }
    }


    return 0;
}