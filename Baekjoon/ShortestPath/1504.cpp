#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

#define MAX 800000 

struct Int2{
    int a;
    int b;
};

struct compare{
    bool operator()(Int2 a, Int2 b){
        return a.b > b.b;
    }
};

void dijkstra(int* path, int V,vector<Int2>* adj, int start){
    fill(path, path+V, MAX);
    path[start] = 0;
    bool check[V];
    memset(check, 0, V);
    priority_queue<Int2, vector<Int2>, compare> q;
    for(int i = 0;i <V;i++){
        Int2 tmp;
        tmp.b = i==start? 0:MAX;
        tmp.a = i;
        q.push(tmp);
    }
    while(!q.empty()){
        Int2 node= q.top();
        q.pop();
        if(check[node.a]) continue;
        check[node.a] = true;
        int len = adj[node.a].size();
        for(int i = 0; i<len;i++){
            Int2 next = adj[node.a][i];
            if(path[next.a] > path[node.a]+next.b){
                path[next.a] = path[node.a]+next.b;
                Int2 tmp2;
                tmp2.a = next.a, tmp2.b= path[next.a];
                q.push(tmp2);
            }
        }
    }
    return;
}



int main(){
    // ios_base :: sync_with_stdio(false); 
    // cin.tie(NULL); 
    // cout.tie(NULL);
    int V,E;
    cin >> V >> E;
    vector<Int2> adj[V];
    for(int i = 0 ;i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        Int2 u1, v1;
        v1.a = v-1, v1.b = w;
        u1.a = u-1, u1.b = w;
        adj[v-1].push_back(u1);
        adj[u-1].push_back(v1);
    }
    int v1, v2; 
    cin >> v1 >> v2;
    int path1[V],path2[V];
    dijkstra(path1, V, adj, v1-1);
    dijkstra(path2, V, adj, v2-1);
    int tmp = min(path1[0]+ path2[V-1]+ path1[v2-1],path2[0]+ path1[V-1]+ path1[v2-1]); 
    if(tmp >= MAX) tmp = -1;
    cout << tmp <<"\n";
    return 0;
}