# Phase 0 Notes — Environment & Orientation
### K&R: The C Programming Language | Sections Read: Introduction through 1.5.4
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

### Section 1.5.2 — Character Counting

The character counter introduces `long` as a type — used instead of `int` when the count could grow large enough to overflow a 32-bit integer. On most systems, `long` is at least 32 bits but guaranteed to be no smaller than `int`. For counting characters across potentially large files, it is the safer choice.

```c
long nc;
nc = 0;
while (getchar() != EOF)
    ++nc;
printf("%ld\n", nc);
```

Key things to note:

- The `%ld` format specifier is required for `long` — using `%d` with a `long` is undefined behavior in C
- The body of the loop is `++nc` with no braces — legal because it is a single statement
- `getchar()` return value is not stored here since we only care about counting, not the character itself
- The counter also includes whitespace characters (`\n`, `\t`, spaces) — everything that comes through stdin gets counted

A second version using `for` instead of `while` is also shown in the book:

```c
long nc;
for (nc = 0; getchar() != EOF; ++nc)
    ;
```

The body is an empty statement (just `;`). All the work happens in the for-loop's init, condition, and increment. This is valid C — the for construct does not require a non-empty body.

---

### Section 1.5.3 — Line Counting

Lines are counted by counting newline characters. Every line of text in a UNIX text stream ends with `\n` — so counting `\n` occurrences equals counting lines.

```c
int c, nl;
nl = 0;
while ((c = getchar()) != EOF)
    if (c == '\n')
        ++nl;
printf("%d\n", nl);
```

Key things to note:

- `'\n'` is a character constant — a single character, value 10 in ASCII
- Single quotes denote character constants in C; double quotes denote string literals — these are not interchangeable
- The if-statement has no braces — again valid for a single-statement body
- `c` must still be `int` for correct EOF detection, even though we are comparing against a character

This program is functionally equivalent to `wc -l` on UNIX systems.

---

### Section 1.5.4 — Word Counting

Word counting combines everything from 1.5.1–1.5.3 into one program: characters, lines, and now words. The key challenge is defining what a "word" is in terms of a character stream — and the answer is a **state machine**.

A word boundary is detected by tracking whether you are currently inside or outside a word. Whitespace (`' '`, `'\n'`, `'\t'`) means you are outside. Any other character means you are inside. A new word is counted exactly once — at the moment you transition from `OUT` to `IN`.

```c
#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */

int c, nl, nw, nc, state;
state = OUT;
nl = nw = nc = 0;

while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
        ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
        state = OUT;
    else if (state == OUT) {
        state = IN;
        ++nw;
    }
}
```

Key things to note:

- `IN` and `OUT` are `#define` constants — not because `1` and `0` would not work, but because named states make the logic readable. When you see `state == OUT` you know immediately what it means. `state == 0` requires you to remember what `0` represents.
- `nw` is only incremented on the `OUT → IN` transition, not on every non-whitespace character. This is the correct logic — a five-letter word crosses that boundary once, not five times.
- The two `if` blocks are intentionally separate (not `else if`). A newline increments `nl` AND sets `state = OUT`. If they were chained, the newline would only do one of those things.
- A bug exists in some printings of K&R: `c = '\t'` (assignment) instead of `c == '\t'` (comparison). The assignment version always evaluates to the value of `'\t'` (9), which is truthy — so the condition would always be true, and every character would be treated as whitespace. Always read `=` vs `==` carefully in conditions.

#### What i actually built: a Finite State Machine

The word counter has two states and transitions between them based on input:

```
         whitespace
    ┌──────────────────┐
    ▼                  │
  OUT ──────────────► IN
       non-whitespace
         (count word)
```

This pattern — carry minimal state, transition on input — is fundamental in C and systems programming. Lexers, parsers, network protocol handlers, and regex engines all use the same idea at their core. You built one without knowing the term for it.

#### The `||` trap — why `c == ' ' || '\n' || '\t'` is always true

This is one of C's most common beginner mistakes coming from Python or JavaScript.

**Broken version:**
```c
if (c == ' ' || '\n' || '\t')   /* WRONG */
```

C parses this as:
```c
if ((c == ' ') || ('\n') || ('\t'))
```

`'\n'` is the integer `10`. `'\t'` is the integer `9`. In C, any non-zero integer is truthy. So this expression is always `(something) || true || true` — always true, regardless of what `c` is. Every character gets treated as whitespace and no words are ever counted.

**Correct version:**
```c
if (c == ' ' || c == '\n' || c == '\t')   /* correct */
```

C has no `in` operator like Python (`if c in (' ', '\n', '\t')`). Every comparison is binary — one left-hand side against one right-hand side. If you are comparing the same variable against multiple values, you must write `c ==` every time. The compiler will not warn you about the broken version — it is valid C that simply does not do what you intend.

**The rule:** every `==` needs its own explicit left-hand operand.

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

### Exercise 1-8 — Count blanks, tabs, and newlines

**Task:** Write a program to count blanks, tabs, and newlines.

**Solution:**

```c
#include <stdio.h>

int main() {
    int c, nl, tc, bc;
    nl = tc = bc = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            nl++;
        else if (c == '\t')
            tc++;
        else if (c == ' ')
            bc++;
    printf(" New Line Count: %d, Tab Count: %d, Blank Count: %d\n", nl, tc, bc);
}
```

**What this demonstrates:** Chained `if / else if` is the correct structure here — each character can only be one thing, so the branches are mutually exclusive. Using three separate `if` statements would work but would do unnecessary comparisons. The chained form short-circuits: once a match is found, the remaining conditions are skipped.

---

### Exercise 1-9 — Collapse multiple blanks into one

**Task:** Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

**Solution:**

```c
#include <stdio.h>

int main() {
    int c, prev_was_space;
    prev_was_space = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev_was_space == ' ') {}
        else {
            printf("%c", c);
        }
        prev_was_space = c;
    }
}
```

**What this demonstrates:** State tracking across loop iterations using a single variable. `prev_was_space` holds the previous character so the current iteration can make a decision based on context. The pattern of "remember what you just saw" appears constantly in stream processing. Note: the empty `if` body `{}` is functional but a cleaner inversion would be `if (!(c == ' ' && prev_was_space == ' ')) putchar(c);`.

---

### Exercise 1-10 — Make tabs and backspaces visible

**Task:** Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`.

**Solution:**

```c
#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }

    return 0;
}
```

**What this demonstrates:** The distinction between escape sequences as input values versus their literal text representations as output. When `c == '\t'`, the character is a real tab (ASCII 9). To print the two visible characters `\t`, you output `"\\t"` — the double backslash produces a literal `\` in the string, followed by `t`. Same logic applies to `\\` → `\\\\`. This kind of character-level transformation is a foundational pattern in parsers and formatters.

---

### Exercise 1-11 — How would you test the word count program?

**Task:** How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

**Answer:**

Test cases that stress the boundaries of the state machine:

- **Empty input** — no characters at all. All counts should be zero.
- **Only whitespace** — spaces, tabs, newlines but no words. Word count should be zero.
- **Single word, no newline** — tests that a word not followed by `\n` is still counted.
- **Multiple consecutive spaces** — `"hello   world"` should count as 2 words, not more.
- **Leading and trailing whitespace** — `"  hello  "` should still count as 1 word.
- **Tabs between words** — `"hello\tworld"` should count as 2 words.
- **Multiple lines** — verifies line counting works alongside word counting.
- **Mixed whitespace** — combinations of spaces, tabs, and newlines between words.

The most dangerous inputs are those at the transitions: starting in whitespace, ending in whitespace, or having consecutive whitespace of different types. Bugs in the state machine tend to appear at boundaries, not in the middle of normal input.

---

### Exercise 1-12 — Print input one word per line

**Task:** Write a program that prints its input one word per line.

**Solution:**

```c
#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, state;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                printf("\n");
            state = OUT;
        } else {
            putchar(c);
            state = IN;
        }
    }
}
```

**What this demonstrates:** The same `IN`/`OUT` state machine from `word_count.c`, repurposed for output formatting. The key insight: a newline should be printed not when whitespace is encountered, but only when whitespace is encountered *after* being inside a word (`state == IN`). This prevents printing blank lines for consecutive whitespace — the exact trap that hours of attempting an array-based approach could not solve cleanly.

**On the process:** This exercise was solved only after stepping away from the keyboard and writing pseudocode on paper first — including a manual trace through the logic with multiple words and multiple spaces as input, mimicking what the compiler would do step by step. The initial instinct was to store words in an array (natural from Python/JS), but arrays had not been covered yet. That constraint forced a simpler and ultimately more correct approach: track only the current state, one character at a time. The pseudocode trace confirmed the logic worked on paper before a single line of code was written.

The lesson: pseudocode and manual tracing are not a beginner crutch — they are how good engineers avoid writing code that needs to be thrown away.

---

## Other Programs Written

### word_count.c — Count lines, words, and characters

```c
#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

Combines line, word, and character counting in one pass. Equivalent to `wc` on UNIX. From K&R Section 1.5.4.

---

### count_character.c — Count all characters from input

```c
#include <stdio.h>

int main() {
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

Counts every character — including spaces and newlines — using a `long` to handle large inputs safely. From K&R Section 1.5.2.

---

### line_counting.c — Count newlines from input

```c
#include <stdio.h>

int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

Counts lines by counting `\n` characters. Equivalent to `wc -l`. From K&R Section 1.5.3.

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

### Date: 17/04/26
```
phase-0/src/
    line_counting.c

    /exercise
    exercise_1_8.c
    exercise_1_9.c
    exercise_1_10.c
```

### Date: 18/04/26
```
phase-0/src/
    word_count.c

    /exercise
    exercise_1_11.c
    exercise_1_12.c
```

---

## Roadmap Alignment

| Roadmap Item | Status |
|---|---|
| Install GCC or Clang | Done |
| Set up VS Code / CLion | Done (CLion) |
| Create GitHub repo: systems-journey | Done |
| Read intro chapters of K&R | In progress (through 1.5.4) |
| Write and compile first C program | Done (hello_world.c) |
| Watch: CS50 Week 1 lecture (free, Harvard edX) | Done |

---

*Continue from: K&R Section 1.6*