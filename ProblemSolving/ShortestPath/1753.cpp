#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

#define MAX 200000 

struct Int2{
    int a;
    int b;
};

struct compare{
    bool operator()(Int2 a, Int2 b){
        return a.b > b.b;
    }
};

int main(){
    // ios_base :: sync_with_stdio(false); 
    // cin.tie(NULL); 
    // cout.tie(NULL);
    int V,E,v0;
    cin >> V >> E >> v0;
    int path[V];
    memset(path, MAX, sizeof(int)*V);
    path[v0-1] = 0;
    vector<Int2> adj[V];
    priority_queue<Int2, vector<Int2>, compare> q;
    v0--;
    for(int i = 0;i <V;i++){
        Int2 tmp;
        tmp.b = i==v0? 0:MAX;
        tmp.a = i;
        q.push(tmp);
    }
    for(int i = 0 ;i<E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        Int2 tmp;
        tmp.a = v-1, tmp.b = w;
        adj[u-1].push_back(tmp);
    }
    bool check[V];
    memset(check, 0, V);
    while(!q.empty()){
        Int2 tmp= q.top();
        q.pop();

        // cout << tmp.a <<"\n";
        // for(int i = 0;i<V;i++){
        //     cout << path[i]<< " ";
        // }
        // cout <<"\n";

        if(check[tmp.a]) continue;
        check[tmp.a] = true;
        int len = adj[tmp.a].size();
        for(int i = 0; i<len;i++){
            Int2 next = adj[tmp.a][i];
            if(path[next.a] > path[tmp.a]+next.b){
                path[next.a] = path[tmp.a]+next.b;
                Int2 tmp2;
                tmp2.a = next.a, tmp2.b= path[next.a];
                q.push(tmp2);
            }
        }
    }
    for(int i = 0;i<V;i++){
        cout << (path[i]>=MAX? "INF": to_string(path[i]) )<< "\n";
    }
    return 0;
}