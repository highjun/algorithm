#include<iostream>

using namespace std;

// i까지를 정렬 후, i+1과 이전의 것들을 비교해서 바꿈
void insertionSort(int N, int* arr){
    for(int i =1;i< N;i++){
        int tmp = arr[i];
        int j = i-1; 
        while(j >= 0){
            if(arr[j] < tmp){
                arr[j+1] = tmp;
                break;
            }
            arr[j+1] = arr[j];
            j--;
        }
        if(j== -1) arr[0] =tmp;
    }
}

// 비교해가면서 Swap해가면서 Max가 마지막에 가게끔한다.
void bubbleSort(int N, int* arr){
    for(int i =0; i<N;i++){
        for(int j = 0; j< N-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i = 0;i<N ; i++) cin >> x[i];
    // insertionSort(N, x);
    bubbleSort(N,x);
    for(int i = 0;i<N;i++) cout << x[i] <<"\n";
    return 0;
}