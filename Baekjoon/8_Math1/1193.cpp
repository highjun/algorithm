#include<iostream>
#include<cmath>

using namespace std;

//분자, 분모 합이 k+1인 경우 1,2,...,k-1 이후에 나온다.
//k(k-1)/2 < x < (k+1)k/2인 경우
//k(k-1) < 2*x < (k+1)k
int main(){
    double N;
    cin >> N;
    int k = (int) sqrt(N*2);//k or k-1
    if(k*(k+1) < N*2) k++;
    int idx = (int) N - k*(k-1)/2;
    if(k%2 ==1){
        cout << (k+1-idx) <<"/" << idx <<"\n";
    }else{
        cout << idx << "/" << (k+1-idx) <<"\n";
    }
    return 0;
}