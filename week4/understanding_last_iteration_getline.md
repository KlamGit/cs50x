## The extra newline at the end is not caused by the code formatting or the `printf()` calls themselves — it’s actually coming from the **newline character (`\n`) that `getline()` includes in the input**.

### Why this happens

`getline()` reads everything up to and including the newline character from user input. So when we type something like:

```
I have hyperventilation
```

`getline()` stores this as:

```
"I have hyperventilation\n\0"
```

That means `strlen(s)` is 24: 23 visible characters + 1 newline (`\n`) — *not* counting the null terminator (`\0`).

### So what is printed in the last iteration?

In the final loop iteration, when `i == 23`, I am printing:

```c
printf("Current character in the %ith place: %c\n", i, s[i]);
```

That character is `\n`, so the `%c` prints a newline — *hence the extra line I am seeing in the output*.

---

### How to handle it

If you **don't want to include the newline** from the input in your output processing, we can strip it like this:

```c
if (read > 0 && s[read - 1] == '\n')
{
    s[read - 1] = '\0';
}
```

And then change the loop to:

```c
for (int i = 0; i < strlen(s); i++)
{
    // ...
}
```

### Updated Code Snippet

```c
ssize_t read = getline(&s, &len, stdin);

if (read != -1)
{
    if (read > 0 && s[read - 1] == '\n')
    {
        s[read - 1] = '\0';  // Remove newline from input
    }

    printf("You said:\n%s\n", s);

    for (int i = 0; i < strlen(s); i++)
    {
        printf("Address of %ith place: %p\n", i, &s[i]);
        printf("Current character in the %ith place: %c\n", i, s[i]);
        printf("Current character in the %ith place (using pointer arithmetic): %c\n\n", i, *(s+i));
    }
}
```

---

### Summary

* The "extra" newline is not extra — it’s the newline `getline()` reads and stores.
* Strip it with `s[read - 1] = '\0';` if present.
* Now your output won't include that final blank line.