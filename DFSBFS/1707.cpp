#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>

using namespace std;

int main(){
    int n_case;
    cin >> n_case;
    for(int i=0;i<n_case; i++){
        int V,E;
        cin >> V >> E;
        vector<int> adj[V];
        for(int j = 0; j <E;j++){
            int u,v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        int check[V];
        memset(check, 0, V*sizeof(int));
        queue<int> bfs;
        int start = 0;
        while(start <V){
            if(check[start] == 0){
                bfs.push(start);
                check[start] = 1;
                while(!bfs.empty()){
                    int node = bfs.front();
                    bfs.pop();
                    int len = adj[node].size();
                    int tmp = check[node];
                    for(int j = 0; j<len;j++){
                        if(check[adj[node][j]] == 0){
                            check[adj[node][j]] = -1*check[node];
                            bfs.push(adj[node][j]);
                        }
                    }
                }
            }else{
                start++;
            }
        }
        bool bipartite = true;
        for(int j = 0;j<V;j++){
            int len  = adj[j].size();
            for(int k = 0;k<len ; k++){
                if(check[j] ==  check[adj[j][k]]){
                    bipartite = false;
                    break;
                }
            }
            if(!bipartite) break;
        }
        cout << (bipartite?"YES":"NO" )<< "\n";
    }
    return 0;
}