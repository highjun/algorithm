#include<iostream>

using namespace std;

//DP와 같이 모두 저장해가면서 나눈다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int MAX = 1000000;
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
    int M,N;
    cin >> M >> N;
    for(int i = M-1;i<N;i++){
        if(x[i]) cout << i+1 <<"\n";
    }
}