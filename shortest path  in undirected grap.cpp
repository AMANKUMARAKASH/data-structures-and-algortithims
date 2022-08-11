#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
vector<int>shortestpath(vector<pair<int,int>>&edges,int n, int m, int s, int t){
//create adjacency list
unordered_map<int, list<int>>adj;
for(int i=0; i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
     adj[u].push_back(v);
     adj[v].push_back(u);

}
//do bfs
unordered_map<int,bool>visited;
unordered_map<int,int>parent;
queue<int>q;
q.push(s);
visited[s]=true;
parent[s]=-1;

while(!q.empty()){
    int frontnode= q.front();
    q.pop();
    for(auto i :adj[frontnode]){
       if(!visited[i]) {
       visited[i]=true;
       parent[i]=frontnode;
       q.push(i);

       }


    }
}
 //prepare shortest path
 vector<int>ans;
 int currentNode=t;
 ans.push_back(t);

 while(currentNode!=s){
    currentNode=parent[currentNode];
    ans.push_back(currentNode);


 }




return ans;

}
int main(){

    return 0;

}
