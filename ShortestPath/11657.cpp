#include<iostream>
#include<vector>
#include<memory.h>

using namespace std; 

struct Int3{
    int src;
    int dest;
    int weight;
};

struct Int2{
    int node;
    int dist;
};

bool compare(Int2 x1, Int2 x2){
    return x1.dist < x2.dist;
}

int main(){
    int n_city,n_line;
    cin >> n_city >> n_line;
    vector<Int3> graph;
    long long dist[n_city];
    fill(dist+1, dist+n_city, INT32_MAX);
    dist[0] =0;
    while(n_line--){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        Int3 insert_;
        insert_.src = node1-1, insert_.dest = node2-1, insert_.weight = weight;
        graph.push_back(insert_);
    }
    for(int i=0;i<n_city;i++){
        int len = graph.size();
        for(int j = 0;j<len; j++){
            Int3 e = graph[j];
            if(dist[e.src] != INT32_MAX &&dist[e.dest] > dist[e.src] + e.weight){
                dist[e.dest] = dist[e.src] + e.weight; 
            }
        }
    }
    int len = graph.size();
    for(int j = 0;j<len; j++){
        Int3 e = graph[j];
        if(dist[e.src] != INT32_MAX && dist[e.dest] > dist[e.src] + e.weight){
            cout << -1 <<"\n"; //음수 사이클의 존재
            return 0;
        }
    }
    for(int j = 1;j<n_city; j++){
        cout << (dist[j] == INT32_MAX? -1: dist[j]) <<"\n"; 
    }
    return 0;
}