#include <iostream>
using namespace std;


int binarySearch(int *nums, int length, int target){
    if(length == 0) return -1;
    int i = -1;
    int j = length;
    int mid = 0;
    while(1){
        mid = (i + j)/2;
        if(nums[mid] < target){
            i = mid;
        }else if(nums[mid] > target){
            j = mid;
        }else{
            return mid;
        }
        if((j - i) == 1) return -1;
    }
}


int main()
{
    int nums[] = {1, 2, 5, 8, 10, 19};
    int result = binarySearch(nums, 6, 19);
    cout << result << endl;
}
