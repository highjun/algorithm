#include<iostream>
#include<vector>
#include<tuple>

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

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;
        vector<pair<int,int>> e;
        while(M--){
            int u, v;
            cin >> u >>v;
            e.emplace_back(u-1, v-1);
        }
        
        int parent[N];
        int rank[N];
        fill(rank, rank+N, 0);
        for(int i = 0;i<N;i++) parent[i] = i;
        int n_edge = 0;
        for(int i = 0;i<e.size();i++){
            int a,b;
            tie(a,b) = e[i];
            if(find(a,parent) == find(b,parent)) continue;
            n_edge++;
            union_(a,b, parent, rank);
        }
        cout << n_edge <<"\n";
    }
    return 0;
}