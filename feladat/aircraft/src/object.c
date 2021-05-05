#include "object.h"
#include <GL/glut.h>

void draw_object(const Object* object){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotatef(object->rotation.x + 90, 1.0, 0, 0);
    glRotatef(object->rotation.y, 0, 1.0, 0);
    glRotatef(object->rotation.z - 90, 0, 0, 1.0);
    glTranslatef(object->position.x, object->position.y, object->position.z);
    glBindTexture(GL_TEXTURE_2D, object->texture_id);
    glColor3f(1, 1, 1);
    draw_model(&object->model);
    glPopMatrix();
}

void set_position(Object* object,  float x, float y, float z){
    object->position.x = x;
    object->position.y = y;
    object->position.z = z;
}

void set_rotation(Object* object, float x, float y, float z){
    object->rotation.x = x;
    object->rotation.y = y;
    object->rotation.z = z;
}

void translate(Object* object, float x, float y, float z){
    object->position.x += x;
    object->position.y += y;
    object->position.z += z;
}

void rotate(Object* object, float x, float y, float z){
    object->rotation.x += x;
    object->rotation.y += y;
    object->rotation.z += z;
}