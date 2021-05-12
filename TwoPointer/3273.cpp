#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    sort(a, a+n);
    int end = n-1, start = 0;
    int cnt = 0;
    while(end != start){
        if(a[start] + a[end] > x){
            end--;
        }else if(a[start] + a[end] == x){
            end--;
            cnt++;
        }else{
            start++;
        }
    }
    cout << cnt <<"\n";

    return 0;
}