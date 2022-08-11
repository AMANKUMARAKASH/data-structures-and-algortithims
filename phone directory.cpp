#include<iostream>
#include <vector>
using namespace std;
class trienode{
    public:
    char data;
    trienode*children[26];
    bool isterminal;
     trienode(char ch){
        data= ch;
        for(int i =0;i<26;i++){
            children[i]=NULL;


        }
        isterminal=false;

     }

};
class trie{
    public:
    trienode*root;
    trie(){
        root=new trienode('\0');

    }
    void insertutil(trienode*root, string word){
        //base case
        if(word.length()==0){
            root->isterminal=true;
            return ;
            
            
        }
        //assumption ,word will be in caps
        int index=word[0]-'a';
         trienode*child;
        //present case
        if(root->children[index]!=NULL){
            child=root->children[index];



        }
        else{
            //absent
            child= new trienode(word[0]);
            root->children[index]=child;


        }
        //recursion
        insertutil(child,word.substr(1));




    }
    void insertingword(string word){
        insertutil(root,word);
       



    }
    void insertingword(string word){
        insertutil(root,word);
    }
    void printsuggestions(trienode*curr,vector<string>&temp,string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
            
        }
        for(char ch='a';ch<='z'; ch++){
            trienode*next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printsuggestions(next,temp,prefix);
                prefix.pop_back();


            }
        }

    }
    vector<vector<string>> getsuggestions(string str){
        trienode*prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);
            //check for lastch
            trienode*curr=prev->children[lastch-'a'];
            //if not found
            if(curr==NULL){
                break;

            }
            //if found
            vector<string> temp;

            printsuggestions(curr, temp,prefix);
             output.push_back(temp);
             temp.clear();
             prev=curr;





            




        }
        return output;
        

    }
    

    

};
vector<vector<string>>phoneDirectory(vector<string>&contactList, string &querystr){
// creation of trie
 trie*t = new trie();
 //insert all contact in trie
 for(int i=0; i<contactList.size();i++){
    string str=contactList[i];
    t->insertingword(str);


 }
 //return ans
 return t->getsuggestions(querystr);
}


int main (){
    return 0;
    
}