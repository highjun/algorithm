#include<iostream>

using namespace std;

// 10000^2 밖에 안되므로 다 계산해본다.
int main(){
    int M,N;
    cin >> M >> N;
    int sum_ = 0;
    int min_ = N;
    for(int p = M;p<=N;p++){
        bool is_prime = true;
        if(p == 1) is_prime = false;
        for(int i = 2; i<p; i++){
            if(p%i == 0){
                is_prime = false;
                break;
            } 
        }
        if(is_prime && min_ > p) min_ = p;
        if(is_prime) sum_+= p;
    }
    if(sum_ == 0){
        cout << -1 <<"\n";
        return 0;
    }
    cout << sum_ <<"\n";
    cout << min_ <<"\n";

    return 0;
}