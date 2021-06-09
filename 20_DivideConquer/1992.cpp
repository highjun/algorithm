#include<iostream>

using namespace std;

//[r, r+n)x[c,c+n)
string func(bool* x, int N, int n, int r ,int c){
    if(n == 1){
        return (x[r*N+c]? "1" : "0");
    }else{
        string a = func(x, N, n/2, r,c);
        string b = func(x, N, n/2, r,c+n/2);
        string d = func(x, N, n/2, r+n/2,c);
        string e = func(x, N, n/2, r+n/2,c+n/2);
        if(a== "0" && b=="0" && d=="0" && e=="0"){
            return "0";
        }else if(a== "1" && b=="1" && d=="1" && e=="1"){
            return "1";
        }else{
            return "("+ a+b+d+e + ")";
        }
        
    }
}
//분할 정복으로 각 Square에서 해당하는 QuadTree를 반환하도록 하자.
int main(){
    int N;
    cin >> N;
    bool x[N*N];
    for(int i = 0; i<N;i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j<tmp.size();j++){
            x[N*i+j] = tmp[j] - '0';
        }
    }
    cout << func(x, N, N, 0,0) <<"\n";
    return 0;
}