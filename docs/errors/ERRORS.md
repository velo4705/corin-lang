# Corin Error Reference

Error codes follow the format `E<category><hex>` — each category has 256 slots (`E_00`–`E_FF`).

| Range | Category |
|-------|----------|
| E1xx  | Syntax   |
| E2xx  | Name     |
| E3xx  | Type     |
| E4xx  | Runtime  |
| E5xx  | Import   |
| E6xx  | IO       |
| E7xx  | Value    |

Run `corin --explain <code>` for a quick inline description.

---

## E1xx — Syntax

### E1A0 — unexpected token

The parser hit a token it didn't expect at that position.

```corin
# bad
if x > 0
    print("yes")

# fix — add colon
if x > 0:
    print("yes")
```

**note:** check for missing colons, parentheses, or mismatched brackets.

---

### E1A1 — expected expression

An expression (value, variable, or call) was required but not found.

```corin
# bad
x = +

# fix
x = 1 + 2
```

---

### E1A2 — invalid indentation

Corin uses 4-space indentation. Mixing tabs and spaces causes this.

```corin
# bad (tab used instead of spaces)
fn greet():
	print("hi")   # tab

# fix
fn greet():
    print("hi")   # 4 spaces
```

**note:** configure your editor to insert spaces on Tab.

---

### E1A3 — unterminated string

A string literal was opened but never closed.

```corin
# bad
name = "Alice

# fix
name = "Alice"
```

---

### E1A4 — invalid decorator placement

Decorators can only be applied to functions and classes.

```corin
# bad
@cached
x = 10

# fix — decorators go on fn/class only
@cached
fn compute():
    ...
```

---

### E1A5 — missing colon

`fn`, `class`, `if`, `for`, and `while` bodies must end with `:`.

```corin
# bad
fn add(a, b)
    return a + b

# fix
fn add(a, b):
    return a + b
```

---

### E1A6 — invalid assignment target

Only variables and subscript expressions can be on the left side of `=`.

```corin
# bad
1 = x

# fix
x = 1
```

---

### E1A7 — body must be indented on the next line

Corin does not allow single-line `if`/`while`/`fn` bodies. The body must be on the next line, indented.

```corin
# bad
if x > 0: print("yes")

# fix
if x > 0:
    print("yes")
```

**note:** this applies to `fn`, `class`, `while`, `for`, and `if`/`else` blocks.

---

## E2xx — Name

### E2A0 — undefined variable

The variable was used before being defined, or the name is misspelled.

```corin
# bad
print(count)   # count not defined yet

# fix
count = 0
print(count)
```

---

### E2A1 — undefined function

The function doesn't exist in scope, or the module wasn't imported.

```corin
# bad
result = sqrt(16)

# fix
import math
result = math.sqrt(16)
```

---

### E2A2 — undefined module

The module name is wrong or not installed.

```corin
# bad
import mathz   # typo

# fix
import math
```

---

### E2A3 — attribute not found

The object doesn't have the attribute or method you're accessing.

```corin
# bad
x = 42
x.append(1)   # int has no append

# fix
items = []
items.append(1)
```

---

## E3xx — Type

### E3A0 — type mismatch

A value of the wrong type was passed or assigned.

```corin
# bad
x = "hello" + 5

# fix
x = "hello" + str(5)
```

---

### E3A1 — unsupported operand types

The operator doesn't support the given types.

```corin
# bad
result = [1, 2] * [3, 4]

# fix
result = [1, 2] + [3, 4]   # list concatenation
```

---

### E3A2 — not callable

You tried to call something that isn't a function or class.

```corin
# bad
x = 42
x()

# fix — call an actual function
fn greet():
    print("hi")
greet()
```

---

### E3A3 — not iterable

`for` loops require a list, string, range, or other iterable.

```corin
# bad
for i in 42:
    print(i)

# fix
for i in range(42):
    print(i)
```

---

### E3A4 — not subscriptable

Only lists, strings, and dicts support `[]` indexing.

```corin
# bad
x = 42
print(x[0])

# fix
items = [42]
print(items[0])
```

---

## E4xx — Runtime

### E4A0 — index out of bounds

The index is outside the valid range of the list or string.

```corin
# bad
items = [1, 2, 3]
print(items[5])

# fix — check length first
if 5 < len(items):
    print(items[5])
```

---

### E4A1 — division by zero

The divisor evaluated to zero.

```corin
# bad
result = 10 / 0

# fix
divisor = 0
if divisor != 0:
    result = 10 / divisor
```

---

### E4A2 — assertion failed

An `assert()` condition was false.

```corin
# bad
assert(1 == 2)

# fix — assert only things that should always be true
assert(len(items) > 0)
```

---

### E4A3 — null dereference

A value is `none` and you tried to use it.

```corin
# bad
x = none
print(x.name)

# fix
if x != none:
    print(x.name)
```

---

### E4A4 — stack overflow

A function is recursing too deeply — usually a missing or wrong base case.

```corin
# bad
fn count(n):
    return count(n - 1)   # no base case

# fix
fn count(n):
    if n <= 0:
        return 0
    return count(n - 1)
```

---

## E5xx — Import

### E5A0 — module not found

The module doesn't exist or isn't installed.

```corin
# bad
import nonexistent_module

# fix — check available stdlib modules
import math
import json
import http
```

---

### E5A1 — circular import

Two modules are importing each other, creating a cycle.

```
# a.corin imports b.corin
# b.corin imports a.corin  ← cycle

# fix — extract shared code into a third module c.corin
# both a.corin and b.corin import c.corin
```

---

## E6xx — IO

### E6A0 — file not found

The file path doesn't exist or is wrong.

```corin
# bad
import fs
content = fs.read("data.txt")   # file doesn't exist

# fix — check path or handle the error
if fs.exists("data.txt"):
    content = fs.read("data.txt")
```

---

### E6A1 — permission denied

The process doesn't have read/write access to the file.

```
# fix — check file permissions
# Linux/macOS: chmod 644 file.txt
# or run with appropriate privileges
```

---

## E7xx — Value

### E7A0 — invalid argument

A function received an argument with an unexpected value.

```corin
# bad
import math
math.sqrt(-1)   # negative input to sqrt

# fix
import math
math.sqrt(abs(-1))
```

---

### E7A1 — argument count mismatch

Wrong number of arguments passed to a function.

```corin
# bad
fn add(a, b):
    return a + b

add(1)       # missing second arg
add(1, 2, 3) # too many args

# fix
add(1, 2)
```

---

### E7A2 — value out of range

The value exceeds the allowed range for the operation.

```corin
# bad
import time
time.sleep(-5)   # negative sleep duration

# fix
time.sleep(1)
```

---

*Run `corin --explain <code>` for a quick inline summary of any error.*
