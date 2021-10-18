#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
// #include<assert.h>

using namespace std;

int MAX = 200000;
int check[200000];

struct compare{
    bool operator()(int node1, int node2){
        return check[node1] > check[node2];
    }
};

int main(){
    int N,K;
    cin >> N >> K;
    priority_queue<int, vector<int>, compare> bfs;
    memset(check, -1, MAX*sizeof(int));
    bfs.push(N);
    check[N] = 0;
    while(!bfs.empty()){
        int node = bfs.top();
        // assert(node < MAX && node >=0);
        // cout << node << ": " << check[node] << "\n";
        bfs.pop();
        if(node > 0 && check[node-1] == -1){
            check[node-1] = check[node]+1;
            if(node-1 == K) break;
            bfs.push(node-1);
        }
        if(node+1<MAX &&check[node+1] == -1 ){
            check[node+1] = check[node]+1;
            if(node == K) break;
            bfs.push(node+1);
        }
        if(node*2 < MAX &&check[2*node]== -1 ){
            check[2*node] = check[node]+1;
            if(node*2 == K) break;
            bfs.push(2*node);
        }
    }
    cout << check[K] << "\n";

    return 0;
}