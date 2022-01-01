#include<iostream>
#include<memory.h>

using namespace std;

void floyd(int* graph, int n_town){
    int tmp[n_town*n_town];
    for(int k = 0; k<n_town;k++){
        for(int i = 0; i<n_town;i++){
            for(int j = 0;j<n_town;j++){
                tmp[i*n_town + j] = graph[i*n_town+j];
                if(graph[k*n_town + j]!= INT32_MAX && graph[i*n_town + k]!= INT32_MAX){
                    tmp[i*n_town+j] = min(tmp[i*n_town + j], graph[i*n_town+k]+graph[k*n_town+j]);
                }
            } 
        }
        memcpy(graph, tmp, sizeof(int)*n_town*n_town);
    }
}

int main(){
    int n_town, n_road;
    cin >> n_town >> n_road;
    int graph[n_town*n_town];
    fill(graph, graph+n_town*n_town, INT32_MAX);
    while(n_road--){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[(src-1)*n_town + dest-1] = weight;
    }
    for(int i = 0; i< n_town;i++){
        graph[i*n_town + i] = INT32_MAX;
    }
    floyd(graph, n_town);
    int min_ = INT32_MAX;
    for(int i = 0;i<n_town;i++){
        min_ = min(graph[i*(n_town+1)], min_); 
    }
    if(min_ != INT32_MAX){
        cout << min_ <<"\n";
    }else{
        cout << -1 << "\n";
    }
    return 0;
}