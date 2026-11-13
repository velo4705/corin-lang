#include "opengl.h"
#include <cmath>

namespace corin {
namespace stdlib {
namespace graphics {

bool OpenGL::init() {
    // OpenGL initialization is typically handled by the window system (SDL2/GLUT)
    return true;
}

void OpenGL::viewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void OpenGL::clear_color(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void OpenGL::clear(unsigned int mask) {
    glClear(mask);
}

void OpenGL::matrix_mode(unsigned int mode) {
    glMatrixMode(mode);
}

void OpenGL::load_identity() {
    glLoadIdentity();
}

void OpenGL::ortho(double left, double right, double bottom, double top, double near_val, double far_val) {
    glOrtho(left, right, bottom, top, near_val, far_val);
}

void OpenGL::perspective(double fovy, double aspect, double near_val, double far_val) {
    gluPerspective(fovy, aspect, near_val, far_val);
}

void OpenGL::frustum(double left, double right, double bottom, double top, double near_val, double far_val) {
    glFrustum(left, right, bottom, top, near_val, far_val);
}

void OpenGL::translate(float x, float y, float z) {
    glTranslatef(x, y, z);
}

void OpenGL::rotate(float angle, float x, float y, float z) {
    glRotatef(angle, x, y, z);
}

void OpenGL::scale(float x, float y, float z) {
    glScalef(x, y, z);
}

void OpenGL::push_matrix() {
    glPushMatrix();
}

void OpenGL::pop_matrix() {
    glPopMatrix();
}

void OpenGL::begin(unsigned int mode) {
    glBegin(mode);
}

void OpenGL::end() {
    glEnd();
}

void OpenGL::vertex2f(float x, float y) {
    glVertex2f(x, y);
}

void OpenGL::vertex3f(float x, float y, float z) {
    glVertex3f(x, y, z);
}

void OpenGL::color3f(float r, float g, float b) {
    glColor3f(r, g, b);
}

void OpenGL::color4f(float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
}

void OpenGL::normal3f(float x, float y, float z) {
    glNormal3f(x, y, z);
}

void OpenGL::tex_coord2f(float s, float t) {
    glTexCoord2f(s, t);
}

void OpenGL::enable(unsigned int cap) {
    glEnable(cap);
}

void OpenGL::disable(unsigned int cap) {
    glDisable(cap);
}

void OpenGL::depth_func(unsigned int func) {
    glDepthFunc(func);
}

void OpenGL::blend_func(unsigned int sfactor, unsigned int dfactor) {
    glBlendFunc(sfactor, dfactor);
}

void OpenGL::cull_face(unsigned int mode) {
    glCullFace(mode);
}

void OpenGL::light(unsigned int light, unsigned int pname, const float* params) {
    glLightfv(light, pname, params);
}

void OpenGL::material(unsigned int face, unsigned int pname, const float* params) {
    glMaterialfv(face, pname, params);
}

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API implementations
extern "C" {
    bool corin_gl_init() {
        return corin::stdlib::graphics::OpenGL::init();
    }
    
    void corin_gl_viewport(int x, int y, int width, int height) {
        corin::stdlib::graphics::OpenGL::viewport(x, y, width, height);
    }
    
    void corin_gl_clear_color(float r, float g, float b, float a) {
        corin::stdlib::graphics::OpenGL::clear_color(r, g, b, a);
    }
    
    void corin_gl_clear(unsigned int mask) {
        corin::stdlib::graphics::OpenGL::clear(mask);
    }
    
    void corin_gl_matrix_mode(unsigned int mode) {
        corin::stdlib::graphics::OpenGL::matrix_mode(mode);
    }
    
    void corin_gl_load_identity() {
        corin::stdlib::graphics::OpenGL::load_identity();
    }
    
    void corin_gl_ortho(double left, double right, double bottom, double top, double near_val, double far_val) {
        corin::stdlib::graphics::OpenGL::ortho(left, right, bottom, top, near_val, far_val);
    }
    
    void corin_gl_perspective(double fovy, double aspect, double near_val, double far_val) {
        corin::stdlib::graphics::OpenGL::perspective(fovy, aspect, near_val, far_val);
    }
    
    void corin_gl_frustum(double left, double right, double bottom, double top, double near_val, double far_val) {
        corin::stdlib::graphics::OpenGL::frustum(left, right, bottom, top, near_val, far_val);
    }
    
    void corin_gl_translate(float x, float y, float z) {
        corin::stdlib::graphics::OpenGL::translate(x, y, z);
    }
    
    void corin_gl_rotate(float angle, float x, float y, float z) {
        corin::stdlib::graphics::OpenGL::rotate(angle, x, y, z);
    }
    
    void corin_gl_scale(float x, float y, float z) {
        corin::stdlib::graphics::OpenGL::scale(x, y, z);
    }
    
    void corin_gl_push_matrix() {
        corin::stdlib::graphics::OpenGL::push_matrix();
    }
    
    void corin_gl_pop_matrix() {
        corin::stdlib::graphics::OpenGL::pop_matrix();
    }
    
    void corin_gl_begin(unsigned int mode) {
        corin::stdlib::graphics::OpenGL::begin(mode);
    }
    
    void corin_gl_end() {
        corin::stdlib::graphics::OpenGL::end();
    }
    
    void corin_gl_vertex2f(float x, float y) {
        corin::stdlib::graphics::OpenGL::vertex2f(x, y);
    }
    
    void corin_gl_vertex3f(float x, float y, float z) {
        corin::stdlib::graphics::OpenGL::vertex3f(x, y, z);
    }
    
    void corin_gl_color3f(float r, float g, float b) {
        corin::stdlib::graphics::OpenGL::color3f(r, g, b);
    }
    
    void corin_gl_color4f(float r, float g, float b, float a) {
        corin::stdlib::graphics::OpenGL::color4f(r, g, b, a);
    }
    
    void corin_gl_normal3f(float x, float y, float z) {
        corin::stdlib::graphics::OpenGL::normal3f(x, y, z);
    }
    
    void corin_gl_tex_coord2f(float s, float t) {
        corin::stdlib::graphics::OpenGL::tex_coord2f(s, t);
    }
    
    void corin_gl_enable(unsigned int cap) {
        corin::stdlib::graphics::OpenGL::enable(cap);
    }
    
    void corin_gl_disable(unsigned int cap) {
        corin::stdlib::graphics::OpenGL::disable(cap);
    }
    
    void corin_gl_depth_func(unsigned int func) {
        corin::stdlib::graphics::OpenGL::depth_func(func);
    }
    
    void corin_gl_blend_func(unsigned int sfactor, unsigned int dfactor) {
        corin::stdlib::graphics::OpenGL::blend_func(sfactor, dfactor);
    }
    
    void corin_gl_cull_face(unsigned int mode) {
        corin::stdlib::graphics::OpenGL::cull_face(mode);
    }
}
