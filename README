
# EXPL Compiler Lab

This repository contains a complete **stage-wise implementation of the EXPL compiler**, built as part of a Compiler Laboratory.  
The compiler is developed incrementally from **Stage 0 to Stage 8**, following the EXPL specification, using **Lex, Yacc, C, and XSM**.

All real development happens inside the `workdir/` directory.

---

## Project Layout

```text
compiler-lab/
│
├── workdir/                     # Main working directory
│   ├── STAGE1 ... STAGE8/       # Incremental compiler stages
│   ├── current/                 # Final stable compiler (Mirror of STAGE8)
│   ├── compiler/                # Shared compiler support files
│   │
│   ├── xsm/                     # XSM assembly programs (Stage 0 / 2)
│   ├── lexus/                   # Lex exercises (Stage 0)
│   ├── lexwithyacc/             # Lex + Yacc exercises (Stage 0)
│   └── yacc/                    # Yacc exercises (Stage 0)
│
├── xsm_dev/                     # XSM simulator and development tools
├── xfs-interface/               # XFS interface for disk management
├── spl/                         # SPL (System Programmer's Language) related files
├── Makefile                     # Root build file
└── README.md                    # This documentation
```

---

## What Stage 0 Means Here

There is **no `STAGE0/` directory**.

Stage 0 exercises are split across these folders:

- `workdir/xsm`
- `workdir/lexus`
- `workdir/lexwithyacc`
- `workdir/yacc`

These contain:
- XSM assembly programs  
- Lex scanners  
- Yacc grammars  
- Lex+Yacc based exercises  

From **Stage 1 onward**, each compiler stage has its own directory (`STAGE1` → `STAGE8`).

---

## What Each Stage Contains

Every `STAGE#` directory contains:
- Lex file: `compiler.l`
- Yacc file: `compiler.y`
- Generated `lex.yy.c`
- C helper files and headers
- Tree, symbol table, type table, codegen modules
- Test input programs
- A label translator (`label/` folder)

From **Stage 5 onwards**, each stage also contains build and debug scripts.

---

## Build & Run System

### Untill STAGE 5

untill stage 5 you don't have compile.sh or debug.sh you have to compile all the files manually to create the final executable 'compiler'

### Above STAGE 5
Each `STAGE5` and above contains:

- `compile.sh`
- `debug.sh`


### compile.sh
This script automates the entire pipeline:

        1. Runs `lex compiler.l`
        2. Runs `yacc compiler.y`
        3. Compiles all `.c` and header files
        4. Links everything into an executable named: compiler

        located inside:
            - workdir/STAGE#/ of corresponding stage.
        5. Then it:
            - Runs the compiler on a given EXPL program as argument to `compile.sh'
            - Produces `output.xsm` in /workdir/STAGE#/.
            - Runs the label translator in /workdir/STAGE#/label.
            - Produces final machine code as: workdir/STAGE#/label/translated.xsm


This is the final executable XSM program.

---

### debug.sh

This script:
- Builds the compiler
- Runs **gdb** on the `compiler` executable
- Uses the provided EXPL input file

It **does not** run the label translator.  
This is meant purely for debugging the compiler itself.

Usage:
    ./debug.sh <input_file.expl>


---

## How to Use a Stage

### To create the ".xsm" machine code

- Go to any stage directory, for example:

```bash
        cd workdir/STAGE8
```




- Compile and generate machine code:
```bash
        ./compile.sh <input_file.expl>
```


- This will create:


        1. workdir/STAGE8/output.xsm
        2. workdir/STAGE8/label/translated.xsm

### To debug:

```bash
        ./debug.sh <input_file.expl>
```

- will enter the gdb

---

## current/

The `current/` directory always mirrors **STAGE8** and represents the final completed compiler.

You can use `current/` if you just want the finished compiler without dealing with intermediate stages.

---

## What This Repository Represents

This is not just a compiler — it is a **complete development history** of an EXPL compiler:
- From raw Lex and Yacc exercises
- To a full-featured compiler that generates executable XSM machine code

Each stage documents a milestone in building a real compiler.

        





