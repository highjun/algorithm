#include<iostream>
#include<memory.h>
using namespace std;

int cache[500][500];
void calMulCost(int x[][2], int start, int end){
    if(cache[start][end]== -1){
        if(start == end){
            cache[start][end] = 0;
        }else{
            int min_ = -1;
            for(int i=start;i<end; i++){
                calMulCost(x,start, i);
                calMulCost(x, i+1, end);
                int cost = cache[start][i] + cache[i+1][end];
                cost += x[start][0] * x[i][1] * x[end][1];
                if(min_ == -1) min_ = cost;
                min_ = min(cost, min_);
            }
            if(min_ == -1) min_ = 0;
            cache[start][end] = min_;
        }
    }
}

int main(){
    int N;
    cin >> N;
    int x[N][2];
    memset(cache, -1, 500*500*sizeof(int));
    for(int i= 0 ;i<N;i++)
    {
        cin >> x[i][0] >> x[i][1];  
    }
    calMulCost(x,0, N-1);
    // for(int i = 0; i<N;i++){
    //     cout << "(" << x[i][0] << " ," << x[i][1] << ")"<< endl;
    // }
    // for(int i = 0; i<N;i++){
    //     for(int j=i; j<N;j++){
    //         cout << "(" << i << " ," << j << "): " << cache[i][j]<< endl;
    //     }
    // }
    cout << cache[0][N-1] << endl;
    return 0;
}