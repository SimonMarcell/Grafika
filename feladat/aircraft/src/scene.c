#include "scene.h"
#include "obj/load.h"
#include "obj/draw.h"
#include "stdlib.h"
#include <GL/glut.h>

void init_scene(Scene *scene)
{
    load_model(&scene->aircraft.model, "models/aircraft.obj");
    set_rotation(&scene->aircraft, 90, -90, 0);
    set_position(&scene->aircraft, 0, 0, 3);
    scene->aircraft.texture_id = load_texture("models/aircraft.jpg"); 
    set_object_position_xspeed(&scene->aircraft, 0);
    set_object_position_yspeed(&scene->aircraft, 0);
    set_object_position_zspeed(&scene->aircraft, 0);
    set_object_rotation_speed(&scene->aircraft, 0, 0, 0);

    load_model(&scene->landscape.model, "models/landscape.obj");
    set_rotation(&scene->landscape, 90, -90, 0);
    scene->landscape.texture_id = load_texture("models/landscape.jpg");

    load_model(&scene->water.model, "models/water.obj");
    set_rotation(&scene->water, 90, -90, 0);
    scene->water.texture_id = load_texture("models/water.jpg");

    scene->helpmenu.texture_id = load_texture("models/helpmenu.jpg");
    
    scene->fog_density = 0.0;

    init_skybox(&scene->skybox);

    scene->leftlight.position.x = 0.63f;
    scene->leftlight.position.y = -2.0f;
    scene->leftlight.position.z = 3.5f;
    scene->leftlight.colour.x = 0.7;
    scene->leftlight.colour.y = 0.1;
    scene->leftlight.colour.z = 0.3;
}

void set_lighting(GLuint lightindex, Light* light){
    // float ambient_light[] = { light.ambientcolour.x, light.ambientcolour.y, light.ambientcolour.z, 1.0f };
    // float diffuse_light[] = { lighting, lighting, lighting, 1.0f };
    // float specular_light[] = { lighting, lighting, lighting, 1.0f };
    // float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(lightindex, GL_AMBIENT, &light->ambientcolour);
    glLightfv(lightindex, GL_DIFFUSE, &light->colour);
    glLightfv(lightindex, GL_SPECULAR, &light->colour);
    glLightfv(lightindex, GL_POSITION, &light->position);
}

void change_lighting(Scene *scene, float change){
    scene->ambientlight.ambientcolour.x += change;
    scene->ambientlight.ambientcolour.y += change;
    scene->ambientlight.ambientcolour.z += change;
    if (scene->ambientlight.ambientcolour.x < 0) {
        scene->ambientlight.ambientcolour.x = 0;
        scene->ambientlight.ambientcolour.y = 0;
        scene->ambientlight.ambientcolour.z = 0;
    }
    if (scene->ambientlight.ambientcolour.x > 1) {
        scene->ambientlight.ambientcolour.x = 1;
        scene->ambientlight.ambientcolour.y = 1;
        scene->ambientlight.ambientcolour.z = 1;
    }
}

void draw_scene(const Scene *scene)
{
    glEnable(GL_LIGHT1);
    draw_object(&scene->aircraft);
    glDisable(GL_LIGHT1);
    draw_object(&scene->landscape);
    draw_object(&scene->water);
    draw_skybox(&scene->skybox);
    draw_sphere(-2.0f, 0.63f, 3.5f);
    draw_sphere(-2.0f, -0.63f, 3.5f);
    if(scene->fog_density>0){
        draw_fog(scene->fog_density);
    }
    else
    {
        remove_fog();
    }
    
    printf("object z position: %f\n", scene->aircraft.position.z);
    printf("camera z position: %f\n", scene->camera.position.z);
    // printf("object y rotation: %f\n", scene->aircraft.rotation.y + 90.0);
    //printf("fog density: %f\n", scene->fog_density);

}

void update_scene(Scene* scene, double time){
    update_object(&scene->aircraft, time);
    move_camera_behind_object(&scene->camera, &scene->aircraft);
    set_lighting(GL_LIGHT0, &scene->ambientlight);
    set_lighting(GL_LIGHT1, &scene->leftlight);
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_sphere(float x, float y, float z)
{
    glPushMatrix();
    glColor3f(0.7f, 0.1f, 0.1f);
    glTranslatef(x, y, z);
    glutSolidSphere(0.1, 8, 8);
    glPopMatrix();
}

void show_texture_preview(Scene* scene)
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, scene->helpmenu.texture_id);

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void draw_fog(float density){

        GLfloat color1[3] = {0.35, 0.2, 0.05};

        glEnable(GL_FOG);
        glFogi(GL_FOG_MODE, GL_EXP2);
        glFogfv(GL_FOG_COLOR, color1);
        glFogf(GL_FOG_DENSITY, density);
        glHint(GL_FOG_HINT, GL_NICEST);
 }

void remove_fog(){
    glDisable(GL_FOG);
 }

void change_fog_density(Scene *scene, float change){
    scene->fog_density += change;
    if (scene->fog_density < 0) {
        scene->fog_density = 0;
    }
    if (scene->fog_density > 0.1) {
        scene->fog_density = 0.1;
    }
}

void move_camera_behind_object(Camera* camera, Object* object){
    double angle;
    angle = degree_to_radian(object->rotation.y + 90.0);

    camera->rotation.x = object->rotation.x - 90;
    camera->rotation.y = object->rotation.z;
    camera->rotation.z = object->rotation.y + 90;
    camera->position.x = object->position.x - 10*cos(angle);
    camera->position.y = object->position.y - 10*sin(angle);
    camera->position.z = object->position.z + 2;
}