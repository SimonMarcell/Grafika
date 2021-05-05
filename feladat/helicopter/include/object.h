#ifndef OBJECT_H
#define OBJECT_H

#include "utils.h"
#include "obj/model.h"

/**
 * Object structure.
 */
typedef struct Object
{
    vec3 position;
    vec3 rotation;
    Model model;
} Object;

/**
 * Draw the objects.
 */
void draw_object(Object* object);

/**
 * Sets object position.
 */
void set_position(Object* object,  float x, float y, float z);

/**
 * Sets object rotation.
 */
void set_rotation(Object* object,  float x, float y, float z);

#endif /* OBJECT_H */