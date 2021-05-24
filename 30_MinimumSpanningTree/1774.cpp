#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>
#include<float.h>

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

double calDist(pair<double,double> a, pair<double,double> b){
    return sqrt(pow((a.first-b.first),2) + pow((a.second-b.second), 2));
}

//Kruskal 알고리즘
//기존의 경로를 union find하기 위해서 사용
int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<double,double>> vec;
    for(int i= 0 ;i<N;i++){
        double u,v;
        cin >> u >> v;
        vec.emplace_back(u,v);
    }
    vector<tuple<double,int,int>> edge;
    for(int i = 0; i<N;i++){
        for(int j = i+1;j<N;j++){
            edge.emplace_back(calDist(vec[i],vec[j]), i,j);
        }
    }
    int parent[N];
    for(int i = 0;i<N;i++) parent[i] = i;
    int rank[N];
    fill(rank, rank+N, 0);
    for(int i =0;i<M;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        union_(u,v,parent, rank);
    }
    sort(edge.begin(), edge.end());
    double cost = 0;
    for(int idx = 0; idx<edge.size();idx++){
        double weight;
        int u,v;
        tie(weight, u, v)= edge[idx];
        if(find(u,parent) == find(v,parent)) continue;
        cost += weight;
        union_(u,v,parent, rank);
    }
    cout << fixed;
    cout.precision(2);
    cout << cost << "\n";
    return 0;
}