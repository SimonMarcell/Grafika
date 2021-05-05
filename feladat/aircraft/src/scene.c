#include "scene.h"
#include "obj/load.h"
#include "obj/draw.h"

#include <GL/glut.h>

void init_scene(Scene *scene)
{
    load_model(&scene->aircraft.model, "models/aircraft.obj");
    set_rotation(&scene->aircraft, -90, -90, 0);
    set_position(&scene->aircraft, 0, 0, 0);
    scene->aircraft.texture_id = load_texture("models/aircraft.jpg"); 
}

void draw_scene(const Scene *scene)
{
    int i, j, k;
    draw_object(&scene->aircraft);
    draw_origin();
    /*

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
*/
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