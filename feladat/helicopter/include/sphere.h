#ifndef SPHERE_H
#define SPHERE_H

/**
 * Sphere position and speed
 */
typedef struct Sphere
{
    float x;
    float y;
    float radius;
    float speed_x;
    float speed_y;
} Sphere;

/**
 * Move the sphere to the given position.
 */
void move_sphere(Sphere* sphere, float x, float y);

/**
 * Start the ball from the given position.
 */
void start_sphere(Sphere* sphere, float x, float y);

/**
 * Update the sphere.
 * @param time elapsed time in seconds.
 */
void update_sphere(Sphere* sphere, double time);

#endif /* SPHERE_H */