# ATM Project — System Architecture

## 1. Overview

The ATM system will be developed in C++. It will provide basic banking operations through a menu-driven interface.

## 2. Planned Project Structure

- `src/main.cpp` — Starts the application and displays the menu.
- `include/atm.h` — Declares the ATM class and its functions.
- `tests/test_atm.cpp` — Contains automated unit tests.
- `docs/` — Contains project features, tasks, architecture, and report.

## 3. Main Components

### User Interface
Displays the menu, receives user input, and shows results.

### ATM Logic
Processes deposits, withdrawals, balance inquiries, and other supported operations.

### Account Management
Maintains account information and the available balance.

### Testing
Checks that the main operations behave as expected.

## 4. Program Flow

1. Start the application.
2. Display the ATM menu.
3. Read the user's choice.
4. Validate the input.
5. Perform the selected operation.
6. Display the result.
7. Return to the menu or exit.

## 5. Design Principles

- Encapsulation of account data.
- Separation of user interface and business logic.
- Input validation and error handling.
- Unit testing of important operations.

## 6. Current Status

This architecture describes the planned design. It may be updated during implementation to match the final requirements.

**Status:** Planned.
