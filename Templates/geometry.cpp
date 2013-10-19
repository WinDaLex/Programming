template <typename T>
struct Point { 
    T x, y; 
    static double GetDistance(Point a, Point b) { 
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); 
    } 
};
