class Solution {
public:
    //构建一个大堆
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [this] (vector<int>& p1, vector<int>& p2) {
            return calcDistance(p1) < calcDistance(p2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pqueue(comp);
        for (int i = 0; i < points.size(); ++i) {
            pqueue.push(points[i]);
            if (pqueue.size() > k) {
                pqueue.pop();
            }
            
        }
        vector<vector<int>> res;
        while (!pqueue.empty()) {
            res.push_back(pqueue.top());
            pqueue.pop();
        }
        return res;

    }
    int calcDistance(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
}