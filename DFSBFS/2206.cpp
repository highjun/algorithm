#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

int check[2][1000][1000];
int M,N;

// struct Coord{
//     int x;
//     int y;
//     int k; //뿌순 벽의 개수
// }

struct compare{
    bool operator()(int node1, int node2){
        int k1 = node1/(N*M), i1= (node1/N)%M, j1 = node1%N;
        int k2 = node2/(N*M), i2= (node2/N)%M, j2 = node2%N;
        return check[k1][i1][j1] > check[k2][i2][j2];
    }
};


int main(){
    cin >> M >> N;
    int x[M][N];
    for(int i=0;i<M;i++){
        string tmp;
        cin >> tmp;
        for(int j = 0;j<N;j++){
            x[i][j] = tmp[j]- '0';
        }
    }

    // for(int i=0;i<M;i++){
    //     for(int j = 0;j<N;j++){
    //         cout << x[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }

    priority_queue<int, vector<int>, compare> bfs;
    memset(check, -1, 1000*1000*2*sizeof(int));

    bfs.push(0);
    check[0][0][0]= 1;
    while(!bfs.empty()){
        int node = bfs.top();
        bfs.pop();
        // cout << node <<" \n";
        int k = node/(N*M), i= (node/N)%M, j = node%N;
        // cout << k <<" " << i << " " << j << "\n";
        int tmp= check[k][i][j];
        if(i>0){
            if(x[i-1][j]== 1 && k == 0 && check[1][i-1][j]== -1){
                check[1][i-1][j] = tmp+1;
                bfs.push(j+(i-1)*N+N*M);
            }
            if(x[i-1][j]== 0 && check[k][i-1][j]== -1){
                check[k][i-1][j] = tmp+1;
                bfs.push(j+(i-1)*N+k*N*M);
            }
        }
        if(j>0){
            if(x[i][j-1]== 1 && k == 0 && check[1][i][j-1]== -1){
                check[1][i][j-1] = tmp+1;
                bfs.push(j-1+(i)*N+N*M);
            }
            if(x[i][j-1]== 0 && check[k][i][j-1]== -1){
                check[k][i][j-1] = tmp+1;
                bfs.push(j-1+(i)*N+k*N*M);
            }
        }
        if(i<M-1){
            if(x[i+1][j]== 1 && k == 0 && check[1][i+1][j]== -1){

                check[1][i+1][j] = tmp+1;
                bfs.push(j+(i+1)*N+N*M);
            }
            if(x[i+1][j]== 0 && check[k][i+1][j]== -1){
                check[k][i+1][j] = tmp+1;
                bfs.push(j+(i+1)*N+k*N*M);
            }
        }
        if(j<N-1){
            if(x[i][j+1]== 1 && k == 0 && check[1][i][j+1]== -1){
                check[1][i][j+1] = tmp+1;
                bfs.push(j+1+(i)*N+N*M);
            }
            if(x[i][j+1]== 0 && check[k][i][j+1]== -1){
                check[k][i][j+1] = tmp+1;
                bfs.push(j+1+(i)*N+k*N*M);
            }
        }
    }
    // cout << "---------\n";
    // for(int i=0;i<M;i++){
    //     for(int j = 0;j<N;j++){
    //         cout << check[0][i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    // cout << "-----\n";
    // for(int i=0;i<M;i++){
    //     for(int j = 0;j<N;j++){
    //         cout << check[1][i][j] << " ";
    //     }
    //     cout <<"\n";
    // }

    int min_;
    if(check[0][M-1][N-1] == -1 && check[1][M-1][N-1] == -1) min_ = -1;
    else if(check[0][M-1][N-1] == -1){
        min_ = check[1][M-1][N-1];
    }else if(check[1][M-1][N-1] == -1){
        min_ = check[0][M-1][N-1];
    }else{
        min_ = min(check[0][M-1][N-1], check[1][M-1][N-1]);
    }
    cout << min_ << "\n";
    
    return 0;
}