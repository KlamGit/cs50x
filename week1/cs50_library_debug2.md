# Debugging a Missing CS50 Library in Ubuntu (WSL): A Beginner’s Journey

If you're a beginner working through Harvard's CS50 course on your local machine (especially on Ubuntu via WSL), you might run into some puzzling compiler or linker errors. This blog post documents such an experience — from confusion to clarity — and breaks down what's going on under the hood so you can troubleshoot better in the future.

---

## 📍 Initial Setup: Creating and Compiling C Programs

Let’s say you’ve written your first C program:

```c
#include <stdio.h>
#include <cs50.h>

int main(void) {
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}
```

You save it as `hello.c` and open VS Code.

Then in your terminal:

```bash
code hello.c
make hello
```

Oops! You see this:

```bash
Command 'make' not found, but can be installed with:
sudo apt install make
```

This simply means `make`, a tool that automates compiling, isn't installed. So you install it:

```bash
sudo apt install make
```

---

## 🧱 Missing Compiler?

Next, you try:

```bash
gcc hello.c -o hello
```

And Ubuntu tells you:

```bash
Command 'gcc' not found, but can be installed with:
sudo apt install gcc
```

So you install `gcc` as well.

---

## 🚨 Compilation Error: `cs50.h: No such file or directory`

After installing `gcc`, you try again:

```bash
gcc hello.c -o hello
```

Now you get:

```bash
hello.c:3:10: fatal error: cs50.h: No such file or directory
```

This means your code depends on a library (`cs50.h`), but your system doesn’t know where to find it. It’s not part of standard C. You need to install the CS50 library first.

Trying to install it via:

```bash
sudo apt install libcs50
```

Returns:

```bash
E: Unable to locate package libcs50
```

Why? Because `libcs50` is not in the default Ubuntu repositories. You have to install it via source from GitHub:

```bash
git clone https://github.com/cs50/libcs50
cd libcs50
make
sudo make install
```

Now the header and the compiled library are in place.

---

## 🧩 Linking: The Missing Puzzle Piece

You try:

```bash
gcc hello.c -o hello
```

Still, you get an error:

```bash
undefined reference to `get_string`
```

This means your program compiled, but when the linker tried to build the final executable, it couldn’t find the implementation of `get_string()`, which is defined in the CS50 library.

**Analogy**:

* Imagine you write a recipe that calls for a special ingredient called `get_string()`.
* You wrote the recipe (`.c` file), and the kitchen (compiler) accepted it.
* But when it's time to cook (linking), the pantry (linker) doesn’t have the ingredient (`get_string` implementation).

You have to explicitly tell the pantry where to find it:

```bash
gcc hello.c -lcs50 -o hello
```

The `-lcs50` flag tells the linker: "Hey, link this program with the cs50 library!"

---

## 🛠️ When `make` Fails But `clang` Works

You tried:

```bash
make compare CFLAGS=-lcs50
```

Which resulted in:

```bash
cc -lcs50 compare.c -o compare
undefined reference to `get_int`
```

But this worked:

```bash
clang compare.c -lcs50 -o compare
```

### 🤯 Why the difference?

* `make` has **default rules** — it doesn’t always pass `CFLAGS` the way you think.
* It uses a default rule like: `cc compare.c -o compare`, and your `-lcs50` didn’t get appended correctly.
* In fact, the `-lcs50` was treated as a **compiler flag**, but it needs to be a **linker flag**.

Try using `LDFLAGS` instead:

```bash
make compare LDFLAGS=-lcs50
```

Or skip `make` and call the compiler directly like you did:

```bash
clang compare.c -lcs50 -o compare
```

---

## 🧠 How Can You Get Better at This?

1. **Read error messages carefully**: Most are very descriptive.
2. **Know the compilation steps**:

   * **Preprocessing**: Handles `#include`, macros.
   * **Compilation**: Turns code into machine language `.o` files.
   * **Linking**: Connects `.o` files and libraries into an executable.
3. **Practice**:

   * Break and fix your own code deliberately.
   * Recompile step-by-step using `gcc -E`, `-S`, `-c`, and `-o` to understand each stage.
4. **Understand `make`**:

   * Write your own `Makefile` so you know what commands are being run.
5. **Use man pages and `--help`**:

   * `man gcc`, `man make`, `gcc --help`

---

## ✅ Summary

| Action                  | Command or Reason                                          |
| ----------------------- | ---------------------------------------------------------- |
| Install compiler        | `sudo apt install gcc` or `clang`                          |
| Install CS50 library    | Clone repo + `make` + `sudo make install`                  |
| Compile with CS50       | `gcc file.c -lcs50 -o file`                                |
| Make + custom link flag | `make file LDFLAGS=-lcs50`                                 |
| VS Code errors          | Fix `includePath` and ensure headers/libraries are present |

---

Want to go deeper? Try writing your own `Makefile`, compile with both `gcc` and `clang`, and read up on how linking works in Linux.

If this helped you, share your learnings or bookmark it for later — because chances are, you'll forget this the next time you write `#include <cs50.h>` 😉
