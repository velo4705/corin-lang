# Corin Examples

This directory contains example programs demonstrating Corin's features.

## ✅ Working Examples (Current v1.0-beta.6)

These examples work with the current parser and have been verified:

### `hello.corin` - Hello World
```bash
./corin examples/hello.corin
```
Output:
```
Hello, Corin!
Hello, World!
```

### `simple.corin` - Basic variables and arithmetic
```bash
./corin examples/simple.corin
```
Output:
```
10
30
```

### `showcase.corin` - Working language features
```bash
./corin examples/showcase.corin
```
Output:
```
30
200
256.000000
true
true
true
50
78.539750
```

### `data_science_simple.corin` - Basic data processing
```bash
./corin examples/data_science_simple.corin
```
Output:
```
=== Corin Data Science Demo ===

Mean:
10.000000
Sum:
30
Average:
10.000000
Variance:
16.666667
Value above threshold:
true

✓ Data analysis complete!
```

### `test_basic.corin` - Basic operations
```bash
./corin examples/test_basic.corin
```
Output:
```
52
15
5.000000
true
true
420
4.200000
```

### `test_arithmetic.corin` - Arithmetic operations
```bash
./corin examples/test_arithmetic.corin
```
Output:
```
15
5
50
2.000000
```

### `test_comparison.corin` - Comparison operators
```bash
./corin examples/test_comparison.corin
```
Output:
```
true
false
false
true
```

### `file_io_example.corin` - File I/O simulation
```bash
./corin examples/file_io_example.corin
```
Demonstrates file operations concepts (reading, writing, CSV, JSON).

### `user_input_example.corin` - User input simulation
```bash
./corin examples/user_input_example.corin
```
Demonstrates user input validation and processing.

### `system_programming_example.corin` - System programming simulation
```bash
./corin examples/system_programming_example.corin
```
Demonstrates system-level operations (processes, memory, CPU, disk).

### `directives_example.corin` - Directives simulation
```bash
./corin examples/directives_example.corin
```
Demonstrates compiler directives and optimization concepts.

### Test All Examples
```bash
./test_examples.sh
```

All 24 examples pass! ✅

## 🔮 Future Vision Examples

These examples demonstrate planned features for future versions. They will not run yet but show the direction of the language:

- **`data_science.corin`** - ML and data analysis (requires: imports, classes, async)
- **`advanced_features.corin`** - Advanced language features
- **`advanced_types.corin`** - Dependent types, higher-kinded types
- **`macros.corin`** - Macro system
- **`jit_compilation.corin`** - JIT compilation features
- **`mobile_example.corin`** - Mobile platform directives
- **`platform_directives.corin`** - Platform-specific code
- **`cli_tool.corin`** - CLI application (requires: imports, modules)
- **`complete_cli_tool.corin`** - Full CLI tool
- **`concurrent_example.corin`** - Concurrency (requires: Thread API)
- **`json_example.corin`** - JSON processing (requires: imports)
- **`web_server.corin`** - HTTP server (requires: imports)
- **`microservice.corin`** - Microservice example
- **`systems_programming.corin`** - Systems programming

These are documentation examples showing the vision for Corin's future capabilities.

## Current Parser Limitations

The current parser (v1.0-beta.6) supports:

✅ Variables (`let x = 10`)  
✅ Arithmetic (`+`, `-`, `*`, `/`)  
✅ Comparisons (`>`, `<`, `==`, `!=`)  
✅ Print statements  
✅ Comments (`#`)  
✅ Basic expressions  

## Coming Soon

Features being implemented for v1.0-beta.6:

### Control Flow
- 🔄 if/else statements
- 🔄 while loops
- 🔄 for loops
- 🔄 match/switch statements
- 🔄 Pattern matching
- 🔄 Guard clauses

### Functions & Methods
- 🔄 Function definitions
- 🔄 Methods
- 🔄 Lambda expressions
- 🔄 Closures
- 🔄 Higher-order functions
- 🔄 Default parameters
- 🔄 Named parameters
- 🔄 Variadic functions

### Object-Oriented
- 🔄 Classes and objects
- 🔄 Inheritance
- 🔄 Interfaces/Traits
- 🔄 Abstract classes
- 🔄 Properties
- 🔄 Constructors/Destructors
- 🔄 Operator overloading
- 🔄 Method overloading

### Data Structures
- 🔄 Arrays
- 🔄 Lists/Vectors
- 🔄 Hash maps/Dictionaries
- 🔄 Sets
- 🔄 Tuples
- 🔄 Structs
- 🔄 Enums

### Advanced Features
- 🔄 Generics
- 🔄 Type inference
- 🔄 Pattern matching
- 🔄 String interpolation
- 🔄 Imports and modules
- 🔄 Async/await
- 🔄 Coroutines
- 🔄 Macros
- 🔄 Reflection
- 🔄 Decorators

### Memory Management
- 🔄 Ownership system
- 🔄 Borrowing
- 🔄 Lifetimes
- 🔄 Smart pointers
- 🔄 Reference counting
- 🔄 Garbage collection

### Concurrency
- 🔄 Threads
- 🔄 Channels
- 🔄 Mutexes
- 🔄 Async/await
- 🔄 Thread pools
- 🔄 Atomic operations

### Standard Library
- 🔄 Collections (Vec, HashMap, Set)
- 🔄 String manipulation
- 🔄 File I/O
- 🔄 Networking (HTTP, TCP, UDP)
- 🔄 JSON/XML parsing
- 🔄 Regular expressions
- 🔄 Date/Time
- 🔄 Math functions
- 🔄 Cryptography
- 🔄 Compression

### Platform Features
- 🔄 Platform directives (#[ios], #[android], #[web])
- 🔄 Native API access
- 🔄 Cross-platform GUI
- 🔄 Mobile support
- 🔄 WASM compilation

### Tooling
- 🔄 Package manager (spm)
- 🔄 Build system
- 🔄 Test framework
- 🔄 Code formatter
- 🔄 Linter
- 🔄 Debugger
- 🔄 Profiler
- 🔄 Documentation generator
- 🔄 REPL
- 🔄 Language server

**See [COMPLETE_FEATURES.md](../docs/COMPLETE_FEATURES.md) for the full list of 500+ features from all major programming languages.**

## Creating Your Own Examples

For now, stick to the supported features:

```corin
# This works!
let x = 10
let y = 20
let sum = x + y
print(sum)

let is_greater = x > 5
print(is_greater)
```

```corin
# This doesn't work yet
if x > 5:
    print("Greater")  # Parser doesn't support if/else yet
```

## Testing Examples

Test a specific example:
```bash
./corin examples/hello.corin
```

Test all working examples:
```bash
for file in examples/hello.corin examples/simple.corin examples/showcase.corin; do
    echo "Testing: $file"
    ./corin "$file"
    echo ""
done
```

## Contributing Examples

When adding new examples:

1. Test with current parser: `./corin your_example.corin`
2. If it uses future features, add a note at the top
3. Consider creating a simplified version that works now
4. Update this README

## Documentation

See the main documentation for more details:
- [Getting Started](../docs/GETTING_STARTED.md)
- [Language Features](../docs/LANGUAGE_FEATURES.md)
- [Standard Library](../docs/STANDARD_LIBRARY.md)
