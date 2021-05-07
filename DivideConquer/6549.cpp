#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<long long> fence_arr;
int N;

long long getMaxRectangle(int left, int right){
    if(right==left){
        return fence_arr[left];
    }
    int center = (left+right)/2;
    long long result =max(getMaxRectangle(left, center), getMaxRectangle(center+1, right));

    long long height = min(fence_arr[center], fence_arr[center+1]);
    int l= center, r = center+1;
    result = max(result, height*(r-l+1));
    while(left <l || right >r){
        if(r <right &&(l==left || fence_arr[l-1] < fence_arr[r+1])){
            ++r;
            height = min(height, fence_arr[r]);
        }else{
            --l;
            height = min(height, fence_arr[l]);
        }
        result = max(result, height*(r-l+1));
    }
    return result;
}

int main()
{
    while(true){
        cin >> N;
        if(N == 0) break;
        fence_arr.reserve(N);
        for(int i = 0; i< N; i++){
            long long tmp;
            cin >> tmp;
            fence_arr.push_back(tmp);
        }
        cout << getMaxRectangle(0, N-1) << endl;
        fence_arr.clear();
    }

	return 0;
}