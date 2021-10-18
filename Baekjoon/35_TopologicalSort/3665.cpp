#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int prev_node_as_idx[500];
int prev_rank_as_idx[500];


bool cmp(pair<int,int> a, pair<int,int> b){
    return (prev_node_as_idx[a.first] < prev_node_as_idx[b.first]) || 
            (prev_node_as_idx[a.first] == prev_node_as_idx[b.first] && 
                prev_node_as_idx[a.second] < prev_node_as_idx[b.second]);
}

int DFS(vector<int> *vec, int N, stack<int> *s, int* in, vector<int> *adj){
    if(!s->empty()){
        int node = s->top();
        s->pop();
        vec->push_back(node+1);
        for(int i = 0; i< adj[node].size();i++){
            in[adj[node][i]]--;
            if(in[adj[node][i]] == 0){
                s->push(adj[node][i]);
            }
        }
        return DFS(vec, N, s, in, adj);
    }else{
        if(vec->size() != N) return -1;
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 0;i< N;i++){
            int node; 
            cin >> node; node--;
            prev_node_as_idx[node] = i;
            prev_rank_as_idx[i] = node;
        }
        int M; cin >> M;
        pair<int,int> change[M];
        for(int i = 0; i < M; i++){
            int u,v; cin >> u >> v;
            u--; v--;
            if(prev_node_as_idx[u] > prev_node_as_idx[v]){
                change[i] = make_pair(v,u);
            }else{
                change[i] = make_pair(u,v);
            }
        }
        sort(change ,change+M,cmp);
        vector<int> adj[N];
        int in[N];
        fill(in, in + N, 0);
        int idx = 0;
        for(int i = 0; i < N;i++){
            int node = prev_rank_as_idx[i];
            for(int j = i+1;j < N;j++){
                if(idx < M && change[idx].first == node && change[idx].second == prev_rank_as_idx[j]){
                    adj[prev_rank_as_idx[j]].push_back(node);
                    in[node]++;
                    idx++;
                }else{
                    adj[node].push_back(prev_rank_as_idx[j]);
                    in[prev_rank_as_idx[j]]++;
                }
            }
        }
        stack<int> s;
        vector<int> vec;
        for(int i = 0;i<N;i++){
            if(in[i]== 0) s.push(i);
        }
        int ret = DFS(&vec, N, &s, in, adj);
        if(ret==-1){
            cout << "IMPOSSIBLE\n";
        }else{
            for(int i = 0 ;i<vec.size();i++){
                cout << vec[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}