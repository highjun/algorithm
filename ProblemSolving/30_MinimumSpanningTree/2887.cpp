#include<iostream>
#include<vector>
#include<tuple>
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

int calDist(tuple<int,int,int,int> a , tuple<int,int,int,int> b){
    int dist = abs(get<3>(a)- get<3>(b));
    dist = min(dist, abs(get<1>(a)-get<1>(b)));
    dist = min(dist, abs(get<2>(a)-get<2>(b)));
    return dist;
}

bool cmpX(tuple<int,int,int,int> a , tuple<int,int,int,int> b){
    return get<1>(a) < get<1>(b);
}
bool cmpY(tuple<int,int,int,int> a , tuple<int,int,int,int> b){
    return get<2>(a) < get<2>(b);
}
bool cmpZ(tuple<int,int,int,int> a , tuple<int,int,int,int> b){
    return get<3>(a) < get<3>(b);
}
//Kruskal 알고리즘
//x좌표 ,y좌표, z좌표로 정렬시 인접한 행성만 고려하면 충분
int main(){
    int N;
    cin >> N;
    vector<tuple<int,int,int,int>> vec;
    for(int i= 0 ;i<N;i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec.emplace_back(i, u,v,w);
    }
    vector<tuple<int,int,int>> edge;
    //x 축 정렬
    sort(vec.begin(), vec.end(), cmpX);
    for(int i = 0; i<N-1;i++){
        // cout << get<0>(vec[i]) << " ";
        edge.emplace_back(calDist(vec[i],vec[i+1]), get<0>(vec[i]),get<0>(vec[i+1]));
    }
    // cout <<"\n";
    sort(vec.begin(), vec.end(), cmpY);
    for(int i = 0; i<N-1;i++){
        // cout << get<0>(vec[i]) << " ";
        edge.emplace_back(calDist(vec[i],vec[i+1]), get<0>(vec[i]),get<0>(vec[i+1]));
    }
    // cout <<"\n";
    sort(vec.begin(), vec.end(), cmpZ);
    for(int i = 0; i<N-1;i++){
        // cout << get<0>(vec[i]) << " ";
        edge.emplace_back(calDist(vec[i],vec[i+1]), get<0>(vec[i]),get<0>(vec[i+1]));
    }
    // cout <<"\n";
    int parent[N];
    for(int i = 0;i<N;i++) parent[i] = i;
    int rank[N];
    fill(rank, rank+N, 0);
    long long cost = 0;
    sort(edge.begin(), edge.end());
    for(int idx = 0; idx<edge.size();idx++){
        int weight;
        int u,v;
        tie(weight, u, v)= edge[idx];
        // cout << weight <<","<< u <<"," << v << "\n";
        if(find(u,parent) == find(v,parent)) continue;
        cost += weight;
        // cout << weight <<","<< u <<"," << v << "\n";
        union_(u,v,parent, rank);
    }
    cout << cost << "\n";
    return 0;
}