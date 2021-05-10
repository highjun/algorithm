#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<memory.h>

using namespace std;

int main(){
    int V,E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i<E;i++){
        int u, v;
        cin >> u>> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    stack<int> dfs;
    bool check[V];
    memset(check, 0, sizeof(bool)*V);
    check[0] = true;
    dfs.push(1);
    int cnt = 0;
    while(!dfs.empty()){
        int node = dfs.top();
        int len  =adj[node-1].size();
        int i = 0;
        while(i<len){
            if(!check[adj[node-1][i]]){
                check[adj[node-1][i]] = true;
                cnt++;
                dfs.push(adj[node-1][i]+1);
                break;
            }
            i++;
        }
        if(i == len){
            dfs.pop();
        }
    }
    cout << cnt << "\n";
    return 0;
}