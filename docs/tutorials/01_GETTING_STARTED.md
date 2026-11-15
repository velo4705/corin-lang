# Tutorial 1: Getting Started with Corin

Welcome to Corin! This tutorial will help you write your first Corin program.

## What is Corin?

Corin is a high-performance programming language designed to be:
- **Fast** - Second only to C/Assembly in speed
- **Multi-purpose** - Great for algorithms, GUIs, OS development, and HPC
- **Easy to learn** - Clean syntax similar to Python and modern languages

## Installation

### Prerequisites
- Linux, macOS, or Windows
- C++ compiler (g++ or clang)
- CMake (optional)

### Quick Install
```bash
git clone https://github.com/corindev/corin-lang.git
cd corin-lang
./install.sh
```

This will install:
- `corin` - Corin compiler
- `cpm` - Corin package manager
- `corin-fmt` - Code formatter

### Verify Installation
```bash
corin --version
```

## Your First Program

### Hello, World!

Create a file called `hello.crn`:

```corin
fn main() {
    println("Hello, World!")
}
```

### Run Your Program

```bash
corin hello.crn
```

You should see:
```
Hello, World!
```

### How It Works

1. `fn main()` - Every Corin program starts with a `main` function
2. `println()` - Prints text to the console with a newline
3. `"Hello, World!"` - A string (text) in quotes

## Basic Output

### Printing Text

```corin
fn main() {
    println("Welcome to Corin!")
    println("This is line 2")
    println("This is line 3")
}
```

### Printing Without Newline

```corin
fn main() {
    print("Hello, ")
    print("World!")
    println("")  // Add newline at the end
}
```

Output:
```
Hello, World!
```

### Printing Numbers

```corin
fn main() {
    println(42)
    println(3.14)
    println(true)
}
```

Output:
```
42
3.14
true
```

## Comments

Comments help explain your code:

```corin
// This is a single-line comment

/*
This is a
multi-line comment
*/

fn main() {
    println("Hello!")  // This prints a greeting
}
```

## Variables

Variables store data:

```corin
fn main() {
    // Declare a variable
    let name = "Alice"
    let age = 25
    let height = 5.6
    
    // Print variables
    println(name)
    println(age)
    println(height)
}
```

### Variable Types

Corin has automatic type inference, but you can specify types:

```corin
fn main() {
    let name: str = "Bob"
    let age: int = 30
    let height: float = 5.9
    let is_student: bool = true
    
    println(name)
    println(age)
    println(height)
    println(is_student)
}
```

### Mutable Variables

By default, variables are immutable (can't be changed). Use `mut` for mutable variables:

```corin
fn main() {
    let x = 5
    // x = 10  // Error! x is immutable
    
    let mut y = 5
    y = 10  // OK! y is mutable
    println(y)
}
```

## Basic Math

```corin
fn main() {
    let a = 10
    let b = 3
    
    println(a + b)  // Addition: 13
    println(a - b)  // Subtraction: 7
    println(a * b)  // Multiplication: 30
    println(a / b)  // Division: 3
    println(a % b)  // Modulo (remainder): 1
}
```

## String Concatenation

```corin
fn main() {
    let first_name = "John"
    let last_name = "Doe"
    
    // Concatenate strings with +
    let full_name = first_name + " " + last_name
    println(full_name)  // John Doe
}
```

## User Input

Get input from the user:

```corin
fn main() {
    print("What is your name? ")
    let name = input()
    
    println("Hello, " + name + "!")
}
```

## Practice Exercises

### Exercise 1: Personal Info
Write a program that asks for your name and age, then prints a greeting.

**Expected output:**
```
What is your name? Alice
How old are you? 25
Hello, Alice! You are 25 years old.
```

### Exercise 2: Calculator
Write a program that adds two numbers:

```corin
fn main() {
    let a = 15
    let b = 27
    let sum = a + b
    println("The sum is: " + str(sum))
}
```

### Exercise 3: Temperature Converter
Convert Celsius to Fahrenheit:

```corin
fn main() {
    let celsius = 25.0
    let fahrenheit = (celsius * 9.0 / 5.0) + 32.0
    println("Temperature in Fahrenheit: " + str(fahrenheit))
}
```

## Common Mistakes

### 1. Forgetting Quotes Around Strings
```corin
// Wrong:
let name = Alice  // Error!

// Correct:
let name = "Alice"
```

### 2. Trying to Change Immutable Variables
```corin
// Wrong:
let x = 5
x = 10  // Error!

// Correct:
let mut x = 5
x = 10  // OK
```

### 3. Missing Parentheses in Function Calls
```corin
// Wrong:
println "Hello"  // Error!

// Correct:
println("Hello")
```

## Summary

In this tutorial, you learned:
- ✅ How to install Corin
- ✅ How to write and run your first program
- ✅ How to print output
- ✅ How to use variables
- ✅ How to do basic math
- ✅ How to get user input

## Next Steps

Continue to [Tutorial 2: Control Flow](02_CONTROL_FLOW.md) to learn about:
- If statements
- Loops
- Conditional logic

## Need Help?

- Check the [FAQ](../FAQ.md)
- Read the [Language Features](../LANGUAGE_FEATURES.md)
- Join our community (Discord/Forum)

Happy coding! 🚀
