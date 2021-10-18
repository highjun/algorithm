#include<iostream>

#include<cassert>
#include<algorithm>

using namespace std;

void swap(int * a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int min(int x, int y){
    return x<y? x:y;
}
// heap은 ARR로 구현됨
// heap[1]부터 채운다. 그러면 child는 idx*2, idx*2+1이 되어서 접근이 쉽다.
// insert는 마지막에 Node를 추가하고, parent보다 작으면 Swap해서 거슬러 올라간다.
// pop은 root Node를 제거하고, 마지막 Node를 root에 넣어서, 아래로 내려간다.
void insert(int *heap,int* len, int data){
    (*len)++;
    heap[*len] = data;
    int idx = *len;
    while(idx != 1 && heap[idx] < heap[idx/2]){
        swap(heap+idx, heap+ idx/2);
        idx/= 2;
    }
}
int pop(int *heap,int* len){
    int data = heap[1];
    heap[1] = heap[*len];
    (*len)--;
    int idx = 1;
    while(idx*2 <= *len){
        if(idx*2 < *len){
            if(heap[idx] > min(heap[idx*2],heap[idx*2+1])){
                if(heap[idx*2]<heap[idx*2+1]){
                    swap(heap+idx*2, heap+idx);
                    idx = idx*2;
                }else{
                    swap(heap+idx*2+1, heap+idx);
                    idx = idx*2 + 1;
                }
            }else{
                break;
            }
        }else if(idx*2 == *len){
            if(heap[idx] > heap[idx*2]){
                swap(heap+idx*2, heap+idx);
                idx = idx*2;
            }
            break;
        }
    }
    return data;
}
void heap_sort(int *arr, int N){
    int tmp[N+1];
    int len = 0;
    for(int i = 0 ;i<N;i++){
        insert(tmp, &len, arr[i]);
    }
    for(int i = 0;i<N;i++){
        arr[i] = pop(tmp, &len);
    }
}
// int main(){
//     int N = 10;
//     int x[N] = {4,1,2,3,5,6,7,8,9,10};
//     heap_sort(x, N);
//     for(int i = 0; i<N;i++){
//         cout << x[i] <<" ";
//     }
//     cout << "\n";
//     return 0;
// }
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N= 1000;
    for(int i=0; i< 100000;i++){
        int x[N], y[N];
        for(int i = 0; i<N;i++){
            x[i] = y[i] = rand();
        }
        sort(y, y+N);
        heap_sort(x, N);
        bool check = true;
        for(int i = 0; i<N;i++){
            check &= x[i] == y[i];
        }
        assert(check);
    }
    return 0;
}