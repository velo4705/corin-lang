#include "glut.h"

namespace corin {
namespace stdlib {
namespace graphics {

void GLUT::init(int* argc, char** argv) {
    glutInit(argc, argv);
}

void GLUT::init_display_mode(unsigned int mode) {
    glutInitDisplayMode(mode);
}

void GLUT::init_window_size(int width, int height) {
    glutInitWindowSize(width, height);
}

void GLUT::init_window_position(int x, int y) {
    glutInitWindowPosition(x, y);
}

int GLUT::create_window(const char* title) {
    return glutCreateWindow(title);
}

void GLUT::main_loop() {
    glutMainLoop();
}

void GLUT::post_redisplay() {
    glutPostRedisplay();
}

void GLUT::set_window(int win) {
    glutSetWindow(win);
}

int GLUT::get_window() {
    return glutGetWindow();
}

void GLUT::set_window_title(const char* title) {
    glutSetWindowTitle(title);
}

void GLUT::set_icon_title(const char* title) {
    glutSetIconTitle(title);
}

void GLUT::position_window(int x, int y) {
    glutPositionWindow(x, y);
}

void GLUT::reshape_window(int width, int height) {
    glutReshapeWindow(width, height);
}

void GLUT::full_screen() {
    glutFullScreen();
}

void GLUT::pop_window() {
    glutPopWindow();
}

void GLUT::push_window() {
    glutPushWindow();
}

void GLUT::show_window() {
    glutShowWindow();
}

void GLUT::hide_window() {
    glutHideWindow();
}

void GLUT::iconify_window() {
    glutIconifyWindow();
}

void GLUT::destroy_window(int win) {
    glutDestroyWindow(win);
}

void GLUT::swap_buffers() {
    glutSwapBuffers();
}

void GLUT::solid_sphere(double radius, int slices, int stacks) {
    glutSolidSphere(radius, slices, stacks);
}

void GLUT::solid_cube(double size) {
    glutSolidCube(size);
}

void GLUT::solid_cone(double base, double height, int slices, int stacks) {
    glutSolidCone(base, height, slices, stacks);
}

void GLUT::solid_torus(double inner_radius, double outer_radius, int sides, int rings) {
    glutSolidTorus(inner_radius, outer_radius, sides, rings);
}

void GLUT::solid_teapot(double size) {
    glutSolidTeapot(size);
}

void GLUT::solid_octahedron() {
    glutSolidOctahedron();
}

void GLUT::solid_dodecahedron() {
    glutSolidDodecahedron();
}

void GLUT::solid_icosahedron() {
    glutSolidIcosahedron();
}

void GLUT::solid_tetrahedron() {
    glutSolidTetrahedron();
}

void GLUT::wire_sphere(double radius, int slices, int stacks) {
    glutWireSphere(radius, slices, stacks);
}

void GLUT::wire_cube(double size) {
    glutWireCube(size);
}

void GLUT::wire_cone(double base, double height, int slices, int stacks) {
    glutWireCone(base, height, slices, stacks);
}

void GLUT::wire_torus(double inner_radius, double outer_radius, int sides, int rings) {
    glutWireTorus(inner_radius, outer_radius, sides, rings);
}

void GLUT::wire_teapot(double size) {
    glutWireTeapot(size);
}

void GLUT::wire_octahedron() {
    glutWireOctahedron();
}

void GLUT::wire_dodecahedron() {
    glutWireDodecahedron();
}

void GLUT::wire_icosahedron() {
    glutWireIcosahedron();
}

void GLUT::wire_tetrahedron() {
    glutWireTetrahedron();
}

int GLUT::get_time() {
    return glutGet(GLUT_ELAPSED_TIME);
}

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API implementations
extern "C" {
    void corin_glut_init() {
        int argc = 0;
        char* argv[] = {nullptr};
        corin::stdlib::graphics::GLUT::init(&argc, argv);
    }
    
    void corin_glut_init_display_mode(unsigned int mode) {
        corin::stdlib::graphics::GLUT::init_display_mode(mode);
    }
    
    void corin_glut_init_window_size(int width, int height) {
        corin::stdlib::graphics::GLUT::init_window_size(width, height);
    }
    
    void corin_glut_init_window_position(int x, int y) {
        corin::stdlib::graphics::GLUT::init_window_position(x, y);
    }
    
    int corin_glut_create_window(const char* title) {
        return corin::stdlib::graphics::GLUT::create_window(title);
    }
    
    void corin_glut_main_loop() {
        corin::stdlib::graphics::GLUT::main_loop();
    }
    
    void corin_glut_post_redisplay() {
        corin::stdlib::graphics::GLUT::post_redisplay();
    }
    
    void corin_glut_set_window(int win) {
        corin::stdlib::graphics::GLUT::set_window(win);
    }
    
    int corin_glut_get_window() {
        return corin::stdlib::graphics::GLUT::get_window();
    }
    
    void corin_glut_set_window_title(const char* title) {
        corin::stdlib::graphics::GLUT::set_window_title(title);
    }
    
    void corin_glut_set_icon_title(const char* title) {
        corin::stdlib::graphics::GLUT::set_icon_title(title);
    }
    
    void corin_glut_position_window(int x, int y) {
        corin::stdlib::graphics::GLUT::position_window(x, y);
    }
    
    void corin_glut_reshape_window(int width, int height) {
        corin::stdlib::graphics::GLUT::reshape_window(width, height);
    }
    
    void corin_glut_full_screen() {
        corin::stdlib::graphics::GLUT::full_screen();
    }
    
    void corin_glut_pop_window() {
        corin::stdlib::graphics::GLUT::pop_window();
    }
    
    void corin_glut_push_window() {
        corin::stdlib::graphics::GLUT::push_window();
    }
    
    void corin_glut_show_window() {
        corin::stdlib::graphics::GLUT::show_window();
    }
    
    void corin_glut_hide_window() {
        corin::stdlib::graphics::GLUT::hide_window();
    }
    
    void corin_glut_iconify_window() {
        corin::stdlib::graphics::GLUT::iconify_window();
    }
    
    void corin_glut_destroy_window(int win) {
        corin::stdlib::graphics::GLUT::destroy_window(win);
    }
    
    void corin_glut_swap_buffers() {
        corin::stdlib::graphics::GLUT::swap_buffers();
    }
    
    void corin_glut_solid_sphere(double radius, int slices, int stacks) {
        corin::stdlib::graphics::GLUT::solid_sphere(radius, slices, stacks);
    }
    
    void corin_glut_solid_cube(double size) {
        corin::stdlib::graphics::GLUT::solid_cube(size);
    }
    
    void corin_glut_solid_cone(double base, double height, int slices, int stacks) {
        corin::stdlib::graphics::GLUT::solid_cone(base, height, slices, stacks);
    }
    
    void corin_glut_solid_torus(double inner_radius, double outer_radius, int sides, int rings) {
        corin::stdlib::graphics::GLUT::solid_torus(inner_radius, outer_radius, sides, rings);
    }
    
    void corin_glut_solid_teapot(double size) {
        corin::stdlib::graphics::GLUT::solid_teapot(size);
    }
    
    void corin_glut_solid_octahedron() {
        corin::stdlib::graphics::GLUT::solid_octahedron();
    }
    
    void corin_glut_solid_dodecahedron() {
        corin::stdlib::graphics::GLUT::solid_dodecahedron();
    }
    
    void corin_glut_solid_icosahedron() {
        corin::stdlib::graphics::GLUT::solid_icosahedron();
    }
    
    void corin_glut_solid_tetrahedron() {
        corin::stdlib::graphics::GLUT::solid_tetrahedron();
    }
    
    void corin_glut_wire_sphere(double radius, int slices, int stacks) {
        corin::stdlib::graphics::GLUT::wire_sphere(radius, slices, stacks);
    }
    
    void corin_glut_wire_cube(double size) {
        corin::stdlib::graphics::GLUT::wire_cube(size);
    }
    
    void corin_glut_wire_cone(double base, double height, int slices, int stacks) {
        corin::stdlib::graphics::GLUT::wire_cone(base, height, slices, stacks);
    }
    
    void corin_glut_wire_torus(double inner_radius, double outer_radius, int sides, int rings) {
        corin::stdlib::graphics::GLUT::wire_torus(inner_radius, outer_radius, sides, rings);
    }
    
    void corin_glut_wire_teapot(double size) {
        corin::stdlib::graphics::GLUT::wire_teapot(size);
    }
    
    void corin_glut_wire_octahedron() {
        corin::stdlib::graphics::GLUT::wire_octahedron();
    }
    
    void corin_glut_wire_dodecahedron() {
        corin::stdlib::graphics::GLUT::wire_dodecahedron();
    }
    
    void corin_glut_wire_icosahedron() {
        corin::stdlib::graphics::GLUT::wire_icosahedron();
    }
    
    void corin_glut_wire_tetrahedron() {
        corin::stdlib::graphics::GLUT::wire_tetrahedron();
    }
    
    int corin_glut_get_time() {
        return corin::stdlib::graphics::GLUT::get_time();
    }
}
