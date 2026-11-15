# Corin Tooling Guide

This guide covers the developer tools available in the Corin ecosystem.

---

## Package Manager (cpm)

The Corin Package Manager helps you create, build, test, and manage Corin projects.

### Installation

The cpm tool is built automatically with the Corin compiler:

```bash
make cpm
```

### Commands

#### Create a New Package

```bash
cpm init my-package
```

Creates a new package with the following structure:
```
my-package/
├── cpm.toml          # Package manifest
├── src/
│   └── main.crn      # Main source file
├── tests/            # Test files
├── examples/         # Example files
├── README.md
└── .gitignore
```

#### Build Package

```bash
cpm build
```

Validates and builds all source files in the `src/` directory.

#### Run Tests

```bash
cpm test
```

Runs all `.crn` files in the `tests/` directory and reports results.

#### Run a File

```bash
cpm run src/main.crn
```

Executes a Corin file using the interpreter.

#### Clean Build Artifacts

```bash
cpm clean
```

Removes build artifacts and compiled binaries.

#### Install Dependencies

```bash
cpm install <package>
```

Note: Package registry not yet implemented. Manually add dependencies to `cpm.toml`:

```toml
[dependencies]
http = "1.0.0"
json = "2.0.0"
```

#### Publish Package

```bash
cpm publish
```

Note: Package registry not yet implemented. Validates package structure.

### Package Manifest (cpm.toml)

```toml
[package]
name = "my-package"
version = "0.1.0"
authors = ["Your Name <your.email@example.com>"]
license = "MIT"
description = "A Corin package"

[dependencies]
# Add dependencies here

[dev-dependencies]
# Add dev dependencies here

[build]
target = "native"
optimization = "release"
```

---

## Code Formatter (corin-fmt)

The Corin code formatter ensures consistent code style across your project.

### Installation

The formatter is built automatically with the Corin compiler:

```bash
make corin-fmt
```

### Commands

#### Format a File

```bash
corin-fmt file.crn
```

Formats the file in-place according to Corin style guidelines.

#### Check Formatting

```bash
corin-fmt --check file.crn
```

Checks if a file is formatted correctly without modifying it. Returns exit code 0 if formatted, 1 if needs formatting.

#### Custom Indent Size

```bash
corin-fmt --indent 2 file.crn
```

Formats with a custom indent size (default is 4 spaces).

### Style Rules

The formatter applies the following rules:

1. **Indentation**: 4 spaces (configurable)
2. **Operators**: Spaces around =, +, -, *, /, <, >, !
3. **Arrow Operator**: Preserved as `->` with spaces: `fn foo() -> int:`
4. **Commas**: Space after commas in parameter lists
5. **Strings**: Preserved exactly as written
6. **Comments**: Preserved with original content

### Examples

Before formatting:
```corin
fn add(a:int,b:int)->int:
x=a+b
return x
```

After formatting:
```corin
fn add(a:int, b:int) -> int:
    x = a + b
    return x
```

### Integration with cpm

You can use the formatter with cpm:

```bash
# Format all source files
find src -name "*.crn" -exec corin-fmt {} \;

# Check formatting in CI
find src -name "*.crn" -exec corin-fmt --check {} \;
```

### Known Limitations

- Indentation inference works best with already-indented code
- No configuration file support yet (.crn-fmt.toml)
- Processes one file at a time (no directory recursion)
- Basic dedent detection (may need manual adjustment for complex nesting)

---

## Compiler (corin)

The Corin compiler and interpreter.

### Usage

```bash
# Run a file
./corin file.crn

# With verbose output
./corin -v file.crn

# Show version
./corin --version
```

### Building

```bash
# Quick build
make quick

# Full build with CMake
./scripts/build.sh
```

---

## Workflow Examples

### Creating a New Project

```bash
# Create package
cpm init my-app
cd my-app

# Write code
vim src/main.crn

# Format code
corin-fmt src/main.crn

# Run it
cpm run src/main.crn

# Add tests
vim tests/test_main.crn

# Run tests
cpm test
```

### Formatting Workflow

```bash
# Format before committing
find src -name "*.crn" -exec corin-fmt {} \;

# Check in CI
corin-fmt --check src/**/*.crn
```

### Testing Workflow

```bash
# Run all tests
cpm test

# Run specific test
cpm run tests/test_feature.crn

# Clean and rebuild
cpm clean
cpm build
cpm test
```

---

## Future Enhancements

### Package Manager
- Remote package registry
- Dependency resolution
- Version management
- Package publishing
- Lock file (cpm.lock)

### Code Formatter
- Configuration file (.crn-fmt.toml)
- Directory recursion
- Improved indentation inference
- Custom style rules
- Editor integration (LSP)

### Additional Tools
- Language Server Protocol (LSP)
- Debugger (lldb integration)
- Documentation generator
- Linter
- Benchmark runner

---

## Contributing

To contribute to Corin tooling:

1. Fork the repository
2. Create a feature branch
3. Add your tool to `tools/`
4. Update the Makefile
5. Add documentation
6. Submit a pull request

See CONTRIBUTING.md for more details.
