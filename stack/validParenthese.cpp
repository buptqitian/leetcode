#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    bool validParenthese(const string str){
        stack<char> s;
        string left = "([{";
        string right = ")]}";
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                s.push(str[i]);
            }else{
                if(s.empty() || s.top() != left[right.find(str[i])]){
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};

int main()
{
    string a = "({{}})";
    Solution s;
    cout << s.validParenthese(a) << endl;
}
