#include<iostream>

using namespace std;

//맨 왼쪽위가 Black일때, White일 때 나눠서 다시
//칠해야 하는 개수 counting
int main(){
    int M,N;
    cin >> N >> M;
    int n_black = 0, n_white = 0;
    string x[N];
    for(int i = 0;i<N;i++){
        string tmp;
        cin >> tmp;
        x[i] = tmp;
    }
    int min_ = N*M;
    for(int i = 0; i<N-7;i++){
        for(int j = 0;j<M-7;j++){
            int n_black = 0;
            for(int h = 0; h<8;h++){
                for(int w = 0;w<8;w++){
                    if(x[i+h][j+w] == 'W'){
                        if((h+w)%2==0){
                            n_black++;
                        }
                    }else{
                        if((h+w)%2==1){
                            n_black++;
                        }
                    }
                }
            }
            min_ = min(min_, min(64-n_black, n_black));
        }
    }
    cout << min_ << "\n";
    return 0;
}