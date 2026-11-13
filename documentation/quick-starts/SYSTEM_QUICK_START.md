# Corin System Library - Quick Start Guide

**Get started with OS-level programming in Corin in 5 minutes!**

---

## Installation

No installation needed! The system library is built into the Corin compiler.

---

## Your First System Program

Create `hello_system.corin`:

```corin
import system

print("=== My First System Program ===")

let pid = corin_system_get_pid()
print("Process ID:", pid)

let cpu_count = corin_system_cpu_count()
print("CPU Cores:", cpu_count)

let username = corin_system_get_username()
print("Username:", username)

print("Done!")
```

Compile and run:

```bash
./corin compile hello_system.corin 2>/dev/null | grep -A 1000 "^; ModuleID" > hello_system.ll
llc hello_system.ll -filetype=obj -o hello_system.o
gcc hello_system.o stdlib/system/system.cpp -o hello_system -lstdc++ -lpthread
./hello_system
```

---

## Common Tasks

### Get Process Information

```corin
import system

let pid = corin_system_get_pid()
print("PID:", pid)
```

### Measure Execution Time

```corin
import system

let start = corin_system_timestamp_ns()

// Your code here
let count = 0
while count < 1000000:
    count = count + 1

let end = corin_system_timestamp_ns()
print("Time:", end - start, "ns")
```

### Check System Resources

```corin
import system

let cpu_count = corin_system_cpu_count()
let cpu_arch = corin_system_cpu_arch()
let page_size = corin_system_page_size()

print("CPUs:", cpu_count)
print("Architecture:", cpu_arch)
print("Page Size:", page_size, "bytes")
```

### Access Environment

```corin
import system

let home = corin_system_get_env("HOME")
let shell = corin_system_get_env("SHELL")
let user = corin_system_get_username()
let host = corin_system_get_hostname()

print("User:", user, "on", host)
print("Home:", home)
print("Shell:", shell)
```

### Work with Files

```corin
import system

let cwd = corin_system_get_cwd()
print("Current directory:", cwd)

let exists = corin_system_file_exists("/etc/passwd")
print("File exists:", exists)

let dir_exists = corin_system_directory_exists("/tmp")
print("Directory exists:", dir_exists)
```

### Allocate Memory

```corin
import system

// Allocate 1KB
let ptr = corin_system_allocate(1024)
print("Allocated memory at:", ptr)

// Use the memory...

// Free it
corin_system_free(ptr)
print("Memory freed")
```

---

## Available Functions

### Process
- `corin_system_get_pid()` → int - Get process ID

### Memory
- `corin_system_allocate(size)` → ptr - Allocate memory
- `corin_system_free(ptr)` → void - Free memory
- `corin_system_page_size()` → int - Get page size

### File System
- `corin_system_file_exists(path)` → bool - Check file
- `corin_system_directory_exists(path)` → bool - Check directory
- `corin_system_create_directory(path)` → bool - Create directory
- `corin_system_get_cwd()` → string - Get current directory

### Environment
- `corin_system_get_env(name)` → string - Get environment variable
- `corin_system_get_username()` → string - Get username
- `corin_system_get_hostname()` → string - Get hostname

### System Info
- `corin_system_cpu_count()` → int - Get CPU count
- `corin_system_cpu_arch()` → string - Get CPU architecture

### Timing
- `corin_system_timestamp_ms()` → int64 - Milliseconds
- `corin_system_timestamp_us()` → int64 - Microseconds
- `corin_system_timestamp_ns()` → int64 - Nanoseconds
- `corin_system_sleep_ms(ms)` → void - Sleep

---

## Examples

### Run the demos:

```bash
# System capabilities demo
./run_kernel_demo.sh

# Or manually:
./corin compile system_demo.corin 2>/dev/null | grep -A 1000 "^; ModuleID" > system_demo.ll
llc system_demo.ll -filetype=obj -o system_demo.o
gcc system_demo.o stdlib/system/system.cpp -o system_demo -lstdc++ -lpthread
./system_demo
```

Available demos:
- `system_demo.corin` - Comprehensive system demo
- `kernel_hello.corin` - Kernel-style initialization
- `process_monitor.corin` - Process monitoring
- `test_system_simple.corin` - Minimal test

---

## Troubleshooting

### "Unknown function" error
Make sure you have `import system` at the top of your file.

### Compilation fails
Check that you're using the correct compilation workflow:
1. Compile to LLVM IR
2. Compile IR to object file
3. Link with system library

### Linking errors
Make sure to link with `-lstdc++ -lpthread`:
```bash
gcc program.o stdlib/system/system.cpp -o program -lstdc++ -lpthread
```

---

## Next Steps

- Read `SYSTEM_LIBRARY_COMPLETE.md` for full documentation
- Check `OS_KERNEL_ROADMAP.md` for OS development path
- See `docs/OS_DEVELOPMENT.md` for advanced features

---

## Need Help?

- Check the examples in the repository
- Read the documentation files
- Look at `stdlib/system/system.h` for C++ API

**Happy system programming!** 🚀
