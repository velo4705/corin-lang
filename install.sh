#!/bin/bash
# Corin One-Line Installer
# Usage: curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash

set -e

echo "╔══════════════════════════════════════════════════════════════╗"
echo "║         Corin Programming Language Installer              ║"
echo "║                    Version 1.0-beta.8                        ║"
echo "╚══════════════════════════════════════════════════════════════╝"
echo ""

# Check prerequisites
echo "Checking prerequisites..."
command -v g++ >/dev/null 2>&1 || { echo "✗ g++ not found. Install: sudo apt install g++"; exit 1; }
command -v make >/dev/null 2>&1 || { echo "✗ make not found. Install: sudo apt install make"; exit 1; }
command -v git >/dev/null 2>&1 || { echo "✗ git not found. Install: sudo apt install git"; exit 1; }
echo "✓ All prerequisites found"
echo ""

# Clone repository
echo "Cloning Corin..."
if [ -d "corin-lang" ]; then
    echo "Directory exists, updating..."
    cd corin-lang
    git pull
else
    git clone https://github.com/velo4705/corin-lang.git
    cd corin-lang
fi

# Build
echo ""
echo "Building Corin..."
make clean
make quick

echo ""
echo "Building additional tools..."
make cpm 2>/dev/null && echo "  ✓ cpm built" || echo "  ⚠ cpm build skipped"
make corin-fmt 2>/dev/null && echo "  ✓ corin-fmt built" || echo "  ⚠ corin-fmt build skipped"

# Hybrid Installation: Both system-wide and user PATH
echo ""
echo "Installing Corin (hybrid approach)..."
echo ""

# Step 1: Try system-wide installation (if sudo available)
echo "Step 1: Attempting system-wide installation..."
if sudo -n true 2>/dev/null; then
    # User has passwordless sudo
    sudo cp corin /usr/local/bin/ 2>/dev/null && echo "✓ System-wide install successful" || echo "⚠ System-wide install failed"
    sudo cp corin /usr/local/bin/ 2>/dev/null
    
    if [ -f "cpm" ]; then
        sudo cp cpm /usr/local/bin/ 2>/dev/null
    fi
    
    if [ -f "corin-fmt" ]; then
        sudo cp corin-fmt /usr/local/bin/ 2>/dev/null
    fi
else
    # Ask for sudo permission
    echo "System-wide installation requires sudo privileges."
    read -p "Install system-wide? (Y/n): " install_system
    install_system=${install_system:-Y}
    
    if [[ $install_system =~ ^[Yy]$ ]]; then
        if sudo cp corin /usr/local/bin/ 2>/dev/null; then
            echo "✓ System-wide install successful"
            sudo cp corin /usr/local/bin/ 2>/dev/null
            
            if [ -f "cpm" ]; then
                sudo cp cpm /usr/local/bin/ 2>/dev/null
            fi
            
            if [ -f "corin-fmt" ]; then
                sudo cp corin-fmt /usr/local/bin/ 2>/dev/null
            fi
        else
            echo "⚠ System-wide install failed (continuing with user install)"
        fi
    else
        echo "⚠ Skipping system-wide install"
    fi
fi

# Step 2: Always set up user PATH (as backup and for development)
echo ""
echo "Step 2: Setting up user PATH..."
CORIN_DIR="$(pwd)"

# Detect shell and add to appropriate config file
if [[ $SHELL == *"zsh"* ]]; then
    SHELL_CONFIG="$HOME/.zshrc"
elif [[ $SHELL == *"bash"* ]]; then
    SHELL_CONFIG="$HOME/.bashrc"
else
    SHELL_CONFIG="$HOME/.profile"
fi

# Add PATH export to shell config if not already present
if ! grep -q "corin-lang" "$SHELL_CONFIG" 2>/dev/null; then
    echo "" >> "$SHELL_CONFIG"
    echo "# Corin Programming Language" >> "$SHELL_CONFIG"
    echo "export PATH=\"\$PATH:$CORIN_DIR\"" >> "$SHELL_CONFIG"
    echo "✓ Added Corin to user PATH in $SHELL_CONFIG"
else
    echo "✓ Corin already in user PATH"
fi

# Also export for current session
export PATH="$PATH:$CORIN_DIR"
echo "✓ Corin available in current session"

echo ""
echo "Installation Summary:"
echo "• System-wide: 'corin' available globally (if sudo install succeeded)"
echo "• User PATH: 'corin' available in your terminal sessions"
echo "• Local: './corin' always works from this directory"
echo "• Best of both worlds - no confusion, maximum compatibility!"

# Test
echo ""
echo "Testing installation..."
./corin --version

echo ""
echo "╔══════════════════════════════════════════════════════════════╗"
echo "║  ✓ Corin installed successfully! (Hybrid Installation)    ║"
echo "╚══════════════════════════════════════════════════════════════╝"
echo ""
echo "Quick start:"
echo "  corin examples/hello.crn"
echo "  corin --version"
echo ""
echo "Available everywhere:"
echo "• 'corin' command works in any terminal (system + user PATH)"
echo "• './corin' works from installation directory"
echo "• Automatic updates when you re-run installer"
echo ""
echo "Documentation: https://github.com/velo4705/corin-lang"
