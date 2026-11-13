#!/bin/bash
# Corin Compiler Demo
# Demonstrates end-to-end compilation from .corin to native executable

set -e

echo "╔════════════════════════════════════════════════════════════════╗"
echo "║         Corin Compiler - End-to-End Demo                   ║"
echo "║         From .corin source to native executable                 ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo ""

# Check if example file is provided
if [ -z "$1" ]; then
    EXAMPLE="examples/simple_test.corin"
else
    EXAMPLE="$1"
fi

BASENAME=$(basename "$EXAMPLE" .corin)
OUTPUT_DIR="/tmp/corin_demo"
mkdir -p "$OUTPUT_DIR"

echo "📄 Source file: $EXAMPLE"
echo ""
echo "--- Source Code ---"
cat "$EXAMPLE"
echo ""
echo "-------------------"
echo ""

echo "🔧 Step 1: Compile to LLVM IR"
./corin compile "$EXAMPLE" > "$OUTPUT_DIR/$BASENAME.ll"
echo "   ✓ Generated: $OUTPUT_DIR/$BASENAME.ll"
echo ""

echo "📊 Step 2: Show IR (first 20 lines)"
head -20 "$OUTPUT_DIR/$BASENAME.ll"
echo "   ..."
echo ""

echo "⚙️  Step 3: Compile IR to object file"
llc -filetype=obj "$OUTPUT_DIR/$BASENAME.ll" -o "$OUTPUT_DIR/$BASENAME.o"
SIZE=$(stat -c%s "$OUTPUT_DIR/$BASENAME.o")
echo "   ✓ Generated: $OUTPUT_DIR/$BASENAME.o ($SIZE bytes)"
echo ""

echo "🔗 Step 4: Link to executable"
clang "$OUTPUT_DIR/$BASENAME.o" -o "$OUTPUT_DIR/$BASENAME"
SIZE=$(stat -c%s "$OUTPUT_DIR/$BASENAME")
echo "   ✓ Generated: $OUTPUT_DIR/$BASENAME ($SIZE bytes)"
echo ""

echo "🚀 Step 5: Run native executable"
"$OUTPUT_DIR/$BASENAME"
EXIT_CODE=$?
echo "   ✓ Exit code: $EXIT_CODE"
echo ""

echo "╔════════════════════════════════════════════════════════════════╗"
echo "║                    SUCCESS!                                    ║"
echo "║   Corin code compiled to native executable!                ║"
echo "║   Performance: Native speed (C-like)                          ║"
echo "╚════════════════════════════════════════════════════════════════╝"
echo ""
echo "Generated files:"
echo "  - LLVM IR:    $OUTPUT_DIR/$BASENAME.ll"
echo "  - Object:     $OUTPUT_DIR/$BASENAME.o"
echo "  - Executable: $OUTPUT_DIR/$BASENAME"
echo ""
echo "Try it yourself:"
echo "  ./scripts/demo_compiler.sh examples/comprehensive_test.corin"
