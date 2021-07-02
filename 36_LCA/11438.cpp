#include<iostream>
#include<vector>

using namespace std;

void DFS(int *depth,int parent[][20], vector<int> * adj,int cur){
    for(int  i = 0; i< adj[cur].size();i++){
        int next  =adj[cur][i];
        if(depth[next]==-1){
            depth[next] = depth[cur] +1;
            parent[next][0] = cur;
            DFS(depth, parent, adj, next);
        }
    }
}

//루트가 정해져있으므로, adj에서 DFS를 통해서 depth와 parent를 잡음
//sparse Matrix로 미리 2^i번째 조상들을 계산한 후, 이를 통해서
//LCA를 logN 시간 안에 찾을 수 있음! 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int in[N]; fill(in, in+N, 0);
    vector<int> adj[N];
    int parent[N][20];
    int depth[N]; fill(depth, depth+N, -1);
    for(int i = 0; i<N-1;i++){
        int src, dest;
        cin >> src >> dest;
        src--; dest--;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    depth[0] = 0;
    parent[0][0] = -1;
    DFS(depth, parent, adj, 0);
    // for(int i = 0;i<N;i++){
    //     cout << parent[i][0] << " ";
    // }
    // cout << "\n";
    for(int i = 1 ;i<20;i++){
        for(int j = 0; j<N;j++){
            if(parent[j][i-1] == -1){
                parent[j][i] = -1;
            }else{
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
        // for(int j = 0;j<N;j++){
        //     cout << parent[j][i] << " ";
        // }
        // cout << "\n";
    }
    int M; cin >> M;
    for(int i = 0; i <M;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(depth[a] < depth[b]){
            swap(a,b);
        }
        int gap = depth[a] - depth[b];
        // cout << gap << "\n";
        int idx = 0;
        while(gap!=0){
            if(gap%2 == 1){
                a = parent[a][idx];
                gap--;
            }
            gap /= 2;
            idx++;
        }
        int d = depth[b];
        if(a != b){
            //처음 같지 않아지는 부분에서 업데이트하여 가장 마지막의 같지 않은 부분까지 올린다.
            for(int  i = 19; i >= 0 ;i--){
                if(parent[a][i]!= parent[b][i]){
                    a = parent[a][i];
                    b = parent[b][i];
                    // cout << "i: " << i << "= " << a << ", " << b << "\n";
                }
            }
            a = parent[a][0];
        }
        cout << a+1 << "\n";
    }
    return 0;
}