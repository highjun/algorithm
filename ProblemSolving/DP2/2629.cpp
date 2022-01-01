#include<iostream>
#include<memory.h>

using namespace std;

// ,-15000~15000
int cache[30+1][30001];
int sinker_weight[30];

int checkMeasureBall(int n_sinker, int weight){
    if(weight > 15000 || weight < -15000){
        return 0;
    }  
    if(cache[n_sinker][weight+ 15000] == -1){
        if(n_sinker > 0){
            int check;
            check = checkMeasureBall(n_sinker-1, weight - sinker_weight[n_sinker-1]);
            check = max(check, checkMeasureBall(n_sinker-1, weight + sinker_weight[n_sinker-1]));
            check = max(check, checkMeasureBall(n_sinker-1, weight));
            cache[n_sinker][weight+15000] = check;
            return check;
        }else{
            cache[n_sinker][weight+ 15000] = weight == 0? 1: 0;
            return cache[n_sinker][weight+15000];
        }
    }else{
        return cache[n_sinker][weight+ 15000];
    }
}

int main(){
    memset(cache, -1, 31*30001 *sizeof(int));
    int N;
    cin >> N;
    for(int i=0 ;i< N;i++){
        cin >> sinker_weight[i];
    }
    int M;
    cin >> M;
    
    for(int i = 0; i< M; i++){
        int weight;
        cin >> weight;
        int check = checkMeasureBall(N, weight);
        cout << (check == 1? "Y": "N")<< " ";
    }
    return 0;
}