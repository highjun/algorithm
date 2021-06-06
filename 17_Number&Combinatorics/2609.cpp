#include<iostream>
#include<algorithm>

using namespace std;

//x >= y로 주어질 경우만 허용
int gcd(int x, int y){
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}

//gcd *lcm = N*M으로
//gcd를 유클리드 호제법으로 구하면 충분
int main(){
    int N,M;
    cin >> N >> M;
    int g = gcd(N,M);
    cout << g <<"\n" << N*M/g << "\n";
    return 0;
}