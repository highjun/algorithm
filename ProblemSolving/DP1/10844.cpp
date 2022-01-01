#include<iostream>
#include<memory.h>

using namespace std;

long long cache[10];

int main(){
    int N;
    cin >> N;
    for(int i=0;i<10;i++){
        cache[i] = 1;
    }
    for(int k=0; k<N-1; k++){
        long long tmp[10];
        for(int i = 0 ; i< 10; i++){
            if(i == 0){
                tmp[0] = cache[1]; 
            }else if(i == 9){
                tmp[9] = cache[8];
            }else{
                tmp[i] = (cache[(i+1)] + cache[(i-1)])%1000000000;
            }
        }
        for(int i = 0 ; i< 10; i++){
           cache[i] = tmp[i];
        }
    }
    long long result = 0;
    for(int i=1;i<10;i++){
        result = (result + cache[i])%1000000000;
    }
    cout << result <<endl;
    return 0;
}