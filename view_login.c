#include "view_login.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>


// Prototypes
static void set_callbacks(GLFWwindow *win);

// Entry point
ViewExit view_login(GLFWwindow *win)
{
    set_callbacks(win);

    while(1) {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win);

        glfwPollEvents();

        if(glfwWindowShouldClose(win)) {
            return ViewExit_EXIT;
        }
    }
}

// Event Handlers
void on_char(GLFWwindow *win, unsigned codepoint)
{
    // A keyboard key was providing text input

    printf("codepoint: %u\n", codepoint);
}

// Internal Functions
static void set_callbacks(GLFWwindow *win)
{
    glfwSetCharCallback(win, on_char);
}
