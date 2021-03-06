#include "callbacks.h"
#include <math.h>

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    set_view(&camera);
    draw_scene(&scene);

    glPopMatrix();
    if (is_preview_visible) {
        show_texture_preview(&scene);
    }
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)width * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)height / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, (GLdouble)width / (GLdouble)height, 0.01, 10000.0);
}

void motion(int x, int y)
{
    // rotate_camera(&camera, x, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    const double speed = 3.0;

    switch (key) {
    case 'w':
        set_object_position_xspeed(&scene.aircraft, speed);
        break;
    case 's':
        set_object_position_xspeed(&scene.aircraft, -speed);
        break;
    case 'a':
        set_object_rotation_speed(&scene.aircraft, 0, 30*speed, 0);
        break;
    case 'd':
        set_object_rotation_speed(&scene.aircraft, 0, -30*speed, 0);
        break;
    case 'q':
        set_object_position_yspeed(&scene.aircraft, speed);
        break;
    case 'e':
        set_object_position_yspeed(&scene.aircraft, -speed);
        break;
    case 'r':
        set_object_position_zspeed(&scene.aircraft, speed);
        break;
    case 'c':
        set_object_position_zspeed(&scene.aircraft, -speed);
        break;
    case 'u':
        set_camera_position_zspeed(&camera, speed);
        break;
    case 'i':
        set_camera_position_zspeed(&camera, -speed);
        break;
    case 'j':
        set_camera_position_xspeed(&camera, speed);
        break;
    case 'k':
        set_camera_position_xspeed(&camera, -speed);
        break;
    case 'l':
        lock_camera(&camera);
        break;
    case '+':
        change_lighting(&scene, 0.1);
        break;
    case '-':
        change_lighting(&scene, -0.1);
        break;
    case 'f':
        change_fog_density(&scene, 0.01);
        break;
    case 'g':
        change_fog_density(&scene, -0.01);
        break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
    float position;
    const double speed = 1.0;

    switch (key) {
    case 'w':
    case 's':
        set_object_position_xspeed(&scene.aircraft, 0);
        break;
    case 'a':
    case 'd':
        set_object_rotation_speed(&scene.aircraft, 0, 0, 0);
        break;
    case 'q':
    case 'e':
        set_object_position_yspeed(&scene.aircraft, 0);
        break;
    case 'r':
    case 'c':
        set_object_position_zspeed(&scene.aircraft, 0);
        break;
    case 'u':
    case 'i':
        set_camera_position_zspeed(&camera, 0);
        break;
    case 'j':
    case 'k':
        set_camera_position_xspeed(&camera, 0);
        break;
    }

    glutPostRedisplay();
}

void ProcessSpecialKeys(unsigned char key, int x, int y)
{
    const double speed = 3.0;

    switch (key) {
    case GLUT_KEY_UP:
        set_camera_position_yspeed(&camera, speed);
        break;
    case GLUT_KEY_DOWN:
        set_camera_position_yspeed(&camera, -speed);
        break;
    case GLUT_KEY_LEFT:
        set_camera_rotation_speed(&camera, 0, 0, 30*speed);
        break;
    case GLUT_KEY_RIGHT:
        set_camera_rotation_speed(&camera, 0, 0, -30*speed);
        break;
    case GLUT_KEY_F1:
        if (is_preview_visible) {
            is_preview_visible = FALSE;
        }
        else {
            is_preview_visible = TRUE;
        }
        break;
    }

    glutPostRedisplay();
}

void ReleaseSpecialKeys(unsigned char key, int x, int y)
{
    const float speed = 1.0;

    switch (key) {
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
        set_camera_position_yspeed(&camera, 0.0);
        break;
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
        set_camera_rotation_speed(&camera, 0, 0, 0);
        break;
    }

    glutPostRedisplay();
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_camera(&camera, elapsed_time);
    update_scene(&scene, elapsed_time);
    move_camera_behind_object(&camera, &scene.aircraft);

    glutPostRedisplay();
}