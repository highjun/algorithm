#include<iostream>
#include<cmath>

using namespace std;

//1 -> 6 -> 12 순으로 가는 것을 고려하면 충분한다. 
//6*k(k-1)/2+1<N<=6*k(k+1)/2+1이면 k+1로 간다.
//k(k-1)< (N-1)/3 <= k(k+1)
int main(){
    double N;
    cin >> N;
    N = (N-1)/3;
    int k = (int) sqrt(N);//k or k-1
    if(k*(k+1) < N) k++;
    cout << k+1 <<"\n";
    return 0;
}