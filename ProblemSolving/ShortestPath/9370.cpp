#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<assert.h>

using namespace std;

#define MAX 4000000 

struct Int2{
    int node;
    int weight;
};

struct compare{
    bool operator()(Int2 a, Int2 b){
        return a.weight > b.weight;
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
        tmp.weight = i==start? 0:MAX;
        tmp.node = i;
        q.push(tmp);
    }
    while(!q.empty()){
        Int2 node= q.top();
        q.pop();
        if(check[node.node]) continue;
        check[node.node] = true;
        int len = adj[node.node].size();
        for(int i = 0; i<len;i++){
            Int2 next = adj[node.node][i];
            if(path[next.node] > path[node.node]+next.weight){
                path[next.node] = path[node.node]+next.weight;
                Int2 tmp2;
                tmp2.node = next.node, tmp2.weight= path[next.node];
                q.push(tmp2);
            }
        }
    }
    return;
}



int main(){
    int n_case; 
    cin >> n_case;
    while(n_case--){
        int n,m,t; 
        cin >> n >> m >> t; 
        int s,g,h; 
        cin >> s >> g >> h; 
        vector<Int2> adj[n];
        int gh_weight= -1;
        while(m--){
            int a,b,d; 
            cin >> a >> b >> d;  
            Int2 a1, b1; 
            //Sol1. 2배해서 Unique하게 만든다.
            // if((a == g && b== h)||(a == h && b== g)){
            //     d = 2*d-1;
            // }else{
            //     d*=2;
            // }
            //Sol2. gh까지의 거리비교
            if((a == g && b== h)||(a == h && b== g)){
                gh_weight = d;
            }
            a1.node = a-1, a1.weight = d;
            b1.node = b-1, b1.weight = d;
            adj[a-1].push_back(b1);
            adj[b-1].push_back(a1);
        }
        assert(gh_weight != -1);
        int path_g[n];
        dijkstra(path_g, n, adj, g-1);
        int path_h[n];
        dijkstra(path_h, n, adj, h-1);
        int path_s[n];
        dijkstra(path_s, n, adj, s-1);
        vector<int> result;
        for(int i = 0; i<t;i++){
            int x; 
            cin >> x; 
            if(min(path_g[s-1]+ gh_weight + path_h[x-1], path_h[s-1]+ gh_weight + path_g[x-1]) == path_s[x-1]){
                result.push_back(x);
            }
        }
        // for(int i = 0; i<t;i++){
        //     int x; 
        //     cin >> x; 
        //     if(path_s[x-1]%2 == 1){
        //         result.push_back(x);
        //     }
        // }
        sort(result.begin(), result.end());
        int len = result.size();
        for(int i = 0;i<len;i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}