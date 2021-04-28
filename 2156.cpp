#include<iostream>
#include<memory.h>
using namespace std;

int cache[10000][2];

void calMaxScore(int score[], int n){
    if(n==0 && cache[0][0] == -1){
        cache[0][0] = score[0];
        cache[0][1] = 0;
    }else if(n==1 && cache[1][0]== -1){
        cache[1][0] = score[1];
        cache[1][1] = score[1]+ score[0];
    }else if(n==2 && cache[2][0]== -1){
        cache[2][0] = score[2] + score[0];
        cache[2][1] = score[2] + score[1];
    }else if(cache[n][0] == -1){
        calMaxScore(score, n-1);
        calMaxScore(score, n-2);
        calMaxScore(score, n-3);
        int tmp = max(cache[n-3][0], cache[n-3][1]);
        tmp = max(tmp,cache[n-2][0]);
        tmp = max(tmp,cache[n-2][1]);
        cache[n][0] = tmp + score[n];
        cache[n][1] = cache[n-1][0] + score[n];
    }
}

int main(){
    memset(cache, -1, 10000*2*sizeof(int));
    int N;
    cin >> N;
    int score[N];
    for(int i = 0; i< N; i++){
        cin >> score[i];
    }
    calMaxScore(score, N-1);
    // for( int i = 0; i< N; i++){
    //     cout << score[i] << " " << cache[i][0] <<" " << cache[i][1] << endl;
    // }
    int result = 0;
    for(int i =0;i<N;i++){
        result = max(result, cache[i][0]);
        result = max(result, cache[i][1]);
    }
    cout << result << endl;
    return 0;
}