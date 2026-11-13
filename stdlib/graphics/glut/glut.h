#ifndef CORIN_STDLIB_GLUT_H
#define CORIN_STDLIB_GLUT_H

#include <GL/glut.h>
#include <string>

namespace corin {
namespace stdlib {
namespace graphics {

/**
 * GLUT Graphics Library for Corin
 * 
 * Provides GLUT (OpenGL Utility Toolkit) for 3D graphics and window management.
 * Use this for quick 3D prototypes and visualizations.
 */

class GLUT {
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
    
    // Window management
    static void set_window(int win);
    static int get_window();
    static void set_window_title(const char* title);
    static void set_icon_title(const char* title);
    static void position_window(int x, int y);
    static void reshape_window(int width, int height);
    static void full_screen();
    static void pop_window();
    static void push_window();
    static void show_window();
    static void hide_window();
    static void iconify_window();
    static void destroy_window(int win);
    
    // Rendering
    static void swap_buffers();
    
    // 3D Shapes - Solid
    static void solid_sphere(double radius, int slices, int stacks);
    static void solid_cube(double size);
    static void solid_cone(double base, double height, int slices, int stacks);
    static void solid_torus(double inner_radius, double outer_radius, int sides, int rings);
    static void solid_teapot(double size);
    static void solid_octahedron();
    static void solid_dodecahedron();
    static void solid_icosahedron();
    static void solid_tetrahedron();
    
    // 3D Shapes - Wireframe
    static void wire_sphere(double radius, int slices, int stacks);
    static void wire_cube(double size);
    static void wire_cone(double base, double height, int slices, int stacks);
    static void wire_torus(double inner_radius, double outer_radius, int sides, int rings);
    static void wire_teapot(double size);
    static void wire_octahedron();
    static void wire_dodecahedron();
    static void wire_icosahedron();
    static void wire_tetrahedron();
    
    // Timing
    static int get_time();
};

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API for Corin code generation
extern "C" {
    // Initialization
    void corin_glut_init();
    void corin_glut_init_display_mode(unsigned int mode);
    void corin_glut_init_window_size(int width, int height);
    void corin_glut_init_window_position(int x, int y);
    int corin_glut_create_window(const char* title);
    
    // Main loop
    void corin_glut_main_loop();
    void corin_glut_post_redisplay();
    
    // Window management
    void corin_glut_set_window(int win);
    int corin_glut_get_window();
    void corin_glut_set_window_title(const char* title);
    void corin_glut_set_icon_title(const char* title);
    void corin_glut_position_window(int x, int y);
    void corin_glut_reshape_window(int width, int height);
    void corin_glut_full_screen();
    void corin_glut_pop_window();
    void corin_glut_push_window();
    void corin_glut_show_window();
    void corin_glut_hide_window();
    void corin_glut_iconify_window();
    void corin_glut_destroy_window(int win);
    
    // Rendering
    void corin_glut_swap_buffers();
    
    // 3D Shapes - Solid
    void corin_glut_solid_sphere(double radius, int slices, int stacks);
    void corin_glut_solid_cube(double size);
    void corin_glut_solid_cone(double base, double height, int slices, int stacks);
    void corin_glut_solid_torus(double inner_radius, double outer_radius, int sides, int rings);
    void corin_glut_solid_teapot(double size);
    void corin_glut_solid_octahedron();
    void corin_glut_solid_dodecahedron();
    void corin_glut_solid_icosahedron();
    void corin_glut_solid_tetrahedron();
    
    // 3D Shapes - Wireframe
    void corin_glut_wire_sphere(double radius, int slices, int stacks);
    void corin_glut_wire_cube(double size);
    void corin_glut_wire_cone(double base, double height, int slices, int stacks);
    void corin_glut_wire_torus(double inner_radius, double outer_radius, int sides, int rings);
    void corin_glut_wire_teapot(double size);
    void corin_glut_wire_octahedron();
    void corin_glut_wire_dodecahedron();
    void corin_glut_wire_icosahedron();
    void corin_glut_wire_tetrahedron();
    
    // Timing
    int corin_glut_get_time();
}

#endif // CORIN_STDLIB_GLUT_H
