# ATM Project — Final Report

## 1. Introduction

This project aims to develop an Automated Teller Machine (ATM) system using C++.

## 2. Project Objectives

- Provide a simple menu-driven banking application.
- Support basic account operations.
- Validate user input and handle errors.
- Test the system's main functions.

## 3. Requirements

The system requirements are documented in `requirements.md` and will be updated according to the teacher's instructions.

## 4. Features

The planned features include account authentication, balance inquiry, deposits, withdrawals, transaction history, and other approved operations.

## 5. System Architecture

The application will be organized into source code, header files, unit tests, and documentation. The design will aim to separate the user interface from the ATM's business logic.

## 6. Implementation

This section will describe the implemented classes, functions, and technologies after development.

## 7. Class Hierarchy

The ATM system will use object-oriented programming in C++. The planned classes will represent ATM operations, account information, and transaction records.

### Planned Classes

- **ATM:** Coordinates ATM operations and interacts with the user interface.
- **Account:** Stores account information and manages the balance.
- **Transaction:** Represents deposits, withdrawals, and other supported transactions.

### Planned Relationships

- The ATM class uses an Account object to perform account operations.
- The Account class manages balance changes according to the system's rules.
- Transaction objects represent operations that can be recorded in the transaction history.

### Planned Class Relationship Diagram

```text
ATM
 |
 | uses
 v
Account
 |
 | records
 v
Transaction
```

**Note:** This is a preliminary design, not an inheritance hierarchy. The final classes and relationships will be adjusted to match the implemented code and the teacher's requirements.

## 8. Testing

This section will document the unit tests, test results, and any issues discovered after implementation.

## 9. Results and Discussion

The completed functionality, test results, and limitations will be described here after development.

## 10. Conclusion

The final conclusion will summarize the project outcomes and possible future improvements.

## 11. References

Add the course materials and other references used during development.

**Status:** Initial report template. Implementation and testing results will be added later.
