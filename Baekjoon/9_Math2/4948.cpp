#include<iostream>

using namespace std;

//에라토스테네스의 체를 사용하여 소수를 미리 판정해놓고 세기만 함
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int MAX = 123456 * 2;
    bool x[MAX];
    fill(x, x+MAX, true);
    x[0] = false;//1
    for(int i = 1; i < MAX;i++){
        if(x[i]){
            int num_ = i+1;
            for(int j =2; j*num_<=MAX; j++){
                x[j*num_-1] = false;
            }
        }
    }
    int n;
    while(cin >> n){
        if(n == 0) break;
        int cnt = 0;
        for(int i = n+1; i <= 2*n ; i++){
            if(x[i-1]) cnt++;
        }
        cout << cnt <<"\n";
    }

    return 0;
}