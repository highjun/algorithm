#include<iostream>

using namespace std;

// 100*1000 밖에 안되므로 다 계산해본다.
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    while(N--){
        int p;
        cin >> p;
        bool is_prime = true;
        if(p == 1) is_prime = false;
        for(int i = 2; i<p; i++){
            if(p%i == 0){
                is_prime = false;
                break;
            } 
        }
        if(is_prime) cnt++;
    }
    cout << cnt <<"\n";
    return 0;
}