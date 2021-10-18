#include<iostream>
#include<iomanip>

using namespace std;

//counting sort를 통해서 정렬하면
//한 for문에 모두 정렬가능
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int x[N];
    int cnt[8001];
    fill(cnt, cnt+8001, 0);
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        cnt[tmp+4000]++;
    }
    //범위
    int max_ = -1;//최댓값
    int min_ = 8002;//최솟값
    //최빈값
    int max_cnt = -1;
    int max_cnt_idx1 = -1;
    int max_cnt_idx2 = -1;
    //산술 평균
    int sum_ = 0;
    //중앙값
    int cnt_ = 0,mid;//중앙값을 위한 개수 counting
    bool check = false;
    for(int i = 0;i<8001;i++){
        cnt_ += cnt[i];
        sum_ += cnt[i]*(i-4000);
        if(!check && cnt_ > N/2){
            check = true;
            mid = i-4000;
        }
        if(cnt[i] > 0&& max_ < i){
            max_ = i;
        }
        if(cnt[i] > 0 && min_ > i){
            min_ = i;
        }
        if(max_cnt <= cnt[i]){
            if(max_cnt == cnt[i]){
                if(max_cnt_idx2 == -1){
                    max_cnt_idx2 = i;
                }
            }else{
                max_cnt = cnt[i];
                max_cnt_idx2 = -1;
                max_cnt_idx1 = i;
            }
        }
    }
    cout << fixed << setprecision(0);
    cout << ((double)sum_)/N <<"\n";
    cout << mid <<"\n";
    if(max_cnt_idx2 == -1){
        cout << max_cnt_idx1 -4000<< "\n";
    }else{
        cout << max_cnt_idx2 -4000<< "\n";
    }
    cout << max_ - min_ <<"\n";
    return 0;
}