#include <iostream>
using namespace std;
#include <vector>
#include<list>
#include<unordered_map>
#include<queue>

bool iscyclicbfs(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjlist){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        for(auto neighbour:adjlist[frontnode]){
            if(visited[neighbour]==true && neighbour!=parent[frontnode]){
 return true;

            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=frontnode;

            }
        }

    }
    return false;

}
 string cycleDetection(vector<vector<int>> &edges,int n,int m){
        //create adjacency list
        unordered_map<int,list<int>>adjlist;
        for( int i=0; i<m; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);

            

        }
        //to handle disconnected components
        unordered_map<int,bool>visited;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool ans=iscyclicbfs(i,visited,adjlist);
                if(ans==1)
                return "yes";

            }
        }
        return "no";


    }
int main(){
    return 0;
   
}