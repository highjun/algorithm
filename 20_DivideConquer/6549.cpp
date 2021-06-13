#include<iostream>

using namespace std;

// [L,R)에서 최고로 큰 직사각형의 넓이를 구한다.
long long func(long long *x,int N,int L, int R){
    if(R-L == 1) return x[L];
    if(L == R) return 0;
    long long max_ = max(func(x, N, L, (L+R)/2),
                        func(x,N,(L+R)/2, R));
    //(L+R)/2와 (L+R)/2 -1을 포함하도록 걸쳐있다.
    int l = (L+R)/2-1 , r = (L+R)/2;
    long long height = min(x[l], x[r]);
    long long area = height * (r-l+1);
    while(l!=L || r!= R-1){
        if(l>L && r< R-1){
            if(x[l-1] > x[r+1]){
                l--;
                height = min(x[l], height);
            }else{
                r++;
                height = min(x[r], height);
            }
        }else if(l == L){
            r++;
            height = min(x[r], height);
        }else{
            l--;
            height = min((long long)x[l], height);
        }
        area = max(height *(r-l+1), area);
    }
    return max(max_, area);
}

// 절반씩 쪼개서 각각에 대한 것을 구한다.
// 분할 정복시 a_n = 2a_(n/2) + n으로 O(nlogn) 수준
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    while(cin >> N){
        if(N == 0) break;
        long long x[N];
        for(int i =0; i< N;i++) cin >> x[i];
        cout << func(x, N, 0, N) << "\n";
    }
    return 0;
}