#include<iostream>
#include<tuple>

using namespace std;

//자신의 피지컬 기준으로 더 큰 사람의 수를 센다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N][2];
    for(int i = 0;i<N;i++) cin >> x[i][0] >> x[i][1];
    for(int i = 0; i<N;i++){
        int rank_ = 1;
        for(int j = 0; j<N;j++){
            if(x[i][0] < x[j][0] && x[i][1] < x[j][1]){
                rank_++;
            }
        }
        cout << rank_ << " ";
    }
    cout << "\n";
    return 0;
}