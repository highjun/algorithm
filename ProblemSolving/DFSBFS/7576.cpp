#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

int check[1000][1000];
int M;

struct compare{
    bool operator()(int a, int b){
        int i1 = a/M, j1 = a%M;
        int i2 = b/M, j2 = b%M;
        return check[i1][j1] > check[i2][j2]; 
    }
};

int main(){
    int N;
    cin >> M >> N;
    int x[N][M];
    memset(check, -1, 1000*1000*sizeof(int));
    priority_queue<int, vector<int>, compare> bfs;
    for(int i = 0;i<N;i++){
        for(int j =0;j<M;j++){
            cin >> x[i][j];
            if(x[i][j] == 1){
                bfs.push(i*M + j);
                check[i][j] = 0;
            }
        }
    }
    // for(int i = 0;i<N;i++){
    //     for(int j =0;j<M;j++){
    //         cout << x[i][j];
    //     }
    //     cout <<"\n";
    // }
    while(!bfs.empty()){
        int node = bfs.top();
        // cout << node << "\n";
        bfs.pop();
        int a = node/M, b= node%M;
        int tmp = check[a][b];
        if(0<= a && a<N-1 && 0<=b && b<M){
            if(x[a+1][b] >-1 && check[a+1][b]== -1){
                check[a+1][b] = tmp+1;
                bfs.push((a+1)*M+b);
            }
        }
        if(0< a && a<N && 0<=b && b<M){
            if(x[a-1][b] >-1 && check[a-1][b]==-1){
                check[a-1][b] = tmp+1;
                bfs.push((a-1)*M+b);
            }
        }
        if(0<= a && a<N && 0<=b && b<M-1){
            if(x[a][b+1]>-1 && check[a][b+1]==-1){
                check[a][b+1] = tmp+1;
                bfs.push(a*M+b+1);
            }
        }
        if(0<= a && a<N && 0<b && b<M){
            if(x[a][b-1]>-1 && check[a][b-1]==-1){
                check[a][b-1] = tmp+1;
                bfs.push(a*M+b-1);
            }
        }
    }
    // cout << "--------\n"; 
    // for(int i = 0;i<N;i++){
    //     for(int j =0;j<M;j++){
    //         cout << check[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }


    int max_ = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(x[i][j]!= -1){
                // cout << i <<" " <<j << "\n";
                if(check[i][j] == -1){
                    max_ = -1;
                    break;
                }else{
                    max_ = max(check[i][j], max_);
                }
            }
        }
        if(max_ == -1){
            break;
        }
    }
    cout << max_ <<"\n";

    return 0;
}