# 🛠️ Debugging a Missing CS50 Library in Ubuntu (WSL): A Beginner’s Journey

When working on the [CS50x Week 1: Credit Assignment](https://cs50.harvard.edu/x/2025/psets/1/credit/), I encountered a common but confusing issue: I couldn’t compile my `hello.c` file due to a missing CS50 library. In this post, I’ll walk you through **how I discovered the problem**, **understood the cause**, and **found a working solution**, with detailed explanations of every terminal command along the way.

---

## 📍 Setting the Stage

After installing `make` and `gcc`, I tried to compile a simple `hello.c` file with the following command:

```bash
gcc hello.c -o hello
```

But it failed with this error:

```
hello.c:3:10: fatal error: cs50.h: No such file or directory
    3 | #include <cs50.h>
      |          ^~~~~~~~
compilation terminated.
```

### 🔍 What Does This Mean?

* `fatal error: cs50.h: No such file or directory`
  → This means the compiler couldn't find the header file `cs50.h`, which is required because the code is using functions like `get_string()` that are defined in that library.

---

## 🧠 Diagnosing the Issue

At this point, it was clear that the **CS50 library was missing** from my system.

I tried:

```bash
sudo apt install libcs50
```

But got:

```
E: Unable to locate package libcs50
```

### 🧠 What's Going On Here?

* `apt` is the **Advanced Package Tool** used to install software on Debian/Ubuntu systems.
* The error means: **`libcs50` is not available in the default Ubuntu package repositories.**

So, if it’s not in the official software catalog, how do you install it?

---

## 🛠️ The Solution: Manually Install the CS50 Library

The CS50 team maintains their library on GitHub, so I had to build it from source.

### 🧩 Step-by-Step Breakdown

```bash
# 1. Install compiler tools and Git
sudo apt install build-essential clang git
```

* `build-essential`: Installs core tools for building C/C++ programs (includes `make`, `gcc`, etc.)
* `clang`: An alternative compiler often used by CS50.
* `git`: Needed to download (clone) the CS50 source code.

---

```bash
# 2. Clone the CS50 library
git clone https://github.com/cs50/libcs50.git
cd libcs50
```

* `git clone ...`: Downloads the CS50 library’s source code into a folder named `libcs50`.
* `cd libcs50`: Navigates into that folder.

---

```bash
# 3. Compile and install the CS50 library
make
sudo make install
```

* `make`: Looks for a file named `Makefile` and uses it to compile the code into a usable library file (`libcs50.so`).
* `sudo make install`: Moves the built library into system folders (like `/usr/local/lib`) so it can be used by other programs.

---

```bash
# 4. Go back to your project
cd ~/projects/repos/cs50x/week1
```

* This returns to the folder where `hello.c` is located.

---

```bash
# 5. Compile with the CS50 library
gcc hello.c -lcs50 -o hello
```

* `-lcs50`: Tells the compiler to **link with the CS50 library**.
* `-o hello`: Output the compiled file as `hello`.

Finally, run it:

```bash
./hello
```

If all goes well, the program prompts for your name and greets you. 🎉

---

## 🚨 Bonus: VS Code “Problems” Panel

You may also have seen these errors:

```
#include errors detected. Please update your includePath.
cannot open source file "cs50.h"
```

These are **VS Code IntelliSense errors** — meaning VS Code can’t "see" where your headers are, even if the compiler can.

### How to fix that later (optional):

You can configure the `.vscode/c_cpp_properties.json` file to include paths like `/usr/local/include`.

But even if VS Code complains, as long as `gcc` can compile it, you’re fine for now.

---

## 💡 What I Learned (and How You Can Too)

### 1. **Read the Error Message Carefully**

Don’t panic. Most of the time, the compiler *tells you* what went wrong.

> `No such file or directory: cs50.h`
> → Think: Where is this file supposed to come from? How can I get it?

---

### 2. **Search Strategically**

Copy-paste the **exact error message** into Google or Stack Overflow. Add context like:

* "CS50"
* "Ubuntu"
* "gcc error"
* "install cs50.h Ubuntu"

---

### 3. **Learn to Recognize Patterns**

* `No such file or directory`: usually means a missing dependency.
* `make: *** No rule to make target`: usually means there’s no Makefile.
* `command not found`: a program isn’t installed yet.

---

### 4. **Practice the Process**

You become better not by memorizing solutions but by *debugging more*. Here's a simple approach:

```
See the error ➔ Understand it ➔ Search it ➔ Try a fix ➔ Learn from it
```

---

## 🛍️ Summary

| Problem                        | Diagnosis                       | Solution                           |
| ------------------------------ | ------------------------------- | ---------------------------------- |
| `cs50.h` not found             | Library not installed           | Clone and build from CS50’s GitHub |
| `libcs50` not found with `apt` | Not in Ubuntu default repos     | Use `git` + `make`                 |
| VS Code red squiggles          | IntelliSense can’t find headers | Optional fix with `includePath`    |

---

## ✅ Final Thoughts

This wasn’t just about fixing a compile error — it was about learning how to think like a developer. By slowing down and examining what the system is telling you, you become less reliant on asking others and more confident in solving issues yourself.

That said, **it’s completely fine to ask for help** (you’re learning!), but over time, you'll start solving things independently just by practicing this debugging process.
