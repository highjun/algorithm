#include<iostream>

using namespace std;

long long R = 1000000007;

long long permutation(int N, int K){
    if(K == 0) return 1;
    return (N*permutation(N-1,K-1))%R;
}

long long getPower(int N, int M){
    if(M == 0) return 1;
    long long tmp = getPower(N, M/2);
    tmp = (tmp* tmp)%R;
    if(M%2==1){
        tmp = (tmp*N)%R;
    }
    return tmp;
}

//1000000007이 소수임으로 페르마 소정리로 곱셈의 역원을 계산 가능하다.
int main(){
    long long N, K;
    cin >> N >> K;
    long long result = (permutation(N,K) *getPower(permutation(K,K), R-2))%R;
    cout << result <<"\n";
    return 0;
}