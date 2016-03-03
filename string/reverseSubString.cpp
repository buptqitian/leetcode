#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseSubString(const string str){
    int length = str.size();
    vector<string> temp;
    string result = "";
    int i = 0;
    int j = i;
    while(i <= str.size()){
        if(str[i] == ' ' || i == str.size()){
            temp.push_back(str.substr(j, i - j));
            j = i + 1;
        }
        i++;
    }
    for(auto it = temp.rbegin(); it != temp.rend(); it++){
        result += *it + " ";
    }
    result = result.substr(0, length);
    return result;
}

int main()
{
    string a = "hello world ni hao";
    //reverseSubString(a);
    string b = reverseSubString(a);
}
