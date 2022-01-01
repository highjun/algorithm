#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(priority_queue<int, vector<int>, greater<int>> * q, int* in, vector<int> *adj){
    if(!q->empty()){
        int curr = q->top();
        q->pop();
        cout << curr+1 << " ";
        for(int i = 0; i< adj[curr].size();i++){
            int next = adj[curr][i];
            in[next]--;
            if(in[next] == 0) q->emplace(next);
        }
        BFS(q,in, adj);
    }else{
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    int in[N];
    fill(in, in+N, 0);
    vector<int> adj[N];
    while(M--){
        int src, dest;
        cin >> src >> dest;
        src--; dest--;
        adj[src].push_back(dest);
        in[dest]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0;i<N;i++){
        if(in[i] == 0) q.emplace(i);
    }
    BFS(&q, in, adj);
    
    return 0;
}