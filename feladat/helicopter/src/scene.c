#include "scene.h"

#include <GL/glut.h>

void init_scene(Scene *scene)
{
}

void draw_scene(const Scene *scene)
{
    int i, j, k;
    draw_origin();

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            for (k = 0; k < 6; k++)
            {
                glPushMatrix();
                glTranslatef(i-3, j-3, k-3);
                draw_sphere();
                glPopMatrix();
            }
        }
    }

    glPushMatrix();
    glTranslatef(i, j, k);
    draw_sphere();
    glPopMatrix();
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

    glColor3f(0, 0, 1);
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