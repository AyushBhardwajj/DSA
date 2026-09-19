class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int rx1 = xCenter - radius;
        int rx2 = xCenter + radius;
        int ry1 = yCenter - radius;
        int ry2 = yCenter + radius;


        for(int i=rx1;i<=rx2;i++){
            for(int j=ry1;j<=ry2;j++){
                double px = i;
                double py = j;
                double xc = xCenter;
                double xy = yCenter;
                double rad = radius;

                double dist = sqrt((xc-px)*(xc-px) + (py-xy)*(py-xy));

                if(dist>radius)continue;

                if(i>=x1 && i<=x2 && j>=y1 && j<=y2)return true;
            }
        }

        return false;
    }
};