#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n_city, n_bus;
    cin >> n_city >> n_bus;
    int shortest_path[n_city*n_city];
    vector<int> shortest_path_[n_city*n_city];
    int shortest_path_old[n_city*n_city];
    vector<int> shortest_path_old_[n_city*n_city];
    fill(shortest_path_old, shortest_path_old + n_city*n_city, INT32_MAX);
    for(int i = 0;i<n_city;i++){
        shortest_path_old[i*n_city+i] = 0;
    }
    while(n_bus--){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        int tmp = (src-1)*n_city + dest-1;
        shortest_path_old[tmp] = min(weight, shortest_path_old[tmp]);
    }
    for(int k =0; k<n_city; k++){
        for(int i = 0; i<n_city;i++){
            for(int j = 0;j<n_city; j++){
                shortest_path[i*n_city + j] = shortest_path_old[i*n_city + j];
                vector<int> *a= &shortest_path_[i*n_city+j];
                (*a).clear();
                (*a).insert((*a).end(), shortest_path_old_[i*n_city + j].begin(), shortest_path_old_[i*n_city + j].end());
                if(shortest_path_old[i*n_city+k] != INT32_MAX && shortest_path_old[k*n_city+ j] != INT32_MAX
                && shortest_path[i*n_city+j] > shortest_path_old[i*n_city+k] + shortest_path_old[k*n_city+j]){
                    shortest_path[i*n_city + j]= shortest_path_old[i*n_city+k] + shortest_path_old[k*n_city+j];
                    vector<int> *b= &shortest_path_old_[i*n_city+k];
                    vector<int> *c= &shortest_path_old_[k*n_city+j];
                    (*a).clear();
                    (*a).insert((*a).end(), (*b).begin(),(*b).end());
                    (*a).push_back(k+1);
                    (*a).insert((*a).end(), (*c).begin(),(*c).end());
                }
            }
        }
        memcpy(shortest_path_old, shortest_path, n_city*n_city*sizeof(int));
        for(int i= 0 ; i<n_city*n_city ; i++){
            shortest_path_old_[i].clear();
            shortest_path_old_[i].assign(shortest_path_[i].begin(), shortest_path_[i].end());
        }
    }
    for(int i = 0; i<n_city;i++){
        for(int j = 0;j<n_city; j++){
            cout << (shortest_path[i*n_city + j] == INT32_MAX? 0: shortest_path[i*n_city +j]) << " ";
        }
        cout <<"\n";
    }
    for(int i = 0; i<n_city;i++){
        for(int j = 0;j<n_city; j++){
            if(shortest_path[i*n_city+j] == 0 || shortest_path[i*n_city+j] ==INT32_MAX){
                cout << 0 <<"\n";
                continue;
            }
            vector<int> tmp =shortest_path_[i*n_city+j];
            cout << tmp.size() + 2 << " " << i+1 <<" ";
            for(int k = 0; k<tmp.size();k++){
                cout << tmp[k] << " ";
            }
            cout << j+1 <<"\n";
        }
    }
    return 0;
}