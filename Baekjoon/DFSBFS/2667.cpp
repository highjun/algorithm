#include<iostream>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int x[N][N];
    for(int i = 0 ; i<N;i++){
        string tmp;
        cin >> tmp;
        for(int j = 0;j<N;j++){
            x[i][j] = tmp[j] - '0';
        }
    }
    // for(int i = 0 ; i<N;i++){
    //     for(int j = 0;j<N;j++){
    //         cout << x[i][j];
    //     }
    //     cout <<"\n";
    // }
    queue<int> bfs;
    bool check[N][N];
    memset(check, 0 ,N*N*sizeof(bool));
    // for(int i =0;i<N;i++){
    //     for(int j =0;j<N;j++){
    //         cout <<(check[i][j]?1:0);
    //     }
    //     cout<<"\n";
    // }
    // cout <<"-------"<<"\n";
    vector<int> result;
    for(int i = 0; i<N;i++){
        for(int j = 0;j<N;j++){
            if(x[i][j] == 1&&!check[i][j]){
                bfs.push(i*N+j);
                check[i][j] = true;
                int cnt =1;
                while(!bfs.empty()){
                    int node = bfs.front();
                    int a = node/N, b= node%N;
                    if(0<= a && a<N-1 && 0<=b && b<N){
                        if(x[a+1][b] == 1 && !check[a+1][b]){
                            check[a+1][b] = true;
                            cnt++;
                            bfs.push((a+1)*N+b);
                        }
                    }
                    if(0< a && a<N && 0<=b && b<N){
                        if(x[a-1][b] == 1 && !check[a-1][b]){
                            check[a-1][b] = true;
                            cnt++;
                            bfs.push((a-1)*N+b);
                        }
                    }
                    if(0<= a && a<N && 0<=b && b<N-1){
                        if(x[a][b+1] == 1 && !check[a][b+1]){
                            check[a][b+1] = true;
                            cnt++;
                            bfs.push(a*N+b+1);
                        }
                    }
                    if(0<= a && a<N && 0<b && b<N){
                        if(x[a][b-1] == 1 && !check[a][b-1]){
                            check[a][b-1] = true;
                            cnt++;
                            bfs.push(a*N+b-1);
                        }
                    }
                    bfs.pop();
                }
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << "\n";
    for(int i = 0;i<result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}