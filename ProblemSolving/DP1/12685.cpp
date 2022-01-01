#include<iostream>
#include<memory.h>
using namespace std;


int main(){
    int N,K;
    cin >> N >>K;
    int x[N][2];
    for(int i = 0; i<N;i++){
        cin >>x[i][0] >> x[i][1];
    }
    int cache[N][K+1];
    memset(cache,0, N*(K+1)*sizeof(int));
    // cache[i][k]는 앞의 i+1개의 보석과 제한이 k일 때의 무게이다.
    for(int i= 0;i<N; i++){
        for(int k=0 ; k<K+1; k++){
            if(i==0){
                cache[0][k] = x[0][0]>k? 0 :x[0][1];
                continue;
            }
            if(x[i][0]> k){
                cache[i][k] = cache[i-1][k];
            }else{
                cache[i][k] = max(cache[i-1][k-x[i][0]]+ x[i][1], cache[i-1][k]);
            }
        }
    }
    cout << cache[N-1][K] << endl;
    return 0;
}