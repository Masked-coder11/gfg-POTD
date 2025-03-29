class Solution {
public:
    vector<vector<int>> CombinationSum2(vector<int>& arr, int n, int k) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        vector<int> current;
        findCombinations(arr, 0, current, k, result);
        return result;
    }

private:
    void findCombinations(vector<int>& arr, int start, vector<int>& current, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < arr.size(); ++i) {
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }
            if (arr[i] > target) {
                break;
            }
            current.push_back(arr[i]);
            findCombinations(arr, i + 1, current, target - arr[i], result);
            current.pop_back();
        }
    }
};
