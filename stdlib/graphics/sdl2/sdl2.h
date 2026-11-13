#ifndef CORIN_STDLIB_SDL2_H
#define CORIN_STDLIB_SDL2_H

#include <SDL2/SDL.h>
#include <string>
#include <cstdint>

namespace corin {
namespace stdlib {
namespace graphics {

/**
 * SDL2 Graphics Library for Corin
 * 
 * Provides cross-platform window management, 2D rendering, and input handling.
 * Use this for 2D games and simple graphics applications.
 */

class SDL2Window {
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool should_close_;
    const uint8_t* keyboard_state_;
    int width_;
    int height_;
    
public:
    SDL2Window(const std::string& title, int width, int height);
    ~SDL2Window();
    
    // Window management
    void show();
    void hide();
    bool should_close() const { return should_close_; }
    int width() const { return width_; }
    int height() const { return height_; }
    
    // Event handling
    void poll_events();
    bool is_key_down(int scancode) const;
    
    // Rendering
    void clear(uint8_t r, uint8_t g, uint8_t b);
    void present();
    void fill_rect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b);
    void draw_line(int x1, int y1, int x2, int y2, uint8_t r, uint8_t g, uint8_t b);
    void draw_point(int x, int y, uint8_t r, uint8_t g, uint8_t b);
    
    // Timing
    static void delay(uint32_t ms);
    static uint32_t get_ticks();
};

} // namespace graphics
} // namespace stdlib
} // namespace corin

// C API for Corin code generation
extern "C" {
    // Window management
    void* corin_sdl2_create_window(const char* title, int width, int height);
    void corin_sdl2_destroy_window(void* window);
    void corin_sdl2_show_window(void* window);
    void corin_sdl2_hide_window(void* window);
    bool corin_sdl2_should_close(void* window);
    int corin_sdl2_get_width(void* window);
    int corin_sdl2_get_height(void* window);
    
    // Event handling
    void corin_sdl2_poll_events(void* window);
    bool corin_sdl2_is_key_down(void* window, int64_t scancode);
    
    // Rendering
    void corin_sdl2_clear(void* window, uint8_t r, uint8_t g, uint8_t b);
    void corin_sdl2_present(void* window);
    void corin_sdl2_fill_rect(void* window, int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b);
    void corin_sdl2_draw_line(void* window, int x1, int y1, int x2, int y2, uint8_t r, uint8_t g, uint8_t b);
    void corin_sdl2_draw_point(void* window, int x, int y, uint8_t r, uint8_t g, uint8_t b);
    
    // Timing
    void corin_sdl2_delay(uint32_t ms);
    uint32_t corin_sdl2_get_ticks();
}

#endif // CORIN_STDLIB_SDL2_H
