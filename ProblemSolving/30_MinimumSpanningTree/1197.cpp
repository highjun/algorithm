#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

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

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int V,E;
    cin >> V >> E;
    vector<tuple<int,int, int>> e;
    while(E--){
        int u, v, w;
        cin >> u >>v >> w;
        e.emplace_back(u-1, v-1, w);
    }
    sort(e.begin(), e.end(), compare);
    int parent[V];
    int rank[V];
    fill(rank, rank+V, 0);
    for(int i = 0;i<V;i++) parent[i] = i;
    int total_weight = 0;
    for(int i = 0;i<e.size();i++){
        int a,b,w;
        tie(a,b, w) = e[i];
        if(find(a,parent) == find(b,parent)) continue;
        total_weight += w;
        union_(a,b, parent, rank);
    }
    cout << total_weight <<"\n";
    return 0;
}