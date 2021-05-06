#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"

typedef struct Scene
{
    Object aircraft;
    Object landscape;
    Object water;
    Object helpmenu;
    float lighting;
    float fog;
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
 * Set the lighting.
 */
void set_lighting(const float lighting);

/**
 * Change the lighting.
 */
void change_lighting(Scene *scene, float change);

/**
 * Update the scene.
 */
void update_scene(Scene*, double time);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draw a sphere.
 */
void draw_sphere();

/**
 * Shows texture preview.
 */
void show_texture_preview(Scene* scene);

#endif /* SCENE_H */