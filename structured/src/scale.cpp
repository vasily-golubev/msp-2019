#include "../scale.hpp"

void Scale::scalegrid(RectGrid origin, float dx, float dy, unsigned long nx, unsigned long ny, float ox, float oy)
{
    newRG.setDx(dx);
        newRG.setDy(dy);
        newRG.setNx(nx);
        newRG.setNy(ny);
        newRG.setOx(ox);
        newRG.setOy(oy);
        for (int i = 0; i < newRG.getNx(); i++)
        {
            for (int j = 0; j < newRG.getNy(); j++)
            {
                float x = newRG.getDx()/origin.getDx();
                float y = newRG.getDy()/origin.getDy();
                float x1 = floor(x);
                float x2 = ceil(x);
                float y1 = floor(y);
                float y2 = ceil(y);
                float px1y1 = origin.getAcousticNode(x1, y1).pressure();
                float px2y1 = origin.getAcousticNode(x2, y1).pressure();
                float px1y2 = origin.getAcousticNode(x1, y2).pressure();
                float px2y2 = origin.getAcousticNode(x2, y2).pressure();
                if (x1 == x2 && y1 == y2)
                {
                    newRG.getAcousticNode(x1, y1).setPressure(px1y1);
                }
                else if (x1 == x2 && y1 != y2)
                {
                    newRG.getAcousticNode(x1, y1).setPressure((px1y2-px1y1)/(y2-y1)*(y-y1));
                }
                else if (x1 != x2 && y1 == y2)
                {
                    newRG.getAcousticNode(x1, y1).setPressure((px2y1-px1y1)/(x2-x1)*(x-x1));
                }
                else
                {
                    newRG.getAcousticNode(x1, y1).setPressure(px1y1/((x2-x1)*(y2-y1))*(x2-x)*(y2-y)+px2y1/((x2-x1)*(y2-y1))*(x-x1)*(y2-y)+px1y2/((x2-x1)*(y2-y1))*(x2-x)*(y-y1)+px2y2/((x2-x1)*(y2-y1))*(x-x1)*(y-y1));
                }
            }
        }
}
