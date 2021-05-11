#include "object.h"
#include "math.h"

void draw_object(const Object* object){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(object->position.x, object->position.y, object->position.z);
    glRotatef(object->rotation.x, 1.0, 0, 0);
    glRotatef(object->rotation.y, 0, 1.0, 0);
    glRotatef(object->rotation.z, 0, 0, 1.0);
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

void translate_object(Object* object, float x, float y, float z){
    object->position.x += x;
    object->position.y += y;
    object->position.z += z;
}

void set_object_position_xspeed(Object* object, double x_speed){
    object->position_speed.x = x_speed;
}

void set_object_position_yspeed(Object* object, double y_speed){
    object->position_speed.y = y_speed;
}

void set_object_position_zspeed(Object* object, double z_speed){
    object->position_speed.z = z_speed;
}

void rotate_object(Object* object, float x, float y, float z){
    object->rotation.x += x;
    object->rotation.y += y;
    object->rotation.z += z;

    if (object->rotation.z < 0) {
        object->rotation.z += 360.0;
    }

    if (object->rotation.z > 360.0) {
        object->rotation.z -= 360.0;
    }

    if (object->rotation.x < 0) {
        object->rotation.x += 360.0;
    }

    if (object->rotation.x > 360.0) {
        object->rotation.x -= 360.0;
    }

    if (object->rotation.y < 0) {
        object->rotation.y += 360.0;
    }

    if (object->rotation.y > 360.0) {
        object->rotation.y -= 360.0;
    }
}

void set_object_rotation_speed(Object* object, double x_speed, double y_speed, double z_speed){
    object->rotation_speed.x = x_speed;
    object->rotation_speed.y = y_speed;
    object->rotation_speed.z = z_speed;
}

void update_object(Object* object, double time){
    double angle;
    double side_angle;

    angle = degree_to_radian(object->rotation.y);
    side_angle = degree_to_radian(object->rotation.y + 90);

    // object->position.x += cos(side_angle) * cos(angle) * object->position_speed.y * time;
    // object->position.y += cos(side_angle) * sin(angle) * object->position_speed.y * time;
    // camera->position.x += cos(third_angle) * cos(side_angle) * camera->speed.x * time;
    // camera->position.y += cos(third_angle) * sin(side_angle) * camera->speed.x * time;
    // object->position.z += object->position_speed.z * time;

    translate_object(object,
        cos(side_angle) * object->position_speed.x * time - cos(angle) * object->position_speed.y * time,
        sin(side_angle) * object->position_speed.x * time - sin(angle) * object->position_speed.y * time,
        object->position_speed.z * time);
    rotate_object(object, object->rotation_speed.x * time, object->rotation_speed.y * time, object->rotation_speed.z * time);
}