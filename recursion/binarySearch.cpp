#include <iostream>
using namespace std;


int binarySearch(int *nums, int left, int right, int target){
    if(right - left == 1) return -1;
    int mid = (left + right)/2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] < target){
        binarySearch(nums, mid, right, target);
    }else{
        binarySearch(nums, left, mid, target);
    }
}


int main()
{
    int nums[] = {1, 2, 5, 8, 10, 19};
    int result = binarySearch(nums, -1, 6, 9);
    cout << result << endl;
}
