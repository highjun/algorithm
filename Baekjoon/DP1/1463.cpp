#include<iostream>
#include<memory.h>

using namespace std;

int cache[1000000];

void cntOperation(int n){
    if(n == 1 & cache[0] == -1){
        cache[0] = 0;
    }else{
        if(cache[n-1] == -1){
            int tmp = -1;
            if(n%3 == 0){
                cntOperation(n/3);
                tmp = cache[n/3-1]+1;
            }
            if(n%2==0){
                cntOperation(n/2);
                if(tmp == -1){
                    tmp = cache[n/2-1] + 1;
                }else{
                    tmp = min(tmp, cache[n/2-1] + 1);
                }
            }
            if(1){
                cntOperation(n-1);
                if(tmp == -1){
                    tmp = cache[n-2] + 1;
                }else{
                    tmp = min(tmp, cache[n-2] + 1);
                }
            }
            cache[n-1] = tmp;
        }
    }
}

int main(){
    memset(cache, -1, sizeof(int)* 1000000);
    int N;
    cin >> N;
    cntOperation(N);
    // for(int i =0 ; i< N; i++){
    //     cout << cache[i] << " ";
    // }
    // cout <<endl;
    cout << cache[N-1] << endl;
    return 0;
}