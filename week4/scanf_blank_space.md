### ⚠️ Why does `scanf("%s", s)` cut off after the first space?

Because `scanf("%s", ...)` reads **a string only up to the first whitespace character** (space, tab, or newline). It **stops reading** once it encounters one of these, leaving the rest of the input in the buffer.

So in this line:

```c
scanf("%s", s);
```

If you input:

```
what is wrong?
```

It stores only `"what"` in memory — everything after the space is **ignored** by this `scanf`.

---

### ✅ How to read a full line (including spaces)?

You should use `fgets` instead of `scanf("%s", ...)`.

Here’s how you can fix the code:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); // Allocate more space for longer input
    if (s == NULL)
    {
        return 1;
    }

    printf("s: ");
    fgets(s, 100, stdin);  // Use fgets instead of scanf
    printf("s: %s", s);    // No need for \n, fgets includes it
    free(s);
    return 0;
}
```

---

### ⚠️ Notes:

* `fgets` **does** include the newline character (`\n`) when you press Enter.
* You can remove it if needed using:

```c
s[strcspn(s, "\n")] = '\0';  // Removes trailing newline
```

---

### Summary

| Input Function       | Reads Until             | Handles Spaces | Includes `\n` |
| -------------------- | ----------------------- | -------------- | ------------- |
| `scanf("%s", s)`     | Whitespace (space, tab) | ❌ No           | ❌ No          |
| `fgets(s, n, stdin)` | Newline (`\n`)          | ✅ Yes          | ✅ Yes         |