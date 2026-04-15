# 🗺️ Systems Programming Roadmap
### C → Rust | Source of Truth Document
*For: AI & Software Engineer pursuing M.Sc. in CS / AI / Systems / Cyber*
*Languages already known: Python, JavaScript, GoLang*

---

> How to use this document
> This is your single source of truth. Review it weekly. Check off milestones as you go.
> The timeline is intentionally generous — you are working and have active projects.
> Do not rush phases. Depth over speed.

---

## 📌 Guiding Principles

1. Build, don't just read. Every concept must produce a working artefact.
2. One project per phase. Finish it before moving on.
3. Public GitHub. Every project goes on GitHub. Accountability through visibility.
4. No tutorial hell. Max 30% consuming content, 70% writing code.
5. Relate everything back to Python/JS. Ask: *"What is C/Rust doing that Python hides from me here?"*

---

## 🗓️ Timeline Overview

| Phase | Language | Focus | Duration | Effort |
|-------|----------|-------|----------|--------|
| 0 | C | Environment & Foundations | 2 weeks | 1–2 hrs/day |
| 1 | C | Core C & Memory | 6 weeks | 1–2 hrs/day |
| 2 | C | Data Structures from Scratch | 8 weeks | 1–2 hrs/day |
| 3 | C | Systems Project | 6 weeks | 1–2 hrs/day |
| 4 | Rust | Rust Foundations | 6 weeks | 1–2 hrs/day |
| 5 | Rust | Ownership, Concurrency & Safety | 8 weeks | 1–2 hrs/day |
| 6 | Rust | Production Systems Project | 8 weeks | 1–2 hrs/day |
| 7 | Both | Masters Prep & Portfolio Polish | Ongoing | Flexible |

Total estimated duration: ~12–18 months at a sustainable pace.

---

## ☑️ Phase 0 — Environment & Orientation *(Weeks 1–2)*

> Goal: Get your tools ready and understand *why* you are here.

### Setup Checklist
- [x] Install GCC or Clang (`gcc --version`)
- [x] Install make and gdb (debugger)
- [x] Set up VS Code with the C/C++ extension or use CLion
- [x] Create a GitHub repo: systems-journey
- [ ] Read: *Why C?* — skim the intro chapters of K&R (The C Programming Language)
- [ ] Watch: CS50 Week 1 lecture (free, Harvard edX)

### Deliverable
- [ ] Write and compile your first C program: a calculator that takes two numbers and an operator from stdin and prints the result.

---

## ☑️ Phase 1 — Core C & Memory Fundamentals *(Weeks 3–8)*

> Goal: Understand how memory actually works. This is the single most important phase.

### Concepts to Master

Week 3–4: C Basics
- [ ] Variables, types, and type sizes (`sizeof`)
- [ ] Functions, header files, #include
- [ ] Loops, conditionals, switch
- [ ] Arrays and strings (null-terminated `char[]`)
- [ ] printf and scanf formatting

Week 5–6: Pointers
- [ ] What a pointer is (address vs value)
- [ ] Pointer arithmetic
- [ ] Pointers to functions
- [ ] Pointers and arrays (they are nearly the same thing)
- [ ] Double pointers (`**ptr`)

Week 7–8: Memory Management
- [ ] Stack vs heap — understand the difference deeply
- [ ] malloc, calloc, realloc, free
- [ ] Memory leaks and how to detect them (`valgrind`)
- [ ] Buffer overflows — what they are and why they matter for Cyber
- [ ] struct and how data is laid out in memory

### Resources
- K&R Chapters 1–6
- CS50 Weeks 2–4
- man pages for malloc, printf, memcpy

### Deliverable
- [ ] Student Grade Manager — a C program that:
    - Reads student names and grades from a file
    - Stores them in a dynamically allocated array of structs
    - Sorts them (implement your own sort — no `qsort`)
    - Prints a formatted report to stdout
    - Frees all memory before exit (verified with `valgrind`)

---

## ☑️ Phase 2 — Data Structures from Scratch in C *(Weeks 9–16)*

> Goal: Implement every major data structure manually. No libraries. This is where DSA clicks.

### Why This Phase Matters
When you implement a linked list in C, you understand why Python's list is secretly an array, why insertion at the head is O(1), and why cache misses make linked lists slower in practice despite matching Big-O. This is irreplaceable knowledge.

### Data Structures to Build

Week 9–10: Linear Structures
- [ ] Dynamic array (your own `ArrayList`)
- [ ] Singly linked list with: insert, delete, search, reverse
- [ ] Doubly linked list
- [ ] Stack (array-backed and linked-list-backed)
- [ ] Queue (circular buffer implementation)

Week 11–12: Trees
- [ ] Binary search tree (BST) with: insert, delete, search, in/pre/post-order traversal
- [ ] Understand tree balance — why a sorted insert breaks a BST
- [ ] AVL tree or Red-Black tree (implement one rotation at minimum)
- [ ] Heap (min-heap) and heapsort

Week 13–14: Hash Structures
- [ ] Hash table with separate chaining
- [ ] Hash table with open addressing (linear probing)
- [ ] Understand load factor and resizing

Week 15–16: Graphs
- [ ] Adjacency list and adjacency matrix representations
- [ ] BFS and DFS
- [ ] Dijkstra's algorithm

### Deliverable
- [ ] DSA Library in C — a single GitHub repo (`c-dsa-lib`) with a clean header file (`dsa.h`) that exposes all the structures above. Each structure in its own .c file. Include a test.c that demonstrates every operation.

---

## ☑️ Phase 3 — Systems Project in C *(Weeks 17–22)*

> Goal: Build something real that uses OS concepts — the bridge between C and systems knowledge you'll need for your masters.

### Concepts to Learn First *(~1 week)*
- [ ] File I/O (`fopen`, fread, fwrite, `fclose`)
- [ ] Process creation (`fork`, exec, `wait`) — Unix/Linux
- [ ] Signals (`SIGINT`, SIGTERM, `signal()`)
- [ ] Pipes and inter-process communication (IPC) basics
- [ ] System calls vs library calls

### Choose One Capstone Project

Pick the one that aligns most with your masters' priority:

| Project | Best For |
|---------|----------|
| Mini Shell — a UNIX shell that handles cd, pipes |, redirects >, background jobs & | Systems Design, CS |
| Memory Allocator — implement your own malloc`/`free using sbrk | CS, AI (understanding runtimes) |
| Network Port Scanner — scan a range of IPs/ports using raw sockets | Cyber |
| Simple HTTP Server — serve static files over TCP sockets | Systems Design, CS |

Recommended default: Mini Shell — it touches processes, file descriptors, signals, parsing, and memory all at once.

### Deliverable
- [ ] Chosen project committed to GitHub with a proper README.md explaining what it does, how to build it (`Makefile`), and what systems concepts it demonstrates.

---

## ☑️ Phase 4 — Rust Foundations *(Weeks 23–28)*

> Goal: Learn Rust's syntax and mental model. Reframe everything C taught you.

### Concepts to Master

Week 23–24: Getting Started
- [ ] Install Rust (`rustup`), understand cargo (Rust's build tool)
- [ ] Variables, mutability (`let` vs `let mut`)
- [ ] Types: scalars, tuples, arrays, slices
- [ ] Functions, match, if let, while let
- [ ] struct, enum, impl

Week 25–26: Ownership — the core of Rust
- [ ] Ownership rules (each value has one owner)
- [ ] Move semantics vs copy semantics
- [ ] Borrowing and references (`&T` vs `&mut T`)
- [ ] The borrow checker — understand its error messages, don't fight them
- [ ] Lifetimes (basic intro — don't over-index here yet)

Week 27–28: Core Rust Patterns
- [ ] Option<T> and Result<T, E> — Rust's answer to null and exceptions
- [ ] Pattern matching (`match`, if let, destructuring)
- [ ] Traits (Rust's answer to interfaces/polymorphism)
- [ ] Iterators and closures
- [ ] Error handling with ? operator

### Resources
- The Rust Book: doc.rust-lang.org/book (free, official, excellent)
- Rustlings: github.com/rust-lang/rustlings (small exercises, do these daily)

### Deliverable
- [ ] CLI Todo App in Rust — a command-line todo manager that:
    - Adds, lists, completes, and deletes tasks
    - Persists tasks to a JSON file
    - Uses Result and Option properly (no .unwrap() in production code paths)
    - Handles all errors gracefully

---

## ☑️ Phase 5 — Ownership Deep Dive, Concurrency & Unsafe *(Weeks 29–36)*

> Goal: Master what makes Rust genuinely different from every other language.

### Concepts to Master

Week 29–30: Smart Pointers & Heap
- [ ] Box<T> — heap allocation
- [ ] Rc<T> and Arc<T> — reference counting
- [ ] RefCell<T> — interior mutability
- [ ] Understand when to use each

Week 31–32: Traits Deep Dive
- [ ] Generic functions and structs
- [ ] Trait objects (`dyn Trait`) vs generics
- [ ] Key standard traits: Clone, Copy, Display, Debug, From, Into
- [ ] Iterator trait — implement your own iterator

Week 33–34: Concurrency
- [ ] Threads (`std::thread`)
- [ ] Message passing with channels (`std::sync::mpsc`)
- [ ] Shared state with Mutex<T> and Arc<T>
- [ ] Why Rust's concurrency model prevents data races at compile time
- [ ] Intro to async`/`await and tokio

Week 35–36: Unsafe Rust & FFI
- [ ] What unsafe means and when it's justified
- [ ] Raw pointers in Rust
- [ ] Calling C code from Rust (FFI) — bridge your C knowledge
- [ ] Writing a small Rust wrapper around a C function

### Deliverable
- [ ] Multithreaded Web Scraper — a Rust program that:
    - Takes a list of URLs from a file
    - Fetches them concurrently using threads or tokio
    - Extracts a specific piece of data (e.g., page title)
    - Writes results to a CSV file
    - Handles network errors and timeouts gracefully

---

## ☑️ Phase 6 — Production Systems Project in Rust *(Weeks 37–44)*

> Goal: Build something substantial enough to put on a masters application and GitHub portfolio.

### Choose One Capstone Project

| Project | Best For | Complexity |
|---------|----------|------------|
| HTTP Server from scratch — TCP sockets, request parsing, routing, static file serving | Systems Design, CS | ★★★☆☆ |
| Key-Value Store — Redis-like in-memory store with persistence, TCP protocol | Systems Design, CS, AI | ★★★★☆ |
| Static Analysis Tool — parse source code files and report metrics/issues | CS, AI | ★★★★☆ |
| Packet Analyser — capture and decode network packets using raw sockets | Cyber | ★★★★☆ |
| WASM Runtime — a tiny WebAssembly interpreter | CS, Systems Design | ★★★★★ |

Recommended default: Key-Value Store — it touches networking, data structures, persistence, concurrency, and performance all at once. Directly relevant to AI/ML infrastructure.

### Project Requirements (whichever you choose)
- [ ] Full README.md with architecture diagram
- [ ] Benchmarks — measure and document performance
- [ ] Tests — unit and integration
- [ ] Proper error handling throughout
- [ ] A DESIGN.md explaining the technical decisions you made and why

---

## ☑️ Phase 7 — Masters Prep & Portfolio Polish *(Ongoing)*

> Goal: Translate your systems knowledge into academic and professional credibility.

### For Your M.Sc. Application
- [ ] Ensure your GitHub profile is clean and professional
- [ ] Write a 1-page technical summary of each capstone project
- [ ] If applying to Systems or Cyber programmes — highlight your C work, your memory allocator, and your Rust systems project
- [ ] If applying to AI/ML programmes — highlight that you understand runtimes, memory layout, and can work close to the metal (rare for AI engineers)
- [ ] Consider contributing a small fix or documentation improvement to an open source Rust project

### Stretch Goals *(do these if time allows)*

| Goal | Value |
|------|-------|
| Implement a basic interpreter or compiler in C or Rust | Directly relevant to CS masters |
| Port one of your C DSA structures to Rust | Shows bridging of knowledge |
| Learn gdb and lldb debugging deeply | Critical for Cyber |
| Read *Computer Systems: A Programmer's Perspective* (CS:APP) | The gold standard systems textbook |
| Contribute to the Rust standard library or an active crate | Portfolio differentiator |

---

## 📚 Complete Resource List

### C
| Resource | Type | Priority |
|----------|------|----------|
| *The C Programming Language* — Kernighan & Ritchie | Book | Essential |
| CS50 (edX, free) | Course | Essential |
| *Computer Systems: A Programmer's Perspective* | Book | High |
| man pages | Reference | Always |
| valgrind documentation | Tool | High |

### Rust
| Resource | Type | Priority |
|----------|------|----------|
| The Rust Book (`doc.rust-lang.org/book`) | Book | Essential |
| Rustlings (`github.com/rust-lang/rustlings`) | Exercises | Essential |
| *Programming Rust* — Blandy & Orendorff | Book | High |
| docs.rs | Reference | Always |
| Jon Gjengset's YouTube channel | Video | High |

### DSA
| Resource | Type | Priority |
|----------|------|----------|
| *Introduction to Algorithms* — CLRS | Book | Reference |
| *The Algorithm Design Manual* — Skiena | Book | High (more readable) |
| LeetCode (Easy → Medium, after Phase 2) | Practice | Medium |

---

## 📊 Progress Tracker

| Date     | Phase | Milestone Completed | Notes                      |
|----------|-------|---------------------|----------------------------|
| 10/04/26 | 0 | Environment setup | Used CLion                 |
| 14/04/26 | 0 | First C program | Simple Hello World Program |
|          | 1 | Pointers mastered |                            |
|          | 1 | Grade Manager complete |                            |
|          | 2 | Linear structures built |                            |
|          | 2 | Trees built |                            |
|          | 2 | Hash table built |                            |
|          | 2 | DSA Library complete |                            |
|          | 3 | Systems concepts learned |                            |
|          | 3 | Capstone project complete |                            |
|          | 4 | Ownership understood |                            |
|          | 4 | CLI Todo App complete |                            |
|          | 5 | Concurrency mastered |                            |
|          | 5 | Web Scraper complete |                            |
|          | 6 | Production project complete |                            |
|          | 7 | Portfolio polished |                            |

---

## ⚠️ Anti-Patterns to Avoid

- Tutorial hopping — pick one resource per phase and finish it
- Skipping the builds — reading without building is not learning
- Jumping to Rust too early — C first, always
- Ignoring compiler warnings — treat all warnings as errors (`-Wall -Wextra` in GCC)
- Copy-pasting solutions — type every line of code yourself, especially early on
- Doing LeetCode instead of building — LeetCode is a supplement, not the foundation
- Abandoning a project 80% through — finishing is a skill, practice it

---

## 🔁 Weekly Review Ritual

At the end of every week, answer these three questions in a private note or journal:

1. What did I build this week? *(if the answer is "nothing", that's the problem)*
2. What concept did I genuinely understand this week that I didn't before?
3. What is the single next thing I need to do? *(just one — not a list)*

---

*Document version: 1.0 | Created: April 2026 | Review: Monthly*