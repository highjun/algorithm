#include<iostream>
#include<cmath>

using namespace std;

// 1[1(1)]
// 2[2(11)]
// 3[3(111) ~4(121)]
// 4[4(1111)~6(1221)]
// 5[5~9(12321)]
// 6[6~12(123321)] 이므로
// [2k,k(k+1)]는 2k개로, [2k-1, k^2]은 2k-1개로 묶을 수 있다.
int main(){
    int T;
    cin >> T;
    while(T--){
        int x,y;
        cin >> x >> y;
        int dist = y-x;
        int k = (int) sqrt(dist-1);// dist in (k^2,(k+1)^2]
        if(k*(k+1)< dist){
            cout << 2*k+1 <<"\n";
        }else{
            cout << 2*k << "\n";
        }
    }
    return 0;
}