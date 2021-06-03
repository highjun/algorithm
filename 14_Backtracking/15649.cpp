#include<iostream>

using namespace std;

bool nextSeqeunce(int* x, bool *use,int M,int N){
    int idx = M-1;
    while(idx >= 0){
        int tmp = x[idx];
        while(tmp <= N){
            if(use[tmp]) tmp++;
            else break;
        }
        if(tmp == N+1){ 
            use[x[idx]] = false;
            idx--;
        }else{
            use[x[idx]] = false;
            use[tmp] = true;
            x[idx] = tmp;
            for(int i = idx+1;i<M;i++){
                for(int j = 1;j<N+1;j++){
                    if(!use[j]){
                        use[j] = true;
                        x[i] = j;
                        break;
                    }
                }
            }
            break;
        }
    }
    if(idx == -1) return false;
    return true;
}

//마지막 숫자를 키워가보면서 적용
//N까지 이미 키웠다면 앞의 숫자를 바꿈
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >>M;
    int x[M];
    bool use[N+1];
    fill(use, use+N+1, false);
    for(int i = 0;i<M;i++){
        x[i] = i+1;
        use[i+1] = true;
    }
    do
    {
        for(int i = 0;i<M;i++) cout << x[i] << " ";
        cout << "\n";
    } while (nextSeqeunce(x, use, M, N));
    return 0;
}