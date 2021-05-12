#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "object.h"
#include "skybox.h"

typedef struct Scene
{
    Object aircraft;
    Object landscape;
    Object water;
    Object moon;
    Object helpmenu;
    float lighting;
    float fog_density;
    Skybox skybox;
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

void move_camera_behind_object(Camera* camera, Object* object);

void draw_fog(float density);

void remove_fog();

void change_fog_density(Scene *scene, float change);

#endif /* SCENE_H */