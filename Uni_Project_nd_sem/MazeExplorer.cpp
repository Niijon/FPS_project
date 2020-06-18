#include <iostream>

#include "MazeExplorer.h"
#include "MapBlocks.h"
#include "CameraComponent.h"
#include <Maze.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>


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



void GameLoop(int _size){
    Maze maze = Maze(_size);
    std::vector<Wall> wallsV;
    wallsV = maze.generateMaze();
    Vec2d start = maze.getStartPos();
    Vec2d end = maze.getGoalPos();

    sf::Window window(sf::VideoMode(16*80, 9*80), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    Floor floor_(_size);
    Camera Cam;
    vec2d v;
    v.x = start.x;
    v.z = start.y;
    Cam.SetCamPos(v);
    sf::Vector2i CenterPoint = sf::Vector2i(window.getSize().x/2, window.getSize().y/2);

    sf::Mouse Mouse;
    Mouse.setPosition(CenterPoint,window);



//    maze.convertMaze();

    sf::Cursor _Cursor;

    //Cam.SetView();
    // activate the window
    window.setActive(true);
    window.setMouseCursorGrabbed(true);
    window.setMouseCursorVisible(false);


    SetView(window.getSize().x, window.getSize().y);
    Cam.SetView();

    SetupLights();

    bool running = true;

    sf::Vector2i PreviousMousePos = Mouse.getPosition(window);


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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                running = false;
            }

            if(event.type == sf::Event::MouseMoved) {
                sf::Vector2i MousePos = sf::Vector2i(Mouse.getPosition(window).x - PreviousMousePos.x, Mouse.getPosition(window).y - PreviousMousePos.y);
                Cam.RotateCam(MousePos.x, MousePos.y);
                PreviousMousePos = Mouse.getPosition(window);
                if(Mouse.getPosition(window).x == (int)window.getSize().x-1){ Mouse.setPosition(CenterPoint,window); PreviousMousePos = Mouse.getPosition(window);}
                else if(Mouse.getPosition(window).y == (int)window.getSize().y-1) {Mouse.setPosition(CenterPoint,window); PreviousMousePos = Mouse.getPosition(window);}
                else if(Mouse.getPosition(window).y == 0) {Mouse.setPosition(CenterPoint,window); PreviousMousePos = Mouse.getPosition(window);}
                else if(Mouse.getPosition(window).x == 0) {Mouse.setPosition(CenterPoint,window); PreviousMousePos = Mouse.getPosition(window);}
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
        for(auto &el:wallsV){
            el.Draw();
        }

        glPopMatrix();



        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

}





