#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;

int check[100][100][100];
int loc[100][100][100];
int M,N,H;

struct compare{
    bool operator()(int node1, int node2){
        int i1= node1/(N*M) , j1 = (node1/M)%N, k1 = node1%M;
        int i2= node2/(N*M) , j2 = (node2/M)%N, k2 = node2%M;

        return check[i1][j1][k1] > check[i2][j2][k2];
    }
};

bool isNotVisit(int x, int y, int z){
    return x>=0 && x<H && y<N && y>=0 && z<M && z>=0 && check[x][y][z] == -1 && loc[x][y][z]!= -1;
}

priority_queue<int, vector<int> ,compare> bfs;

void pushNotVisit(int x, int y, int z, int tmp){
    if(isNotVisit(x,y,z)){
        check[x][y][z] = tmp+1;
        bfs.push(z + y*M + x*N*M);
    }
}

int main(){
    cin >> M >> N >> H;
    memset(check, -1, 100*100*100*sizeof(int));
    for(int i = 0;i<H;i++){
        for(int j = 0; j<N;j++){
            for(int k = 0; k<M; k++){
                cin >> loc[i][j][k];
                if(loc[i][j][k] == 1){
                    bfs.push(k + j*M + i*N*M);
                    check[i][j][k] = 0;
                }
            }
        }
    }
    while(!bfs.empty()){
        int node = bfs.top();
        bfs.pop();
        int i= node/(N*M) , j = (node/M)%N, k = node%M;
        int tmp = check[i][j][k];
        pushNotVisit(i+1, j, k,tmp);
        pushNotVisit(i-1,j,k,tmp);
        pushNotVisit(i, j-1, k,tmp);
        pushNotVisit(i,j+1,k,tmp);
        pushNotVisit(i, j, k-1,tmp);
        pushNotVisit(i,j,k+1,tmp);
    }
    
    int max_ = 0;
    for(int i = 0;i<H;i++){
        for(int j = 0; j<N;j++){
            for(int k = 0; k<M; k++){
                if(loc[i][j][k] != -1){
                    if(check[i][j][k]== -1){
                        cout << -1 <<"\n";
                        return 0;
                    }
                    max_ = max(check[i][j][k], max_);
                }
                // cout << check[i][j][k] << " ";
            }
            // cout << "\n";
        }
    }
    cout << max_ <<"\n";
    return 0;
}