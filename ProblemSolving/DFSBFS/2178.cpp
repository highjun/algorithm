#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    bool x[N][M];
    for(int i = 0;i<N;i++){
        string tmp;
        cin >> tmp;
        for(int j =0;j<M;j++){
            x[i][j] = tmp[j] - '0';
        }
    }
    int check[N][M];
    memset(check, -1, N*M*sizeof(int));
    queue<int> bfs;
    bfs.push(0);
    check[0][0] = 1;
    while(!bfs.empty()){
        int node = bfs.front();
        int a = node/M, b= node%M;
        int tmp = check[a][b];
        if(0<= a && a<N-1 && 0<=b && b<M){
            if(x[a+1][b] && check[a+1][b]== -1){
                check[a+1][b] = tmp+1;
                bfs.push((a+1)*M+b);
            }
        }
        if(0< a && a<N && 0<=b && b<M){
            if(x[a-1][b] && check[a-1][b]==-1){
                check[a-1][b] = tmp+1;
                bfs.push((a-1)*M+b);
            }
        }
        if(0<= a && a<N && 0<=b && b<M-1){
            if(x[a][b+1] && check[a][b+1]==-1){
                check[a][b+1] = tmp+1;
                bfs.push(a*M+b+1);
            }
        }
        if(0<= a && a<N && 0<b && b<M){
            if(x[a][b-1] && check[a][b-1]==-1){
                check[a][b-1] = tmp+1;
                bfs.push(a*M+b-1);
            }
        }
        bfs.pop();
    }
    cout << check[N-1][M-1] << "\n";

    return 0;
}