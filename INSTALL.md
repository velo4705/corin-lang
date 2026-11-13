# Corin Installation Guide

## Quick Install (One Line)

```bash
curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash
```

This is the easiest way to install Corin. It will:
1. Check prerequisites (g++, make, git)
2. Clone the repository
3. Build Corin automatically
4. Ask if you want system-wide installation

## Prerequisites

Before installing, make sure you have:

- **C++20 compiler** (g++ 10+ or clang++ 10+)
- **Make**
- **Git**
- **LLVM** (optional, for native compilation)

### Install Prerequisites

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install g++ make git
```

**Fedora:**
```bash
sudo dnf install gcc-c++ make git
```

**macOS:**
```bash
brew install gcc make git
```

## Build from Source

### Step 1: Clone

```bash
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang
```

### Step 2: Build

```bash
# Build the compiler
make quick

# Build additional tools (optional)
make spm           # Package manager
make corin-fmt  # Code formatter
```

This creates:
- `./corin` - Corin compiler/interpreter
- `./corin` - Alias for corin
- `./spm` - Package manager (if built)
- `./corin-fmt` - Code formatter (if built)

### Step 3: Test

```bash
./corin --version
./corin examples/hello.corin
```

## System-Wide Installation

To use Corin from anywhere:

```bash
sudo cp corin /usr/local/bin/
sudo cp corin /usr/local/bin/
```

Optional tools (if available):
```bash
sudo cp spm /usr/local/bin/           # Package manager
sudo cp corin-fmt /usr/local/bin/  # Code formatter
```

Now you can run:
```bash
corin --version
corin myprogram.corin
```

## Update

Corin includes a built-in update system:

```bash
# Check for updates (no authentication required)
corin --check-updates

# Update to latest version
corin --update
```

### First-Time Update Setup

The first time you run `corin --update`, git may ask for your GitHub credentials. To avoid this:

**Option 1: Use credential helper (recommended)**
```bash
cd corin-lang
git config credential.helper store
```

After this, git will remember your credentials after the first use.

**Option 2: Use the one-line installer**
```bash
curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash
```

This will update your installation without requiring credentials.

### What Update Does

The update command will:
- Pull the latest code from GitHub
- Rebuild automatically
- Preserve your local changes

### Update Requirements

The auto-update feature requires:
- Installation via git (using the one-line installer or manual git clone)
- Internet connection
- Git installed on your system

### If Not Installed via Git

If you installed Corin without git, you'll see:
```
ℹ Not installed via git. To update, run:
  curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash
```

Simply run the one-line installer again - it will update your installation.

## Manual Update

If auto-update doesn't work:

```bash
cd corin-lang
git pull origin main
make quick
```

## Uninstall

### Remove System Installation

```bash
sudo rm /usr/local/bin/corin
sudo rm /usr/local/bin/corin

# If you installed optional tools
sudo rm /usr/local/bin/spm 2>/dev/null
sudo rm /usr/local/bin/corin-fmt 2>/dev/null
```

### Remove Source

```bash
rm -rf corin-lang
```

## Troubleshooting

### "g++ not found"

Install C++ compiler:
```bash
sudo apt install g++  # Ubuntu/Debian
sudo dnf install gcc-c++  # Fedora
```

### "make: command not found"

Install make:
```bash
sudo apt install make  # Ubuntu/Debian
sudo dnf install make  # Fedora
```

### "git: command not found"

Install git:
```bash
sudo apt install git  # Ubuntu/Debian
sudo dnf install git  # Fedora
```

### Build Errors

Make sure you have C++20 support:
```bash
g++ --version  # Should be 10.0 or higher
```

### Permission Denied

When installing system-wide, use sudo:
```bash
sudo cp corin /usr/local/bin/
```

## Verify Installation

```bash
# Check version
corin --version

# Run hello world
corin examples/hello.corin

# Check all tools
corin --help
spm --help
corin-fmt --help
```

## Next Steps

After installation:

1. **Read the docs**: [Getting Started](docs/GETTING_STARTED.md)
2. **Try examples**: `ls examples/`
3. **Create a project**: `spm init my-project`
4. **Join the community**: [GitHub Discussions](https://github.com/velo4705/corin-lang/discussions)

## Platform Support

Corin works on:
- ✅ Linux (primary)
- ✅ macOS
- ✅ Windows (via WSL)
- ✅ Web (via WASM)
- ✅ iOS (native)
- ✅ Android (native)

## Getting Help

- **Documentation**: [docs/](docs/)
- **Issues**: [GitHub Issues](https://github.com/velo4705/corin-lang/issues)
- **Discussions**: [GitHub Discussions](https://github.com/velo4705/corin-lang/discussions)
- **Quick Fix**: [QUICK_FIX.md](QUICK_FIX.md)

## Advanced Installation

### Custom Build Options

```bash
# Debug build
make debug

# Release build with optimizations
make release

# Build with LLVM support
make llvm

# Build everything
make all
```

### Install to Custom Location

```bash
# Install to ~/bin
cp corin ~/bin/
export PATH="$PATH:$HOME/bin"
```

### Docker Installation

```dockerfile
FROM ubuntu:22.04
RUN apt update && apt install -y g++ make git
RUN git clone https://github.com/velo4705/corin-lang.git
WORKDIR /corin-lang
RUN make quick
CMD ["./corin"]
```

## Development Installation

For contributing to Corin:

```bash
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang
make debug  # Build with debug symbols
make test   # Run tests
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for more details.
