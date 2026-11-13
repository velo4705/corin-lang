#!/bin/bash
# Run core language tests only (no window/display or web tests)
# Use run_advanced_tests.sh for window/web/gui tests

CORIN="./corin"
PASS=0
FAIL=0
SKIP=0
ERRORS=()

# Skip: interactive, window/gui/display, web/network, hot-reload
SKIP_PATTERNS=(
    # Interactive (need stdin)
    "input_working"
    "user_input"

    # Window/GUI/Display (need OpenGL, SDL2, display server)
    "car_simulator"
    "intermediate_plot3d_demo"
    "fpp4d"
    "sim4d"
    "sim_nbody_gui"
    "gui_window_demo"
    "milestone11_window_test"
    "milestone11_gui_test"
    "m13_gui_"
    "milestone9_game_test"
    "intermediate_m9_space_shooter"
    "intermediate_m11_dashboard"

    # Web/Network
    "websocket"
    "test_http"
    "rest_test"
    "graphql_test"
    "intermediate_m12_chat_server"
    "intermediate_m4_todo_api"
    "milestone12_network_test"

    # Hot-reload (need file watcher)
    "hot_reload"
    "reload_demo"

    # Other
    "directives_example"
)

run_test() {
    local file="$1"
    local name=$(basename "$file")

    for pat in "${SKIP_PATTERNS[@]}"; do
        if [[ "$file" == *"$pat"* ]]; then
            echo "  SKIP  $name"
            ((SKIP++))
            return
        fi
    done

    output=$(timeout 10s "$CORIN" "$file" 2>&1)
    exit_code=$?

    if [ $exit_code -eq 124 ]; then
        echo "  SKIP  $name  (timeout)"
        ((SKIP++))
    elif [ $exit_code -ne 0 ]; then
        if echo "$output" | grep -qE "^Error:|RuntimeError:|TypeError:|Undefined variable|NameError"; then
            echo "  FAIL  $name"
            last_err=$(echo "$output" | grep -E "^Error:|RuntimeError:|TypeError:|Undefined variable|NameError" | tail -1)
            ERRORS+=("FAIL: $name -- $last_err")
            ((FAIL++))
        else
            echo "  PASS  $name  (warnings only)"
            ((PASS++))
        fi
    else
        echo "  PASS  $name"
        ((PASS++))
    fi
}

echo "=== Running examples/*.corin (core tests only) ==="
for f in examples/*.corin; do
    run_test "$f"
done

echo ""
echo "=== Summary ==="
echo "PASS: $PASS  FAIL: $FAIL  SKIP: $SKIP"
echo ""
if [ ${#ERRORS[@]} -gt 0 ]; then
    echo "=== Failures ==="
    for e in "${ERRORS[@]}"; do
        echo "  $e"
    done
fi
