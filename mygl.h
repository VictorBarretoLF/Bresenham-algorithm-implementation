#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"

// https://saturncloud.io/blog/bresenham-line-algorithm-a-powerful-tool-for-efficient-line-drawing/
//-----------------------------------------------------------------------------
void MyGlDraw(void);

void PutPixel(void);
void DrawLine(void);

void PutPixel(int x, int y, int r, int g, int b) {
    if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT) {
        return;
    }

    int index = (x + y * IMAGE_WIDTH) * 4;
    FBptr[index] = r;
    FBptr[index + 1] = g;
    FBptr[index + 2] = b;
    FBptr[index + 3] = 255;
}

void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b){
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    bool slope = dy > dx;
    
    if (slope) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    dx = std::abs(x2 - x1);
    dy = std::abs(y2 - y1);
    int error = dx / 2;
    int y = y1;
    int ystep = (y1 < y2) ? 1 : -1;
    
    for (int x = x1; x <= x2; ++x) {
        if (slope) {
            PutPixel(y, x, r, g, b);
        } else {
            PutPixel(x, y, r, g, b);
        }
        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b) {
    DrawLine(x1, y1, x2, y2, r, g, b);
    DrawLine(x2, y2, x3, y3, r, g, b);
    DrawLine(x3, y3, x1, y1, r, g, b);
}

void MyGlDraw(void) {
    int middleX = (int)(IMAGE_WIDTH / 2); // 256
    int middleY = (int)(IMAGE_WIDTH / 2); // 256
    
    DrawTriangle(middleX, middleY / 2, middleX / 2, middleY + (middleY / 2), middleX + (middleX / 2), middleY + (middleY / 2),
        255, 0, 0);
    
}


