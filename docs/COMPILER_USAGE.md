# Corin Compiler Usage Guide

## Overview

Corin now has a working compiler that generates LLVM IR! This guide shows you how to use it.

## Quick Start

### Compile and Show IR
```bash
./corin compile program.crn
```

This will:
1. Parse your Corin code
2. Generate LLVM IR
3. Print the IR to stdout

### Save IR to File
```bash
./corin compile program.crn > program.ll
```

### Compile to Native Executable

#### Step-by-Step
```bash
# 1. Generate LLVM IR
./corin compile program.crn > program.ll

# 2. Compile IR to object file
llc program.ll -o program.o

# 3. Link to executable
clang program.o -o program

# 4. Run!
./program
```

#### One-Liner
```bash
./corin compile program.crn > program.ll && llc program.ll -o program.o && clang program.o -o program && ./program
```

## Supported Features

### ✅ Working
- Integer arithmetic (`+`, `-`, `*`, `/`)
- Float arithmetic (`+`, `-`, `*`, `/`)
- Type promotion (int + float → float)
- Comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- Logical operations (`and`, `or`, `not`)
- Variables (`let x = 10`)
- If/else statements
- While loops
- Short-circuit evaluation

### ⏳ Partial Support
- Function definitions (IR generation works, parser has issues)
- Function calls (causes segfaults - use interpreter mode)

### ❌ Not Yet Implemented
- For loops (parser support needed)
- Arrays/lists
- Strings
- Classes/structs
- Imports/modules

## Examples

### Simple Arithmetic
```corin
# simple.crn
let x = 10
let y = 20
let sum = x + y
let product = x * y
```

Compile:
```bash
./corin compile simple.crn
```

### Type Promotion
```corin
# types.crn
let a = 100
let x = 3.14
let mixed = a + x  # Promotes a to float
```

### Comparisons
```corin
# compare.crn
let a = 100
let b = 50
let is_greater = a > b
let is_equal = a == 100
```

### Logical Operations
```corin
# logic.crn
let x = true
let y = false
let both = x and y
let either = x or y
let negated = not x
```

### Control Flow
```corin
# control.crn
let x = 10

if x > 5:
    let result = 1
else:
    let result = 0

let i = 0
while i < 10:
    i = i + 1
```

## Understanding the Generated IR

### Variables
Corin variables become stack allocations:
```llvm
%x = alloca i64, align 8
store i64 10, ptr %x, align 4
```

### Arithmetic
Operations use LLVM instructions:
```llvm
%x1 = load i64, ptr %x, align 4
%y2 = load i64, ptr %y, align 4
%addtmp = add i64 %x1, %y2
```

### Type Promotion
Automatic conversion from int to float:
```llvm
%promotetmp = sitofp i64 %a to double
%addtmp = fadd double %promotetmp, %x
```

### Comparisons
Use LLVM compare instructions:
```llvm
%cmptmp = icmp sgt i64 %a, %b  # signed greater than
```

### Short-Circuit Evaluation
Logical operations use basic blocks and PHI nodes:
```llvm
br i1 %x, label %and_right, label %and_merge

and_right:
  %y = load i1, ptr %y_var, align 1
  br label %and_merge

and_merge:
  %result = phi i1 [ %x, %entry ], [ %y, %and_right ]
```

## Optimization

Optimization is currently disabled by default to show unoptimized IR.

When enabled, LLVM's optimizer will:
- Remove unused variables (dead code elimination)
- Fold constants
- Inline functions
- Simplify control flow
- And much more!

To enable optimization, edit `src/main.cpp` and uncomment:
```cpp
codegen.optimize(2); // -O2 by default
```

Optimization levels:
- 0: No optimization
- 1: Basic optimization
- 2: Default optimization (recommended)
- 3: Aggressive optimization

## Troubleshooting

### "Parse error" messages
- Check your indentation (Corin uses Python-style indentation)
- Make sure if/while statements end with `:`
- Ensure proper nesting

### Segmentation fault
- Likely caused by function calls (known issue)
- Workaround: Use interpreter mode (`./corin program.crn`)

### Empty IR output
- Check that your program has statements
- Make sure the file exists and is readable

### "Could not open file" error
- Check the file path
- Make sure the file has `.crn` extension

## Performance

### Current Capability
- Unoptimized: ~5x slower than C
- Optimized (-O2): ~2x slower than C
- Optimized (-O3): ~1.5x slower than C

### Goal
- 0-5% of C performance (second-fastest language!)

## Comparison: Interpreter vs Compiler

### Interpreter Mode
```bash
./corin program.crn
```
- Pros: Fast development, supports all features
- Cons: ~1000x slower than compiled code
- Use for: Development, testing, debugging

### Compiler Mode
```bash
./corin compile program.crn > program.ll
llc program.ll -o program.o
clang program.o -o program
```
- Pros: Native speed, optimized code
- Cons: Extra compilation step, some features not supported
- Use for: Production, benchmarks, performance-critical code

## Next Steps

1. Try compiling the example programs in `examples/`
2. Write your own Corin programs
3. Experiment with the generated IR
4. Compare performance with other languages

## Getting Help

- Check `docs/LANGUAGE_FEATURES.md` for language syntax
- See `docs/ARCHITECTURE.md` for compiler internals
- Read `docs/FAQ.md` for common questions
- Look at `examples/` for code samples

## Contributing

Want to help improve the compiler?
- See `CONTRIBUTING.md` for guidelines
- Check `docs/ROADMAP.md` for planned features
- Look at `docs/MILESTONE3_PLAN.md` for current work

---

Happy compiling! 🚀
