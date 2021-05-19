#include<iostream>

using namespace std;

//find root
int find(int x, int* parent){
    if(parent[x] == x){
        return x;
    }else{
        //path compression
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
}
void union_(int x, int y, int* parent, int* rank){
    int x_root = find(x, parent);
    int y_root = find(y, parent);
    if(x_root == y_root) return;
    // union-by-rank 알고리즘
    if(rank[x_root] < rank[y_root]){
        parent[x_root] = y_root;
    }else{
        parent[y_root] = x_root;
        if(rank[x_root] == rank[y_root]){
            rank[x_root]++;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    cin >> n >>m;
    int x[n+1];//root node 혹은 parent를 저장
    int rank[n+1];
    fill(rank, rank+n+1, 0);
    for(int i = 0;i<n+1; i++) x[i] = i;
    while(m--){
        int cmd, a,b;
        cin >> cmd >> a >> b;
        if(cmd == 0){
            union_(a,b, x, rank);
        }else{
            cout << (find(a,x) == find(b,x)? "YES" :"NO") <<"\n";
        }
        // cout << cmd << a<< b <<"\n";
        // for(int i = 0;i<n+1;i++){
        //     cout << x[i] << " ";
        // }
        // cout <<"\n";
    }
    return 0;
}