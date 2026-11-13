#include "../gui/window.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace corin::stdlib;

void test_window_creation() {
    std::cout << "Test 1: Window Creation" << std::endl;
    
    try {
        Window window("Test Window", 800, 600);
        std::cout << "  ✓ Window created: " << window.title() 
                  << " (" << window.width() << "x" << window.height() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "  ✗ Failed: " << e.what() << std::endl;
    }
}

void test_hello_corin() {
    std::cout << "\nTest 2: Hello Corin Window" << std::endl;
    std::cout << "  Opening window with 'Hello Corin' text..." << std::endl;
    std::cout << "  Window will stay open for 5 seconds" << std::endl;
    std::cout << "  (You can close it early by clicking the X button)" << std::endl;
    
    try {
        Window window("Hello Corin", 800, 600);
        window.show();
        
        auto start = std::chrono::steady_clock::now();
        int frames = 0;
        
        while (window.is_open()) {
            // Check if 5 seconds have passed
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
            if (elapsed >= 5) {
                break;
            }
            
            // Handle events
            window.poll_events();
            
            // Clear screen (dark blue background)
            window.clear(20, 30, 50);
            
            // Draw "Hello Corin" text
            window.draw_text("Hello Corin", 250, 250, 48, 255, 255, 255);
            
            // Draw subtitle
            window.draw_text("Cross-platform GUI Window System", 200, 320, 24, 200, 200, 200);
            
            // Draw platform info
            window.draw_text("Running on Linux with SDL2", 220, 380, 20, 150, 150, 150);
            
            // Draw a decorative rectangle
            window.fill_rect(50, 50, 700, 10, 100, 150, 255);
            window.fill_rect(50, 540, 700, 10, 100, 150, 255);
            
            // Present
            window.present();
            
            frames++;
            
            // ~60 FPS
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
        
        double fps = frames / 5.0;
        std::cout << "  ✓ Window displayed successfully" << std::endl;
        std::cout << "  ✓ Average FPS: " << fps << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "  ✗ Failed: " << e.what() << std::endl;
    }
}

void test_c_api() {
    std::cout << "\nTest 3: C API" << std::endl;
    
    if (!corin_gui_init()) {
        std::cout << "  ✗ Failed to initialize GUI" << std::endl;
        return;
    }
    
    void* window = corin_window_create("C API Test", 640, 480);
    if (!window) {
        std::cout << "  ✗ Failed to create window" << std::endl;
        return;
    }
    
    corin_window_show(window);
    
    for (int i = 0; i < 60; i++) {  // 1 second at 60 FPS
        if (!corin_window_poll_events(window)) break;
        
        corin_window_clear(window, 0, 0, 0);
        corin_window_draw_text(window, "C API Works!", 250, 200, 36, 0, 255, 0);
        corin_window_present(window);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    
    corin_window_destroy(window);
    corin_gui_quit();
    
    std::cout << "  ✓ C API test passed" << std::endl;
}

int main() {
    std::cout << "=== Corin GUI Window System Tests ===" << std::endl;
    std::cout << std::endl;
    
    test_window_creation();
    test_hello_corin();
    test_c_api();
    
    std::cout << std::endl;
    std::cout << "================================================================================";
    std::cout << std::endl;
    std::cout << "All GUI window tests completed! 🪟✅" << std::endl;
    std::cout << "================================================================================";
    std::cout << std::endl;
    
    return 0;
}
