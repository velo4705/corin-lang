# Corin Command Name

## Why Two Names?

Corin provides **two commands** for flexibility:

### `corin` (Primary - 4 characters)
- **Short and fast to type**
- Stands for "Corin App" or "Corin Compiler"
- Similar to: `rustc`, `javac`, `clang`
- Recommended for daily use

### `corin` (Alias - 8 characters)
- **Full name for clarity**
- Better for documentation and tutorials
- Self-documenting in scripts
- Alias/symlink to `corin`

## Usage

Both commands work identically:

```bash
# Using short name (recommended)
corin hello.crn
corin --version
corin --help

# Using full name (also works)
corin hello.crn
corin --version
corin --help
```

## Comparison with Other Languages

| Language | Short | Full | Notes |
|----------|-------|------|-------|
| Python | `py` | `python` | Both widely used |
| TypeScript | `tsc` | - | TypeScript Compiler |
| Rust | `rustc` | - | Rust Compiler |
| Go | `go` | - | Very short |
| Java | `javac` | - | Java Compiler |
| C/C++ | `gcc`, `clang` | - | Short names |
| **Corin** | **`corin`** | **`corin`** | Best of both! |

## Installation

When installed system-wide, both commands are available:

```bash
# Install
sudo make install

# Both work
corin myprogram.crn
corin myprogram.crn
```

## In Scripts

For scripts and documentation, you can use either:

```bash
#!/usr/bin/env corin
# Short and clear

#!/usr/bin/env corin  
# Self-documenting
```

## Recommendation

- **Daily use**: Use `corin` (faster to type)
- **Documentation**: Use `corin` (clearer)
- **Scripts**: Either works, choose based on preference

The choice is yours!
