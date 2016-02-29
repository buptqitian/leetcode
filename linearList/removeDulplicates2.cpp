#include <iostream>
#include <vector>
using namespace std;



class Solution{
public:
    int removeDulicates(vector<int> &nums){
        int index = 0;
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[index] != nums[i]){
                index++;
                nums[index] = nums[i];
                count = 0;
            }else{
                count++;
                if(count == 1){
                    index++;
                    nums[index] = nums[i];
                }
            }
        }
        return index + 1;
    }
};


int main()
{
    Solution S;
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3};
    S.removeDulicates(nums);

    cout << nums.size() << endl;
    for(auto i : nums){
        cout << i << endl;
    }
}
