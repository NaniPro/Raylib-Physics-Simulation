#include "raylib.h"
#include <math.h>
#include <iostream>
#include <cmath>

int main() {
    // 1. Initialize Window
    InitWindow(800, 450, "raylib - 3D Circle");


    SetTargetFPS(60);
    // 2. MainLoop
    float x1 = 800;
    float r1 = 20;
    float r2 = 20;
    float y1 = 300;
    float x2 = 200;
    float y2 = 155;
    float angle = 0.0f;
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        float m1;
        float m2;
        float r = 0;
        float g = 9.81f;
        double G = 6.6743;
        float a1;
        float a2;
        float F;
        float dx = x2 - x1;
        float dy = y2 - y1;

        BeginDrawing();
        ClearBackground(BLACK);
        m1 = 5.0f;
        m2 = 5.0f;
        r = sqrt((dx * dx) + (dy * dy));
        dx /= r;
        dy /= r;
        F = (G * m1 * m2) / (r * r);

        a1 = (F / m1) * 100000;
        a2 = (F / m2) * 100000;
        if (r < (r1 + r2)*1.5 || dy*1.5 > 0) {
            x1 += 0;
            x2 -= 0;
        }
        else if (x1 - x2 < 0) {
            if (dx < 1)
            {
                dx = 1;
                x1 -= (a1 * dt) * cos(angle);
                x2 += (a2 * dt) * cos(angle);
            }
            else
            {
                x1 += (a1 * dt) * cos(angle);
                x2 -= (a2 * dt) * cos(angle);
            }
        }
        else
        {
            if (dx < 1)
            {
                dx = 1;
                x1 -= (a1 * dt) * cos(angle);
                x2 += (a2 * dt) * cos(angle);
            }
            else
            {
                x1 -= (a1 * dt) * cos(angle);
                x2 += (a2 * dt) * cos(angle);
            }
        }
        if (y1 - y2 < 0)
        {
            if (dy < 1)
            {
                dy = 1;
                y1 -= (a1 * dt) * sin(angle);
                y2 += (a2 * dt) * sin(angle);
            }
            else
            {
                y1 -= (a1 * dt) * sin(angle);
                y2 += (a2 * dt) * sin(angle);
            }
        }
        else
        {
            if (dy < 1)
            {
                dy = 1;
                y1 -= (a1 * dy * dt) * sin(angle);
                y2 += (a2 * dy * dt) * sin(angle);
            }
            else
            {
                y1 -= (a1 * dy * dt) * sin(angle);
                y2 += (a2 * dy * dt) * sin(angle);
            }
        }

        angle = asin((y1 - y2) / (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))));
        DrawCircle(x1, y1, r1, RED);
        DrawCircle(x2, y2, r2, RED);
        printf("%e\n", angle);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}