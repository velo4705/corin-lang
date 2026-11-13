# Corin Keywords Reference

Complete list of all keywords, reserved words, and their usage in Corin.

## Control Flow Keywords

### `if` / `else` / `elif`
Conditional execution

```corin
if x > 0:
    print("positive")
elif x < 0:
    print("negative")
else:
    print("zero")
```

### `match`
Pattern matching

```corin
match value:
    0 => print("zero")
    1..=10 => print("small")
    _ => print("large")
```

### `while`
Loop while condition is true

```corin
while x < 10:
    print(x)
    x += 1
```

### `for`
Iterate over collection

```corin
for item in collection:
    print(item)

for i in 0..10:
    print(i)
```

### `loop`
Infinite loop

```corin
loop:
    if should_break():
        break
```

### `break`
Exit loop

```corin
for i in 0..100:
    if i == 50:
        break
```

### `continue`
Skip to next iteration

```corin
for i in 0..10:
    if i % 2 == 0:
        continue
    print(i)
```

### `return`
Return from function

```corin
fn add(a, b):
    return a + b
```

## Declaration Keywords

### `let`
Variable declaration

```corin
let x = 42
let mut y = 10  // Mutable
let z: i64 = 100  // With type
```

### `const`
Constant declaration

```corin
const PI = 3.14159
const MAX_SIZE: usize = 1000
```

### `static`
Static variable

```corin
static COUNTER: i64 = 0
static mut GLOBAL: String = ""
```

### `fn`
Function declaration

```corin
fn add(a: i64, b: i64) -> i64:
    return a + b
```

### `type`
Type alias or struct definition

```corin
type Point = (i64, i64)

type User {
    name: String
    age: i64
}
```

### `enum`
Enumeration

```corin
enum Color {
    Red
    Green
    Blue
}
```

### `struct`
Structure (alternative syntax)

```corin
struct Point {
    x: i64
    y: i64
}
```

### `class`
Class definition

```corin
class Animal {
    fn speak(self):
        print("...")
}
```

### `trait`
Trait definition

```corin
trait Drawable {
    fn draw(self)
}
```

### `impl`
Implementation block

```corin
impl Point {
    fn new(x: i64, y: i64) -> Point {
        return Point { x, y }
    }
}
```

## Module Keywords

### `import`
Import module or items

```corin
import math
import json::{parse, stringify}
import http::*
```

### `from`
Import from module

```corin
from math import sqrt, pow
from collections import Vec, HashMap
```

### `export`
Export items

```corin
export fn public_function() { }
export type PublicType { }
```

### `mod`
Module declaration

```corin
mod utils {
    fn helper() { }
}
```

### `use`
Bring items into scope

```corin
use std::collections::HashMap
use super::parent_module
use self::current_module
```

### `pub`
Public visibility

```corin
pub fn public_function() { }
pub type PublicType { }
```

### `priv`
Private visibility (default)

```corin
priv fn private_function() { }
```

## Type Keywords

### `i8`, `i16`, `i32`, `i64`, `i128`
Signed integers

```corin
let x: i32 = -42
let y: i64 = 1000
```

### `u8`, `u16`, `u32`, `u64`, `u128`
Unsigned integers

```corin
let x: u32 = 42
let y: u64 = 1000
```

### `f32`, `f64`
Floating point

```corin
let x: f32 = 3.14
let y: f64 = 2.71828
```

### `bool`
Boolean type

```corin
let x: bool = true
let y: bool = false
```

### `char`
Character type

```corin
let c: char = 'A'
```

### `str`
String type

```corin
let s: str = "Hello"
```

### `void`
No return value

```corin
fn print_message() -> void {
    print("Hello")
}
```

### `never`
Never returns

```corin
fn panic() -> never {
    abort()
}
```

### `any`
Any type

```corin
let x: any = 42
let y: any = "string"
```

## Memory Keywords

### `ref`
Reference

```corin
let x = 42
let r: &i64 = &x
```

### `mut`
Mutable

```corin
let mut x = 42
x = 50
```

### `move`
Move ownership

```corin
let x = vec![1, 2, 3]
let y = move x  // x is no longer valid
```

### `copy`
Copy value

```corin
let x = 42
let y = copy x
```

### `clone`
Deep clone

```corin
let x = vec![1, 2, 3]
let y = x.clone()
```

### `drop`
Explicitly drop value

```corin
let x = allocate_resource()
drop(x)  // Free immediately
```

## Async Keywords

### `async`
Async function

```corin
async fn fetch_data() -> String {
    let response = await http.get(url)
    return response.text()
}
```

### `await`
Wait for async operation

```corin
let data = await fetch_data()
```

### `yield`
Yield value from generator

```corin
fn* generator() {
    yield 1
    yield 2
    yield 3
}
```

## Error Handling Keywords

### `try`
Try block

```corin
try {
    risky_operation()
} catch e {
    handle_error(e)
}
```

### `catch`
Catch exception

```corin
try {
    may_fail()
} catch FileNotFoundError as e {
    print(f"File not found: {e}")
} catch e {
    print(f"Other error: {e}")
}
```

### `finally`
Always execute

```corin
try {
    open_file()
} catch e {
    handle_error(e)
} finally {
    cleanup()
}
```

### `throw`
Throw exception

```corin
fn validate(x: i64) {
    if x < 0:
        throw ValueError("x must be positive")
}
```

### `panic`
Unrecoverable error

```corin
if critical_error:
    panic("System failure!")
```

## Ownership Keywords

### `own`
Owned value

```corin
fn take_ownership(x: own String) {
    // x is owned here
}
```

### `borrow`
Borrowed reference

```corin
fn use_reference(x: borrow String) {
    // x is borrowed
}
```

### `lifetime`
Lifetime annotation

```corin
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}
```

## Unsafe Keywords

### `unsafe`
Unsafe code block

```corin
unsafe {
    let ptr = raw_pointer()
    *ptr = 42
}
```

### `raw`
Raw pointer

```corin
let ptr: *mut i64 = raw_alloc()
```

## Concurrency Keywords

### `atomic`
Atomic operation

```corin
let counter: atomic i64 = 0
counter.fetch_add(1)
```

### `sync`
Synchronization

```corin
sync {
    // Synchronized block
    shared_data.modify()
}
```

### `spawn`
Spawn thread

```corin
spawn {
    background_task()
}
```

## Special Keywords

### `self`
Current instance

```corin
impl Point {
    fn distance(self) -> f64 {
        return sqrt(self.x * self.x + self.y * self.y)
    }
}
```

### `Self`
Current type

```corin
impl Point {
    fn new() -> Self {
        return Self { x: 0, y: 0 }
    }
}
```

### `super`
Parent class/module

```corin
class Child: Parent {
    fn method(self) {
        super.method()
    }
}
```

### `this`
Alternative to self

```corin
class MyClass {
    fn method(this) {
        print(this.value)
    }
}
```

## Literal Keywords

### `true` / `false`
Boolean literals

```corin
let x = true
let y = false
```

### `null` / `nil` / `none`
Null value

```corin
let x = null
let y: Option<i64> = None
```

### `inf`
Infinity

```corin
let x = inf
let y = -inf
```

### `nan`
Not a number

```corin
let x = nan
```

## Operator Keywords

### `and` / `or` / `not`
Logical operators

```corin
if x > 0 and y > 0:
    print("both positive")

if x > 0 or y > 0:
    print("at least one positive")

if not x:
    print("x is false")
```

### `in`
Membership test

```corin
if item in collection:
    print("found")
```

### `is`
Identity test

```corin
if x is None:
    print("x is None")
```

### `as`
Type cast

```corin
let x = 42 as f64
let y = value as String
```

### `typeof`
Get type

```corin
let t = typeof(x)
print(t)
```

### `sizeof`
Get size

```corin
let size = sizeof(i64)  // 8 bytes
```

## Context Keywords

### `with`
Context manager

```corin
with File.open("data.txt") as f:
    let content = f.read()
```

### `defer`
Defer execution

```corin
fn process() {
    let file = open("data.txt")
    defer file.close()
    
    // file.close() called automatically
}
```

### `guard`
Early return

```corin
fn process(x: Option<i64>) {
    guard let value = x else {
        return
    }
    // value is available here
}
```

## Macro Keywords

### `macro`
Define macro

```corin
macro! debug(expr) {
    print(f"[DEBUG] {expr}")
}
```

### `quote`
Quote code

```corin
let code = quote! {
    let x = 42
}
```

### `unquote`
Unquote code

```corin
let expr = parse_expr()
let code = quote! {
    let x = unquote!(expr)
}
```

## Testing Keywords

### `test`
Test function

```corin
#[test]
fn test_addition() {
    assert_eq!(2 + 2, 4)
}
```

### `assert`
Assertion

```corin
assert(x > 0)
assert_eq!(x, 42)
assert_ne!(x, 0)
```

### `debug_assert`
Debug-only assertion

```corin
debug_assert!(x > 0)
```

## Reserved Keywords

These keywords are reserved for future use:

- `abstract`
- `become`
- `box`
- `do`
- `final`
- `macro_rules`
- `override`
- `priv`
- `typeof`
- `unsized`
- `virtual`
- `where`
- `yield`

## Contextual Keywords

These are keywords only in specific contexts:

- `dyn` - Dynamic dispatch
- `union` - Union type
- `'static` - Static lifetime
- `crate` - Current crate
- `extern` - External linkage

## Soft Keywords

These can be used as identifiers in some contexts:

- `auto` - Type inference
- `default` - Default value
- `macro` - Macro definition

## Best Practices

1. **Don't use keywords as identifiers** - They're reserved
2. **Use descriptive names** - Don't rely on keywords alone
3. **Follow conventions** - Use snake_case for variables, PascalCase for types
4. **Be consistent** - Pick one style and stick to it
5. **Avoid reserved keywords** - They may become keywords in future versions

## See Also

- [Language Features](LANGUAGE_FEATURES.md)
- [Syntax Guide](syntax.md)
- [Type System](TYPE_SYSTEM.md)
- [Operators](OPERATORS.md)
