#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<int>* adj,int* depth, int visit){
    for(int i = 0;i<adj[visit].size();i++){
        int next = adj[visit][i];
        if(depth[next] == -1){
            depth[next] = depth[visit]+1;
            DFS(adj, depth, next);
        }
    }
}

// Lowest Common Ancestor
// 가장 기본적인 방법으로 O(N)으로 성립
// Depth를 맞추고 순서대로 parent로 올라가면서 비교한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int parent[N];
        vector<int> adj[N];
        fill(parent, parent+N, -1);
        for(int i = 1 ;i<N; i++){
            int src, dest; cin >> src >> dest;
            src--; dest--;
            parent[dest] = src;
            adj[src].push_back(dest);
        }
        int depth[N];
        fill(depth, depth+N, -1);
        int root;
        for(root = 0; root <N;root++){
            if(parent[root] == -1) break;
        }
        depth[root] = 0;
        DFS(adj, depth, root);

        int a,b; cin >> a >> b;
        a--; b--;
        if(depth[a] >depth[b]){
            swap(a, b);
        }
        while(depth[a] != depth[b]){
            // cout << a+1 << ", " <<  b+1 <<"\n";
            b = parent[b];
        }
        while(a != b){
            // cout << a+1 << ", " <<  b+1 <<"\n";
            a = parent[a];
            b = parent[b];
        }
        cout << a+1 <<"\n";
    }
    return 0;
}