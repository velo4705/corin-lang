# Corin Module Import - Quick Reference

## Import Syntax

```corin
import graphics.sdl2    // Import SDL2 module
import graphics.opengl  // Import OpenGL module
import graphics.glut    // Import GLUT module
import graphics.vulkan  // Import Vulkan module

// Short names also work
import sdl2
import opengl
import glut
import vulkan
```

## SDL2 Functions

```corin
import graphics.sdl2

fn main() {
    // Create window
    let window = corin_sdl2_create_window("Title", 800, 600)
    corin_sdl2_show_window(window)
    
    // Rendering
    corin_sdl2_clear(window, r, g, b)  // r,g,b: 0-255
    corin_sdl2_fill_rect(window, x, y, w, h, r, g, b)
    corin_sdl2_draw_line(window, x1, y1, x2, y2, r, g, b)
    corin_sdl2_draw_point(window, x, y, r, g, b)
    corin_sdl2_present(window)
    
    // Events
    corin_sdl2_poll_events(window)
    let is_down = corin_sdl2_is_key_down(window, scancode)
    let should_quit = corin_sdl2_should_close(window)
    
    // Timing
    corin_sdl2_delay(milliseconds)
    
    // Cleanup
    corin_sdl2_destroy_window(window)
}
```

## OpenGL Functions

```corin
import graphics.opengl

fn render() {
    // Setup
    corin_gl_clear_color(r, g, b, a)  // 0.0 - 1.0
    corin_gl_clear(mask)
    
    // Drawing
    corin_gl_begin(mode)
    corin_gl_color3f(r, g, b)
    corin_gl_vertex3f(x, y, z)
    corin_gl_end()
    
    // Transformations
    corin_gl_translate(x, y, z)
    corin_gl_rotate(angle, x, y, z)
    corin_gl_scale(x, y, z)
    
    // Matrix
    corin_gl_matrix_mode(mode)
    corin_gl_load_identity()
    corin_gl_push_matrix()
    corin_gl_pop_matrix()
}
```

## GLUT Functions

```corin
import graphics.glut

fn main() {
    // Initialization
    corin_glut_init()
    corin_glut_init_display_mode(mode)
    corin_glut_init_window_size(width, height)
    let window = corin_glut_create_window("Title")
    
    // Rendering
    corin_glut_swap_buffers()
    
    // 3D Shapes
    corin_glut_solid_sphere(radius, slices, stacks)
    corin_glut_wire_sphere(radius, slices, stacks)
    corin_glut_solid_cube(size)
    corin_glut_solid_teapot(size)
}
```

## Vulkan Functions

```corin
import graphics.vulkan

fn main() {
    // Create context
    let ctx = corin_vulkan_create_context("Title", 800, 600)
    corin_vulkan_init(ctx)
    
    // Render loop
    while !corin_vulkan_should_close(ctx) {
        corin_vulkan_poll_events(ctx)
        corin_vulkan_begin_frame(ctx)
        corin_vulkan_draw_triangle(ctx)
        corin_vulkan_end_frame(ctx)
    }
    
    // Cleanup
    corin_vulkan_destroy_context(ctx)
}
```

## Compilation

```bash
# 1. Compile to LLVM IR
./corin compile myapp.corin 2>/dev/null > myapp.ll

# 2. Compile to object file
llc myapp.ll -filetype=obj -o myapp.o

# 3. Link (choose your module)
# For SDL2:
clang myapp.o -o myapp -L./stdlib/graphics/sdl2 -lcorin_sdl2 -lSDL2 -lstdc++

# For OpenGL:
clang myapp.o -o myapp -L./stdlib/graphics/opengl -lcorin_opengl -lGL -lGLU -lstdc++

# For GLUT:
clang myapp.o -o myapp -L./stdlib/graphics/glut -lcorin_glut -lglut -lGL -lGLU -lstdc++

# For Vulkan:
clang myapp.o -o myapp -L./stdlib/graphics/vulkan -lcorin_vulkan -lvulkan -lSDL2 -lstdc++

# 4. Run (set library path)
LD_LIBRARY_PATH=./stdlib/graphics/MODULE:$LD_LIBRARY_PATH ./myapp
```

## Complete Example

```corin
// simple_window.corin
import graphics.sdl2

fn main() {
    print("Creating window...")
    
    let window = corin_sdl2_create_window("My First Window", 800, 600)
    corin_sdl2_show_window(window)
    
    // Red background
    corin_sdl2_clear(window, 255, 0, 0)
    corin_sdl2_present(window)
    
    // Wait 3 seconds
    corin_sdl2_delay(3000)
    
    corin_sdl2_destroy_window(window)
    print("Done!")
}
```

Compile and run:
```bash
./corin compile simple_window.corin 2>/dev/null > simple_window.ll
llc simple_window.ll -filetype=obj -o simple_window.o
clang simple_window.o -o simple_window \
    -L./stdlib/graphics/sdl2 -lcorin_sdl2 -lSDL2 -lstdc++
LD_LIBRARY_PATH=./stdlib/graphics/sdl2:$LD_LIBRARY_PATH ./simple_window
```

## Tips

1. **Type Conversions**: Color values (0-255) are automatically converted from Corin integers
2. **Error Handling**: Check compilation errors in stderr
3. **Library Path**: Always set LD_LIBRARY_PATH when running
4. **Multiple Imports**: You can import multiple modules in one program
5. **Examples**: See `examples/test_import_sdl2.corin` for a working example

## Troubleshooting

**"Unknown function" error**: Make sure you added the import statement

**Linking errors**: Check that library path is correct and libraries are built

**"file format not recognized"**: Use `-filetype=obj` with llc

**Window doesn't appear**: Check that you have a display (X11/Wayland)

**Segfault**: Make sure to initialize before using (e.g., create window before drawing)

## More Information

- Full documentation: `stdlib/graphics/IMPORT_GUIDE.md`
- Build instructions: `stdlib/graphics/BUILD.md`
- Graphics guide: `GRAPHICS_QUICK_START.md`
- Examples: `examples/test_import_sdl2.corin`
