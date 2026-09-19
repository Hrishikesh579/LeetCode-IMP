class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        if(yCenter <= y2 && yCenter >= y1){
            if(xCenter <= (x2 + radius) && xCenter >= (x1 - radius)) return true;
        }
        if(xCenter <= x2 && xCenter >= x1){
            if(yCenter <= (y2 + radius) && yCenter >= (y1 - radius)) return true;
        }
            if (dist(x1, y1, xCenter, yCenter) <= radius*radius)
                return true;
            if (dist(x1, y2, xCenter, yCenter) <= radius*radius)
                return true;
            if (dist(x2, y1, xCenter, yCenter) <= radius*radius)
                return true;
            if (dist(x2, y2, xCenter, yCenter) <= radius*radius)
                return true;
        return false;
    }
};