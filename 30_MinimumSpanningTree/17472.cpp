#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;


//find root
int find(int x, int* parent){
    if(parent[x] == x){
        return x;
    }else{
        //path compression
        //root로 가는 길에 있는 노드를 root의 child로 올려버린다.
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
}
void union_(int x, int y, int* parent, int* rank){
    x = find(x, parent);
    y = find(y, parent);
    if(x == y) return;
    // union-by-rank 알고리즘
    // rank는 root Node에서만 업데이트된다. 
    if(rank[x] < rank[y]){
        parent[x] = y;
    }else{
        parent[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }
}

int BFS(int * map, int N, int M){
    queue<int> q;
    int n_island = 0;
    for(int idx = 0; idx< N*M;idx++){
        if(map[idx] ==-1){
            n_island++;
            q.push(idx);
            map[idx] = n_island;
            while(!q.empty()){
                int node= q.front();
                int x = node/M, y= node%M;
                q.pop();
                if(x>0 && map[node-M]==-1){
                    q.push(node-M);
                    map[node-M] = n_island; 
                }
                if(x<N-1 && map[node+M]==-1){
                    q.push(node+M);
                    map[node+M] = n_island; 
                }
                if(y>0 && map[node-1]==-1){
                    q.push(node-1);
                    map[node-1] = n_island;
                }
                if(y<M-1 && map[node+1]==-1){
                    q.push(node+1);
                    map[node+1] = n_island;
                }
            }
        }
    }
    return n_island;
}

//1. BFS로 각 섬을 identify해서 각 섬의 땅에 번호를 매긴다.
//각 섬에서 다른 섬으로의 거리를 측정한다.
//Kruskal로 최소합을 계산한다.
int main(){
    int N,M;
    cin >> N >> M;
    int map[N*M];
    for(int i = 0;i<N*M;i++){
        int tmp;
        cin >> tmp;
        map[i] = -tmp;
    }
    int n_island = BFS(map, N, M);
    // check map
    // for(int i =0 ; i<N;i++){
    //     for(int j = 0;j<M;j++){
    //         cout << map[i*M+j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    //다리의 경우, 가로 세로만 가능하므로 그에 따라 측정 가능
    vector<tuple<int,int,int>> edge;
    for(int i = 0; i<N;i++){
        int prev = -1;
        int dist = 0;
        for(int j = 0; j <M;j++){
            dist++;
            if(map[i*M+j]>0){
                dist--;
                if(prev!=-1&& map[i*M+j] != prev && dist >1){
                    edge.emplace_back(dist, map[i*M+j]-1, prev-1);
                }
                prev= map[i*M+j];
                dist = 0;
            }
        }
    }
    for(int j= 0; j<M;j++){
        int prev = -1;
        int dist = 0;
        for(int i = 0; i <N;i++){
            dist++;
            if(map[i*M+j]>0){
                dist--;
                if(prev!=-1&& map[i*M+j] != prev && dist>1){
                    edge.emplace_back(dist,prev-1, map[i*M+j]-1);
                }
                prev= map[i*M+j];
                dist = 0;
            }
        }
    }
    // check edge
    // for(int i = 0; i<edge.size();i++){
    //     int x,y,z;
    //     tie(x,y,z) = edge[i];
    //     cout << x <<" " << y<< " "<< z << "\n";
    // }

    //kruskal
    sort(edge.begin(), edge.end());
    int parent[n_island];
    for(int  i =0;i<n_island;i++) parent[i] = i;
    int rank[n_island];
    fill(rank, rank+n_island , 0);
    int cost = 0;
    int n_edge = 0;
    for(int i = 0; i<edge.size();i++){
        int weight, u,v;
        tie(weight, u, v) = edge[i];
        if(find(u,parent) ==  find(v,parent)) continue;
        cost+= weight;
        n_edge++;
        union_(u,v,parent,rank);
    }
    cout << (n_edge == n_island-1? cost: -1) << "\n";
    return 0;
}