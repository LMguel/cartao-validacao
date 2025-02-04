# Credit Card Validator (credit.c)

This C program validates credit card numbers using the Luhn algorithm. The Luhn algorithm is widely used for verifying the validity of credit card numbers and other numeric identifiers.

## Description

The program prompts the user to enter a credit card number and validates whether it is valid or not. It checks the number using the Luhn formula and also identifies the type of card based on the first two digits. Supported card types are:

- **VISA** (if the number starts with 4 and has 13 or 16 digits)
- **MASTERCARD** (if the number starts with 51, 52, 53, 54, or 55 and has 16 digits)
- **AMEX** (if the number starts with 34 or 37 and has 15 digits)

If the card number is invalid, the program will notify the user. The user can continue checking other card numbers until they decide to exit the program.

## How to Use

### Prerequisites

This program is written in C and uses the C standard library. No external libraries are required.

### Compiling and Running

1. **Compile the Program**:
   If you're using a development environment with `gcc`, compile the program using the following command:

   ```bash
   gcc credit.c -o credit

2. **Run the Program:** After compiling, run the program wihth:

   ```bash
   ./credit
