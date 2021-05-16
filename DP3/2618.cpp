#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int calDist(pair<int,int> x, pair<int,int> y){
    int x_ = x.first - y.first;
    int y_ = x.second - y.second;
    x_ = x_> 0 ? x_ : -x_;
    y_ = y_> 0 ? y_ : -y_;
    return x_ + y_;
}

void setSave(int** v, int seq, int idx, int value){
    v[seq][idx] = value;
}

// allocate_arr: 할당된 경찰차 true면 1 false 면 2
// loc_arr: 할당되지 않은 경찰차의 위치 사건에 대한 index
// DP, 위치에 대한 Index로 2*N, 사건의 발생으로 N을 곱해서 2*N*N
int main(){
    int N, n_event;
    cin >> N >> n_event;
    vector<pair<int,int>> event_arr;
    event_arr.emplace_back(0,0);
    int* save_x[n_event+1];
    int* save_y[n_event+1];

    save_x[0] = new int[1];
    fill(save_x[0], save_x[0] + 1, 0);
    save_y[0] = new int[1];
    fill(save_y[0], save_y[0] + 1, 0);
    for(int i = 1;i<n_event+1;i++){
        save_x[i] = new int[i];
        fill(save_x[i], save_x[i] + i, i==0? 0: INT32_MAX);
        save_y[i] = new int[i];
        fill(save_y[i], save_y[i] + i, i==0? 0: INT32_MAX);
    }
    for(int nth = 0;nth<n_event; nth++){
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        event_arr.push_back(tmp);
        pair<int,int> init_1, init_2;
        init_1 = make_pair(1,1);
        init_2 = make_pair(N,N);
        if(nth == 0){
            save_y[nth+1][nth] = min(save_y[nth+1][nth], save_x[nth][0] + calDist(tmp,init_2));
            save_x[nth+1][nth] = min(save_x[nth+1][nth], save_y[nth][0] + calDist(tmp, init_1));
        }
        for(int k = 0;k<nth;k++){
            //(nth,k) - (nth+1,k)
            save_x[nth+1][k] = min(save_x[nth+1][k], save_x[nth][k] + calDist(tmp, nth == 0? init_1: event_arr[nth]));
            //(nth,k) - (nth, nth+1)
            save_y[nth+1][nth] = min(save_y[nth+1][nth], save_x[nth][k] + calDist(tmp, k==0? init_2: event_arr[k]));
            //(k, nth) - (k, nth+1)
            save_y[nth+1][k] = min(save_y[nth+1][k], save_y[nth][k] + calDist(tmp, nth==0? init_2: event_arr[nth]));
            //(k,nth) - (nth+1, nth)
            save_x[nth+1][nth] = min(save_x[nth+1][nth], save_y[nth][k] + calDist(tmp, k==0? init_1: event_arr[k]));
        }
    }
    // for(int i = 0;i<n_event+1; i++){
    //     cout << i << ":" << event_arr[i].first <<"," << event_arr[i].second << "--------\n";
    //     for(int k=0;k<i; k++){
    //         cout << i << "," << k <<": " << save_x[i][k] << " ";
    //     }
    //     cout <<"\n";
    //     for(int k=0;k<i; k++){
    //         cout << k << "," << i <<": " << save_y[i][k] << " ";
    //     }
    //     cout << "\n";
    // }

    int result_ = INT32_MAX;
    //[n]: n번째 event를 마친 후의 위치
    bool alloc_arr[n_event+1];
    int loc_arr[n_event+1];
    for(int i = 0; i<n_event; i++){
        if(result_ > save_x[n_event][i]){
            result_ =save_x[n_event][i];
            alloc_arr[n_event] = true;
            loc_arr[n_event] = i;
        }
        if(result_ > save_y[n_event][i]){
            result_ =save_y[n_event][i];
            alloc_arr[n_event] = false;
            loc_arr[n_event] = i;
        }
    }
    for(int nth = n_event-1; nth>=1;nth--){
        int k = loc_arr[nth+1];
        if(alloc_arr[nth+1]){
            //(nth,k) - (nth+1,k)
            if(k<nth){
                alloc_arr[nth] = true;
                loc_arr[nth] = k;
            }
            //(k, nth) - (nth+1, nth)
            if(k == nth){
                for(k = 0 ; k <nth; k++){
                    if(save_x[nth+1][nth] == save_y[nth][k] + calDist(event_arr[nth+1], k==0?make_pair(1,1):event_arr[k])){
                        alloc_arr[nth] = false;
                        loc_arr[nth] = k;
                        break;
                    }
                }
            }
        }else{
            //(k, nth) - (k, nth+1)
            if(k<nth){
                alloc_arr[nth] = false;
                loc_arr[nth] = k;
            } 
            //(nth,k) - (nth,nth+1)
            if(k == nth){
                for(k = 0 ; k <nth; k++){
                    if(save_y[nth+1][nth] == save_x[nth][k] + calDist(event_arr[nth+1], k==0? make_pair(N,N):event_arr[k])){
                        alloc_arr[nth] = true;
                        loc_arr[nth] = k;
                        break;
                    }
                }
            }
        }
    }
    cout <<result_ <<"\n";
    for(int i = 1; i<n_event+1;i++){
        cout << (alloc_arr[i]? 1:2) <<"\n";
    }

    return 0;
}