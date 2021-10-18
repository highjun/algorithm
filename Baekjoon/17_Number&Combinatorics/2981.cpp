#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

// x>=y인 경우만
int gcd(int x, int y){
    if(x<y) return gcd(y,x);
    if(y == 0) return x;
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}
void getFactor(int x, int root_x, int i){
    if(i<= root_x){
        if(x%i==0){
            cout << i <<" ";
            getFactor(x, root_x, i+1);
            if(i*i!=x) cout << x/i << " ";
        }else{
            getFactor(x, root_x, i+1);
        }
    }
}
//차들의 gcd를 구하자.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i = 0;i<N;i++) cin >> x[i];
    sort(x, x+N);
    int g = 0;
    for(int i = 1;i<N;i++){
        g = gcd(x[i]-x[i-1], g);
    }
    int k = sqrt(g);
    getFactor(g, k, 2);
    cout << g <<"\n";
    return 0;
}