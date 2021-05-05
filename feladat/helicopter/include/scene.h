#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
    Object aircraft;
} Scene;

/**
 * Initialize the scene.
 */
void init_scene(Scene* scene);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draw a sphere.
 */
void draw_sphere();

#endif /* SCENE_H */