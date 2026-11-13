#include "opengl.h"
#include <iostream>

namespace corin {
namespace stdlib {
namespace graphics {

bool OpenGLContext::init() {
    // OpenGL initialization is typically handled by the windowing system
    // (SDL, GLUT, GLFW, etc.)
    return true;
}

void OpenGLContext::viewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void OpenGLContext::clear_color(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void OpenGLContext::clear(unsigned int mask) {
    glClear(mask);
}

void OpenGLContext::matrix_mode(unsigned int mode) {
    glMatrixMode(mode);
}

void OpenGLContext::load_identity() {
    glLoadIdentity();
}

void OpenGLContext::ortho(double left, double right, double bottom, double top, double near, double far) {
    glOrtho(left, right, bottom, top, near, far);
}

void OpenGLContext::perspective(double fovy, double aspect, double near, double far) {
    gluPerspective(fovy, aspect, near, far);
}

void OpenGLContext::translate(float x, float y, float z) {
    glTranslatef(x, y, z);
}

void OpenGLContext::rotate(float angle, float x, float y, float z) {
    glRotatef(angle, x, y, z);
}

void OpenGLContext::scale(float x, float y, float z) {
    glScalef(x, y, z);
}

void OpenGLContext::begin(unsigned int mode) {
    glBegin(mode);
}

void OpenGLContext::end() {
    glEnd();
}

void OpenGLContext::vertex2f(float x, float y) {
    glVertex2f(x, y);
}

void OpenGLContext::vertex3f(float x, float y, float z) {
    glVertex3f(x, y, z);
}

void OpenGLContext::color3f(float r, float g, float b) {
    glColor3f(r, g, b);
}

void OpenGLContext::color4f(float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
}

void OpenGLContext::enable(unsigned int cap) {
    glEnable(cap);
}

void OpenGLContext::disable(unsigned int cap) {
    glDisable(cap);
}

void OpenGLContext::depth_func(unsigned int func) {
    glDepthFunc(func);
}

void OpenGLContext::blend_func(unsigned int sfactor, unsigned int dfactor) {
    glBlendFunc(sfactor, dfactor);
}

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API implementations
extern "C" {
    bool corin_gl_init() {
        return corin::stdlib::graphics::OpenGLContext::init();
    }
    
    void corin_gl_viewport(int x, int y, int width, int height) {
        corin::stdlib::graphics::OpenGLContext::viewport(x, y, width, height);
    }
    
    void corin_gl_clear_color(float r, float g, float b, float a) {
        corin::stdlib::graphics::OpenGLContext::clear_color(r, g, b, a);
    }
    
    void corin_gl_clear(unsigned int mask) {
        corin::stdlib::graphics::OpenGLContext::clear(mask);
    }
    
    void corin_gl_matrix_mode(unsigned int mode) {
        corin::stdlib::graphics::OpenGLContext::matrix_mode(mode);
    }
    
    void corin_gl_load_identity() {
        corin::stdlib::graphics::OpenGLContext::load_identity();
    }
    
    void corin_gl_ortho(double left, double right, double bottom, double top, double near, double far) {
        corin::stdlib::graphics::OpenGLContext::ortho(left, right, bottom, top, near, far);
    }
    
    void corin_gl_perspective(double fovy, double aspect, double near, double far) {
        corin::stdlib::graphics::OpenGLContext::perspective(fovy, aspect, near, far);
    }
    
    void corin_gl_translate(float x, float y, float z) {
        corin::stdlib::graphics::OpenGLContext::translate(x, y, z);
    }
    
    void corin_gl_rotate(float angle, float x, float y, float z) {
        corin::stdlib::graphics::OpenGLContext::rotate(angle, x, y, z);
    }
    
    void corin_gl_scale(float x, float y, float z) {
        corin::stdlib::graphics::OpenGLContext::scale(x, y, z);
    }
    
    void corin_gl_begin(unsigned int mode) {
        corin::stdlib::graphics::OpenGLContext::begin(mode);
    }
    
    void corin_gl_end() {
        corin::stdlib::graphics::OpenGLContext::end();
    }
    
    void corin_gl_vertex2f(float x, float y) {
        corin::stdlib::graphics::OpenGLContext::vertex2f(x, y);
    }
    
    void corin_gl_vertex3f(float x, float y, float z) {
        corin::stdlib::graphics::OpenGLContext::vertex3f(x, y, z);
    }
    
    void corin_gl_color3f(float r, float g, float b) {
        corin::stdlib::graphics::OpenGLContext::color3f(r, g, b);
    }
    
    void corin_gl_color4f(float r, float g, float b, float a) {
        corin::stdlib::graphics::OpenGLContext::color4f(r, g, b, a);
    }
    
    void corin_gl_enable(unsigned int cap) {
        corin::stdlib::graphics::OpenGLContext::enable(cap);
    }
    
    void corin_gl_disable(unsigned int cap) {
        corin::stdlib::graphics::OpenGLContext::disable(cap);
    }
    
    void corin_gl_depth_func(unsigned int func) {
        corin::stdlib::graphics::OpenGLContext::depth_func(func);
    }
    
    void corin_gl_blend_func(unsigned int sfactor, unsigned int dfactor) {
        corin::stdlib::graphics::OpenGLContext::blend_func(sfactor, dfactor);
    }
}
