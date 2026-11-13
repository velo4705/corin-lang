#ifndef CORIN_STDLIB_GLUT_H
#define CORIN_STDLIB_GLUT_H

#include <GL/glut.h>

namespace corin {
namespace stdlib {
namespace graphics {

/**
 * GLUT (OpenGL Utility Toolkit) Support
 * 
 * Provides easy window management and event handling for OpenGL applications.
 * GLUT is simpler than SDL2 for pure OpenGL applications.
 */

class GLUTContext {
public:
    // Initialization
    static void init(int* argc, char** argv);
    static void init_display_mode(unsigned int mode);
    static void init_window_size(int width, int height);
    static void init_window_position(int x, int y);
    static int create_window(const char* title);
    
    // Main loop
    static void main_loop();
    static void post_redisplay();
    
    // Callbacks (set function pointers)
    static void display_func(void (*func)());
    static void reshape_func(void (*func)(int, int));
    static void keyboard_func(void (*func)(unsigned char, int, int));
    static void mouse_func(void (*func)(int, int, int, int));
    static void motion_func(void (*func)(int, int));
    static void idle_func(void (*func)());
    static void timer_func(unsigned int msecs, void (*func)(int), int value);
    
    // Window management
    static void swap_buffers();
    static void set_window(int win);
    static int get_window();
    
    // Utility
    static void solid_sphere(double radius, int slices, int stacks);
    static void wire_sphere(double radius, int slices, int stacks);
    static void solid_cube(double size);
    static void wire_cube(double size);
    static void solid_torus(double innerRadius, double outerRadius, int sides, int rings);
    static void wire_torus(double innerRadius, double outerRadius, int sides, int rings);
};

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API for code generation
extern "C" {
    // Initialization
    void corin_glut_init(int* argc, char** argv);
    void corin_glut_init_display_mode(unsigned int mode);
    void corin_glut_init_window_size(int width, int height);
    void corin_glut_init_window_position(int x, int y);
    int corin_glut_create_window(const char* title);
    
    // Main loop
    void corin_glut_main_loop();
    void corin_glut_post_redisplay();
    
    // Window management
    void corin_glut_swap_buffers();
    
    // Utility shapes
    void corin_glut_solid_sphere(double radius, int slices, int stacks);
    void corin_glut_wire_sphere(double radius, int slices, int stacks);
    void corin_glut_solid_cube(double size);
    void corin_glut_wire_cube(double size);
    void corin_glut_solid_torus(double innerRadius, double outerRadius, int sides, int rings);
    void corin_glut_wire_torus(double innerRadius, double outerRadius, int sides, int rings);
}

// GLUT Constants
#define CORIN_GLUT_RGB 0x0000
#define CORIN_GLUT_RGBA 0x0000
#define CORIN_GLUT_SINGLE 0x0000
#define CORIN_GLUT_DOUBLE 0x0002
#define CORIN_GLUT_DEPTH 0x0010
#define CORIN_GLUT_STENCIL 0x0020
#define CORIN_GLUT_MULTISAMPLE 0x0080

#endif // CORIN_STDLIB_GLUT_H
