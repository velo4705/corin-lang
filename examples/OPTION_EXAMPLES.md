# Option Type Examples

Corin's Option<T> type provides a type-safe way to handle nullable values, inspired by Rust's Option type.

## Available Examples

### 1. option_comprehensive.crn
Complete feature demonstration covering all Option capabilities:
- Basic construction (Some/None)
- State checking (is_some/is_none)
- Safe unwrapping (unwrap/unwrap_or)
- Pattern matching
- Transformations (map)
- Chaining (and_then)
- Nested Options
- Real-world scenarios

Run: `./corin examples/option_comprehensive.crn`

### 2. option_practical.crn
Real-world usage patterns:
- Safe dictionary lookup
- Configuration with defaults
- Chained operations
- Optional function parameters
- Safe array access
- Transforming values
- Multiple pattern matching
- Nested Options
- Option in loops

Run: `./corin examples/option_practical.crn`

### 3. option_error_handling.crn
Error handling patterns with Option:
- Safe division
- Safe string parsing
- Cascading operations with early exit
- Optional return values
- Avoiding null pointer errors

Run: `./corin examples/option_error_handling.crn`

## Quick Reference

### Construction
```corin
let some_value = Some(42)
let no_value = None()
```

### Methods
```corin
# Check state
some_value.is_some()  # true
some_value.is_none()  # false

# Unwrap
some_value.unwrap()        # 42 (or throws if None)
no_value.unwrap_or(0)      # 0 (returns default)

# Transform
some_value.map(double)     # Some(84)
no_value.map(double)       # None

# Chain
some_value.and_then(safe_divide)  # Chains operations
```

### Pattern Matching
```corin
match some_value:
    Some(x) => print("Value:", x)
    None => print("No value")

# Multiple patterns
match opt:
    Some(0) => print("Zero")
    Some(x) => print("Non-zero:", x)
    None => print("None")
```

## Common Patterns

### Safe Lookup
```corin
fn find_user(id):
    if id == 1:
        return Some("Alice")
    return None()

let user = find_user(1).unwrap_or("Guest")
```

### Configuration Defaults
```corin
let port = get_config("port").unwrap_or(8080)
let host = get_config("host").unwrap_or("localhost")
```

### Chained Transformations
```corin
let result = parse_int(input)
    .and_then(validate)
    .and_then(process)
    .unwrap_or(default_value)
```

### Safe Array Access
```corin
fn safe_get(arr, index):
    if index >= 0 and index < len(arr):
        return Some(arr[index])
    return None()

let item = safe_get(numbers, 5).unwrap_or(-1)
```

## Next: Result<T, E> Type

Coming in Phase 2 of Milestone 5:
- Result<T, E> for error handling
- Ok(value) and Err(error) constructors
- Pattern matching with Ok/Err
- ? operator for error propagation
