# Corin System Programming - Quick Reference

**Fast reference for OS and embedded development in Corin**

---

## Import System Library

```corin
import system
```

---

## System Functions

### Process
```corin
let pid = corin_system_get_pid()
corin_system_exit(0)
```

### Memory
```corin
let ptr = corin_system_allocate(1024)
corin_system_free(ptr)
let page_size = corin_system_page_size()
```

### File System
```corin
let exists = corin_system_file_exists("/path/to/file")
let dir_exists = corin_system_directory_exists("/path/to/dir")
corin_system_create_directory("/path/to/dir")
let cwd = corin_system_get_cwd()
```

### Environment
```corin
let home = corin_system_get_env("HOME")
let user = corin_system_get_username()
let host = corin_system_get_hostname()
```

### System Info
```corin
let cpu_count = corin_system_cpu_count()
let cpu_arch = corin_system_cpu_arch()
```

### Timing
```corin
let ms = corin_system_timestamp_ms()
let us = corin_system_timestamp_us()
let ns = corin_system_timestamp_ns()
corin_system_sleep_ms(100)
```

---

## Common Patterns

### Measure Execution Time
```corin
let start = corin_system_timestamp_ns()
// ... your code ...
let end = corin_system_timestamp_ns()
print("Time:", end - start, "ns")
```

### Real-Time Control Loop
```corin
let cycle_count = 0
while cycle_count < 100:
    let cycle_start = corin_system_timestamp_ns()
    
    // ... control logic ...
    
    let cycle_end = corin_system_timestamp_ns()
    let cycle_time = (cycle_end - cycle_start) / 1000
    
    if cycle_time > 1000:
        print("[WARN] Deadline miss:", cycle_time, "us")
    
    corin_system_sleep_ms(100)
    cycle_count = cycle_count + 1
```

### Data Buffering
```corin
let BUFFER_SIZE = 10
let buffer_index = 0
let data_sum = 0

while running:
    let sensor_value = read_sensor()
    data_sum = data_sum + sensor_value
    buffer_index = buffer_index + 1
    
    if buffer_index >= BUFFER_SIZE:
        let average = data_sum / BUFFER_SIZE
        transmit_data(average)
        buffer_index = 0
        data_sum = 0
```

### State Machine
```corin
let STATE_IDLE = 0
let STATE_ACTIVE = 1
let STATE_ERROR = 2

let current_state = STATE_IDLE

while running:
    if current_state == STATE_IDLE:
        // ... idle logic ...
        if condition:
            current_state = STATE_ACTIVE
    
    if current_state == STATE_ACTIVE:
        // ... active logic ...
        if error:
            current_state = STATE_ERROR
    
    if current_state == STATE_ERROR:
        // ... error handling ...
        current_state = STATE_IDLE
```

---

## Compilation

### Quick Compile
```bash
./corin compile program.crn 2>/dev/null | grep -A 1000 "^; ModuleID" > program.ll
llc program.ll -filetype=obj -o program.o
gcc program.o stdlib/system/system.cpp -o program -lstdc++ -lpthread
./program
```

### One-Liner
```bash
./corin compile program.crn 2>/dev/null | grep -A 1000 "^; ModuleID" > program.ll && llc program.ll -filetype=obj -o program.o && gcc program.o stdlib/system/system.cpp -o program -lstdc++ -lpthread && ./program
```

---

## Run Demos

### OS Demos
```bash
./run_kernel_demo.sh
```

### Embedded Demos
```bash
./run_embedded_demos.sh
```

---

## Example Programs

### Minimal System Program
```corin
import system

print("Hello from Corin!")
let pid = corin_system_get_pid()
print("PID:", pid)
```

### Temperature Controller
```corin
import system

let TARGET_TEMP = 22
let current_temp = 20
let heater_on = 0

while cycle_count < 30:
    if current_temp < TARGET_TEMP:
        heater_on = 1
        current_temp = current_temp + 1
    
    if current_temp >= TARGET_TEMP:
        heater_on = 0
    
    print("Temp:", current_temp, "Heater:", heater_on)
    corin_system_sleep_ms(100)
    cycle_count = cycle_count + 1
```

### IoT Sensor Node
```corin
import system

let BUFFER_SIZE = 5
let buffer_index = 0
let temp_sum = 0

print("[BOOT] IoT Sensor Node")

let temp_buffer = corin_system_allocate(BUFFER_SIZE * 8)

while cycle_count < 25:
    let temp = 25 + cycle_count % 5
    temp_sum = temp_sum + temp
    buffer_index = buffer_index + 1
    
    if buffer_index >= BUFFER_SIZE:
        let avg = temp_sum / BUFFER_SIZE
        print("[TX] Temperature:", avg, "C")
        buffer_index = 0
        temp_sum = 0
    
    corin_system_sleep_ms(200)
    cycle_count = cycle_count + 1

corin_system_free(temp_buffer)
```

---

## Documentation

### Quick Start
- `SYSTEM_QUICK_START.md` - System programming quick start
- `EMBEDDED_DEVELOPMENT.md` - Embedded development guide

### Complete Guides
- `SYSTEM_LIBRARY_COMPLETE.md` - Complete system library docs
- `EMBEDDED_COMPLETE.md` - Complete embedded summary

### Examples
- `system_demo.crn` - System capabilities
- `kernel_hello.crn` - Kernel initialization
- `process_monitor.crn` - Process monitoring
- `embedded_demo.crn` - Temperature controller
- `iot_sensor_node.crn` - IoT sensor node

---

## Performance Tips

### 1. Use Nanosecond Timing
```corin
let start = corin_system_timestamp_ns()  // Most precise
```

### 2. Minimize Allocations
```corin
// Allocate once, reuse
let buffer = corin_system_allocate(1024)
// ... use buffer many times ...
corin_system_free(buffer)
```

### 3. Check Cycle Time
```corin
let cycle_time_us = (cycle_end - cycle_start) / 1000
if cycle_time_us > 1000:
    print("[WARN] Slow cycle:", cycle_time_us, "us")
```

### 4. Use Fixed Sample Rates
```corin
corin_system_sleep_ms(100)  // Consistent timing
```

---

## Troubleshooting

### "Unknown function" error
→ Add `import system` at top of file

### Compilation fails
→ Check compilation workflow (3 steps)

### Linking errors
→ Include `-lstdc++ -lpthread`

### Slow performance
→ Check cycle time, optimize loop

---

## Need Help?

- Check examples in repository
- Read documentation files
- Look at `stdlib/system/system.h`

---

**Happy system programming!** 🚀
