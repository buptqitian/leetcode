#include <iostream>
#include <vector>
using namespace std;

int findMin(int *nums, int left, int right){

    if(left  == right) return nums[left];
    if(right - left == 1){
        return min(nums[left], nums[right]);
    }

    if(nums[left] <= nums[right]){
        return nums[left];
    }else{
        int mid = (left + right)/2;
        if(nums[mid] >= nums[left] && nums[mid] > nums[right]){
            return findMin(nums, mid, right);

        }
        if(nums[mid] <= nums[right] && nums[mid] < nums[left]){
            return findMin(nums, left, mid);

        }
        return nums[left];
    }

}


int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int nums1[] = {4, 5, 6, 1, 2, 3};
    int nums2[] = {3, 1, 2};
    int a =  findMin(nums2, 0, 2);
    cout << a << endl;

}
