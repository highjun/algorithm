#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>

using namespace std;

// Divide & Conquer
// Divide로 2개의 Stage로 나눈다.
// 부분적으로 정렬된 Array들을 Conquer단계에서는
// 번갈아 보면서 합친다.
void merge_sort(int* arr, int start, int end){
    if(end - start > 1){
        int mid = (start+end)/2;
        //[start, mid), [mid, end)
        merge_sort(arr, start, mid);
        merge_sort(arr, mid, end);
        int N = end - start;
        int tmp[N];
        int p = 0, q = 0;
        for(int i = 0; i<N;i++){
            if(p< mid-start && q< end-mid){
                if(arr[start+p] <= arr[mid+q]){
                    tmp[i] = arr[start+p];
                    p++;
                }else{
                    tmp[i] = arr[mid+q];
                    q++;
                }
            }else{
                if(p == mid-start){
                    tmp[i] = arr[mid+q];
                    q++;
                }else{
                    tmp[i] = arr[start+p];
                    p++;
                }
            }
        }
        memcpy(arr+start, tmp, N*sizeof(int)); 
    }
}


// int main(){
//     int N;
//     cin >> N;
//     int x[N];
//     for(int i = 0;i<N;i++)
//         cin >> x[i];
//     merge_sort(x, 0, N);
//     for(int i=0;i<N;i++){
//         cout << x[i] << " ";
//     }
//     return 0;
// }

int main(){
    int N= 1000;
    for(int i=0; i< 100000;i++){
        int x[N], y[N];
        for(int i = 0; i<N;i++){
            x[i] = y[i] = rand();
        }
        sort(y, y+N);
        merge_sort(x, 0, N);
        bool check = true;
        for(int i = 0; i<N;i++){
            check &= x[i] == y[i];
        }
        assert(check);
    }
    return 0;
}