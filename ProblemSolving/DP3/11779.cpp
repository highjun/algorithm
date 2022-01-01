#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void dijkstra(int* dist, vector<pair<int,int>> * adj, int n_city, int start){
    fill(dist, dist+n_city, INT32_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.emplace(0, start);
    dist[start]  =0;
    while(!q.empty()){
        pair<int,int> pop = q.top();
        q.pop();
        for(int i = 0; i<adj[pop.second].size();i++){
            pair<int,int> adj_ = adj[pop.second][i];
            if(dist[adj_.first] == INT32_MAX || dist[adj_.first] > pop.first + adj_.second){
                q.emplace(pop.first+ adj_.second, adj_.first);
                dist[adj_.first] =  pop.first+ adj_.second;
            }
        }
    }
}

int main(){
    int n_city, n_bus;
    cin >> n_city >> n_bus;
    vector<pair<int,int>> adj[n_city];
    vector<pair<int,int>> inverse_adj[n_city];
    while(n_bus--){
        int src,dest ,weight;
        cin >> src >> dest >> weight;
        adj[src-1].push_back(make_pair(dest-1, weight));
        inverse_adj[dest-1].push_back(make_pair(src-1, weight));
    }
    int src, dest;
    cin >> src >> dest;
    int dist[n_city];
    dijkstra(dist,adj, n_city, src-1);
    // for(int i = 0;i<n_city;i++){
    //     cout << dist[i] << " ";
    // }
    // cout<< "\n";
    cout << dist[dest-1] << "\n";
    int tmp = dist[dest-1];
    stack<int> s;
    s.push(dest-1);
    while(tmp!=0){
        int top = s.top();
        for(int i = 0; i< inverse_adj[top].size(); i++){
            pair<int,int> adj_ = inverse_adj[top][i];
            if(dist[adj_.first] != INT32_MAX && tmp == adj_.second + dist[adj_.first]){
                s.push(adj_.first);
                tmp = dist[adj_.first];
                break;
            }
        }
    }
    cout << s.size() << "\n";
    while(!s.empty()){
        cout << s.top()+1 << " ";
        s.pop();
    }
    cout <<"\n";

    return 0;
}