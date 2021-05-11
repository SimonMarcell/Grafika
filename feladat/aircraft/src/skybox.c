#include "scene.h"
#include "skybox.h"

#include <GL/glut.h>
#include <SOIL/SOIL.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_skybox(Skybox* skybox)
{
    skybox->skybox_right = load_texture("models/skyboxRight.png");
    skybox->skybox_left = load_texture("models/skyboxLeft.png");
    skybox->skybox_top = load_texture("models/skyboxTop.png");
    skybox->skybox_bottom = load_texture("models/skyboxBottom.png");
    skybox->skybox_back = load_texture("models/skyboxBack.png");
    skybox->skybox_front = load_texture("models/skyboxFront.png");
}

void draw_skybox(Skybox* skybox)
{

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_right);
    glBegin(GL_QUADS);
        glTexCoord2f(1,1);
        glVertex3f(-50.0f, -50.0f, -50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(-50.0f, -50.0f, 50.0f); 

        glTexCoord2f(0,0);
        glVertex3f(50.0f, -50.0f, +50.0f); 

        glTexCoord2f(0,1);
        glVertex3f(50.0f, -50.0f, -50.0f); 
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_left);
    glBegin(GL_QUADS);
        glTexCoord2f(1,1);
        glVertex3f(50.0f, 50.0f, -50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(50.0f, 50.0f, 50.0f); 

        glTexCoord2f(0,0);
        glVertex3f(-50.0f, 50.0f, +50.0f); 

        glTexCoord2f(0,1);
        glVertex3f(-50.0f, 50.0f, -50.0f); 
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_top);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f(-50.0f, 50.0f, 50.0f); 

        glTexCoord2f(0,1);
        glVertex3f(50.0f, 50.0f, 50.0f); 

        glTexCoord2f(1,1);
        glVertex3f(50.0f, -50.0f, 50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(-50.0f, -50.0f, 50.0f); 
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_bottom);
    glBegin(GL_QUADS);
        glTexCoord2f(0,1);
        glVertex3f(-50.0f, 50.0f, -50.0f); 

        glTexCoord2f(0,0);
        glVertex3f(50.0f, 50.0f, -50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(50.0f, -50.0f, -50.0f); 

        glTexCoord2f(1,1);
        glVertex3f(-50.0f, -50.0f, -50.0f); 
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_back);
    glBegin(GL_QUADS);
        glTexCoord2f(0,1);
        glVertex3f(-50.0f, -50.0f, -50.0f); 

        glTexCoord2f(0,0);
        glVertex3f(-50.0f, -50.0f, 50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(-50.0f, 50.0f, +50.0f); 

        glTexCoord2f(1,1);
        glVertex3f(-50.0f, 50.0f, -50.0f); 
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox->skybox_front);
    glBegin(GL_QUADS);
        glTexCoord2f(0,1);
        glVertex3f(50.0f, 50.0f, -50.0f); 

        glTexCoord2f(0,0);
        glVertex3f(50.0f, 50.0f, 50.0f); 

        glTexCoord2f(1,0);
        glVertex3f(50.0f, -50.0f, +50.0f); 

        glTexCoord2f(1,1);
        glVertex3f(50.0f, -50.0f, -50.0f); 
    glEnd();
}