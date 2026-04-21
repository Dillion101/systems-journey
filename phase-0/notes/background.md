# Background — C, UNIX, and Environment
*Date started: April 15, 2026*

---

## What does C stand for?

C does not stand for anything. It is simply the language that came after B, which itself came from BCPL (Basic Combined Programming Language). When Dennis Ritchie improved upon B, the next letter was the natural choice. The name is purely sequential.

---

## What is the DEC PDP-11?

- DEC = Digital Equipment Corporation
- PDP = Programmed Data Processor
- The PDP-11 was a minicomputer from the late 1960s and 1970s — smaller than room-sized mainframes but still a cabinet-sized, expensive machine
- C and UNIX were written on and for the PDP-11
- The machine's architecture directly influenced C's design — particularly how C treats pointers and integers
- This is why C feels close to the hardware: it was shaped by real hardware constraints

---

## What does UNIX stand for?

UNIX is a play on an earlier system called MULTICS (Multiplexed Information and Computing Service). Developers built a simpler version and called it UNICS — Uniplexed Information and Computing Service — which eventually became UNIX.

---

## How is UNIX unique from operating systems today?

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

## Environment & Compiler Notes

### CLion Setup

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

### Compiler Warning: implicit int

When compiling `hello_world.c` with `cc`:

```
hello_world.c:6:1: warning: return type defaults to 'int' [-Wimplicit-int]
```

This appears because K&R-style C allowed `main()` without an explicit return type. Modern C requires `int main()`. The warning is expected when following the book's early examples — the code still compiles and runs correctly.

The K&R book was written before C was formally standardised, so some syntax in early chapters will trigger warnings on modern compilers. Treat warnings as information — understand them, do not panic over them.
