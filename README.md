 SimpleLang Compiler

This project is a basic compiler for **SimpleLang**, a toy high-level language that compiles into assembly code for an 8-bit CPU.

 Structure
- src/ → Source code (C++ compiler components)
- examples/ → Sample SimpleLang programs
- output/ → Generated assembly outputs

How to Run
1. Open project in VS Code.
2. Compile:
   ```bash
   g++ src/compiler.cpp -o compiler
   ./compiler examples/program1.sl
   ```
3. Check output assembly inside `output/`.

Example
Input (`examples/program1.sl`):
```c
int a;
int b;
a = 10;
b = 20;
if (a == b) {
  a = a + 1;
}
```
