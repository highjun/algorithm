#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void DFS(int N, stack<int> *s, int* in, vector<int> *adj){
    if(!s->empty()){
        int node = s->top();
        s->pop();
        cout << node+1 <<" ";
        for(int i = 0; i< adj[node].size();i++){
            in[adj[node][i]]--;
            if(in[adj[node][i]] == 0){
                s->push(adj[node][i]);
            }
        }
        DFS(N, s, in, adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<int> adj[N];
    int in[N];
    fill(in ,in+N,0);
    for(int i = 0;i<M;i++){
        int src,dest;
        cin >> src >> dest;
        src--; dest--;
        adj[src].push_back(dest);
        in[dest]++;
    }
    stack<int> s;
    for(int i = 0;i<N;i++){
        if(in[i]== 0) s.push(i);
    }
    DFS(N, &s, in, adj);
    cout << "\n";
    return 0;
}
