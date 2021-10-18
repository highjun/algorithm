#include<iostream>
#include<memory.h>
using namespace std;

int cache[500][500];
void calMergeCost(int x[], int start, int end){
    if(cache[start][end]== -1){
        if(start == end){
            cache[start][end] = 0;
        }else{
            int min_ = -1;
            for(int i=start;i<end; i++){
                calMergeCost(x,start, i);
                calMergeCost(x, i+1, end);
                if(min_ == -1) min_ = cache[start][i] + cache[i+1][end];
                min_ = min(cache[start][i]+ cache[i+1][end], min_);
            }
            if(min_ == -1) min_ = 0;
            for(int i =start;i<=end; i++){
                min_ += x[i];
            }
            cache[start][end] = min_;
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        int x[N];
        // [start, end]까지를 고를 경우
        // top-down
        memset(cache, -1, 500*500*sizeof(int));
        for(int i = 0; i<N;i++){
            cin >> x[i];
        }
        calMergeCost(x,0, N-1);      
        // for(int i = 0; i<N;i++){
        //     for(int j=i; j<N;j++){
        //         cout << "(" << i << " ," << j << "): " << cache[i][j]<< endl;
        //     }
        // }
        cout << cache[0][N-1] << endl;  
    }
    return 0;
}