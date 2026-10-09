# Hexdump

A small command-line program written in C that reads data from standard input and displays it in hexadecimal format.

## Build

Using GCC:

```bash
gcc -Wall -Wextra -o hexdump main.c
```

## Usage

Pipe data to the program:

```bash
cat file | ./hexdump
```

You can also pipe text directly:

```bash
echo "Hello, world" | ./hexdump
```

## Example output

```text
00000000  48 6f 6c 61 2c 20 6d 75   6e 64 6f 0a               [ H o l a , . m u n d o . ]
```
