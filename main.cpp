#define GL_SILENCE_DEPRECATION
#include "main.h"
#include "mygl.h"
//#include "mygl.cpp"

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
//    // Inicializações.
    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;


//    // Framebuffer scan loop.
    glutMainLoop();

    return 0;
}



//
//#include <iostream> // Include this for std::cout
//#include <math.h>
//
//#if defined(__APPLE__)
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
//
//// https://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/ link to work on macbook
//// https://www.youtube.com/watch?v=-e3k3Jiq2Wk&ab_channel=stella-vir link that help-me find the things
//
//
//void display() {
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white and opaque
//    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
//
//    glFlush();  // Render now
//}
//
//int main(int argc, char *argv[])
//{
//    glutInit(&argc, argv); // Initialize GLUT
//    glutInitWindowSize(400, 400);   // Set the window's initial width & height
//    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
//    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
//    glutDisplayFunc(display); // Register display callback handler for window re-paint
//    glutMainLoop();           // Enter the infinitely event-processing loop
//    return 0;
//}
//
