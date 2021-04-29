#include<iostream>

using namespace std;

int inc[1000];
int dec_[1000];

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int i = 0; i<N;i++){
        cin >>x[i];
    }
    for(int i = 0; i<N; i++){
        int inc_max = 0;
        for(int j = 0; j<i; j++){
            if(x[j]< x[i]){
                inc_max = max(inc_max , inc[j]);
            }
        }
        inc[i] = inc_max + 1;
    }
    for(int i = N-1; i>=0; i--){
        int dec_max = 0;
        for(int j = i+1; j<N; j++){
            if(x[j]< x[i]){
                dec_max = max(dec_max , dec_[j]);
            }
        }
        dec_[i] = dec_max + 1;
    }
    int bionic = 0;
    for (int i = 0; i<N;i++){
        bionic = max(bionic, inc[i] + dec_[i] -1);
    }
    cout << bionic <<endl;
    return 0;
}