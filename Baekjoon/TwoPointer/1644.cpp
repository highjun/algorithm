#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int target;
    cin >> target;

    vector<int> prime_arr;
    vector<bool> v(target+1);
    for (int i = 2; i <= target; i++)
	{
		if (!v[i]) {
			prime_arr.push_back(i);
			for (int j = i*2; j <= target; j += i)
			{
				v[j] = true;
			}
		}
	}
    int start =0 , end = 0;
    int sum_  = 2;   
    int cnt  = 0; 
    while(start != prime_arr.size()){
        if(sum_ < target){
            if(end == prime_arr.size()) break;
            end++;
            sum_ += prime_arr[end];
        }else if(sum_ == target){
            cnt++;
            sum_ -= prime_arr[start];
            start++;
        }else{
            sum_ -= prime_arr[start];
            start++;
        }
    }
    // for(int i = 0 ;i<prime_arr.size();i++){
    //     cout << prime_arr[i] << " ";
    // }
    // cout <<"\n";
    cout << cnt << "\n";
    return 0;
}