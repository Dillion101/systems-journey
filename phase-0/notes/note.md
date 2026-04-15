# Phase 0 Notes — Environment & Orientation
### K&R: The C Programming Language | Sections Read: Introduction to 1.4
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

## Key Concepts from K&R (Introduction to Section 1.4)

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

---

## Roadmap Alignment

| Roadmap Item | Status                    |
|---|---------------------------|
| Install GCC or Clang | Done                      |
| Set up VS Code / CLion | Done (CLion)              |
| Create GitHub repo: systems-journey | Done                      |
| Read intro chapters of K&R | In progress (through 1.4) |
| Write and compile first C program | Done (hello_world.c)      |
 | Watch: CS50 Week 1 lecture (free, Harvard edX) | Done                      |
---

*Continue from: K&R Section 1.5*