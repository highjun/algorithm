#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<int>* adj,int* parent, int* early_in, int* early_ex, int node){
    early_in[node] = 1;
    early_ex[node] = 0;
    for(int i = 0; i< adj[node].size(); i++){
        int neighbor = adj[node][i];
        if(parent[neighbor] == -1){
            parent[neighbor] = node;
            DFS(adj, parent, early_in, early_ex, neighbor);
            early_in[node] += min(early_in[neighbor], early_ex[neighbor]);
            early_ex[node] += early_in[neighbor];
        }
    }
}

//마찬가지로 처음의 early adopter에 root가 포함되는 경우와 아닌 경우에 따라 저장
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> adj[N];
    for(int i = 0; i<N-1;i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int early_in[N],early_ex[N], parent[N];
    fill(parent, parent+N, -1);
    parent[0] = 0;
    DFS(adj, parent, early_in, early_ex, 0);
    cout << min(early_in[0], early_ex[0]) << "\n";
    return 0;
}