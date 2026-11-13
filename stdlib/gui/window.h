#ifndef CORIN_STDLIB_WINDOW_H
#define CORIN_STDLIB_WINDOW_H

#include <string>
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace corin {
namespace stdlib {

/**
 * Window - Cross-platform GUI Window System
 * 
 * Provides window creation and management using SDL2.
 * Works on Linux, Windows, and macOS.
 */

class Window {
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    std::string title_;
    int width_;
    int height_;
    bool is_open_;
    const uint8_t* keyboard_state_;
    
public:
    Window(const std::string& title, int width, int height);
    ~Window();
    
    // Window management
    void show();
    void hide();
    void close();
    bool is_open() const { return is_open_; }
    
    // Event handling
    bool poll_events();
    
    // Keyboard state
    bool is_key_down(int keycode) const;
    
    // Rendering
    void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);
    void present();
    
    // Drawing
    void draw_text(const std::string& text, int x, int y, int size = 24,
                   uint8_t r = 255, uint8_t g = 255, uint8_t b = 255);
    void draw_rect(int x, int y, int w, int h,
                   uint8_t r = 255, uint8_t g = 255, uint8_t b = 255);
    void fill_rect(int x, int y, int w, int h,
                   uint8_t r = 255, uint8_t g = 255, uint8_t b = 255);
    
    // Properties
    int width() const { return width_; }
    int height() const { return height_; }
    const std::string& title() const { return title_; }
    
    // Set properties
    void set_title(const std::string& title);
};

// Initialize SDL subsystem
bool init_gui();
void quit_gui();

} // namespace stdlib
} // namespace corin

// C API for code generation
extern "C" {
    bool corin_gui_init();
    void corin_gui_quit();
    
    void* corin_window_create(const char* title, int width, int height);
    void corin_window_destroy(void* window);
    void corin_window_show(void* window);
    void corin_window_close(void* window);
    bool corin_window_is_open(void* window);
    bool corin_window_poll_events(void* window);
    
    void corin_window_clear(void* window, uint8_t r, uint8_t g, uint8_t b);
    void corin_window_present(void* window);
    void corin_window_draw_text(void* window, const char* text, int x, int y, int size,
                                   uint8_t r, uint8_t g, uint8_t b);
    void corin_window_fill_rect(void* window, int x, int y, int w, int h,
                                   uint8_t r, uint8_t g, uint8_t b);
    
    // Keyboard functions
    bool corin_window_is_key_down(void* window, int keycode);
    
    // Window state
    bool corin_window_should_close(void* window);
}

#endif // CORIN_STDLIB_WINDOW_H
