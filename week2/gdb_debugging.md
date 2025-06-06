# **GDB Debugging Guide**  
*A quick reference for debugging C programs with GDB (GNU Debugger)*  

---

## **What is GDB?**  
**GDB (GNU Debugger)** is a powerful command-line tool for debugging programs written in C, C++, and other languages. It allows you to:  
- **Pause execution** at specific points (breakpoints)  
- **Inspect variables** while the program runs  
- **Step through code** line by line  
- **Find crashes** (segmentation faults, infinite loops, etc.)  

---

## **Basic GDB Workflow**  

### **1. Compile with Debug Symbols**  
Before using GDB, compile your C program with the `-g` flag:  
```bash
clang -g -o program program.c -lcs50  # For CS50 programs
# or
gcc -g -o program program.c          # Standard C programs
```
- `-g` includes debugging information in the executable.  
- Without this, GDB won’t show source code or variable names.  

### **2. Launch GDB**  
```bash
gdb ./program
```
- Replace `program` with your executable’s name.  

### **3. Essential GDB Commands**  

| Command          | Description |
|------------------|-------------|
| `break main`     | Set a breakpoint at `main()` |
| `break line_num` | Break at a specific line (e.g., `break 10`) |
| `run` (or `r`)   | Start the program |
| `next` (or `n`)  | Execute next line (step **over** functions) |
| `step` (or `s`)  | Step **into** functions |
| `print var`      | Show the value of `var` (e.g., `print h`) |
| `continue` (or `c`) | Resume execution until next breakpoint |
| `backtrace` (or `bt`) | Show the call stack (useful for crashes) |
| `quit` (or `q`)  | Exit GDB |

---

### **Example Debugging Session**  
1. **Set a breakpoint** at `main()`:  
   ```gdb
   (gdb) break main
   ```
2. **Run the program**:  
   ```gdb
   (gdb) run
   ```
3. **Step through code**:  
   - `next` to execute `get_int()`  
   - Enter input (e.g., `3`) when prompted  
4. **Inspect variables**:  
   ```gdb
   (gdb) print h
   ```
5. **Continue execution**:  
   ```gdb
   (gdb) continue
   ```

---

## **Common Issues & Fixes**  

| Problem | Solution |
|---------|----------|
| `No debugging symbols found` | Recompile with `-g` |
| `No such file or directory` | Check executable name (`ls` to verify) |
| GDB won’t show source code | Ensure `-g` was used in compilation |
| Program crashes in GDB | Use `backtrace` to find where it failed |

---

## **Quick Tips**  
- **View code while debugging**:  
  ```gdb
  (gdb) layout src
  ```
- **List breakpoints**:  
  ```gdb
  (gdb) info breakpoints
  ```
- **Delete a breakpoint**:  
  ```gdb
  (gdb) delete 1  # (1 = breakpoint number)
  ```

---

## **Summary**  
✅ **Compile with `-g`** → `gcc -g -o program program.c`  
✅ **Run GDB** → `gdb ./program`  
✅ **Set breakpoints** → `break main` or `break line_num`  
✅ **Debug interactively** → `run`, `next`, `print`, `continue`  

## IMPORTANT!
Before everything make sure you are compiling the right file and that there are no naming mismatch.
I kept confusing 0 with o in with naming the file and compilation command code, which resulted in a lot of frustrations.