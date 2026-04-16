# Phase 0 Notes — Environment & Orientation
### K&R: The C Programming Language | Sections Read: Introduction through 1.5
*Date started: April 15, 2026*

---

## Background Questions

### What does C stand for?

C does not stand for anything. It is simply the language that came after B, which itself came from BCPL (Basic Combined Programming Language). When Dennis Ritchie improved upon B, the next letter was the natural choice. The name is purely sequential.

### What is the DEC PDP-11?

- DEC = Digital Equipment Corporation
- PDP = Programmed Data Processor
- The PDP-11 was a minicomputer from the late 1960s and 1970s — smaller than room-sized mainframes but still a cabinet-sized, expensive machine
- C and UNIX were written on and for the PDP-11
- The machine's architecture directly influenced C's design — particularly how C treats pointers and integers
- This is why C feels close to the hardware: it was shaped by real hardware constraints

### What does UNIX stand for?

UNIX is a play on an earlier system called MULTICS (Multiplexed Information and Computing Service). Developers built a simpler version and called it UNICS — Uniplexed Information and Computing Service — which eventually became UNIX.

### How is UNIX unique from operating systems today?

UNIX was built around a small set of ideas that were radical at the time:

- **Everything is a file** — devices, processes, network connections — all treated uniformly as files you read and write
- **Small tools that do one thing well** — programs like `ls`, `grep`, and `cat` each do one job and are chained together with pipes (`|`)
- **Written in C, not assembly** — this allowed UNIX to be ported to different hardware, which was virtually unheard of at the time
- **Multi-user and multitasking** from the start

Most modern operating systems are philosophically descended from UNIX. macOS is a certified UNIX. Linux is a UNIX clone. Android runs on Linux. The servers running the internet run Linux. Windows is the main mainstream OS that did not come from the UNIX lineage — and even Microsoft now ships WSL (Windows Subsystem for Linux) due to demand for UNIX-like tooling.

### UNIX's position in the tech world today

- Linux runs the majority of the world's servers, cloud infrastructure, and supercomputers
- macOS and iOS are built on Darwin, which is UNIX-certified
- Android is Linux under the hood
- Every tool in this roadmap — `gcc`, `make`, `valgrind`, `fork`, `pipe` — is a UNIX concept
- C and UNIX were born together, shaped each other, and their DNA is in virtually every system you will ever work on

---

## Key Concepts from K&R (Introduction through Section 1.4)

### Indentation in C

C does not enforce indentation. The compiler does not care whether your code is indented or not — it will compile either way. Indentation in C is a human convention for readability.

This is a fundamental difference from Python, which uses indentation as syntax. Remove indentation in Python and the code breaks. Remove it in C and the compiler does not notice.

Best practice: always indent function bodies, loops, and conditionals consistently. Use it for yourself and for anyone reading your code — not for the compiler.

### Variables vs Symbolic Constants

**Variable** — a named location in memory whose value can change during program execution.

Think of it as a box you can open and change what is inside.

```c
int temperature = 30;
temperature = 45; // valid — the value changed
```

**Symbolic constant** — a label defined with `#define` that always represents the same value everywhere it appears. The preprocessor replaces every occurrence of the name with the value before compilation begins. It is not a variable. It has no memory address. It cannot be changed.

Think of it as a label that always means the same thing everywhere.

```c
#define BOILING_POINT 100
// Every use of BOILING_POINT in the code becomes 100 before the compiler sees it
```

Key differences:

| | Variable | Symbolic Constant |
|---|---|---|
| Value can change | Yes | No |
| Lives in memory | Yes | No (replaced before compile) |
| Defined with | Type declaration | `#define` |
| Convention | lowercase | ALL_CAPS |

Using symbolic constants instead of raw numbers (magic numbers) makes code easier to read and maintain. If the value needs to change, you change it in one place.

---

## Key Concepts from K&R Section 1.5 — Character Input and Output

### The model: text streams

C treats all input and output as streams of characters. Whether you are reading from the keyboard, a file, or a pipe, the program sees the same thing: a sequence of characters arriving one at a time. This is the UNIX philosophy made concrete in the language itself.

### getchar() and putchar()

These are the two most fundamental I/O functions in C:

- `getchar()` — reads one character from standard input and returns it as an `int`
- `putchar(c)` — writes one character to standard output

```c
int c;
c = getchar();
putchar(c);
```

Note that `c` is declared as `int`, not `char`. This is intentional and important — see the EOF section below.

### EOF — End of File

EOF is a symbolic constant defined in `<stdio.h>`. Its value is `-1`.

It is the sentinel value that `getchar()` returns when there is no more input — either because you have reached the end of a file, or because the user typed `Ctrl+D` on Linux/macOS (or `Ctrl+Z` on Windows) to signal end of input.

```c
#define EOF -1  // what the standard library defines internally
```

This is why `c` must be `int` and not `char`. A `char` can only hold character values (typically 0–255). EOF is `-1`, which falls outside that range on many systems. If you store `getchar()`'s return value in a `char`, you may never correctly detect EOF — the program would loop forever or behave incorrectly.

The rule: **always store the return value of `getchar()` in an `int`.**

### The standard read loop

The idiomatic C pattern for reading all input until EOF:

```c
int c;
while ((c = getchar()) != EOF)
    putchar(c);
```

Two things to understand about this loop:

1. The assignment `c = getchar()` happens inside the condition. C allows assignment anywhere an expression is valid. The parentheses around `c = getchar()` are required — without them, `!=` binds tighter than `=` and the logic breaks.

2. The loop body runs zero or more times. If the very first character is EOF, the body never executes.

---

## Exercises Completed

### Exercise 1-6 — Verify that `getchar() != EOF` is 0 or 1

**Task:** Verify that the expression `getchar() != EOF` evaluates to 0 or 1.

**Solution:**

```c
#include <stdio.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        printf("%d\n", c != EOF);
    }

    return 0;
}
```

**What this proves:** The expression `c != EOF` is a comparison. In C, comparisons always produce either `1` (true) or `0` (false) — nothing else. While input is being read and `c` is a valid character, `c != EOF` is `1`. The loop exits when `getchar()` returns EOF, so by definition `c != EOF` is never `0` inside the loop body — it only becomes `0` at the condition check that exits the loop.

The conclusion: `(getchar() != EOF)` equals `1` for all valid characters and `0` when EOF is reached.

---

### Exercise 1-7 — Print the value of EOF

**Task:** Write a program to print the value of EOF.

**Solution:**

```c
#include <stdio.h>

int main() {
    printf("EOF value: %d\n", EOF);
}
```

**Output:** `EOF value: -1`

**What this shows:** EOF is not a character. It is the integer `-1`, defined as a symbolic constant in `<stdio.h>`. No valid character has the value `-1`, which is exactly why it works as a sentinel — it can never be confused with real input. This is also why `getchar()` returns `int` and not `char`.

---

## Other Programs Written

### read_char.c — Echo input back to output

```c
#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}
```

The simplest useful C program: reads every character from stdin and writes it to stdout. Compile and run it, type some text, and it mirrors it back. This is essentially what the `cat` command does.

---

## Compiler Warning Observed

When compiling `hello_world.c` with `cc`:

```
hello_world.c:6:1: warning: return type defaults to 'int' [-Wimplicit-int]
```

This warning appears because K&R-style C allowed `main()` without an explicit return type. Modern C standards require `int main()`. The warning is expected when following the book's early examples. The code still compiles and runs correctly.

The K&R book was written before C was formally standardized, so some syntax in early chapters will trigger warnings on modern compilers. This is normal. Treat warnings as information — understand them, do not panic over them.

---

## CLion Setup Note

CLion requires a `CMakeLists.txt` file to understand a project. It cannot compile a loose `.c` file on its own. Two options:

**Option 1** — Create a new project in CLion (File > New Project > C Executable) and let it generate the `CMakeLists.txt` automatically.

**Option 2** — Manually add a `CMakeLists.txt` to an existing directory:

```cmake
cmake_minimum_required(VERSION 3.10)
project(phase0)
add_executable(hello_world hello_world.c)
```

Then open the folder (not the file) in CLion.

Note: compiling directly in the terminal with `cc hello_world.c` is the more K&R-authentic approach and aligns with how the roadmap uses `make` and `Makefile` in later phases.

---

## Files Written

### Date: 15/04/26
```
phase-0/src/
    hello_world.c
    fahrenheit_celsius_table.c
    exercise.c
    CMakeLists.txt
    a.out
```

### Date: 16/04/26
```
phase-0/src/
    read_char.c
    count_character.c
    
    /exercise
    exercise_1_6.c
    exercise_1_7.c
```

---

## Roadmap Alignment

| Roadmap Item | Status |
|---|---|
| Install GCC or Clang | Done |
| Set up VS Code / CLion | Done (CLion) |
| Create GitHub repo: systems-journey | Done |
| Read intro chapters of K&R | In progress (through 1.5) |
| Write and compile first C program | Done (hello_world.c) |
| Watch: CS50 Week 1 lecture (free, Harvard edX) | Done |

---

*Continue from: K&R Section 1.6*