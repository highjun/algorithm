#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        int H,W,K;
        cin >> H >> W >> K;
        bool loc[H][W];
        memset(loc, 0, H*W*sizeof(bool));
        for(int j = 0;j<K;j++){
            int a,b;
            cin >> a >> b;
            loc[a][b] = true;
        }
        queue<int> bfs;
        bool check[H][W];
        memset(check, 0, H*W*sizeof(bool));
        int cnt = 0;
        for(int u = 0;u<H;u++){
            for(int v= 0;v<W;v++){
                if(loc[u][v] && !check[u][v]){
                    bfs.push(u*W+v);
                    check[u][v] = true;
                    cnt++;
                    while(!bfs.empty()){
                        int node = bfs.front();
                        int a = node/W, b= node%W;
                        if(0<= a && a<H-1 && 0<=b && b<W){
                            if(loc[a+1][b] && !check[a+1][b]){
                                check[a+1][b] = true;
                                bfs.push((a+1)*W+b);
                            }
                        }
                        if(0< a && a<H && 0<=b && b<W){
                            if(loc[a-1][b] && !check[a-1][b]){
                                check[a-1][b] = true;
                                bfs.push((a-1)*W+b);
                            }
                        }
                        if(0<= a && a<H && 0<=b && b<W-1){
                            if(loc[a][b+1] && !check[a][b+1]){
                                check[a][b+1] = true;
                                bfs.push(a*W+b+1);
                            }
                        }
                        if(0<= a && a<H && 0<b && b<W){
                            if(loc[a][b-1] && !check[a][b-1]){
                                check[a][b-1] = true;
                                bfs.push(a*W+b-1);
                            }
                        }
                        bfs.pop();
                    }
                }
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}