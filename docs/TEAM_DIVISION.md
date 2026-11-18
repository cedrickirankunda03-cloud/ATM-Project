# Team Work Division

To ensure a clean Git history, avoid merge conflicts, and demonstrate proper architectural separation, our team has divided the work by **System Components** rather than individual files. 

Each member owns a distinct vertical slice of the architecture.

## Roles

### Person A: Nathan (Bank Core & Data Logic)
**Focus:** The "Brain" of the ATM. Handles all data integrity, money movement, and transaction records. 
**Owned Files:** `Account.h/.cpp`, `Transaction.h/.cpp`, `Bank.h/.cpp`

**Responsible Requirements:**
* **FR3:** Balance calculation
* **FR4, FR5, FR9, FR11:** Deposit, Withdraw, Transfer math
* **FR8, FR13, FR14, FR15:** Transaction recording, history, mini-statement, and receipt generation
* **FR12, FR24:** Account information and types (Savings/Current)
* **FR22, FR23:** Daily withdrawal limits and ATM cash availability checks
* **FR25:** Backend data validation (e.g., preventing negative deposits)

**C++ Concepts Demonstrated:**
* **OOP:** Abstract `Transaction` base class with derived `Deposit`, `Withdraw`, and `Transfer` classes (Polymorphism).
* **STL:** `std::vector` for storing transaction history.

---

### Person B: Cedrick (ATM Interface & Security)
**Focus:** The "Face" and "Security" of the ATM. Handles user interaction, menus, voice guidance, and input safety.
**Owned Files:** `main.cpp`, `atm.h/.cpp`, `VoiceGuidance.h/.cpp`, `Validator.h/.cpp`, `Repository.h`

**Responsible Requirements:**
* **FR1:** Displaying the main menu
* **FR2, FR10, FR21:** PIN verification, PIN change, and PIN attempt limits
* **FR6, FR7:** Catching invalid inputs safely and displaying clear messages
* **FR16, FR26, FR27, FR28, FR31:** Voice Guidance and spoken notifications
* **FR17, FR18, FR19, FR29, FR30:** Card removal reminders and session ending
* **FR20:** Language selection

**C++ Concepts Demonstrated:**
* **Templates:** `Repository<T>` template class to manage data storage.
* **OOP:** `VoiceGuidance` interface with different language implementations.
* **STL:** `std::map` for fast lookups.

---

## The Interface Contract (How we connect)
To ensure we can work in parallel without touching each other's files, we follow this strict rule:

1. Cedrick (ATM) **never** modifies account balances directly. Cedrick calls `Account::deposit()`, `Account::withdraw()`, etc.
2. Nathan (Bank Core) **never** uses `std::cout` or `std::cin` for the main UI. Nathan's classes only return `bool` (success/fail) or data. Cedrick handles all printing to the screen.
