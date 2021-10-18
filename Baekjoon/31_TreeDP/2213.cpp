#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void DFS(vector<int>* adj,int* weight, int* parent, int*indep_in, int* indep_ex, int node){
    indep_in[node] = weight[node];
    indep_ex[node] = 0;
    for(int i = 0; i< adj[node].size(); i++){
        int neighbor = adj[node][i];
        if(parent[neighbor] == -1){
            parent[neighbor] = node;
            DFS(adj, weight, parent, indep_in, indep_ex, neighbor);
            indep_in[node] += indep_ex[neighbor];
            indep_ex[node] += max(indep_in[neighbor], indep_ex[neighbor]);
        }
    }
}

void getResult(vector<int>*result,vector<int>* adj,int* parent,int* indep_in,int* indep_ex,int node, bool is_include){
    if(is_include) result->push_back(node);
    for(int i = 0; i<adj[node].size();i++){
            int u = adj[node][i];
            if(u== parent[node]) continue;
            //is_include면 false
            //!is_include+ indep_in[u] > indep_ex[u] 면 true
            getResult(result, adj, parent, indep_in, indep_ex, u, (!is_include) && (indep_in[u] > indep_ex[u]));
    }
}

//먼저, 최대 독립집합의 크기를 DFS로 구함 이 때, DP는 subtree에 대해 root를 포함하는 독립집합, 포함하지 않는 독립집합
//이후, 백트래킹을 통해서 필요한 Node를 구해냄
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
    DFS(adj,weight, parent, indep_in, indep_ex, 0);
    vector<int> result;
    getResult(&result, adj, parent, indep_in, indep_ex, 0, indep_in[0]> indep_ex[0]);
    
    cout << max(indep_in[0], indep_ex[0]) << "\n";
    sort(result.begin(), result.end());
    for(int i = 0; i<result.size();i++){
        cout<< result[i] +1 << " ";
    }
    cout << "\n";
    return 0;
}