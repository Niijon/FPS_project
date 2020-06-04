

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

vec3d mat3::GetColumn1()
{

}

vec3d mat3::GetColumn2()
{

}

vec3d mat3::GetColumn3()
{

}

mat3::mat3(float x1_, float x2_, float x3_, float x4_, float x5_, float x6_, float x7_, float x8_, float x9_){
    x1=x1_;
    x2=x2_;
    x3=x3_;
    x4=x4_;
    x5=x5_;
    x6=x6_;
    x7=x7_;
    x8=x8_;
    x9=x9_;
}

mat3::mat3(vec3d row1, vec3d row2, vec3d row3){
    x1 = row1.x;
    x2 = row1.y;
    x3 = row1.z;
    x4 = row2.x;
    x5 = row2.y;
    x6 = row2.z;
    x7 = row3.x;
    x8 = row3.y;
    x9 = row3.z;
}

mat3 mat3::MultiplyMatrix(mat3 Mult_){
    float x1_ = x1*Mult_.x1 + x2 * Mult_.x4+ x3 * Mult_.x7;
    float x2_ = x1 * Mult_.x2 + x2 * Mult_.x5 + x3 * Mult_.x8;
    float x3_ = x1 * Mult_.x3 + x2 * Mult_.x6 + x3 * Mult_.x9;
    return mat3(x1_, x2_, x3_);
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
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluLookAt(10.0, 1.0, 10.0, // Camera pos
              0.0, 0.0, 0.0, // Camera target
              0.0, 1.0, 0.0); // Up camera translation
}



void GameLoop(){
    sf::Window window(sf::VideoMode(1024, 768), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    Floor floor_;
    Camera Cam;
    glVertex3f(3.0,2.0,1.0);
    //Cam.SetView();
    // activate the window
    window.setActive(true);

    SetView(window.getSize().x, window.getSize().y);

    SetupLights();

    bool running = true;

    sf::Clock clk;


    while (running) {
        // handle events
        sf::Event event;
        vec2d Dir_;
        while (window.pollEvent(event)) {
            Dir_.x = 0;
            Dir_.z = 0;
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            } else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                SetView(event.size.width, event.size.height);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                Dir_.x = -1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                Dir_.x = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                Dir_.z = 1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                Dir_.z = -1;
            }

        }
        float deltaT_ = clk.getElapsedTime().asSeconds() * 90;
        Cam.MoveCam(Dir_,deltaT_);
        Cam.SetView();
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





