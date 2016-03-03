#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

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

    vector<vector<int>> fourSum1(vector<int> &nums, int target){
        vector<vector<int>> result;
        if(result.size() < 4) return result;
        sort(nums.begin(), nums.end());

        multimap<int, pair<int, int>> cache;
        for(int i = 0; i < nums.size(); i ++){
            for(int j = 0; j < nums.size(); j++){
                cache.insert(make_pair({nums[i] + nums[j], make_pair(i, j)}));
            }
        }

        for(auto i = cache.begin(); i != cache.end(); i++){
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for(auto j = range.first; j != range.second; j++){
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                // avoid a number two times
                if(a!= c && a!= d && b != c && b != d){
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
