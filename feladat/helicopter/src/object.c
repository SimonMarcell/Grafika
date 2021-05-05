#include "object.h"
#include <GL/glut.h>

void draw_object(Object* object){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotatef(object->rotation.x + 90, 1.0, 0, 0);
    glRotatef(object->rotation.z - 90, 0, 0, 1.0);
    glRotatef(object->rotation.y, 0, 1.0, 0);
    glTranslatef(object->position.x, object->position.y, object->position.z);
    draw_model(&object->model);
    glPopMatrix();
}

void set_position(Object* object,  float x, float y, float z){
    object->position.x = x;
    object->position.y = y;
    object->position.z = z;
}

void set_rotation( Object* object, float x, float y, float z){
    object->rotation.x = x;
    object->rotation.y = y;
    object->rotation.z = z;
}

