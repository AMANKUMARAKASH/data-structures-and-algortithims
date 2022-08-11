 #include<iostream>
 using namespace std;
 #include<vector>
 #include<unordered_map>
 #include<map>
 #include<list>
 #include<queue>
 void prepareAdjList(unordered_map<int,list<int>>&adjList,vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

 }
 void printAdj(unordered_map<int,list<int>>&adjList){
    for(auto i:adjList){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }cout<<endl;
    }

 }
 void bfs(unordered_map<int,list<int>>  &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
 queue<int>q;
 q.push(node);
 visited[node]=1;
 while(!q.empty()){
    int frontnode=q.front();
    q.pop();

    //store frontnode into ans
    ans.push_back(frontnode);
    //traverse all neighbours of frontnode
    for(auto i: adjList[frontnode]){
        if(!visited[i]){
            q.push(i);
            visited[i]=1;


        }

    }



 }


 }
 vector<int>BFS(int vertex,vector<pair<int, int>>edges){
    unordered_map<int,list<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool>visited;
    printAdj(adjList);


 prepareAdjList(adjList,edges);
 //traverse all components of graph
 for(int i=0; i<vertex; i++){
    if(!visited[i]){
        bfs(adjList,visited,ans,i);
    }

 }
return ans;



 }
 int main(){
    return 0;

 }