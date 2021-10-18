#include<iostream>

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
int union_(int x, int y, int* parent, int* rank){
    x = find(x, parent);
    y = find(y, parent);
    if(x == y) return -1;
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
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int rank[n];
    int parent[n];
    fill(rank, rank+n,0);
    for(int i = 0;i<n;i++) parent[i] = i;
    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x>> y;
        int result = union_(x,y, parent, rank);
        if(result == -1){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}