#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<memory.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M,V;
    cin >> N>> M>> V;
    vector<int> adjacent[N];
    for(int i = 0; i< M; i++){
        int u,v;
        cin >> u >> v;
        adjacent[u-1].push_back(v-1);
        adjacent[v-1].push_back(u-1);
    }
    for(int i = 0 ;i<N;i++){
        sort(adjacent[i].begin(), adjacent[i].end());
    }
    stack<int> dfs;
    bool check[N];
    memset(check, 0, sizeof(bool)*N);
    check[V-1] = true;
    cout << V << " "; 
    dfs.push(V);
    while(!dfs.empty()){
        int node = dfs.top();
        int len  =adjacent[node-1].size();
        int i = 0;
        while(i<len){
            if(!check[adjacent[node-1][i]]){
                cout << adjacent[node-1][i]+1 << " ";
                check[adjacent[node-1][i]] = true;
                dfs.push(adjacent[node-1][i]+1);
                break;
            }
            i++;
        }
        if(i == len){
            dfs.pop();
        }
    }
    cout << "\n";
    
    queue<int> bfs;
    memset(check, 0, sizeof(bool)*N);
    check[V-1] = true;
    cout << V << " "; 
    bfs.push(V);
    while(!bfs.empty()){
        int node = bfs.front();
        int len  =adjacent[node-1].size();
        for(int i = 0; i<len;i++){
            if(!check[adjacent[node-1][i]]){
                cout << adjacent[node-1][i]+1 << " ";
                check[adjacent[node-1][i]] = true;
                bfs.push(adjacent[node-1][i]+1);
            }
        }
        bfs.pop();
    }
    cout << "\n";


    return 0;
}