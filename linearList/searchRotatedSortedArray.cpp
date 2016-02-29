#include <iostream>
#include <vector>

using  namespace std;


class Solution{
public:
    int search(const vector<int>& nums, int target){
        int bias = 0;
        int min = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min){
                min = nums[i];
                bias = i;
            }
        }

        cout << bias << endl;
        cout << min << endl;
        int left = bias;
        int right = (bias + nums.size() - 1);
        int mid = (left + right)/2;
        int index = 0;
        while(left <= right){
            index = mid % nums.size();
            if(nums[index] == target){
                return index;
            }else if(nums[index] < target){
                left = mid + 1;
                mid = (left + right)/2;
                cout << mid << endl;
            }else{
                right = mid - 1;
                mid = (left + right)/2;
                cout << mid << endl;
            }
        }
        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = S.search(nums, 7);
    cout << result << endl;

}
