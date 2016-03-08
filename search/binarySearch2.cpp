#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> nums, int target){
    if(nums.size() == 0) return -1;
    int left = -1;
    int right = nums.size();
    while(1){
        int mid = (left + right)/2;
        if(nums[mid] < target){
            left = mid;
        }else if(nums[mid] > target){
            right = mid;
        }else{
            return mid;
        }
        if((right - left) == 1) return -1;
    }
}

int main()
{
    //vector<int> nums = {1, 2, 5, 8, 10, 19};
    vector<int> nums = {1, 2};
    int result = binarySearch(nums, 2);
    cout << result << endl;
}
