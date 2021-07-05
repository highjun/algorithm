#include<iostream>
#include<vector>

using namespace std;

void DFS(int* depth, int parent[][20],long long sum[][20], vector<pair<int,int>> * adj, int cur){
    for(int i = 0; i<adj[cur].size();i++){
        int next = adj[cur][i].first;
        if(depth[next]==-1){
            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;
            sum[next][0] = adj[cur][i].second;
            DFS(depth, parent,sum, adj, next);
        }
    }
}
//type 1의 경우 sum 역시 희소배열과 같이해서 바로 계산가능
//type 2의 경우 미리 길이를 계산해서 희소배열을 이용해서 다시 계산
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int,int>> adj[N];
    int parent[N][20];
    long long sum[N][20];
    int depth[N]; fill(depth, depth+N, -1);
    for(int i = 0;i < N-1; i++){
        int u,v,cost;
        cin >> u >> v >> cost;
        u--; v--;
        adj[u].emplace_back(v,cost);
        adj[v].emplace_back(u,cost);
    }
    depth[0] = 0;
    parent[0][0] = -1;
    sum[0][0] = 0;
    DFS(depth, parent, sum, adj, 0);
    for(int i = 1; i<20;i++){
        for(int j = 0; j < N ; j++){
            if(parent[j][i-1] == -1){
                parent[j][i] = -1;
                sum[j][i] = sum[j][i-1];
            }else{
                parent[j][i] = parent[parent[j][i-1]][i-1];
                sum[j][i] = sum[j][i-1] + sum[parent[j][i-1]][i-1];
            }
        }
    }
    int M; cin >> M;
    for(int i = 0; i<M;i++){
        int type, u, v,k; cin >> type >> u >> v;
        u--; v--;
        int start_u = u, start_v = v;
        int d_u = depth[u], d_v = depth[v];
        if(depth[u]< depth[v]){
            swap(u,v);
        }
        int gap = depth[u]- depth[v];
        int idx = 0;
        long long total_cost = 0;
        while(gap!= 0){
            if(gap%2 == 1){
                gap--;
                total_cost += sum[u][idx];
                u = parent[u][idx];
            }
            gap/= 2;
            idx++;
        }
        if(u != v){
            for(int  j = 19; j >= 0 ;j--){
                if(parent[u][j]!= parent[v][j]){
                    total_cost += sum[u][j];
                    total_cost += sum[v][j];
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            total_cost += sum[u][0];
            total_cost += sum[v][0];
            u = parent[u][0];
            v = parent[v][0];
        }
        if(type == 1){
            cout << total_cost << "\n";
        }else{
            int k; cin >> k;
            k--;
            if(k <=d_u- depth[u]){
                int idx = 0;
                while(k!= 0){
                    if(k%2 == 1){
                        k--;
                        start_u = parent[start_u][idx];
                    }
                    k/= 2;
                    idx++;
                }
                cout << start_u+1 << "\n";
            }else{
                k = d_u + d_v - depth[u]*2 - k;
                int idx = 0;
                while(k!= 0){
                    if(k%2 == 1){
                        k--;
                        start_v = parent[start_v][idx];
                    }
                    k/= 2;
                    idx++;
                }
                cout << start_v+1 << "\n";
            }
        }
    }

    return 0;
}