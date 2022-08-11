#include<iostream>
#include <unordered_map>
#include<list>
#include<vector>
#include<limits.h>


using namespace std;
vector<pair<pair<int,int>,int>>calculatePrimeMST(int n, int m,vector<pair<pair<int,int>,int>> &edges){
    //cretae adj list
    unordered_map<int,list<pair<int,int>>>adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first.first;
        int v=edges[i].first.second;
        int w =edges[i].second;
        adjlist[u].push_back(make_pair(v,w));
        adjlist[v].push_back(make_pair(u,w));


    }
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    for(int i=0; i<=n; i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;

    }
    //let's start the algo
    key[1]=0;
    parent[1]=-1;
    for(int i=1; i<n;i++){
        int mini=INT_MAX;
        int u;
        //find the min wali node;

        for(int v=1; v<=n; v++){
            if(mst[v]==false &&key[v]<mini){
                u=v;
                mini=key[v];


            }
        }
        //mark min nodes astrue
        mst[u]=true;
        //check its adjacent nodes
        for(auto it:adjlist[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;

            }

        }

    }
    vector<pair<pair<int,int>,int>>result;
    for(int i=2; i<=n;i++){
        result.push_back({{parent[i],i},key[i]});

    }
    return result;




}
int main(){
    return 0;

}