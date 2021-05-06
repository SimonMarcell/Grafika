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

void set_object_position_speed(Object* object, double x_speed, double y_speed, double z_speed){
    object->position_speed.x = x_speed;
    object->position_speed.y = y_speed;
    object->position_speed.z = z_speed;
}

void rotate(Object* object, float x, float y, float z){
    object->rotation.x += x;
    object->rotation.y += y;
    object->rotation.z += z;
}

void set_object_rotation_speed(Object* object, double x_speed, double y_speed, double z_speed){
    object->rotation_speed.x = x_speed;
    object->rotation_speed.y = y_speed;
    object->rotation_speed.z = z_speed;
}

void update_object(Object* object, double time){
    translate(object, object->position_speed.x * time, object->position_speed.y * time, object->position_speed.z * time);
    rotate(object, object->rotation_speed.x * time, object->rotation_speed.y * time, object->rotation_speed.z * time);
}