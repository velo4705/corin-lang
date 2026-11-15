# Corin Examples

This directory contains example programs demonstrating Corin's features.

## ✅ Working Examples (Current v1.0-beta.6)

These examples work with the current parser and have been verified:

### `hello.crn` - Hello World
```bash
./corin examples/hello.crn
```
Output:
```
Hello, Corin!
Hello, World!
```

### `simple.crn` - Basic variables and arithmetic
```bash
./corin examples/simple.crn
```
Output:
```
10
30
```

### `showcase.crn` - Working language features
```bash
./corin examples/showcase.crn
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

### `data_science_simple.crn` - Basic data processing
```bash
./corin examples/data_science_simple.crn
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

### `test_basic.crn` - Basic operations
```bash
./corin examples/test_basic.crn
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

### `test_arithmetic.crn` - Arithmetic operations
```bash
./corin examples/test_arithmetic.crn
```
Output:
```
15
5
50
2.000000
```

### `test_comparison.crn` - Comparison operators
```bash
./corin examples/test_comparison.crn
```
Output:
```
true
false
false
true
```

### `file_io_example.crn` - File I/O simulation
```bash
./corin examples/file_io_example.crn
```
Demonstrates file operations concepts (reading, writing, CSV, JSON).

### `user_input_example.crn` - User input simulation
```bash
./corin examples/user_input_example.crn
```
Demonstrates user input validation and processing.

### `system_programming_example.crn` - System programming simulation
```bash
./corin examples/system_programming_example.crn
```
Demonstrates system-level operations (processes, memory, CPU, disk).

### `directives_example.crn` - Directives simulation
```bash
./corin examples/directives_example.crn
```
Demonstrates compiler directives and optimization concepts.

### Test All Examples
```bash
./test_examples.sh
```

All 24 examples pass! ✅

## 🔮 Future Vision Examples

These examples demonstrate planned features for future versions. They will not run yet but show the direction of the language:

- **`data_science.crn`** - ML and data analysis (requires: imports, classes, async)
- **`advanced_features.crn`** - Advanced language features
- **`advanced_types.crn`** - Dependent types, higher-kinded types
- **`macros.crn`** - Macro system
- **`jit_compilation.crn`** - JIT compilation features
- **`mobile_example.crn`** - Mobile platform directives
- **`platform_directives.crn`** - Platform-specific code
- **`cli_tool.crn`** - CLI application (requires: imports, modules)
- **`complete_cli_tool.crn`** - Full CLI tool
- **`concurrent_example.crn`** - Concurrency (requires: Thread API)
- **`json_example.crn`** - JSON processing (requires: imports)
- **`web_server.crn`** - HTTP server (requires: imports)
- **`microservice.crn`** - Microservice example
- **`systems_programming.crn`** - Systems programming

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
- 🔄 Package manager (cpm)
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
./corin examples/hello.crn
```

Test all working examples:
```bash
for file in examples/hello.crn examples/simple.crn examples/showcase.crn; do
    echo "Testing: $file"
    ./corin "$file"
    echo ""
done
```

## Contributing Examples

When adding new examples:

1. Test with current parser: `./corin your_example.crn`
2. If it uses future features, add a note at the top
3. Consider creating a simplified version that works now
4. Update this README

## Documentation

See the main documentation for more details:
- [Getting Started](../docs/GETTING_STARTED.md)
- [Language Features](../docs/LANGUAGE_FEATURES.md)
- [Standard Library](../docs/STANDARD_LIBRARY.md)
