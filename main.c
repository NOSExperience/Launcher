#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "view_login.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;
const char WINDOW_TITLE[] = "NOSExperience";

//
// Global VARIABLES
//
struct Model {
    GLFWwindow *win;
} _g;
static struct Model *g = &_g;
//

//
// Method DECLARATIONS
//
void init_glfw(void);
void create_window(void);
void center_window(void);
void init_glad(void);
void finish(void);

//
// Event HANDLERS
//
void on_close(GLFWwindow *win);
//


int main(int argc, char **argv)
{
    init_glfw();
    create_window();
    init_glad();

    switch(view_login(g->win)) {
        case ViewExit_EXIT:
            finish();
            break;
        default:
            break;
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

    glfwWindowHint(GLFW_DECORATED, 0);
    glfwWindowHint(GLFW_RESIZABLE, 0);

    GLFWwindow *w = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if(w) {
        g->win = w;
    } else {
        exit(-1);
    }

    glfwMakeContextCurrent(g->win);

    glfwSwapInterval(1);

    glfwSetWindowCloseCallback(g->win, on_close);

    center_window();
}

void center_window(void)
{

}

void init_glad(void)
{
    if(!gladLoadGL()) {
        exit(-1);
    }
}

void finish(void)
{
    glfwTerminate();
    exit(0);
}
//

//
// **APP WIDE** EVENT HANDLERS
//

void on_close(GLFWwindow *win)
{
    printf("Seeya!");
}
