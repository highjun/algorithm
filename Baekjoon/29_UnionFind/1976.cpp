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
    int N,M;
    cin >> N >> M;
    int root[N];
    int rank[N];
    for(int i =0;i<N;i++) root[i] = i;
    fill(rank, rank+N, 0);
    for(int i = 0; i<N*N;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            union_(i/N, i%N, root, rank);
        }
    }
    int next;
    int root_=-1;
    while(M--){
        cin >> next;
        next--;
        if(root_ == -1)
            root_ = find(next, root);
        else{
            if(root_ != find(next,root)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0; 
}