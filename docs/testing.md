# ATM Project — Testing Plan

## 1. Purpose
This document describes how the ATM application will be tested.

## 2. Planned Tests
| Test ID | Test Case | Expected Result |
|---|---|---|
| T1 | Enter a correct PIN | Access is granted |
| T2 | Enter an incorrect PIN | Access is denied |
| T3 | Check the account balance | The current balance is displayed |
| T4 | Deposit a valid amount | The balance increases |
| T5 | Withdraw an affordable amount | The balance decreases |
| T6 | Withdraw more than the available balance | The withdrawal is rejected |
| T7 | Enter a negative amount | The amount is rejected |
| T8 | Enter an invalid menu choice | An error message is displayed |
| T9 | Review transaction history | Recorded transactions are displayed |


## 3. Testing Approach
- Test each important operation separately.
- Check normal inputs and invalid inputs.
- Verify that balance calculations are correct.
- Run automated unit tests after implementation.
- Record the test results after running the program.

## 4. Test Results
Test results will be added after the tests have been implemented and executed.

## 5. Status
**Planned:** Tests have not yet been executed.
