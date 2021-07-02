#include<iostream>
#include<vector>

using namespace std;

void DFS(int* depth, int parent[][20],int max_[][20], int min_[][20], vector<pair<int,int>>* adj, int cur){
    for(int i = 0;i < adj[cur].size();i++){
        int next = adj[cur][i].first;
        if(depth[next] == -1){
            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;
            max_[next][0] = adj[cur][i].second;
            min_[next][0] = adj[cur][i].second;
            DFS(depth, parent, max_,min_, adj, next);
        }
    }
}

// 트리 구조의 데이터므로 루트를 1로 임의로 설정
// min, max 역시 마찬가지로 희소배열을 통해 계산이 가능하다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<pair<int,int>> adj[N];
    for(int i = 0; i<N-1;i++){
        int u,v, cost;
        cin >> u >> v >> cost;
        u--; v--;
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }
    int depth[N]; fill(depth, depth+N, -1);
    int parent[N][20];
    int max_[N][20];
    int min_[N][20];
    depth[0] = 0; parent[0][0] = -1;
    max_[0][0] = INT32_MIN;
    min_[0][0] = INT32_MAX;
    DFS(depth, parent, max_,min_,adj, 0);

    // for(int j = 0 ; j<N ; j++){
    //     cout << parent[j][0] << " ";
    // }
    // cout << "\n";
    for(int i = 1; i<20; i++){
        for(int j = 0;j<N; j++){
            if(parent[j][i-1]==-1){
                parent[j][i] = -1;
                max_[j][i] = max_[j][i];
                min_[j][i] = min_[j][i];
            }else{
                parent[j][i] = parent[parent[j][i-1]][i-1];
                max_[j][i] = max(max_[j][i-1], max_[parent[j][i-1]][i-1]);
                min_[j][i] = min(min_[j][i-1], min_[parent[j][i-1]][i-1]);
            }
        }
    }

    int M; cin >> M;
    for(int i = 0; i <M;i++){
        int a,b;
        // cout << "query " << i+1 << "\n";
        cin >> a >> b;
        a--; b--;
        if(depth[a] < depth[b]){
            swap(a,b);
        }
        int gap = depth[a] - depth[b];
        // cout << gap << "\n";
        int idx = 0;
        int max_cost = INT32_MIN, min_cost = INT32_MAX;
        while(gap!=0){
            if(gap%2 == 1){
                max_cost = max(max_cost, max_[a][idx]);
                min_cost = min(min_cost, min_[a][idx]);
                a = parent[a][idx];
                // cout << "a,b : " << a+1 << ", " << b+1 <<"\n";
                // cout << min_cost << ", " << max_cost << "\n";
                gap--;
            }
            gap /= 2;
            idx++;
        }
        if(a != b){
            //처음 같지 않아지는 부분에서 업데이트하여 가장 마지막의 같지 않은 부분까지 올린다.
            for(int  i = 19; i >= 0 ;i--){
                if(parent[a][i]!= parent[b][i]){
                    max_cost = max(max_cost, max(max_[a][i], max_[b][i]));
                    min_cost = min(min_cost, min(min_[a][i], min_[b][i]));
                    a = parent[a][i];
                    b = parent[b][i];
                    // cout << "a,b : " << a+1 << ", " << b+1 <<"\n";
                    // cout << min_cost << ", " << max_cost << "\n";
                    // cout << "i: " << i << "= " << a << ", " << b << "\n";
                }
            }
            max_cost = max(max_cost, max(max_[a][0], max_[b][0]));
            min_cost = min(min_cost, min(min_[a][0], min_[b][0]));
            b = a = parent[a][0];
            // cout << "a,b : " << a+1 << ", " << b+1 <<"\n";
            // cout << min_cost << ", " << max_cost << "\n";
        }
        cout << min_cost << " " << max_cost <<"\n";
    }

    return 0;
}