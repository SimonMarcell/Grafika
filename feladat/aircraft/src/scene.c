#include "scene.h"
#include "obj/load.h"
#include "obj/draw.h"
#include "stdlib.h"
#include <GL/glut.h>

void init_scene(Scene *scene)
{
    load_model(&scene->aircraft.model, "models/aircraft.obj");
    set_rotation(&scene->aircraft, -90, -90, 0);
    set_position(&scene->aircraft, 0, 3, 0);
    scene->aircraft.texture_id = load_texture("models/aircraft.jpg"); 
    set_object_position_speed(&scene->aircraft, 0, 0, 0);
    set_object_rotation_speed(&scene->aircraft, 0, 0, 0);
    load_model(&scene->landscape.model, "models/landscape.obj");
    set_rotation(&scene->landscape, -90, -90, 0);
    scene->landscape.texture_id = load_texture("models/landscape.jpg");
    load_model(&scene->water.model, "models/water.obj");
    set_rotation(&scene->water, -90, -90, 0);
    scene->water.texture_id = load_texture("models/water.jpg"); 
    scene->helpmenu.texture_id = load_texture("models/helpmenu.jpg");
    
    scene->lighting = 0.5;
}

void set_lighting(const float lighting){
    float ambient_light[] = { lighting, lighting, lighting, 1.0f };
    float diffuse_light[] = { lighting, lighting, lighting, 1.0f };
    float specular_light[] = { lighting, lighting, lighting, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void change_lighting(Scene *scene, float change){
    scene->lighting += change;
    if (scene->lighting < 0) {
        scene->lighting = 0;
    }
    if (scene->lighting > 1) {
        scene->lighting = 1;
    }
}

void draw_scene(const Scene *scene)
{
    int i, j, k;
    draw_object(&scene->aircraft);
    draw_object(&scene->landscape);
    draw_object(&scene->water);
    draw_origin();
    set_lighting(scene->lighting);
    

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            for (k = 0; k < 7; k++)
            {
                glPushMatrix();
                glTranslatef(i-3, j-3, k-3);
                draw_sphere();
                glPopMatrix();
            }
        }
    }

}

void update_scene(Scene* scene, double time){
    update_object(&scene->aircraft, time);
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

void draw_sphere()
{
    glPushMatrix();
    glColor3f(1.0, 0.9, 0.8);
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