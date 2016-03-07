#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution{
public:
    string bigNumAdd(string s1, string s2){
        int x = 0;
        int size = max(s1.size(), s2.size());

        string result;
        int temp = 0;
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){

            temp = ((s1[i] - '0') + (s2[j] - '0') + x)%10;
            x = ((s1[i] - '0') + (s2[j] - '0') + x)/10;
            result.append(to_string(temp));
            i++;
            j++;
        }

        if(s1.size() > s2.size()){
            while(i < s1.size()){
                temp = ((s1[i] - '0') + x)%10;
                x = ((s1[i] - '0') + x)/10;
                result.append(to_string(temp));
                i++;
            }
        }else if(s2.size() > s1.size()){
            while(j < s2.size()){
                temp = ((s2[j] - '0') + x)%10;
                x = ((s2[j] - '0') + x)/10;
                result.append(to_string(temp));
                j++;
            }
        }

        if(x > 0){
            result.append(to_string(x));
        }
        return result;
    }

};


int main()
{
    string s1 = "12345";
    string s2 = "999";
    Solution s;
    string result = s.bigNumAdd(s1, s2);
    cout << result << endl;
}
