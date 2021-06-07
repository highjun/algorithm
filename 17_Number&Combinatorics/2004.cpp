#include<iostream>

using namespace std;

int cntFactor(int N, int m){
    int cnt = 0;
    while(N!=0){
        cnt += N/m;
        N /= m;
    }
    return cnt;
}

//nCm의 0의 개수는 각각의 5의 개수, 각각의 2의개수를 Counting하자.
int main(){
    int N,M;
    cin >> N >> M;
    int cnt5 = cntFactor(N,5) - cntFactor(N-M,5) -cntFactor(M,5);
    int cnt2 = cntFactor(N,2) - cntFactor(N-M,2) -cntFactor(M,2);
    cout << min(cnt5, cnt2) << "\n";
    return 0;
}