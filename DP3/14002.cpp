#include<iostream>
#include<memory.h>

using namespace std;

// 증가하는 부분수열의 각 길이 중 마지막 값이 제일 작은 경우의 수열을 저장한다. 
// 1000*1000*4 byte = 4MB
int main(){
    int N;
    cin >> N;
    int save[N][N];
    save[0][0] = 0;
    int longest = -1;
    for(int i = 0; i<N;i++){
        int arr;
        cin >> arr;
        int idx = 0;
        while(idx < longest + 1){
            if(save[idx][idx] >= arr){
                // memcpy(save[longest], save[longest-1], longest* sizeof(int));
                // save[idx][idx] = arr;
                break;
            }
            idx++;
        }
        if(idx != 0) memcpy(save[idx], save[idx-1], idx* sizeof(int));
        save[idx][idx] = arr;
        if(idx == longest+1) longest++;
    }
    cout << longest+1 << "\n";
    for(int i = 0;i<longest+1;i++){
        cout << save[longest][i] << " ";
    }
    cout << "\n";
    return 0;
}