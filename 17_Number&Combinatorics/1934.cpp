#include<iostream>
#include<algorithm>

using namespace std;

//x >= y로 주어질 경우만 허용
int gcd(int x, int y){
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int A,B;
        cin >> A >> B;
        cout << A*B/gcd(A,B) << "\n";
    }
    return 0;
}