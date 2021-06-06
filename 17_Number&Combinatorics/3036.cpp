#include<iostream>

using namespace std;

// x>=y인 경우만
int gcd(int x, int y){
    if(x<y) return gcd(y,x);
    if(y == 0) return x;
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i = 0;i<N;i++) cin >> x[i];
    for(int i = 1;i<N;i++){
        int g= gcd(x[0], x[i]);
        cout << x[0]/g  << "/" << x[i]/g << "\n";
    }
    return 0;
}