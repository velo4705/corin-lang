#ifndef CORIN_STDLIB_OPENGL_H
#define CORIN_STDLIB_OPENGL_H

#include <GL/gl.h>
#include <GL/glu.h>

namespace corin {
namespace stdlib {
namespace graphics {

/**
 * OpenGL Graphics Support
 * 
 * Provides OpenGL 3D graphics capabilities for Corin.
 * Use with SDL2 or GLUT for window management.
 */

class OpenGLContext {
public:
    // Initialize OpenGL context
    static bool init();
    
    // Set viewport
    static void viewport(int x, int y, int width, int height);
    
    // Clear buffers
    static void clear_color(float r, float g, float b, float a);
    static void clear(unsigned int mask);
    
    // Matrix operations
    static void matrix_mode(unsigned int mode);
    static void load_identity();
    static void ortho(double left, double right, double bottom, double top, double near, double far);
    static void perspective(double fovy, double aspect, double near, double far);
    
    // Transformations
    static void translate(float x, float y, float z);
    static void rotate(float angle, float x, float y, float z);
    static void scale(float x, float y, float z);
    
    // Drawing
    static void begin(unsigned int mode);
    static void end();
    static void vertex2f(float x, float y);
    static void vertex3f(float x, float y, float z);
    static void color3f(float r, float g, float b);
    static void color4f(float r, float g, float b, float a);
    
    // Enable/Disable features
    static void enable(unsigned int cap);
    static void disable(unsigned int cap);
    
    // Depth testing
    static void depth_func(unsigned int func);
    
    // Blending
    static void blend_func(unsigned int sfactor, unsigned int dfactor);
};

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API for code generation
extern "C" {
    // Initialization
    bool corin_gl_init();
    
    // Viewport and clearing
    void corin_gl_viewport(int x, int y, int width, int height);
    void corin_gl_clear_color(float r, float g, float b, float a);
    void corin_gl_clear(unsigned int mask);
    
    // Matrix operations
    void corin_gl_matrix_mode(unsigned int mode);
    void corin_gl_load_identity();
    void corin_gl_ortho(double left, double right, double bottom, double top, double near, double far);
    void corin_gl_perspective(double fovy, double aspect, double near, double far);
    
    // Transformations
    void corin_gl_translate(float x, float y, float z);
    void corin_gl_rotate(float angle, float x, float y, float z);
    void corin_gl_scale(float x, float y, float z);
    
    // Drawing primitives
    void corin_gl_begin(unsigned int mode);
    void corin_gl_end();
    void corin_gl_vertex2f(float x, float y);
    void corin_gl_vertex3f(float x, float y, float z);
    void corin_gl_color3f(float r, float g, float b);
    void corin_gl_color4f(float r, float g, float b, float a);
    
    // State management
    void corin_gl_enable(unsigned int cap);
    void corin_gl_disable(unsigned int cap);
    void corin_gl_depth_func(unsigned int func);
    void corin_gl_blend_func(unsigned int sfactor, unsigned int dfactor);
}

// OpenGL Constants
#define CORIN_GL_COLOR_BUFFER_BIT 0x00004000
#define CORIN_GL_DEPTH_BUFFER_BIT 0x00000100
#define CORIN_GL_MODELVIEW 0x1700
#define CORIN_GL_PROJECTION 0x1701
#define CORIN_GL_POINTS 0x0000
#define CORIN_GL_LINES 0x0001
#define CORIN_GL_LINE_LOOP 0x0002
#define CORIN_GL_LINE_STRIP 0x0003
#define CORIN_GL_TRIANGLES 0x0004
#define CORIN_GL_TRIANGLE_STRIP 0x0005
#define CORIN_GL_TRIANGLE_FAN 0x0006
#define CORIN_GL_QUADS 0x0007
#define CORIN_GL_DEPTH_TEST 0x0B71
#define CORIN_GL_BLEND 0x0BE2
#define CORIN_GL_SRC_ALPHA 0x0302
#define CORIN_GL_ONE_MINUS_SRC_ALPHA 0x0303

#endif // CORIN_STDLIB_OPENGL_H
