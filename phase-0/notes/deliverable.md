# Phase 0 Deliverable — Calculator Program
*Date: May 7, 2026*

---

## The Brief

Write and compile a C program that takes two numbers and an operator from stdin and prints the result.

---

## What the Program Does

Reads two floats and an operator character from stdin, passes them to a `calculator` function, and prints the result to 3 decimal places.

```c
Enter your Values
5
3
/
The Result is 1.667
```

---

## Design Decisions

### Why a separate `calculator` function?

The computation is separated from `main` deliberately. `main` handles I/O — reading input and printing output. `calculator` handles logic. This separation means the function could be reused or tested independently without touching the I/O layer.

### Why `float` and not `int`?

Division. `5 / 3` in integer arithmetic gives `1`. Using `float` gives `1.667`, which is what a calculator should produce.

### Why `result = 0.0` at the top of `calculator`?

All error paths — invalid operator, divide by zero — need to return *something*. Initialising `result = 0.0` at the top means every branch is covered without repeating the assignment in each error case. The alternative (assigning `0.0` in each `else` block) is redundant.

---

## Bugs Encountered

### Bug 1 — `scanf` return value assigned to the variable

**What I wrote:**
```c
float num1 = scanf("%f", &num1);
```

**What this actually does:** `scanf` returns the number of items successfully read — an `int`, not the scanned value. So `num1` was being set to `1.0` (one item read successfully), not the user's input. `num2` same. The scanned values were written into the variables via the pointer (`&num1`) and immediately overwritten by the return value assignment.

**Fix:** `scanf` writes through the pointer. You don't assign its return value.
```c
float num1;
scanf("%f", &num1);
```

---

### Bug 2 — `\n` left in the input buffer swallowed by `%c`

**What happened:** After reading two floats, pressing Enter left a `\n` sitting in the input buffer. `scanf("%c", &operator)` grabbed that newline immediately — the program never waited for the operator to be typed. The operator variable held `\n`, which matched no case, triggering the invalid operator branch.

**What I tried first:** Putting `\n` in the format string — `scanf("%f\n", ...)`. This is wrong. In `scanf`, whitespace in a format string matches *any amount* of whitespace and causes `scanf` to block waiting for the next non-whitespace character.

**Fix:** A leading space in the format string tells `scanf` to skip all whitespace (including the leftover `\n`) before reading the character.
```c
scanf(" %c", &operator);
```

---

### Bug 3 — Infinite recursion on invalid input

**What I wrote:**
```c
else
{
    printf("Invalid operator!\n");
    result = calculator(num1, num2, operator);
}
```

**What happened:** Called `calculator` recursively with the same invalid operator. Nothing changed between calls — infinite recursion until stack overflow and segfault.

**Fix:** Recursion only makes sense when each call gets closer to a base case. Here, the operator never changes. The error path just prints the message and returns `0.0` — no recursion needed.

---

### Bug 4 — Divide by zero returns `inf`

**What happened:** `5 / 0` in IEEE 754 float arithmetic produces `inf`, not an error. C doesn't throw an exception.

**Fix:** Guard the division with an explicit check before dividing.
```c
if (num2 != 0) result = num1 / num2;
else printf("Invalid Operation, cannot divide by zero\n");
```

---

### Bug 5 — Uninitialised `result` returned on error paths

**What happened:** In the divide-by-zero and invalid operator branches, `result` was never assigned. The function returned whatever garbage happened to be in that memory location. It printed `0.000` by coincidence — this is undefined behaviour.

**Fix:** Initialise `result = 0.0` at the top of the function. Every error path then naturally returns `0.0` without needing explicit assignments in each branch.

---

## Key Things Learned

**`scanf` writes through a pointer, returns item count.** The variable gets its value via `&var`, not from the return value. Assigning the return value to the variable overwrites what `scanf` just wrote.

**`%c` reads the very next character, including whitespace.** After `%f` reads a number, the newline from Enter stays in the buffer. `" %c"` with a leading space skips all pending whitespace first.

**Whitespace in a `scanf` format string is not a literal match.** `"%f\n"` does not consume one newline — it consumes all whitespace until a non-whitespace character appears, which blocks the program.

**Recursion requires a changing base case.** Calling a function recursively with identical arguments is an infinite loop. Either the inputs change each call, or recursion is the wrong tool.

**Uninitialised variables are not zero.** A declared-but-unassigned `float result` holds whatever was in that stack memory. Initialise at declaration.

**IEEE 754 float division by zero gives `inf`, not a crash.** C does not raise an exception — the caller must guard against it explicitly.

---

## Files Written

### Date: 07/05/26
```
phase-0/src/exercise/
    deliverable.c
```