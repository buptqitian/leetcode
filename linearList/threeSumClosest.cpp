#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int> &nums, int target){
        int result = 0;
        int min_gap = 1000;

        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for(auto i = nums.begin(); i < last - 2; i++){
            auto j = i + 1;
            auto k = last - 1;
            while(j < k){
                int sum = *i + *j + *k;
                int gap = abs(sum - target);

                if(gap < min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum < target) ++j;
                else --k;
            }
        }
        return result;
    }
};


int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution s;
    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
}
