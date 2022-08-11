#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;
 bool checkcycleDFS(int node,unordered_map<int ,bool>&visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adjlist){
visited[node]=true;
dfsvisited[node]=true;
for(auto neighbour :adjlist[node]){
    if(!visited[neighbour]){
        bool cycledetected=checkcycleDFS(neighbour,visited,dfsvisited,adjlist);
        if(cycledetected)
        return true;

    }
    else if(dfsvisited[neighbour]){
        return true;

    }
}
dfsvisited[node]=false;
return false;

 }
int detectcycleInDirectedGraph(int n, vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adjlist;
    for(int i=0; i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adjlist[u].push_back(v);
    

    }
    //call dfs for all components
    unordered_map<int ,bool>visited;
    unordered_map<int,bool>dfsvisited;
    for(int i=0; i<=n; i++){
        if(!visited[i]){
            bool cycleFound= checkcycleDFS(i,visited,dfsvisited,adjlist);
            if(cycleFound)
            return true;

        }
    }
return false;

}
int main(){

    return 0;

}