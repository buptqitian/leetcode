#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(result.size() < 4) return result;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for(auto a = nums.begin(); a < last - 3; a++){
            for(auto b = a + 1; b < last - 2; b++){
                auto c = b + 1;
                auto d = last -1;
                while(c < d){
                    if( *a + *b + *c + *d < target){
                        ++c;
                    }else if( *a + *b + *c + *d > target){
                        --d;
                    }else{
                        result.push_back({*a, *b, *c, *d});
                        ++c;
                        --d;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }


    
};
