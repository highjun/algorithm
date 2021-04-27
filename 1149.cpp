#include<iostream>
using namespace std;

//RGB 각각으로 마지막 집을 칠할때의 최소비용
int cache[1000][3];
void colorLast(int n, int r , int g, int b){
    if(n == 0){
        cache[0][0] = r;
        cache[0][1] = g;
        cache[0][2] = b;
    }else{
        cache[n][0] = min(cache[n-1][1], cache[n-1][2]) +r;
        cache[n][1] = min(cache[n-1][2], cache[n-1][0]) +g;
        cache[n][2] = min(cache[n-1][0], cache[n-1][1]) +b;
    }
}
int main(){
    int N;
    cin >> N;
    for(int i =0 ; i<N; i++){
        int r,g,b;
        cin >> r >> g >> b;
        colorLast(i, r, g, b);
    }
    int result = min(cache[N-1][0], cache[N-1][1]);
    result = min(result, cache[N-1][2]);
    cout << result << endl;
}