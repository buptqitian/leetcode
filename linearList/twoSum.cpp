#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution{
public:
    vector<int> twoSum(vector<int> nums, int target){
        map<int, int> mapping;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            mapping[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int gap = target - nums[i];
            if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> results = s.twoSum(nums, 9);

    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}
