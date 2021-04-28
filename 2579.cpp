#include<iostream>
#include<memory.h>
using namespace std;

int cache[300][2];

void calMaxScore(int score[], int n){
    if(n==0 && cache[0][0] == -1){
        cache[0][0] = score[0];
        cache[0][1] = 1;
    }else if(n==1 && cache[1][0]== -1){
        cache[1][0] = score[1];
        cache[1][1] = score[1]+ score[0];
    }else if(cache[n][0] == -1){
        calMaxScore(score, n-1);
        calMaxScore(score, n-2);
        cache[n][0] = max(cache[n-2][0], cache[n-2][1]) + score[n];
        cache[n][1] = cache[n-1][0] + score[n];
    }
}

int main(){
    memset(cache, -1, 300*2*sizeof(int));
    int N;
    cin >> N;
    int score[N];
    for(int i = 0; i< N; i++){
        cin >> score[i];
    }
    calMaxScore(score, N-1);
    cout << max(cache[N-1][0], cache[N-1][1]) << endl;
    return 0;
}