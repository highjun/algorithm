#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>

using namespace std;

//node, price ,time
typedef tuple<int,int,int> Int3;
// struct Int3{
//     int node;
//     int price;
//     int time;
// };

struct compare{
    bool operator()(Int3 x, Int3 y){
        return (get<2>(x) > get<2>(y));
    }
};

void dijkstra(int* dist, int V, int M, vector<Int3>* adj, int start){
    fill(dist, dist+V*M, INT32_MAX);
    dist[start*M] = 0;
    priority_queue<Int3, vector<Int3>,compare> q;
    // Int3 push;
    // push.node = 0, push.price = 0, push.time = 0;
    q.emplace(0,0,0);
    while(!q.empty()){
        // cout << "node: " << pop.node << ", price: "<< pop.price << ", time: " << pop.time <<"\n";
        int n, p, t;
        tie(n,p,t) = q.top();
        q.pop();
        int len = adj[n].size();
        if(t > dist[n*M+p]) continue;
        for(int i=0;i<len;i++){
            int nn, np, nt;
            tie(nn,np,nt) = adj[n][i];
            if(p + np < M&& t != INT32_MAX &&
            dist[nn*M+p+np] > t + nt){
                // Int3 push;
                // push.node = next.node, push.price = p+next.price,push.time = t+ next.time;
                // q.emplace(push);
                dist[nn*M+p+np] = t+ nt;
                q.emplace(nn, p+np, t+nt);
            }
        }
    }

}
int main(){
    // ios_base :: sync_with_stdio(false); 
    // cin.tie(NULL); cout.tie(NULL);
    int n_case;
    cin >> n_case;
    while(n_case--){
        int n_airport, total_support, n_line;
        cin >> n_airport >> total_support >> n_line;
        total_support++;
        vector<Int3> adj[n_airport];
        while(n_line--){
            int src, dest, price, time;
            cin >> src >> dest >> price >> time;
            // Int3 insert_;
            // insert_.node = dest-1, insert_.price = price, insert_.time = time;
            adj[src-1].emplace_back(dest-1, price, time);
        }
        int dist[n_airport*total_support];
        dijkstra(dist, n_airport, total_support, adj, 0);
        int min_ = INT32_MAX;
        for(int i = 0;i<total_support; i++){
            min_ = min(dist[(n_airport-1)*total_support + i], min_);
        }
        cout << (min_ == INT32_MAX? "Poor KCM": to_string(min_)) << "\n";
    }
    return 0;
}