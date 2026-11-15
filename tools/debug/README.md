# Corin Debug Adapter Protocol (DAP)

The Corin Debug Adapter provides debugging capabilities for Corin code.

## Features

- **Breakpoints**: Set breakpoints in your code
- **Step Execution**: Step through code line by line
- **Variable Inspection**: View variable values (coming soon)
- **Call Stack**: View the call stack (coming soon)
- **Continue/Pause**: Control execution flow

## Building

```bash
make corin-debug
```

## Usage

The debug adapter communicates over stdin/stdout using the Debug Adapter Protocol (DAP).

### With VSCode

1. Install the Corin VSCode extension from `editors/vscode/`
2. Open a `.crn` file
3. Set breakpoints by clicking in the gutter
4. Press F5 or click "Run and Debug"
5. Select "Debug Corin Program"

### Manual Testing

You can test the debug adapter manually:

```bash
echo 'Content-Length: 50\r\n\r\n{"type":"request","command":"initialize","seq":1}' | ./corin-debug
```

## Architecture

```
┌─────────────┐         ┌─────────────┐         ┌─────────────┐
│   VSCode    │ ←DAP→   │   Debug     │ ←API→   │ Interpreter │
│  Debug UI   │         │  Adapter    │         │  (Enhanced) │
└─────────────┘         └─────────────┘         └─────────────┘
```

## Implementation

- **dap_server.h**: Debug adapter interface
- **main.cpp**: DAP server implementation

## Supported DAP Requests

- `initialize` - Initialize debug capabilities
- `launch` - Launch program for debugging
- `setBreakpoints` - Set breakpoints in a file
- `configurationDone` - Configuration complete
- `threads` - Get thread list
- `stackTrace` - Get call stack
- `scopes` - Get variable scopes
- `variables` - Get variable values
- `continue` - Continue execution
- `next` - Step over
- `stepIn` - Step into function
- `stepOut` - Step out of function
- `pause` - Pause execution
- `disconnect` - End debug session

## Current Status

### Phase 1: Basic DAP Server ✅
- DAP protocol implementation
- Breakpoint management
- Execution control commands
- VSCode integration

### Phase 2: Interpreter Integration (In Progress)
- Breakpoint hooks in interpreter
- Step-by-step execution mode
- Variable capture
- Stack frame tracking

### Phase 3: Advanced Features (Planned)
- Expression evaluation
- Watch expressions
- Conditional breakpoints
- Hit count breakpoints

## Future Enhancements

- Variable inspection
- Call stack tracking
- Expression evaluation in debug console
- Conditional breakpoints
- Logpoints
- Data breakpoints
