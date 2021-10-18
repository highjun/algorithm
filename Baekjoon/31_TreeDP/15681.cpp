#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<int>* adj,int* parent, int* sub_tree, int node){
    sub_tree[node] = 1;
    for(int i = 0; i< adj[node].size(); i++){
        int neighbor = adj[node][i];
        if(parent[neighbor] == -1){
            parent[neighbor] = node;
            DFS(adj, parent, sub_tree, neighbor);
            sub_tree[node] += sub_tree[neighbor];
        }
    }
}

//DFS로 정점을 탐색하면서 방문
//새로 방문하게 되는 점은 이전에 방문한 점의 child가 된다.
//또한, Subtree에 대한 탐색이 끝났을 때, 정점의 개수도 같이 저장하게 하면 충분
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,R,Q;
    cin >> N >> R >> Q;
    int parent[N];
    int sub_tree[N];
    fill(parent,parent+N, -1);
    vector<int> adj[N];
    for(int i = 0; i< N-1;i++){
        int u,v;
        cin >> u >>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[R-1] = R-1;
    DFS(adj, parent,sub_tree, R-1);
    while(Q--){
        int q;
        cin >> q;
        cout << sub_tree[q-1] << "\n";
    }

    return 0;
}