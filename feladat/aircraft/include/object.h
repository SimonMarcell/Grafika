#ifndef OBJECT_H
#define OBJECT_H

#include "utils.h"
#include "obj/model.h"
#include <GL/glut.h>
#include "math.h"

/**
 * Object structure.
 */
typedef struct Object
{
    vec3 position;
    vec3 rotation;
    vec3 position_speed;
    vec3 rotation_speed;
    Model model;
    GLuint texture_id;
} Object;

/**
 * Draw the objects.
 */
void draw_object(const Object* object);

/**
 * Sets object position.
 */
void set_position(Object* object,  float x, float y, float z);

/**
 * Sets object rotation.
 */
void set_rotation(Object* object,  float x, float y, float z);

/**
 * Changes object position.
 */
void translate(Object* object, float x, float y, float z);

/**
 * Changes object position speed.
 */
void set_object_xposition_speed(Object* object, double x_speed);

/**
 * Changes object position speed.
 */
void set_object_yposition_speed(Object* object, double y_speed);

/**
 * Changes object position speed.
 */
void set_object_zposition_speed(Object* object, double z_speed);

/**
 * Changes object rotation.
 */
void rotate(Object* object, float x, float y, float z);

/**
 * Changes object rotation speed.
 */
void set_object_rotation_speed(Object* object, double x_speed, double y_speed, double z_speed);

/**
 * Updates object fields.
 */
void update_object(Object* object, double time);

#endif /* OBJECT_H */