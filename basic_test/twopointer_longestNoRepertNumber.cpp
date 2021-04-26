#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char** argv) {
    vector<int> arr{1,2,2,3,5};
    vector<int> count(arr.size(), 0);
    cout << "count " << count[4];
    int r = 0;
    for(int i = 0,j = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
        while(count[arr[i]] > 1) --count[arr[j++]];
        r = max(r, i - j + 1);
    }
    cout << " res " << r << endl;
    return 0;
}