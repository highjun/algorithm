#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int n_case = 1;
    while(n!=0 || m!=0){
        bool visit[n];
        fill(visit, visit+n, false);
        vector<int> adj[n];
        int n_tree = 0;
        while(m--){
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>> q;
        int idx = 0;
        while(idx != n){
            if(!visit[idx]){
                visit[idx] = true;
                q.emplace(-1,idx);
                bool is_tree = true;
                while(!q.empty()){
                    int from, node;
                    tie(from, node) = q.front();
                    // cout << from <<"," << node <<"\n";
                    q.pop();
                    for(int i = 0; i<adj[node].size();i++){
                        if(visit[adj[node][i]] && adj[node][i]!= from) is_tree = false;
                        if(!visit[adj[node][i]]){
                            visit[adj[node][i]] = true;
                            q.emplace(node, adj[node][i]);
                        }
                    }
                }
                if(is_tree) n_tree++;
            }
            idx++;
        }
        cout << "Case " << n_case  <<": ";
        if(n_tree > 1){
            cout << "A forest of " << n_tree << " trees.\n";
        }else if(n_tree == 1){
            cout << "There is one tree.\n";
        }else{
            cout << "No trees.\n";
        }
        cin >> n>> m;
        n_case++;
    }
    return 0; 
}