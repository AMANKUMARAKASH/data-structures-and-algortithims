#include<iostream>
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
        int index=word[0]-'A';
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
    void insertword(string word){
        insertutil(root,word);
    }
    bool searchutil(trienode* root, string word){
        //base case
        if(word.length()==0){
            return root->isterminal;

        }
        int index=word[0]-'A';
        trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];


        }
        else{
            //absent
            return false;

        }
        //recursion
        return searchutil(root, word);




    }
    bool search(string word){
        return searchutil(root,word);

    }

};

int main(){
    trie*t = new trie();
    t->insertingword("abcd");
    cout<<"present or not"<<t->search("abcd")<<endl;




    return 0;

}