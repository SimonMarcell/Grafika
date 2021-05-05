#include "sphere.h"

void move_sphere(Sphere* sphere, float x, float y)
{
    sphere->x = x;
    sphere->y = y;
}

void start_sphere(Sphere* sphere, float x, float y)
{
    sphere->radius = 50;
    move_sphere(sphere, x, y);
    sphere->speed_x = 100;
    sphere->speed_y = 100;
}

void update_sphere(Sphere* sphere, double time)
{
    sphere->x += sphere->speed_x * time;
    sphere->y += sphere->speed_y * time;
}