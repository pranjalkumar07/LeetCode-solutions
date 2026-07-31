class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>> ans;
        set<int> timestamps;

        // Store all unique timestamps
        for (auto &x : series1)
            timestamps.insert(x[0]);

        for (auto &x : series2)
            timestamps.insert(x[0]);

        for (int t : timestamps) {

            int val1 = 0;
            int val2 = 0;

            // Find first timestamp >= t in series1
            auto it1 = lower_bound(series1.begin(), series1.end(),
                                   vector<int>{t, INT_MIN});

            if (it1 != series1.end())
                val1 = (*it1)[1];

            // Find first timestamp >= t in series2
            auto it2 = lower_bound(series2.begin(), series2.end(),
                                   vector<int>{t, INT_MIN});

            if (it2 != series2.end())
                val2 = (*it2)[1];

            ans.push_back({t, val1 + val2});
        }

        return ans;
    }
};