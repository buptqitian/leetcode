#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    multimap<int, pair<int, int>> temp;
    temp.insert(make_pair(5, make_pair(1, 2)));
    temp.insert(make_pair(5, make_pair(2, 3)));
    temp.insert(make_pair(5, make_pair(4, 5)));

    auto range = temp.equal_range(5);
    for(auto i = range.first; i != range.second; i++){
        cout<< i->first << " ";
        cout << i->second.first << " ";
        cout << i->second.second << " ";
        cout << endl;
    }

    cout << INT_MAX << endl;
}
