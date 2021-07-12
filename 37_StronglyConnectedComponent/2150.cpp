#include<iostream>
#include<vector>
#include<stack>
// #include<algorithm>
// #include<queue>

using namespace std;

//return the number of idx, which is visited number of node.
int SCC(vector<int> * adj, int node,stack<int> *s, int* index,int* scc, int idx){
    idx++;
    s->push(node);
    index[node] = scc[node] = idx;
    // cout << node +1 << " visited at " << idx << "\n";
    for(int i = 0; i<adj[node].size();i++){
        int next = adj[node][i];
        if(index[next] == -1){//첫 방문하는 경우
            idx = SCC(adj, next, s, index, scc, idx);
            scc[node] = min(scc[node],scc[next]);
        }else if(index[next] > 0){//stack에 있는 경우
            scc[node] = min(scc[node], index[next]);
        }
    }
    if(index[node] == scc[node]){
        int pop;
        while((pop = s->top())!= node){
            index[pop] = 0;
            scc[pop] = index[node];
            s->pop();
            // cout << "processing " << node+1 << " , "<< pop+1 << " popped as " << scc[pop] << "\n";
        }
        s->pop();
        index[node] = 0;
        // cout << "processing " << node+1 << " , "<< pop+1 << " popped as " << scc[pop] << "\n";
    }
    // cout << "scc of " << node+1 << " is " << scc[node] << "\n"; 
    return idx;
}

//Tarjan 알고리즘
//DFS를 통해서 방문한 순서를 기록하고, 방문한 순서로 
//각각의 노드가 최대한 앞으로 갈 수 있는 곳을 적어놓는다.
//자기보다 앞으로 갈 수 없는 노드는 결국 그 자체로 SCC가 된다. 
int main(){
    int V,E;
    cin >> V >> E;
    vector<int> adj[V];
    int index[V];// 방문한 번째수
    fill(index,index+V, -1);
    int scc[V];//scc id
    for(int i = 0; i<E;i++){
        int src ,dest;
        cin >> src >> dest;
        src--; dest--;
        adj[src].emplace_back(dest);
        // cout << src+1 <<" " << dest+1 << "\n" ;
    }
    int idx = 0;
    stack<int> s;
    for(int i = 0; i <V;i++){
        if(index[i] == -1){
            idx = SCC(adj, i,&s, index, scc, idx);
        }
    }
    vector<int> scc_arr[V];
    int cnt[V]; fill(cnt, cnt+V,0);
    vector<int> scc_ids;
    for(int i = 0;i< V;i++){
        cnt[scc[i]-1]++;
        if(cnt[scc[i]-1] == 1){ 
            scc_ids.emplace_back(scc[i]-1);
        }
        scc_arr[scc[i]-1].emplace_back(i+1);
    }
    cout << scc_ids.size() << "\n";
    for(int scc_id: scc_ids){
        for(int node: scc_arr[scc_id]){
            cout << node << " "; 
        }
        cout << "-1\n";
    }
    return 0;
}