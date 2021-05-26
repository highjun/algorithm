#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int score[N];
    for(int i = 0; i<N;i++){
        cin >> score[i];
    }
    int max_ = *max_element(score, score+N);
    double sum = 0;
    for(int i =0;i<N;i++) sum+= score[i]; 
    sum/= N * max_;
    sum*= 100;
    cout << sum <<"\n";
    return 0;
}