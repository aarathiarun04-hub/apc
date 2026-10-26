# APC — Arbitrary Precision Calculator

A command-line calculator in C that adds, subtracts, multiplies and divides
integers of **any length**. There is no 64-bit limit: every number is stored as a
doubly linked list with one decimal digit per node, so a thousand-digit operand
works just as well as `7 + 5`.

## Build

```sh
make            # or: gcc -o apc *.c
make clean      # removes *.o and the binary
```

## Usage

```sh
./apc <number1> <operator> <number2>
```

```sh
./apc 12345678901234567890 + 98765432109876543210
./apc 99999999999999999999 * 99999999999999999999
./apc 100000000000000000000 / 7
```

Both operands are printed first, then the result.

### Argument validation

- both operands must contain digits only (no signs, no decimal point)
- the operator must be a single character: `+`, `-`, `*` or `/`

Anything else prints `Invalid arguments entered` and exits.

## How it works

1. `main.c` validates the command-line arguments.
2. Each operand string is converted into a doubly linked list (`create_list`),
   one digit per node.
3. The selected operation builds a result list digit by digit:
   - `addition.c` — column addition with carry
   - `subtraction.c` — digit-wise subtraction with borrow
   - `multiplication.c` — repeated/partial-product multiplication
   - `division.c` — repeated subtraction division producing a quotient
4. Leading zeros are trimmed from the result before printing.

## Project structure

| File | Purpose |
| --- | --- |
| `apc.h` | `Dlist` node type, status codes, prototypes |
| `main.c` | Driver: argument validation, list creation, dispatch |
| `addition.c` | Arbitrary precision addition |
| `subtraction.c` | Arbitrary precision subtraction |
| `multiplication.c` | Arbitrary precision multiplication |
| `division.c` | Arbitrary precision division |
| `insert.c` | Doubly linked list helpers (insert first/last) |
| `Makefile` | Build and clean targets |
