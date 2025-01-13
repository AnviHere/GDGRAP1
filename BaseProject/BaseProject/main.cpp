#include <GLFW/glfw3.h>
#include <math.h>

static float to_radians(float input) {
    return (float) input * 3.14159f / 180.0f;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Ivan James Penas", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* The octagon fits perfectly inside a circle with the radius below.
       Adjust the radius below to resize the octagon. */
    float radius = 1.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* - The octagon is made of 8 triangles with an interior angle of 45 degrees each. 
           - Its in an interval of 22.5 degrees so the up, down, left, and right sides are
           flat. */

        for (int i = 0; i < 8; i++) {
            glBegin(GL_TRIANGLES);
            //The first point of the triangle is always at the center of the triangle
            glVertex2f(0.0f, 0.0f);
            //This uses the polar to cartesian coordinates you thought in GD-MATH sir hehe.
            glVertex2f(radius * cos(to_radians(-22.5 + (45 * i))), radius * sin(to_radians(-22.5 + (45 * i))));
            glVertex2f(radius * cos(to_radians(22.5 + (45 * i))), radius * sin(to_radians(22.5 + (45 * i))));
            glEnd();
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
