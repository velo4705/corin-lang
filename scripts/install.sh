#!/bin/bash
# Corin installation script

set -e

PREFIX="${PREFIX:-/usr/local}"

echo "Installing Corin to $PREFIX"

# Check if build exists
if [ ! -f "build/corin" ]; then
    echo "Error: Build not found. Run ./scripts/build.sh first"
    exit 1
fi

# Install binaries
sudo install -m 755 build/corin "$PREFIX/bin/"
sudo install -m 755 build/tools/cpm/cpm "$PREFIX/bin/" 2>/dev/null || true

# Install libraries
sudo mkdir -p "$PREFIX/lib/corin"
sudo cp -r stdlib "$PREFIX/lib/corin/"
sudo cp build/libcorin_runtime.so "$PREFIX/lib/" 2>/dev/null || true

# Install examples
sudo mkdir -p "$PREFIX/share/corin"
sudo cp -r examples "$PREFIX/share/corin/"

# Install man pages
sudo mkdir -p "$PREFIX/share/man/man1"
# sudo cp docs/man/corin.1 "$PREFIX/share/man/man1/" 2>/dev/null || true

echo "✓ Installation complete!"
echo ""
echo "Run 'corin --version' to verify installation"
