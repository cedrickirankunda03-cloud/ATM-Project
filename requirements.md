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
- # Additional Functional Requirements

## FR10 – Change PIN
The system shall allow an authenticated customer to change their current PIN after verifying the existing PIN.

## FR11 – Money Transfer
The system shall allow an authenticated customer to transfer money to another account.

## FR12 – Account Information
The system shall display the customer's account information, including account number and current balance.

## FR13 – Transaction History
The system shall record and display the customer's completed transactions, including deposits, withdrawals, and transfers.

## FR14 – Mini Statement
The system shall allow customers to view a summary of their five most recent transactions.

## FR15 – Transaction Receipt
The system shall generate a receipt containing the details of a completed transaction.

## FR16 – Voice Guidance
The system shall provide spoken instructions and notifications during ATM operations, including welcome messages, PIN instructions, transaction confirmations, and goodbye messages.

## FR17 – Card Removal Reminder
The system shall remind customers to take their bank card before ending an ATM session.

## FR18 – Card Removal Confirmation
The system shall allow customers to confirm that they have taken their card before the session ends.

## FR19 – Card Reminder Warning
The system shall provide an additional warning if the customer has not confirmed card removal within the specified time.

## FR20 – Language Selection
The system shall allow customers to select a supported language for ATM messages and voice guidance.

## FR21 – PIN Attempt Limit
The system shall limit the number of consecutive incorrect PIN attempts and temporarily block access after the permitted number is exceeded.

## FR22 – Daily Withdrawal Limit
The system shall enforce a maximum permitted withdrawal amount per customer per day.

## FR23 – ATM Cash Availability
The system shall check simulated ATM cash availability before approving a withdrawal.

## FR24 – Multiple Account Support
The system shall allow customers to select between supported account types, such as savings and current accounts.

## FR25 – Transaction Validation
The system shall validate transaction amounts and account details before processing deposits, withdrawals, and transfers.
## FR26 – Voice Assistant
The system shall provide a voice assistant that communicates with customers through spoken messages during ATM operations.

## FR27 – Spoken Transaction Notifications
The system shall announce the results of important ATM operations, including successful deposits, withdrawals, and transfers.

## FR28 – Spoken Balance Information
The system shall allow customers to hear their current account balance through voice output.

## FR29 – Card Removal Reminder
The system shall remind customers to take their bank card before the ATM session ends.

## FR30 – Repeated Card Reminder
The system shall repeat the card removal reminder if the customer has not confirmed card removal.

## FR31 – Voice Session Completion
The system shall provide a spoken goodbye message when the ATM session ends.

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
