#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dijkstra(int target, int* D, int* in, vector<int>* adj,priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> *q, int elapsed){
    if(!q->empty()){
        auto tmp = q->top();
        q->pop();
        elapsed = tmp.first;
        for(int i = 0; i< adj[tmp.second].size();i++){
            int dest = adj[tmp.second][i];
            if(--in[dest] == 0){
                q->emplace(elapsed + D[dest],dest);
            }
        }
        // cout << "건물: " << tmp.second+1 << " ,현재 소요 시간: " << elapsed <<"\n"; 
        if(tmp.second == target)
            return elapsed;
        return dijkstra(target,D, in, adj, q, elapsed);
    }else{
        return elapsed;
    }
}
// 위상 정렬을 사용하면서 동시에 Dijkstra와 같이 Min heap을 사용한다.
// 현재 진행된 시간을 체크해서 건설이 완료되는 시간을 queue에 저장하여 이후에 pop하면 충분!
int main(){
    int T;
    cin >> T;
    while(T--){
        int N,K;
        cin >> N >> K;
        int D[N];
        for(int i = 0;i<N;i++) cin >> D[i];
        vector<int> adj[N];
        int in[N]; fill(in, in+N, 0);
        for(int i = 0;i< K ; i++){
            int src, dest;
            cin >> src >> dest;
            src--; dest--;
            adj[src].push_back(dest);
            in[dest]++;
        }
        int target; cin >> target; target--;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 0; i< N;i++){
            if(in[i] == 0) q.emplace(D[i], i);
        }  
        cout << dijkstra(target,D, in, adj, &q, 0) << "\n";
    }
    return 0;
}