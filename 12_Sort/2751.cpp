#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;

// Divide Conquer를 통함
// [left, right)
void mergeSort(int* arr, int left, int right){
    if(right - left > 1){
        int mid= (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        int sorted[right-left]; 
        int lidx = left, ridx = mid; 
        for(int i = 0;i< right-left;i++){
            if(lidx == mid){
                sorted[i] = arr[ridx];
                ridx++;
                continue;
            }
            if(ridx == right){
                sorted[i] = arr[lidx];
                lidx++;
                continue;
            }
            if(arr[lidx] < arr[ridx]){
                sorted[i] = arr[lidx];
                lidx++;
            }else{
                sorted[i] = arr[ridx];
                ridx++;
            }
        }
        memcpy(arr+left, sorted, sizeof(int)*(right-left));
    }
}
//완전 이진트리를 이용한 정렬
//이진트리 구현안하고 그냥 라이브러리 사용
void heapSort(int N,int* arr){
    priority_queue<int, vector<int>> queue;
    for(int i = 0;i<N;i++){
        queue.push(arr[i]);
    }
    for(int i = N-1;i>=0;i--){
        arr[i] = queue.top();
        queue.pop();
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    for(int i = 0;i<N ; i++) cin >> x[i];
    // mergeSort(x, 0, N);
    heapSort(N,x);
    for(int i = 0;i<N;i++) cout << x[i] <<"\n";
    return 0;
}