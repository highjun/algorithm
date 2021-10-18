#include<iostream>
#include<tuple>

using namespace std;

struct triple{
    int a[3];
    triple& operator+(const triple& x)
    {
        a[0]+= x.a[0];
        a[1]+= x.a[1];
        a[2]+= x.a[2];
        return *this;
    }
};

triple func(int *x,int N, int n,int r, int c){
    triple result;
    fill(result.a,  result.a+3, 0);
    if(n == 1){
        result.a[x[r*N+c]+1] = 1;
        return result;
    }
    triple tmp[9];
    for(int i = 0 ;i <3; i++){
        for(int j = 0; j<3;j++){
            tmp[i*3+j] = func(x, N, n/3, r+i*n/3, c+j*n/3);
        }
    }
    for(int idx = 0; idx< 9;idx++){
        result = result+ tmp[idx];
    }
    if(result.a[0] == 9 &&result.a[1] == 0 && result.a[2] == 0) result.a[0] = 1;
    if(result.a[0] == 0 &&result.a[1] == 9 && result.a[2] == 0) result.a[1] = 1;
    if(result.a[0] == 0 &&result.a[1] == 0 && result.a[2] == 9) result.a[2] = 1;
    
    // cout<< n << " " << r <<" " << c << ":\n";
    // cout << result.a[0] <<" ";
    // cout << result.a[1] <<" ";
    // cout << result.a[2] <<"\n"; 
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N*N];
    for(int i = 0;i<N*N;i++) cin >> x[i];
    triple result= func(x, N, N, 0,0);
    cout << result.a[0] <<"\n";
    cout << result.a[1] <<"\n";
    cout << result.a[2] <<"\n";
    return 0;
}