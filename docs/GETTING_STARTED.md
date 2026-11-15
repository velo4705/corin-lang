# Getting Started with Corin

Welcome to Corin! This guide will help you get up and running in 15 minutes.

## What is Corin?

Corin is a modern programming language that combines:
- 🐍 Python's clean syntax
- ⚡ C++'s performance
- 🦀 Rust's safety
- 🔵 Go's concurrency

## Installation

### Prerequisites
- C++20 compiler (g++ or clang++)
- LLVM (optional, for code generation)
- Make
- Git

### Build from Source

**Option 1: SSH (Recommended - No password needed)**

```bash
# First time setup (run once)
bash <(curl -s https://raw.githubusercontent.com/velo4705/corin-lang/main/scripts/setup_git_ssh.sh)

# Clone and build
git clone git@github.com:velo4705/corin-lang.git
cd corin-lang
make quick
```

**Option 2: HTTPS (Requires Personal Access Token)**

```bash
# Clone and build
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang
make quick
```

**Having authentication issues?** See [Git Setup Guide](GIT_SETUP.md) for detailed help.

This creates the `corin` compiler.

## Your First Program

Create a file called `hello.crn`:

```corin
# Hello World in Corin
print("Hello, Corin!")
```

Run it:

```bash
./corin hello.crn
```

Output:
```
Hello, Corin!
```

## Using the Package Manager

Corin comes with `cpm`, a package manager for creating and managing projects.

### Create a New Project

```bash
./cpm init my-project
cd my-project
```

This creates:
```
my-project/
  cpm.toml          # Project configuration
  src/
    main.crn        # Main source file
  tests/            # Test files
  docs/             # Documentation
```

### Build and Run

```bash
../cpm build    # Build the project
../cpm run      # Build and run
```

### Run Tests

```bash
../cpm test
```

## Language Basics

### Variables

```corin
let x = 42
let name = "Alice"
let pi = 3.14159
```

### Functions

```corin
fn add(a: int, b: int) -> int {
    return a + b
}

let result = add(10, 20)
print(result)  # 30
```

### Control Flow

```corin
# If statements
if x > 10 {
    print("x is big")
} else {
    print("x is small")
}

# While loops
let i = 0
while i < 5 {
    print(i)
    i = i + 1
}
```

### Data Structures

```corin
# Arrays (Vec)
let numbers = Vec::new()
numbers.push(1)
numbers.push(2)
numbers.push(3)

# Hash maps
let ages = HashMap::new()
ages["Alice"] = 30
ages["Bob"] = 25

# Strings
let greeting = "Hello, " + "World!"
```

## Standard Library

Corin includes a rich standard library:

### String Operations

```corin
let text = "Hello, World!"
let upper = text.to_upper()
let parts = text.split(", ")
```

### File I/O

```corin
# Write to file
File::write_all("data.txt", "Hello, File!")

# Read from file
let content = File::read_all("data.txt")
print(content)
```

### Math Functions

```corin
let x = Math::sqrt(16.0)    # 4.0
let y = Math::sin(Math::PI)  # 0.0
let z = Math::pow(2.0, 3.0)  # 8.0
```

### JSON

```corin
# Parse JSON
let json = JSON::parse('{"name": "Alice", "age": 30}')
print(json["name"])  # Alice

# Create JSON
let obj = JSON::object()
obj["name"] = "Bob"
obj["age"] = 25
print(obj.serialize())
```

## Concurrency

Corin has built-in concurrency support:

### Threads

```corin
# Spawn a thread
let t = Thread::spawn(|| {
    print("Hello from thread!")
})
t.join()
```

### Channels

```corin
# Create a channel
let ch = Channel::new()

# Send in one thread
Thread::spawn(|| {
    ch.send(42)
})

# Receive in another
let value = ch.receive()
print(value)  # 42
```

### Thread Pool

```corin
# Create a thread pool
let pool = ThreadPool::new(4)

# Submit tasks
let future = pool.submit(|| {
    return expensive_computation()
})

let result = future.get()
```

## Next Steps

- Read the [Language Tutorial](LANGUAGE_TUTORIAL.md) for in-depth coverage
- Explore the [Standard Library Guide](STANDARD_LIBRARY.md)
- Learn about [Concurrency](CONCURRENCY_GUIDE.md)
- Check out [Example Projects](../examples/)

## Getting Help

- Documentation: `docs/` directory
- Examples: `examples/` directory
- Issues: GitHub Issues
- Community: (Coming soon!)

## Quick Reference

### Common Commands

```bash
# Compiler
./corin program.crn              # Run program
./corin compile program.crn      # Compile to LLVM IR

# Package Manager
./cpm init <name>               # Create new project
./cpm build                     # Build project
./cpm run                       # Build and run
./cpm test                      # Run tests
./cpm clean                     # Clean build artifacts
./cpm doc                       # Generate docs
./cpm fmt                       # Format code

# Tools
./corin-fmt file.crn         # Format code
./corin-fmt --check file.crn # Check formatting
```

### Syntax Cheat Sheet

```corin
# Comments
# This is a comment

# Variables
let x = 42
let name = "Alice"

# Functions
fn add(a: int, b: int) -> int {
    return a + b
}

# Control flow
if condition {
    # ...
} else {
    # ...
}

while condition {
    # ...
}

# Data structures
let vec = Vec::new()
let map = HashMap::new()
let str = String::new()

# Concurrency
let thread = Thread::spawn(|| { })
let channel = Channel::new()
let pool = ThreadPool::new(4)
```

Welcome to Corin! Happy coding!
