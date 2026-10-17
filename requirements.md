# ATM Project — Requirements

## 1. Purpose

The purpose of this project is to develop a simple Automated Teller Machine (ATM) application using C++.

## 2. Functional Requirements

The system is planned to:

- **FR1:** Display a menu of available operations.
- **FR2:** Validate account access using a PIN.
- **FR3:** Display the account balance.
- **FR4:** Allow cash deposits.
- **FR5:** Allow cash withdrawals when sufficient funds are available.
- **FR6:** Reject invalid amounts and invalid menu choices.
- **FR7:** Display clear messages for successful and unsuccessful operations.
- **FR8:** Record transactions.
- **FR9:** Support transfers between accounts if required by the final specification.

## 3. Non-Functional Requirements

- **NFR1:** The program should be easy to use.
- **NFR2:** The code should be organized into understandable components.
- **NFR3:** The program should handle invalid input safely.
- **NFR4:** The main operations should be covered by unit tests.
- **NFR5:** The code should include appropriate documentation.

## 4. Technical Requirements

- Programming language: C++.
- Build system: CMake.
- Testing framework: To be confirmed.
- Documentation: Markdown and Doxygen.

## 5. Constraints and Assumptions

- The initial version is intended for educational use.
- Account data may be stored in memory unless persistent storage is required.
- This project is a simulation and is not intended to process real banking transactions.

## 6. Status

These requirements are preliminary and must be checked against the teacher's official assignment.
