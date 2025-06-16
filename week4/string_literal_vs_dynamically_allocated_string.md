### There is a difference of behavior in how C handles **string literals** (`"Hi!"`) versus **dynamically allocated strings** (like those from `get_string()`).

### Key Difference:
1. **String Literals (`"Hi!"`)**  
   - When you write `char *s = "Hi!";` and `char *t = "Hi!";`, the compiler may **optimize memory usage** by storing **only one copy** of the identical string literal in read-only memory.
   - Both `s` and `t` point to the **same memory location** (same address), so `s == t` evaluates to `true`.

2. **Dynamically Allocated Strings (`get_string()`)**  
   - `get_string()` allocates **new memory** for each input, even if the strings are identical.
   - So `s` and `t` point to **different memory locations**, meaning `s == t` evaluates to `false`.

---

### Why the Code from simple_substring.c Outputs `"Same"`:
```c
char *s = "Hi!";
char *t = "Hi!";

if (s == t) {
    printf("Same\n");  // This runs because the compiler reuses the same "Hi!" in memory
}
```

- The compiler sees that `"Hi!"` is used twice and **stores it once** (string pooling).
- Both `s` and `t` point to the same address, so `s == t` is `true`.

---

### Why the Second Code from compare_string.c Outputs `"Different"`:
```c
char *s = get_string("s: ");  // Allocates new memory (e.g., address 0x1000)
char *t = get_string("t: ");  // Allocates different memory (e.g., address 0x2000)

if (s == t) {
    printf("Same\n");
} else {
    printf("Different\n");  // This runs because `s` and `t` point to different addresses
}
```

- `get_string()` dynamically allocates memory for each input, even if the strings are identical.
- `s` and `t` have **different memory addresses**, so `s == t` is `false`.

---

### How to **Correctly Compare Strings** in C:
Since `==` compares **addresses** (not contents), you should use:
- `strcmp(s, t) == 0` (for standard C)
- Or CS50’s `strcmp(s, t)` (which returns `0` if strings match).

#### Example Fix:
```c
#include <string.h>  // For strcmp

if (strcmp(s, t) == 0) {
    printf("Same\n");
} else {
    printf("Different\n");
}
```

---

### Summary:
| Case | Example | `s == t` Result | Why? |
|------|---------|----------------|------|
| **String Literals** | `char *s = "Hi!"; char *t = "Hi!";` | `Same` | Compiler reuses the same memory for identical literals. |
| **Dynamic Allocation** | `s = get_string(); t = get_string();` | `Different` | `get_string()` allocates new memory each time. |

## use `strcmp()` to compare string **contents**, not `==` (which compares **addresses**).