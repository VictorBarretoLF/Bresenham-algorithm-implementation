#define GL_SILENCE_DEPRECATION
#include "main.h"
#include "mygl.h"
//#include "mygl.cpp"

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // Inicializações.
    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;
    
    int middleX = (int)(IMAGE_WIDTH / 2); // 256
    int middleY = (int)(IMAGE_WIDTH / 2); // 256
    
    DrawTriangle(middleX, middleY / 2, middleX / 2, middleY + (middleY / 2), middleX + (middleX / 2), middleY + (middleY / 2),
        255, 0, 0);


    // Framebuffer scan loop.
    glutMainLoop();
    


    return 0;
}

//// https://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/ link to work on macbook
//// https://www.youtube.com/watch?v=-e3k3Jiq2Wk&ab_channel=stella-vir link that help-me find the things
