#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int MAX = 10000;
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
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = n/2; i > 0 ; i--){
            if(x[i-1] && x[n-i-1]){
                cout << i << " " << n-i << "\n";
                break;
            }
        }
    }
    return 0;
}