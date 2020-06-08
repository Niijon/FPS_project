

#include "MazeExplorer.h"
#include "MapBlocks.h"
#include "CameraComponent.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

vec3d MultiplyByConstant(vec3d toMultiply,float multiplier){
    toMultiply.x *= multiplier;
    toMultiply.y *= multiplier;
    toMultiply.z *= multiplier;
    return toMultiply;
}
float MultiplyVectors(const vec3d &v1, const vec3d &v2){
    return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z;
}


void SetupLights(){
    GLfloat light_position[] = { 2.0, 0.0, 2.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };


    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );

    GLfloat global_ambient[] = {0.3, 0.3, 0.3, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_NORMALIZE) ;
}

void SetView(int width, int height){
    //const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,16.0/9.0,1,75);
}



void GameLoop(){
    sf::Window window(sf::VideoMode(16*100, 9*100), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    Floor floor_;
    Camera Cam;
    //Cam.SetView();
    // activate the window
    window.setActive(true);

    SetView(window.getSize().x, window.getSize().y);
    Cam.SetView();

    SetupLights();

    bool running = true;

    sf::Clock clk;

    while (running) {
        // handle events
        sf::Event event;
        float deltaT_ = clk.getElapsedTime().asSeconds() * 90;
        clk.restart();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            } else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                SetView(event.size.width, event.size.height);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                Cam.StrafeLeft(deltaT_);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                Cam.StrafeRight(deltaT_);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                Cam.MoveForward(deltaT_);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                Cam.MoveBackwards(deltaT_);
            }
        }


        Cam.UpdateCam();
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        // draw stuff
        glPushMatrix();



        // TODO
        // test functions below (glTranslated, glRotated, glColor3d)
        // what happens when you change their arguments?
        // does their order change the result?

        floor_.Draw();

        glPopMatrix();

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
}





