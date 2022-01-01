#include<iostream>

using namespace std;


int dp(int save[][3][3], int N, int x[][3], int c0, int c1, int k){
    if(save[k][c0][c1] == -1){
        // cout << c0 <<"," << c1 << "," << k <<"\n";
        int min_ = INT32_MAX;
        min_ = min(dp(save, N, x,c0, (c1+1)%3, k-1), dp(save, N, x,c0, (c1+2)%3, k-1));
        if(min_ != INT32_MAX)
            min_ += x[k][c1]; 
        save[k][c0][c1] = min_;
    }
    return save[k][c0][c1];
}

//0부터 I까지 겹치지 않게 칠할 때, 0, I의 색을 State로 저장
int main(){
    int N;
    cin >> N;
    int x[N][3];
    for(int i = 0;i<N;i++) 
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    // for(int i = 0;i<N;i++)
    //     cout << x[i][0] <<" " << x[i][1] << " " <<x[i][2] << "\n";
    int save[N][3][3];
    fill(&save[0][0][0],&save[0][0][0]+N*3*3,-1);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(i == j)
                save[0][i][j] = x[0][i];
            else
                save[0][i][j] = INT32_MAX;
        }
    }
    // for(int i = 0;i < N;i++){
    //     cout << save[i][0][0] << " " << save[i][0][1] << " ";
    //     cout << save[i][0][2] << " " << save[i][1][0] << " ";
    //     cout << save[i][1][1] << " " << save[i][1][2] << " "; 
    //     cout << save[i][2][0] << " " << save[i][2][1] << " "; 
    //     cout << save[i][2][2] << "\n"; 
    // }
    int min_ = INT32_MAX;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(i!=j)
                min_ = min(min_, dp(save,N,x,i,j,N-1));
        }
    }
    cout << min_ << "\n";
    return 0;
}