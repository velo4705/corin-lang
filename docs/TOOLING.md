# Corin Tooling Guide

This guide covers the developer tools available in the Corin ecosystem.

---

## Package Manager (spm)

The Corin Package Manager helps you create, build, test, and manage Corin projects.

### Installation

The spm tool is built automatically with the Corin compiler:

```bash
make spm
```

### Commands

#### Create a New Package

```bash
spm init my-package
```

Creates a new package with the following structure:
```
my-package/
├── spm.toml          # Package manifest
├── src/
│   └── main.corin      # Main source file
├── tests/            # Test files
├── examples/         # Example files
├── README.md
└── .gitignore
```

#### Build Package

```bash
spm build
```

Validates and builds all source files in the `src/` directory.

#### Run Tests

```bash
spm test
```

Runs all `.corin` files in the `tests/` directory and reports results.

#### Run a File

```bash
spm run src/main.corin
```

Executes a Corin file using the interpreter.

#### Clean Build Artifacts

```bash
spm clean
```

Removes build artifacts and compiled binaries.

#### Install Dependencies

```bash
spm install <package>
```

Note: Package registry not yet implemented. Manually add dependencies to `spm.toml`:

```toml
[dependencies]
http = "1.0.0"
json = "2.0.0"
```

#### Publish Package

```bash
spm publish
```

Note: Package registry not yet implemented. Validates package structure.

### Package Manifest (spm.toml)

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
corin-fmt file.corin
```

Formats the file in-place according to Corin style guidelines.

#### Check Formatting

```bash
corin-fmt --check file.corin
```

Checks if a file is formatted correctly without modifying it. Returns exit code 0 if formatted, 1 if needs formatting.

#### Custom Indent Size

```bash
corin-fmt --indent 2 file.corin
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

### Integration with spm

You can use the formatter with spm:

```bash
# Format all source files
find src -name "*.corin" -exec corin-fmt {} \;

# Check formatting in CI
find src -name "*.corin" -exec corin-fmt --check {} \;
```

### Known Limitations

- Indentation inference works best with already-indented code
- No configuration file support yet (.corin-fmt.toml)
- Processes one file at a time (no directory recursion)
- Basic dedent detection (may need manual adjustment for complex nesting)

---

## Compiler (corin)

The Corin compiler and interpreter.

### Usage

```bash
# Run a file
./corin file.corin

# With verbose output
./corin -v file.corin

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
spm init my-app
cd my-app

# Write code
vim src/main.corin

# Format code
corin-fmt src/main.corin

# Run it
spm run src/main.corin

# Add tests
vim tests/test_main.corin

# Run tests
spm test
```

### Formatting Workflow

```bash
# Format before committing
find src -name "*.corin" -exec corin-fmt {} \;

# Check in CI
corin-fmt --check src/**/*.corin
```

### Testing Workflow

```bash
# Run all tests
spm test

# Run specific test
spm run tests/test_feature.corin

# Clean and rebuild
spm clean
spm build
spm test
```

---

## Future Enhancements

### Package Manager
- Remote package registry
- Dependency resolution
- Version management
- Package publishing
- Lock file (spm.lock)

### Code Formatter
- Configuration file (.corin-fmt.toml)
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
