*This project has been created as part of the 42 curriculum by refernan, phkaway.*

## Description
Push_swap is a highly optimized data sorting algorithmic project. The primary goal is to sort a randomly generated list of integers in a stack (Stack A) in ascending order, utilizing an initially empty secondary stack (Stack B). The project enforces a severely restricted set of allowed operations (such as swapping top elements, pushing elements between stacks, and rotating or reverse rotating elements). The overarching objective is to achieve this sorted state using the absolute minimum number of operations possible, demonstrating a deep understanding of algorithmic time complexity, data structures, and memory management in C.

## Instructions
### Compilation
To compile the project, run the following command in the root of the repository. The Makefile complies with all 42 standards (using `-Wall -Wextra -Werror` flags).
```bash
make
```
This will generate the `push_swap` executable.

You can also use:
- `make clean` to remove object files.
- `make fclean` to remove object files and the executable.
- `make re` to fully recompile the project from scratch.

### Execution
Run the program by passing a list of integers as arguments. The program will output the exact sequence of operations required to sort the stack.
```bash
./push_swap 4 67 3 87 23
```
If the arguments contain duplicates, non-numeric characters, or numbers outside the standard integer limits (MAX_INT / MIN_INT), the program will print `Error` to the standard error output (`stderr`) and cleanly exit without any memory leaks.

You can verify the output sequence using the official 42 checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms Selected and Justification

Handling a completely random stack of integers with only two stacks and restricted movements is a complex problem. To optimize the number of moves across different input sizes (from 3 numbers up to 500+), the project utilizes a heavily decoupled architecture consisting of **Data Normalization** followed by an advanced **Adaptive Routing Strategy**.

### 1. Pre-Processing: Data Normalization (Quicksort)
Before any push_swap operation is executed, the raw integer values (which could include massive negative and positive numbers) are normalized into a simplified array of sequential indices from `0` to `N-1`. This is achieved by duplicating the input into a temporary array and sorting it using the classic **Quicksort** algorithm.
**Justification:** Normalization completely eliminates edge-cases related to negative numbers and large gaps between values. It allows the main sorting algorithms to work predictably with a contiguous sequence of indices, drastically reducing algorithm complexity.

### 2. The Adaptive Router & Disorder Ratio
Instead of blindly picking an algorithm based solely on the amount of numbers, the program calculates a **Disorder Ratio** (a mathematical float from `0.0` to `1.0`). It computes the current number of inversions in the stack and divides it by the maximum theoretical inversions for that size. 
**Justification:** A nearly sorted list of 100 elements (e.g., ratio `0.1`) requires a completely different approach than a perfectly reversed list (ratio `1.0`). The adaptive router dynamically selects between *Simple*, *Chunk*, or *Radix* sort based on a matrix of the input size and this exact disorder ratio, ensuring the lowest operation cost possible.

### 3. Small Inputs (3 to 5 elements): Hardcoded Decision Trees
- **3 Elements:** Calculates the theoretical minimum moves using a hardcoded decision tree (`sa`, `ra`, `rra`).
- **5 Elements:** Pushes the two absolute smallest values to Stack B, calls the 3-element sort on A, and pushes the two values back.
**Justification:** Complex algorithms waste operations on tiny lists. This hardcoded approach guarantees the absolute theoretical minimum of operations (max 2 for 3 elements, max 12 for 5 elements).

### 4. Simple Sort (Small-to-Medium Inputs)
The Simple Sort repeatedly finds the absolute smallest element in Stack A, rotates it to the top, and pushes it to Stack B. Once Stack A is empty, it pushes everything back.
**Justification:** For small lists (e.g., 6 to ~40 elements) or heavily ordered lists (low disorder ratio), Simple Sort outperforms complex chunking by reducing unnecessary algorithmic overhead.

### 5. Chunk Sort (Medium Inputs)
The Chunk Sort divides the normalized indices into mathematical "chunks". It iterates through Stack A, pushing elements that belong to the current chunk into Stack B. To optimize further, it pushes the larger half of the chunk to the top of B, and rotates the smaller half to the bottom of B. Once all chunks are transferred, it smartly pushes elements back to A.
**Justification:** For medium-sized lists (like the official 100-number test), Chunk Sort is highly efficient. By sorting the chunks roughly during the push phase, the return phase costs significantly fewer operations. It consistently scores the maximum grade for 100 numbers (averaging ~550 operations).

### 6. Radix Sort (Large Inputs)
For massive and highly disordered inputs (e.g., 500+ numbers), the project employs a **Base-2 Radix Sort** implemented via bitwise operations. It loops through each bit of the normalized indices (from least to most significant). If the current bit is `0`, it pushes to Stack B. If `1`, it rotates Stack A. Everything in B is then pushed back to A for the next bit cycle.
**Justification:** Radix Sort in base-2 (`>>` and `&`) is mathematically stable and completely avoids the infinite loops found in deep Quicksort recursion. It reliably sorts 500 numbers in ~5100 operations, well below the 5500 limit for maximum points.

## Resources
The development of this project relied on several fundamental computer science resources and tools:

**Classic References:**
- *Introduction to Algorithms (Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein)*: Used as the foundational reference for understanding the time complexity of Quicksort and the bitwise mechanics of Radix Sort.
- *Push_swap visualizers (e.g., o-reo push_swap_visualizer)*: Essential for debugging sorting anomalies and visually understanding the physical movement of the stack nodes during bitwise rotations.
- *42 Curriculum Documentation*: Norminette standard guidelines and standard Libc documentation (`malloc`, `free`, `write`).

**How AI was Used:**
Artificial Intelligence (specifically Large Language Models) was used actively during the development cycle to accelerate learning and code refactoring. The AI was utilized strictly for the following specific tasks:
1. **Architectural Brainstorming:** Discussing the pros and cons of Chunk-Sort versus Radix-Sort algorithms, ultimately leading to the decision to use Data Normalization combined with an Adaptive Router based on Disorder Ratio.
2. **Memory Management Auditing:** Assisting in designing a global state `t_env` struct to ensure that all dynamically allocated memory could be easily tracked and freed in a single `free_env()` function, guaranteeing zero memory leaks during edge-case error handling.
3. **Test Generation:** Generating Bash one-liners and Python scripts to run hundreds of random permutations (`shuf`) against the binary to strictly validate the operation count averages for the 100 and 500 number evaluation tiers.
