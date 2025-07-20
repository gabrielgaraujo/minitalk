


# Minitalk Project Subject - Text Format

## Project Summary
**Minitalk** - Version 3.2  
The purpose of this project is to code a small data exchange program using UNIX signals.

---

## Common Instructions
- Your project must be written in **C**
- Your project must be written in accordance with the **Norm**
- If you have bonus files/functions, they are included in the norm check, and you will receive a 0 if there is a norm error
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior
- All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated
- You must submit a **Makefile** that compiles your source files to the required output with the flags **-Wall, -Wextra, and -Werror**, using **cc**
- Your Makefile must not perform unnecessary relinking
- Your Makefile must contain at least the rules: **$(NAME), all, clean, fclean and re**
- To submit bonuses, you must include a **bonus rule** in your Makefile
- Bonuses must be placed in **_bonus.{c/h}** files
- **If your project allows you to use your libft, you must copy its sources and its associated Makefile into a libft folder. Your project's Makefile must compile the library by using its Makefile, then compile the project.**

---

## Project Instructions
- Name your executable files **client** and **server**
- You must submit a Makefile that compiles your source files. It must not perform unnecessary relinking
- **You are allowed to use your libft**
- You have to handle errors thoroughly. Under no circumstances should your program quit unexpectedly
- Your program must be free of memory leaks
- **You are allowed to use one global variable per program** (one for the client and one for the server), but its usage must be justified

### Permitted Functions for Mandatory Part:
- **write**
- **ft_printf** or any equivalent YOU coded
- **signal**
- **sigemptyset**
- **sigaddset**
- **sigaction**
- **kill**
- **getpid**
- **malloc**
- **free**
- **pause**
- **sleep**
- **usleep**
- **exit**

---

## Mandatory Part Requirements

### Overview
You must create a communication program in the form of a **client** and a **server**.

### Server Requirements:
- The server must be started first
- Upon launch, it must **print its PID**
- Once it receives a message, the server must **print it**
- The server must display the string **without delay**. If it seems slow, it is likely too slow
- **If displaying 100 characters takes 1 second, the program is too slow!**
- Your server should be able to **receive strings from several clients in a row without needing to restart**

### Client Requirements:
- The client takes **two parameters**:
  - The server PID
  - The string to send
- The client must send the specified string to the server

### Communication Rules:
- Communication between the client and server must **exclusively use UNIX signals**
- You can **only use these two signals: SIGUSR1 and SIGUSR2**
- **Important note: Linux system does NOT queue signals when you already have pending signals of this type!**

---

## Bonus Part (Optional)
**Note: The bonus part will only be assessed if the mandatory part is PERFECT.**

Bonus features:
- The server must acknowledge each received message by sending a signal to the client
- Unicode characters support!

---

## Technical Implementation Approach
Based on the requirements, here's how the system should work:

### Signal-Based Communication:
- Convert each character to binary (8 bits)
- Use **SIGUSR1** to represent bit **0**
- Use **SIGUSR2** to represent bit **1**
- Send each bit as a separate signal from client to server
- Server reconstructs characters bit by bit using signal handlers

### Key Functions Usage:
- **sigaction**: Set up robust signal handlers (preferred over signal())
- **kill**: Send signals from client to server
- **pause**: Server waits for incoming signals
- **getpid**: Server gets and displays its process ID
- **usleep**: Add delays between signals for reliability

### Error Handling:
- Validate command line arguments
- Check if target process exists
- Handle signal sending failures
- Prevent memory leaks
- Handle edge cases gracefully

---

## Project Structure Example:
```
minitalk/
├── Makefile
├── client.c
├── server.c
├── minitalk.h (optional)
└── libft/          (if using libft)
    ├── Makefile
    ├── libft.h
    └── *.c files
```

---

## Expected Behavior:
1. Start server: `./server` → displays "Server PID: [number]"
2. Send message: `./client [server_pid] "Hello World"` → server immediately displays "Hello World"
3. Server continues running, ready for next client
4. Multiple clients can send messages consecutively to same server

This is the complete mandatory specification for the Minitalk project.

