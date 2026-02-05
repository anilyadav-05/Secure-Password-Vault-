# Task 1: Secure Password System

## Overview
This is a C++ project for the OWASP Recruitment Task 1 ("Build Secure Thinking").
It implements a custom **Vigenère Cipher** to encrypt and decrypt passwords using a Master Key.

## How It Works
1. **The Logic:** The system takes a "Master Key" (like a password) and shifts the characters of your text based on that key.
2. **The Math:** - It converts characters to ASCII numbers.
   - It adds the Key's value to the Password's value.
   - It uses `Modulo 95` to ensure the result always stays within the printable text range (ASCII 32-126).
3. **Security:** Without the Master Key, the encrypted text cannot be reversed to readable language.

## How to Run
1. Open a terminal in this folder.
2. Compile the code:
   ```bash
   g++ main.cpp -o secure_tool