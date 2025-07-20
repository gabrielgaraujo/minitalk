
![Libft](https://github.com/user-attachments/assets/75b0ba16-b352-4218-b661-7a5f2a0ec76f)

Libft is the first project at [42 Wolfsburg](https://42wolfsburg.de). It is a custom implementation of essential C standard library functions and additional utilities designed to deepen your understanding of C programming fundamentals.

## Features

Libft provides a variety of essential programming tasks, including:

- **String Manipulation:** Functions to measure, modify, and join strings.
- **Character Checks:** Functions to identify character types (e.g., digits, alphabetic characters).
- **Memory Manipulation and Allocation:** Functions to copy, set, move, and allocate memory.
- **Data Conversion:** Functions like `ft_atoi` and `ft_itoa` to convert data between formats.

To see the complete list of available functions and their prototypes (return types, names, and arguments), refer to [`libft.h`](./libft.h).

## Getting Started

### Prerequisites
- A C compiler (e.g., `gcc` or `cc`).

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/gabrielgaraujo/libft.git
   cd libft
   ```
2. Build the library:
   ```bash
   make
   ```
3. Include `libft.a` in your projects by adding it to your linker flags:
   ```bash
   gcc your_program.c -L. -lft -o your_program
   ```

### Cleaning Up
- Remove object files:
  ```bash
  make clean
  ```
- Remove object files and the compiled library:
  ```bash
  make fclean
  ```
- Rebuild the library from scratch:
  ```bash
  make re
  ```

## Usage Example
Here's a simple program using `libft`:

```c
#include "libft.h"
#include <stdio.h>

int main() {
    const char *str = "Hello, World!";
    printf("Length: %zu\n", ft_strlen(str));
    return 0;
}
```

Compile it with:
```bash
gcc main.c -L. -lft -o main
./main
```
---

Crafted with care during the 42 Wolfsburg journey by [Gabriel Araujo](https://github.com/gabrielgaraujo).
