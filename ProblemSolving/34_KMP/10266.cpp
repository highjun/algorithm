#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;


void failure(int *ps,int N, int* pattern){
    int prev = 0;
    ps[0] = 0;
    for(int i = 1; i< N; i++){
        if(pattern[prev]== pattern[i]){
            prev++;
            ps[i] = prev;
        }else{
            if(prev > 0){
                prev = ps[prev-1];
                i--;
            }else{
                ps[i] = 0;
            }
        }
    }
}
int KMP(int * ps,int* text, int* pattern, int text_len, int pattern_len){
    int prev = 0;
    int n_match = 0;
    for(int idx  = 0; idx < text_len;idx++){
        // cout << idx+1 << " " << prev << "\n";
        if(prev == pattern_len){
            n_match++;
            prev = ps[prev-1];
            idx--;
            continue;
        }
        if(pattern[prev] == text[idx]){
            prev++;
        }else{
            if(prev> 0){
                idx--;
                prev = ps[prev-1];
            }
        }
    }
    if(prev == pattern_len){
        n_match++;
    }
    return n_match;
}

// sort후 바늘사이의 간격을 나열한 순열을 고려하자.
// 배열로 되어 있기에 시작 idx가 다를 수는 있지만 결국 같은 순열이 되어야한다.
// [ x ][ x ]에 y가 속하는 것은 문자열이 같은 것과 동치다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N], y[N];
    for(int i = 0;i<N;i++) cin >> x[i];
    for(int i = 0;i<N;i++) cin >> y[i];
    sort(x, x+N);
    sort(y, y+N);
    int bx[N], by[N];
    for(int i = 0;i<N;i++){
        bx[i] = (x[(i+1)%N]- x[i] + 360000)%360000;
        by[i] = (y[(i+1)%N]- y[i] + 360000)%360000;
    }
    int ps[N];
    failure(ps, N, by);
    int bx_repeat[2*N];
    memcpy(bx_repeat, bx, sizeof(int)*N);
    memcpy(bx_repeat+N, bx, sizeof(int)*N);
    int result = KMP(ps, bx_repeat, by, 2*N, N);
    cout << (result > 0? "possible":"impossible") << "\n";
    return 0;
}