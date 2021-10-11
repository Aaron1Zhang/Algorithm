#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        auto comp = [origin](Point& p1, Point& p2) {
            auto d1 = pow(origin.x - p1.x, 2) + pow(origin.y - p1.y, 2);
            auto d2 = pow(origin.x - p2.x, 2) + pow(origin.y - p2.y, 2);
            if (d1 > d2) {
                return true;
            } else if (d1 == d2) {
                return p1.x > p2.x? true: p1.y > p2.y;
            } else {
                return false;
            }
        };
        
        priority_queue<Point, std::vector<Point>, decltype(comp)> Queue(comp);
        vector<Point> res;
        for (auto& p: points) {
            Queue.push(p);
        }

        for (int i = 0; i < k; ++i) {
            res.push_back(Queue.top());
            Queue.pop();
        }
        return res;
    }
    
};