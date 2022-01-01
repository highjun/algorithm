#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int  i =0; i<N;i++){
        cin >> x[i]; 
    }
    sort(x, x+N);
    int start = 0, end = N-1;
    int abs_min = INT32_MAX;
    int start_, end_;
    while(start!=end){
        int sum_;
        if((sum_ = x[start] + x[end]) > 0){
            if(sum_ < abs_min){
                abs_min = sum_;
                start_ = start, end_= end;
            }
            end--;
        }else if(sum_ == 0){
            start_ = start, end_= end;
            break;
        }else{
            if(-sum_ < abs_min){
                abs_min = -sum_;
                start_ = start, end_= end;
            }
            start++;
        }
    }
    cout <<x[start_] << " " << x[end_] << "\n";
    return 0;
}