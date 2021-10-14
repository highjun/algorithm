#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>

using namespace std;

// pivot(배열의 첫번째 수)와의 비교를 통해서
// pivot 이하의 배열과 pivot 초과의 배열로 나누어서 분할-정복을 사용한다.
// 평균적으로 O(nlogn)이나 최악의 경우 O(n^2)이다.
// 공간 복잡도는 tmp array가 모든 단계에서 나타나므로 O(nlogn)이 된다.
void quick_sort(int* arr, int start, int end){
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
        quick_sort(arr, start, start + st);
        quick_sort(arr, start + st + 1, end);
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