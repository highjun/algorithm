#include<iostream>

#include<cstring>
#include<cassert>
#include<algorithm>

using namespace std;

// pivot(배열의 첫번째 수)와의 비교를 통해서
// pivot 이하의 배열과 pivot 초과의 배열로 나누어서 분할-정복을 사용한다.
// 평균적으로 O(nlogn)이나 최악의 경우 O(n^2)이다.
// Swap을 이용하면 O(n)의 Space Complexity를 가진다.
void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;  
}

// arr[start,end)의 정렬
void quick_sort(int* arr, int start, int end){
    if(end-start > 1){
        int pivot = arr[start];
        int st = start+1;
        int ed = end-1;
        while(st <= ed){
            if(pivot < arr[st]){
                swap(arr+st, arr+ ed);
                ed--;
            }else{
                st++;
            }
        }
        swap(arr+st-1, arr+ start);
        quick_sort(arr, start, st-1);
        quick_sort(arr, st, end);
    }
}
// 배열을 통해서 구현한 경우.
void quick_sort2(int* arr, int start, int end){
    if(start < end){
        int pivot = arr[start];
        // cout << pivot <<"\n";
        int len = end-start-1;
        int tmp[len];
        int st = 0, ed = len-1;
        for(int i =start+1; i<end ; i++){
            if(pivot >= arr[i]){
                tmp[st] = arr[i];
                st++;
            }else{
                tmp[ed] = arr[i];
                ed--;
            }
        }
        memcpy(arr + start, tmp, st*sizeof(int));
        arr[start + st] = pivot;
        memcpy(arr + start + st + 1, tmp + st, (len-st)*sizeof(int));
        quick_sort2(arr, start, start + st);
        quick_sort2(arr, start + st + 1, end);
    }
}


int main(){
    int N= 1000;
    for(int i=0; i< 100000;i++){
        int x[N], y[N];
        for(int i = 0; i<N;i++){
            x[i] = y[i] = rand();
        }
        sort(y, y+N);
        quick_sort(x, 0, N);
        bool check = true;
        for(int i = 0; i<N;i++){
            check &= x[i] == y[i];
        }
        assert(check);
    }
    return 0;
}