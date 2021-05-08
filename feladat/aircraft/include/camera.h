#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"
#include "math.h"

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 position_speed;
    vec3 rotation_speed;
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Is the texture preview visible?
 */
int is_preview_visible;

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

/**
 * Set the speed of lifting up and down motion.
 */
void set_camera_vertical_speed(Camera* camera, double speed);

void translate_camera(Camera* camera, float x, float y, float z);

void set_camera_position_xspeed(Camera* camera, double x_speed);

void set_camera_position_yspeed(Camera* camera, double y_speed);

void set_camera_position_zspeed(Camera* camera, double z_speed);

void rotate_camera(Camera* camera, float x, float y, float z);

void set_camera_rotation_speed(Camera* camera, double x_speed, double y_speed, double z_speed);

void move_camera_to_aircraft(Camera* camera);

void move_camera_from_aircraft(Camera* camera);

#endif /* CAMERA_H */