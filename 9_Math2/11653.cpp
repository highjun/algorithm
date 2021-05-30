#include<iostream>

using namespace std;

//while 문을 통해서 작은 수부터 일일이 나눈다.
//2로 모두 나눴으면 4로는 안 나누어질 것으로 소수만 나올 것
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int idx = 2;
    while(idx <= N){
        if(N%idx == 0){
            N /= idx;
            cout << idx <<"\n";
        }else{
            idx++;
        }
    }
    return 0;
}