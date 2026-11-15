# Directives in Corin

Complete guide to compiler directives, attributes, and annotations.

## Platform Directives

### Target Platform

```corin
// Compile only for specific platform
#[ios]
fn ios_specific_function() {
    // iOS-only code
}

#[android]
fn android_specific_function() {
    // Android-only code
}

#[web]
fn web_specific_function() {
    // Web/WASM-only code
}

#[desktop]
fn desktop_specific_function() {
    // Desktop-only code
}

#[mobile]
fn mobile_specific_function() {
    // iOS or Android
}
```

### Architecture

```corin
#[x86_64]
fn x86_specific() { }

#[arm64]
fn arm_specific() { }

#[wasm]
fn wasm_specific() { }
```

### Operating System

```corin
#[linux]
fn linux_only() { }

#[macos]
fn macos_only() { }

#[windows]
fn windows_only() { }

#[unix]
fn unix_only() {  // Linux, macOS, BSD
}
```

## Optimization Directives

### Inline

```corin
// Always inline
#[inline(always)]
fn fast_function() {
    // This will always be inlined
}

// Never inline
#[inline(never)]
fn debug_function() {
    // This will never be inlined
}

// Hint to inline
#[inline]
fn maybe_inline() {
    // Compiler decides
}
```

### Optimization Level

```corin
// Optimize for speed
#[optimize(speed)]
fn hot_path() {
    // Aggressive optimizations
}

// Optimize for size
#[optimize(size)]
fn rarely_used() {
    // Minimize code size
}

// No optimization (for debugging)
#[optimize(none)]
fn debug_code() {
    // Easy to debug
}
```

### Loop Optimization

```corin
#[unroll]
fn process_array(arr: [i64; 4]) {
    // Loop will be unrolled
    for x in arr {
        process(x)
    }
}

#[vectorize]
fn sum_array(arr: Vec<f64>) -> f64 {
    // Use SIMD instructions
    let sum = 0.0
    for x in arr {
        sum += x
    }
    return sum
}
```

## Memory Directives

### Alignment

```corin
// Align to 16 bytes
#[align(16)]
type AlignedStruct {
    data: [u8; 64]
}

// Packed struct (no padding)
#[packed]
type PackedStruct {
    a: u8
    b: u32
}
```

### Memory Layout

```corin
// C-compatible layout
#[repr(C)]
type CStruct {
    x: i32
    y: i32
}

// Transparent wrapper
#[repr(transparent)]
type Wrapper {
    inner: i64
}
```

## Safety Directives

### Unsafe

```corin
// Mark unsafe function
#[unsafe]
fn raw_pointer_access(ptr: *mut u8) {
    *ptr = 42
}

// Unsafe block
fn safe_wrapper() {
    unsafe {
        raw_pointer_access(ptr)
    }
}
```

### Bounds Checking

```corin
// Disable bounds checking (unsafe!)
#[no_bounds_check]
fn fast_array_access(arr: Vec<i64>, idx: usize) -> i64 {
    return arr[idx]  // No bounds check
}
```

## Concurrency Directives

### Thread Safety

```corin
// Mark as thread-safe
#[thread_safe]
type SafeCounter {
    count: Atomic<i64>
}

// Require Send trait
#[send]
type SendableData {
    data: Vec<u8>
}

// Require Sync trait
#[sync]
type SyncableData {
    data: Arc<Mutex<i64>>
}
```

### Async

```corin
// Async function
#[async]
fn fetch_data() -> String {
    let response = await http.get("https://api.example.com")
    return response.text()
}

// Async block
let result = async {
    let data = await fetch_data()
    process(data)
}
```

## Testing Directives

### Test

```corin
// Mark as test function
#[test]
fn test_addition() {
    assert_eq!(2 + 2, 4)
}

// Benchmark test
#[bench]
fn bench_sorting() {
    let arr = generate_random_array(1000)
    sort(arr)
}

// Integration test
#[test(integration)]
fn test_full_system() {
    // Test entire system
}

// Ignore test
#[test]
#[ignore]
fn slow_test() {
    // Skipped by default
}
```

## Documentation Directives

### Doc Comments

```corin
/// This is a documentation comment
/// 
/// # Examples
/// 
/// ```
/// let x = add(2, 3)
/// assert_eq!(x, 5)
/// ```
#[doc]
fn add(a: i64, b: i64) -> i64 {
    return a + b
}

// Hide from documentation
#[doc(hidden)]
fn internal_function() { }
```

## Deprecation

```corin
// Mark as deprecated
#[deprecated]
fn old_function() {
    // Old implementation
}

// With message
#[deprecated(since: "1.5.0", note: "Use new_function instead")]
fn old_api() { }

// With replacement
#[deprecated(use: "new_function")]
fn legacy_code() { }
```

## Conditional Compilation

### Feature Flags

```corin
// Compile only if feature enabled
#[cfg(feature: "advanced")]
fn advanced_feature() {
    // Only compiled with --features advanced
}

// Multiple conditions
#[cfg(all(feature: "ssl", target_os: "linux"))]
fn ssl_linux() { }

#[cfg(any(feature: "json", feature: "xml"))]
fn parse_data() { }

#[cfg(not(feature: "minimal"))]
fn full_version() { }
```

### Debug/Release

```corin
#[cfg(debug)]
fn debug_only() {
    print("Debug mode")
}

#[cfg(release)]
fn release_only() {
    // Optimized code
}
```

## Derive Directives

### Auto-Implement Traits

```corin
// Automatically implement traits
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
type Point {
    x: i64
    y: i64
}

// Custom derive
#[derive(Serialize, Deserialize)]
type User {
    name: String
    age: i64
}
```

## Macro Directives

### Macro Definition

```corin
// Define macro
#[macro]
fn debug(expr) {
    print(f"[DEBUG] {stringify!(expr)} = {expr}")
}

// Procedural macro
#[proc_macro]
fn my_macro(input: TokenStream) -> TokenStream {
    // Transform tokens
}

// Attribute macro
#[proc_macro_attribute]
fn route(attr: TokenStream, item: TokenStream) -> TokenStream {
    // Generate routing code
}
```

## Performance Directives

### Hot/Cold Paths

```corin
// Mark as hot path (frequently executed)
#[hot]
fn inner_loop() {
    // Optimize aggressively
}

// Mark as cold path (rarely executed)
#[cold]
fn error_handler() {
    // Optimize for size
}
```

### Likely/Unlikely

```corin
fn process(value: i64) {
    #[likely]
    if value > 0 {
        // Common case
        fast_path()
    } else {
        #[unlikely]
        // Rare case
        slow_path()
    }
}
```

## Link Directives

### External Linking

```corin
// Link to C library
#[link(name: "m")]
extern "C" {
    fn sqrt(x: f64) -> f64
}

// Link to static library
#[link(name: "mylib", kind: "static")]
extern { }

// Link to dynamic library
#[link(name: "mylib", kind: "dylib")]
extern { }
```

### Symbol Export

```corin
// Export symbol
#[export]
fn public_api() { }

// Export with specific name
#[export(name: "my_function")]
fn internal_name() { }

// Don't export
#[no_export]
fn private_function() { }
```

## Custom Directives

### User-Defined Directives

```corin
// Define custom directive
#[directive]
fn logged(func) {
    return |args| {
        print(f"Calling {func.name}")
        let result = func(args)
        print(f"Returned {result}")
        return result
    }
}

// Use custom directive
#[logged]
fn my_function(x: i64) -> i64 {
    return x * 2
}
```

### Directive with Parameters

```corin
#[directive]
fn retry(func, max_attempts: i64 = 3) {
    return |args| {
        for attempt in 1..=max_attempts {
            try {
                return func(args)
            } catch e {
                if attempt == max_attempts {
                    throw e
                }
                print(f"Retry {attempt}/{max_attempts}")
            }
        }
    }
}

#[retry(max_attempts: 5)]
fn unreliable_operation() {
    // May fail, will retry up to 5 times
}
```

## Compiler Directives

### Warnings

```corin
// Allow specific warning
#[allow(unused_variables)]
fn test() {
    let x = 42  // No warning
}

// Deny warning (make it an error)
#[deny(unsafe_code)]
fn safe_only() {
    // unsafe blocks will cause compile error
}

// Warn on specific pattern
#[warn(missing_docs)]
fn public_api() { }
```

### Lints

```corin
// Disable lint
#[allow(clippy::too_many_arguments)]
fn complex_function(a, b, c, d, e, f, g, h) { }

// Enable lint
#[warn(clippy::pedantic)]
fn strict_code() { }
```

## Build Directives

### Conditional Compilation

```corin
// Compile only in tests
#[cfg(test)]
mod tests {
    #[test]
    fn test_something() { }
}

// Compile only for specific target
#[cfg(target_arch: "x86_64")]
fn x86_optimized() { }
```

### Build Scripts

```corin
// Run at build time
#[build_script]
fn generate_code() {
    // Generate code during compilation
}
```

## Examples

### Cross-Platform Code

```corin
#[cfg(unix)]
fn get_path_separator() -> char {
    return '/'
}

#[cfg(windows)]
fn get_path_separator() -> char {
    return '\\'
}
```

### Performance-Critical Code

```corin
#[inline(always)]
#[optimize(speed)]
#[vectorize]
fn dot_product(a: Vec<f64>, b: Vec<f64>) -> f64 {
    let sum = 0.0
    for i in 0..a.len() {
        sum += a[i] * b[i]
    }
    return sum
}
```

### API with Deprecation

```corin
#[deprecated(since: "2.0.0", note: "Use new_api instead")]
fn old_api(x: i64) -> i64 {
    return new_api(x)
}

fn new_api(x: i64) -> i64 {
    return x * 2
}
```

## Best Practices

1. **Use platform directives** for cross-platform code
2. **Mark hot paths** with optimization directives
3. **Document public APIs** with doc comments
4. **Deprecate gradually** with clear migration paths
5. **Test conditionally** with cfg directives
6. **Be careful with unsafe** - use sparingly
7. **Use custom directives** for cross-cutting concerns

## Example Code

See [examples/directives_example.crn](../examples/directives_example.crn) for a complete working example.

## See Also

- [Platform Directives](PLATFORM_DIRECTIVES.md)
- [Macros](MACROS.md)
- [Optimization](OPTIMIZATION.md)
- [Testing](TESTING.md)
