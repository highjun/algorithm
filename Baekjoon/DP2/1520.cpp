#include<iostream>
#include<memory.h>

using namespace std;
// cache[i][j] = i, j에서 n-1,m-1에 가는 경로의 개수
int cache[500][500];
int height[500][500];

void cntPath(int x, int y, int N, int M){
    if(cache[x][y] == -1){
        if(x == N-1 & y == M-1){
            cache[x][y] = 1;
        }else{
            cache[x][y] = 0;
            if(x>0 && height[x][y] > height[x-1][y]){
                cntPath(x-1, y,N, M);
                cache[x][y] += cache[x-1][y];
            }
            if(y>0 && height[x][y] > height[x][y-1]){
                cntPath(x, y-1, N,M);
                cache[x][y] += cache[x][y-1];
            }
            if(y+1< M && height[x][y] > height[x][y+1]){
                cntPath(x, y+1, N,M);
                cache[x][y] += cache[x][y+1];
            }
            if(x+1 <N && height[x][y] > height[x+1][y]){
                cntPath(x+1, y, N,M);
                cache[x][y] += cache[x+1][y];
            }
        }
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        for (int j = 0; j<M;j++){
            cin >> height[i][j];
        }
    }
    memset(cache, -1, 500*500* sizeof(int));
    cntPath(0, 0, N,M);
    // for(int i = 0; i<N; i++){
    //     for (int j = 0; j<M;j++){
    //         cout << cache[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << cache[0][0] << endl; 
}