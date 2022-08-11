#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<list>
using namespace std;
void topsort(int node,vector<bool>&visited,stack<int>&s, unordered_map<int,list<int>>adj){
 visited[node]=1;
 for(auto neighbour : adj[node]){
    if(!visited[neighbour])
    topsort(neighbour,visited,s,adj);

 }
 //important
 s.push(node);

}
vector<int>topologicalsort(vector<vector<int>>edges,int n, int e){
    //creating aadjaceny list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
int u=edges[i][0];
int v=edges[i][1];

adj[u].push_back(v);

    }
    // call dfs topological sort util function for all components
vector<bool>visited(n);
stack<int>s;
for(int i=0; i<n; i++){
    if(!visited[i])
    topsort(i,visited,s,adj);

    
}
vector<int>ans;
while(!s.empty()){
   ans.push_back(s.top()) ;
   s.pop();

}
return ans;


}

int main() {
    return 0;
}
