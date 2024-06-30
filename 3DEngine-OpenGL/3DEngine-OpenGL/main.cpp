#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "OpenGL/OpenGL.h"

// Callback for window resizing
void updateFramebufferSize(GLFWwindow* window, float fbW, float fbH) {
    glViewport(0, 0, fbW, fbH);
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        glfwSetWindowContentScaleCallback(window, updateFramebufferSize);

        glClear(GL_COLOR_BUFFER_BIT);

        /* Each window has two rendering buffers; a front buffer and a back buffer.
         The front buffer is the one being displayed and the back buffer the one you render to. */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
