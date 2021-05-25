#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void DFS(vector<int>* adj,int* weight, int* parent, int*indep_in, int* indep_ex,int* indep_all_ex, int node){
    indep_in[node] = weight[node];
    indep_ex[node] = 0;
    indep_all_ex[node] = 0;
    bool all_ex = true;
    int min_ = INT32_MAX;
    bool is_leaf = true;
    for(int i = 0; i< adj[node].size(); i++){
        int neighbor = adj[node][i];
        if(parent[neighbor] == -1){
            is_leaf = false;
            parent[neighbor] = node;
            DFS(adj, weight, parent, indep_in, indep_ex, indep_all_ex, neighbor);
            indep_in[node] += max(indep_ex[neighbor], indep_all_ex[neighbor]);
            indep_all_ex[node] += indep_ex[neighbor];
            if(indep_ex[neighbor]< indep_in[neighbor]){
                indep_ex[node] += indep_in[neighbor];
                all_ex = false;
            }else{
                indep_ex[node] += indep_ex[neighbor];
                if(min_ > indep_ex[neighbor]- indep_in[neighbor]){
                    min_ = indep_ex[neighbor]- indep_in[neighbor];
                }
            }
        }
    }
    // cout << node << ": " << indep_in[node] << ", " <<indep_ex[node] << "\n";
    if(all_ex && !is_leaf){
        indep_ex[node] -= min_;
    }
}

//indep_ex: root가 들어가지는 않지만 모두 덮는 경우
//indep_all_ex : root가 안 들어가고, 덮이지도 않는 경우
//indep_in : root가 포함되는 경우
//로 DP를 써서 DFS를 사용하여 계산

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    int weight[N];
    for(int i = 0; i<N;i++){
        cin >> weight[i];
    }
    int parent[N];
    int indep_in[N];
    int indep_ex[N];
    int indep_all_ex[N];
    fill(parent,parent+N, -1);
    vector<int> adj[N];
    for(int i = 0; i< N-1;i++){
        int u,v;
        cin >> u >>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[0] = 0;
    DFS(adj,weight, parent, indep_in, indep_ex, indep_all_ex,0);
    
    cout << max(indep_in[0], indep_ex[0]) << "\n";
    return 0;
}