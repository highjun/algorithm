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