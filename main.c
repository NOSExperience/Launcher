#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;
const char WINDOW_TITLE[] = "NOSExperience";

//
// Global VARIABLES
//
struct _Model{
    GLFWwindow *win;
} _g_model;
static struct _Model *g = &_g_model;
//

//
// Method DECLARATIONS
//
void init_glfw(void);
void create_window(void);
void init_glad(void);
//

int main(int argc, char **argv)
{
    init_glfw();
    create_window();
    init_glad();

    while(1) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(g->win);
    }

    return 0;
}

//
// Method DEFINITIONS
//
void init_glfw(void)
{
    if(!glfwInit()) {
        exit(-1);
    }
}

void create_window(void)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *w = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if(w) {
        g->win = w;
    } else {
        exit(-1);
    }

    glfwMakeContextCurrent(g->win);

    glfwSwapInterval(1);
}

void init_glad(void)
{
    if(!gladLoadGL()) {
        exit(-1);
    }
}
//
