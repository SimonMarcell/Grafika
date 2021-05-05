#ifndef OBJECT_H
#define OBJECT_H

#include "utils.h"
#include "obj/model.h"
#include <GL/glut.h>

/**
 * Object structure.
 */
typedef struct Object
{
    vec3 position;
    vec3 rotation;
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
 * Changes object rotation.
 */
void rotate(Object* object, float x, float y, float z);

#endif /* OBJECT_H */