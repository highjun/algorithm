#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;

long long calNum(long long N, long long k){
    long long cnt = 0;
    for(long long i = 1;i<= N; i++){
        cnt += min(k/i , N); 
    }
    return cnt;
}

//이진 탐색을 통해서 calNum(N, ans) >= K이고,  
//calNum(N, ans-1) <K 인 ans를 찾는다.
int main(){
    long long N, K;
    cin >> N >> K;
    long long l=1, r= N*N; 
    long long ret;
    while(l <= r){
        long long center = (l+r)/2;
        if(calNum(N,center) >= K){
            r= center-1;
            ret = center;
        }else{
            l = center + 1;
        }
    }
    cout << ret << endl;
    return 0;
}