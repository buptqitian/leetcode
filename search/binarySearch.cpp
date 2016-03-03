#include <iostream>
#include <vector>

using namespace std;


int binarySearch(vector<int> &nums, int target){
    if (nums.size() == 0) return -1;
    int i = 0;
    int j = nums.size() - 1;
    int mid = (i + j)/2;
    while(i <= j){
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            i = mid + 1;
            mid = (i + j)/2;
        }else{
            j = mid - 1;
            mid = (i + j)/2;
        }
    }
    return -1;
}


int main()
{
    vector<int> nums = {1, 2, 5, 8, 10, 19};
    int result = binarySearch(nums, 2);
    cout << result << endl;
}
