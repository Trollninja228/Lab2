#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canDivideIntoGroups(const vector<int>& arr, int group, long max_sum) {
    long current_sum = 0;
    int group_count = 1;

    for (int value : arr) {
        if (current_sum + value > max_sum) {
            group_count++;
            current_sum = value;

            if (group_count > group) {
                return false;
            }
        } else {
            current_sum += value;
        }
    }

    return true;
}

long findMinMaxSum(const vector<int>& arr, int group) {
    long low = *max_element(arr.begin(), arr.end());
    long high = accumulate(arr.begin(), arr.end(), 0L);
    long result = high;

    while (low <= high) {
        long mid = (low + high) / 2;

        if (canDivideIntoGroups(arr, group, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int num, group;
    cin >> num >> group;

    vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    long result = findMinMaxSum(arr, group);
    cout << result << endl;

}
