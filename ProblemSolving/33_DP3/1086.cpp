#include<iostream>

using namespace std;

#define ll long long

string x[15];
int N,K;
int pw[750];//10^i의 나머지
int res[15];// x[i]의 나머지
ll save[100<<15]; //dp를 위한 save, 15!이 2^40가량으로 long long 사용

//string으로 받은 숫자에 대한 나머지 연산
int mod(string num){
    int result = 0;
    for(int i = 0; i<num.size();i++){
        result = (num[i]-'0' + result*10)%K;
    }
    return result;
}

ll gcd(ll x, ll y){
    if(x == 0) return y;
    if(y% x == 0) return x;
    return gcd(y%x, x);
}

//아직 계산되지 않은 State만 계산한다.
//State는 현재 사용된 숫자들의 비트마스크와 현재 수의 나머지
ll dp(int r, int mask, int m){
    // cout << r << "," << mask << "," << m << "\n";
    if(save[(r << 15) + mask] == -1){
        ll cnt = 0;
        for(int i = 0 ;i<N;i++){
            int tmp = 1 << i;
            //이미 사용한 숫자가 가장 왼쪽에 쓰였을 경우
            if((tmp& mask)){
                int r_tmp = (r - pw[m-x[i].size()] * res[i])%K;
                if(r_tmp< 0) r_tmp += K;
                cnt += dp(r_tmp, (~tmp) & mask, m-x[i].size());
            }
        }
        save[(r<<15)+mask] = cnt;
        // cout << r << "," << mask << "," << m <<"," << cnt <<"\n";
    }
    return save[(r<<15)+mask];
}

//save[i << N + mask]: mask에 해당하는 숫자로 이루어진 순열 중 K로 나눈 나머지가 i
//인 숫자의 개수
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    //길이 50이하로 되어 있어서 String으로 받는다.
    for(int i = 0;i<N;i++) cin >> x[i];
    cin >> K;
    //pw는 10^i의 나머지
    pw[0] = 1;
    for(int i = 0;i<750-1;i++){
        pw[i+1] = (pw[i]*10)% K; 
    }
    for(int i = 0;i<N;i++) res[i] = mod(x[i]);
    fill(save, save + (100 << 15) , -1);
    save[0] = 1;
    for(int i = 1;i<K;i++){
        save[i << 15] = 0;
    }
    int M = 0;
    for(int i = 0;i<N;i++) M += x[i].size();
    ll p = dp(0, (1<<N)-1, M);
    ll q = 1;
    for(int i = 1;i<=N;i++) q *= i;
    ll g= gcd(p,q);
    p /= g;
    q /= g;
    cout << p <<"/" <<q << "\n";
    return 0;
}