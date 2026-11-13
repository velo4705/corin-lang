# Quick Start Guide

## Installation

### Build from Source

```bash
# Clone repository
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang

# Build (requires C++20 compiler)
make quick

# Verify installation
./corin --version
```

## Your First Program

Create `hello.corin`:

```corin
# Hello World in Corin
let message = "Hello, Corin!"
print(message)
```

Run it:

```bash
./corin hello.corin
# or
./corin hello.corin
```

**Note:** Both `corin` (short) and `corin` (full) work!

Output:
```
Hello, Corin!
```

## Basic Examples

### Variables and Arithmetic

```corin
let x = 10
let y = 20
let sum = x + y
print(sum)  # 30

let power = 2 ** 8
print(power)  # 256
```

### Conditionals

```corin
let age = 25

if age >= 18:
    print("Adult")
else:
    print("Minor")
```

### Loops

```corin
# While loop
let i = 0
while i < 5:
    print(i)
    i = i + 1

# For loop
for j in range(10):
    print(j)
```

### Comments

```corin
# This is a single-line comment

let x = 42  # Inline comment
```

## What Works Now (Milestone 1)

✅ Variables (let/const)  
✅ Integers, floats, strings, booleans  
✅ Arithmetic (+, -, *, /, %, **)  
✅ Comparisons (==, !=, <, <=, >, >=)  
✅ Logical operators (and, or, not)  
✅ If/else statements  
✅ While loops  
✅ For loops with range  
✅ Print function  
✅ Comments  

## What's Coming Next (Milestone 2)

⏳ Type system and inference  
⏳ Function calls  
⏳ Classes and objects  
⏳ Imports  
⏳ Better error messages  
⏳ More built-in functions  

## More Examples

Check out the `examples/` directory:

```bash
./corin examples/demo.corin
./corin examples/simple.corin
```

## Getting Help

- Documentation: `docs/`
- Examples: `examples/`
- Issues: GitHub Issues
- Contributing: `CONTRIBUTING.md`

## Next Steps

1. Read [Language Features](LANGUAGE_FEATURES.md)
2. Explore [Examples](../examples/)
3. Check [Project Status](PROJECT_STATUS.md)
4. Contribute! See [CONTRIBUTING.md](../CONTRIBUTING.md)
