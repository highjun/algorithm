#include<iostream>
#include<list>

#include<cstring>
#include<cassert>
#include<algorithm>

using namespace std;

// Divide & Conquer
// Divide로 2개의 Stage로 나눈다.
// 부분적으로 정렬된 Array들을 Conquer단계에서는
// 번갈아 보면서 합친다.

// Linked List를 통해서 구현할 경우,
// Node의 포인터 주소만을 변경하면 충분하기에 
// 더 좋은 방법이 될 수 있다.
struct Node{
    int data;
    Node *next;
};

// Linked List로의 구현
void merge_sort(struct Node** head, int len){
    struct Node *mid = *head;
    struct Node *start = *head;
    if(len <= 1) return;
    for(int i = 0; i<len/2-1; i++){
        mid = mid->next;
    }
    struct Node *tmp = mid;
    mid = mid->next;
    tmp->next = NULL;
    merge_sort(&start, len/2);
    merge_sort(&mid, len-(len/2));
    // Conquer
    struct Node* new_start = NULL;
    if(start->data < mid->data){
        new_start = start;
        start= start->next;
    }else{
        new_start = mid;
        mid = mid->next;
    }
    struct Node* add = new_start;
    while(start!= NULL && mid!=NULL){
        if(start->data < mid->data){
            add->next = start;
            add = add->next;
            start = start->next;
        }else{
            add->next = mid;
            add = add->next;
            mid = mid->next;
        }
    }
    if(start == NULL){
        add->next = mid;
    }else{
        add->next = start;
    }
    *head = new_start;
}

// arr[start, end)의 정렬
void merge_sort2(int* arr, int start, int end){
    if(end - start > 1){
        int mid = (start+end)/2;
        //[start, mid), [mid, end)
        merge_sort2(arr, start, mid);
        merge_sort2(arr, mid, end);
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
//     int N = 10;
//     int x[N] = {4,1,2,3,5,6,7,8,9,10};
//     Node *head = NULL;
//     Node *tail = NULL;
//     for(int i = 0;i<N; i++){
//         Node* tmp = new Node;
//         tmp->data = x[i];
//         tmp->next = NULL;
//         if(i==0){
//             head = tmp;
//             tail = tmp;
//         }else{
//             tail->next = tmp;
//             tail = tail->next;
//         }
//     }
//     cout <<"check\n";
//     merge_sort(&head, N);
//     for(int i = 0; i<N;i++){
//         cout << head->data <<" ";
//         struct Node* tmp = head->next;
//         delete head;
//         head = tmp;
//     }
//     cout << "\n";
//     return 0;
// }

// int main(){
//     int N;
//     cin >> N;
//     int x[N];
//     for(int i = 0;i<N;i++)
//         cin >> x[i];
//     merge_sort2(x, 0, N);
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
        struct Node *head = NULL;
        struct Node *tail = NULL; 
        for(int i = 0;i<N; i++){
            Node* tmp = new Node;
            tmp->data = x[i];
            tmp->next = NULL;
            if(i==0){
                head = tmp;
                tail = tmp;
            }else{
                tail->next = tmp;
                tail = tail->next;
            }            
        }
        merge_sort(&head,N);
        bool check = true;
        for(int i = 0; i<N;i++){
            check &= head->data == y[i];
            struct Node* tmp = head->next;
            delete head;
            head = tmp;
        }
        assert(check);
    }
    return 0;
}

// int main(){
//     int N= 1000;
//     for(int i=0; i< 100000;i++){
//         int x[N], y[N];
//         for(int i = 0; i<N;i++){
//             x[i] = y[i] = rand();
//         }
//         sort(y, y+N);
//         merge_sort2(x, 0, N);
//         bool check = true;
//         for(int i = 0; i<N;i++){
//             check &= x[i] == y[i];
//         }
//         assert(check);
//     }
//     return 0;
// }