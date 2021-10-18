#include<iostream>
using namespace std;

long long cache[100];
void calPadovan(int n){
    if(n > 5 && cache[n-1] == 0){
        calPadovan(n-1);
        calPadovan(n-5);
        cache[n-1] = cache[n-2] + cache[n-6];
    }
}
int main(){
    cache[0] =cache[1] = cache[2] = 1;
    cache[3] = cache[4] = 2;

    int N;
    cin >> N;
    for(int i=0 ;i<N;i++){
        int n;
        cin >> n;
        calPadovan(n);
        cout << cache[n-1] <<endl;
    }
}