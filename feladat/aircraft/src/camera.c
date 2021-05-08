#include "camera.h"
#include <GL/glut.h>

#include <math.h>

void init_camera(Camera* camera)
{
    camera->position.x = -10;
    camera->position.y = 0.0;
    camera->position.z = 5;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->position_speed.x = 0.0;
    camera->position_speed.y = 0.0;
    camera->position_speed.z = 0.0;
}

void update_camera(Camera* camera, double time)
{    
    double angle;
    double side_angle;
    double third_angle;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);
    third_angle = degree_to_radian(camera->rotation.x);

    camera->position.x += cos(angle) * camera->position_speed.y * time + cos(side_angle) * camera->position_speed.x * time;
    camera->position.y += sin(angle) * camera->position_speed.y * time + sin(side_angle) * camera->position_speed.x * time;
    // camera->position.x += cos(third_angle) * cos(side_angle) * camera->speed.x * time;
    // camera->position.y += cos(third_angle) * sin(side_angle) * camera->speed.x * time;
    camera->position.z += camera->position_speed.z * time;
    rotate_camera(camera, camera->rotation_speed.x * time, camera->rotation_speed.y * time, camera->rotation_speed.z * time);

    printf("camera y position: %f\n", camera->position.y);
}

void move_camera_to_aircraft(Camera* camera){
    double angle;
    double third_angle;
    
    angle = degree_to_radian(camera->rotation.z);
    third_angle = degree_to_radian(camera->rotation.x);

    camera->position.x += cos(third_angle) * cos(angle) * 10;
    camera->position.y += cos(third_angle) * sin(angle) * 10;
}

void move_camera_from_aircraft(Camera* camera){
    double angle;
    double third_angle;
    
    angle = degree_to_radian(camera->rotation.z);
    third_angle = degree_to_radian(camera->rotation.x);

    camera->position.x += -cos(third_angle) * cos(angle) * 10;
    camera->position.y += -cos(third_angle) * sin(angle) * 10;
}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glRotatef(-(camera->rotation.y), 0, 1.0, 0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

// void rotate_camera(Camera* camera, double yaw, double pitch, double roll)
// {
//     camera->rotation.z += yaw;
//     camera->rotation.x += pitch;
//     camera->rotation.y += roll;

//     if (camera->rotation.z < 0) {
//         camera->rotation.z += 360.0;
//     }

//     if (camera->rotation.z > 360.0) {
//         camera->rotation.z -= 360.0;
//     }

//     if (camera->rotation.x < 0) {
//         camera->rotation.x += 360.0;
//     }

//     if (camera->rotation.x > 360.0) {
//         camera->rotation.x -= 360.0;
//     }

//     if (camera->rotation.y < 0) {
//         camera->rotation.y += 360.0;
//     }

//     if (camera->rotation.y > 360.0) {
//         camera->rotation.y -= 360.0;
//     }
// }

// void set_camera_speed(Camera* camera, double speed)
// {
//     camera->speed.y = speed;
// }

// void set_camera_side_speed(Camera* camera, double speed)
// {
//     camera->speed.x = speed;
// }

// void set_camera_vertical_speed(Camera* camera, double speed)
// {
//     camera->speed.z = speed;
// }

void translate_camera(Camera* camera, float x, float y, float z){
    camera->position.x += x;
    camera->position.y += y;
    camera->position.z += z;
}

void set_camera_position_xspeed(Camera* camera, double x_speed){
    camera->position_speed.x = x_speed;
}

void set_camera_position_yspeed(Camera* camera, double y_speed){
    camera->position_speed.y = y_speed;
}

void set_camera_position_zspeed(Camera* camera, double z_speed){
    camera->position_speed.z = z_speed;
}

void rotate_camera(Camera* camera, float x, float y, float z){
    camera->rotation.x += x;
    camera->rotation.y += y;
    camera->rotation.z += z;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }

    if (camera->rotation.y < 0) {
        camera->rotation.y += 360.0;
    }

    if (camera->rotation.y > 360.0) {
        camera->rotation.y -= 360.0;
    }
}

void set_camera_rotation_speed(Camera* camera, double x_speed, double y_speed, double z_speed){
    camera->rotation_speed.x = x_speed;
    camera->rotation_speed.y = y_speed;
    camera->rotation_speed.z = z_speed;
}

void asdasd(Camera* camera, double z_speed, double x_speed){
    camera->position_speed.x = x_speed;
    camera->rotation_speed.z = z_speed;
}