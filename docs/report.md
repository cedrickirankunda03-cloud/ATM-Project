# ATM Project — Final Report

## 1. Introduction
This project is a fully functional Automated Teller Machine (ATM) system developed in C++. It simulates a real-world banking interface, allowing users to authenticate, manage their funds, and interact with a secure, multi-language user interface.

## 2. Project Objectives
* Provide a simple, menu-driven banking application.
* Support core account operations (deposits, withdrawals, balance inquiry).
* Validate user input to prevent crashes and handle errors safely.
* Demonstrate practical use of OOP, STL, and C++ Templates.
* Test the system's main functions using unit tests and CI/CD.

## 3. Requirements
All 31 functional requirements (FR1-FR31) and non-functional requirements have been documented in `requirements.md`. The final implementation successfully addresses the core requirements (authentication, transactions, validation) and several advanced features (voice guidance, language selection, OOP design).

## 4. Features (Implemented)
* **Security:** PIN authentication and input validation.
* **Transactions:** Deposits, withdrawals, and balance inquiries.
* **Multi-Language Voice Guidance:** An OOP-based voice assistant that speaks to the user in English or French.
* **Safe UI:** A robust menu loop that catches invalid inputs (e.g., typing letters instead of numbers) without crashing.
* **Session Management:** Card removal reminders and a proper logout sequence.

## 5. System Architecture
The application is organized into a clean directory structure (`include/`, `src/`, `tests/`, `docs/`). The design strictly separates the user interface (menus, voice) from the business logic (account math, transactions).

## 6. Implementation
The project was built using **C++17** and **CMake**. We utilized:
* **GitHub Actions** for continuous integration (automated builds and tests).
* **Google Test** for unit testing.
* **Doxygen** for code documentation.

## 7. Class Hierarchy
The system uses Object-Oriented Programming (OOP).
* **ATM Class:** Acts as the main controller, handling the menu loop and calling the bank core.
* **VoiceGuidance (Abstract Base Class):** Defines the interface for spoken messages.
* **EnglishVoice / FrenchVoice:** Derived classes that implement polymorphic voice behavior.
* **Validator Class:** A static utility class for safe input handling.
* **Repository<T> (Template Class):** A generic template used to demonstrate modern C++ data storage.
* **Account Logic:** Handles the balance, deposits, and withdrawals.

## 8. Testing
Unit testing is implemented using Google Test. Tests are stored in the `tests/` directory and run via `ctest`. The tests verify:
* Valid and invalid PIN authentication.
* Successful deposits and withdrawals.
* Rejection of invalid or negative amounts.
* The CI pipeline automatically runs these tests on every push to `main`. All tests pass with a 100% success rate.

## 9. Results and Discussion
The completed system runs flawlessly. Users can start the ATM, hear the welcome voice, navigate menus safely, change languages, and perform transactions. The architecture is highly modular. 
*Limitations:* The system currently stores data in memory rather than a persistent database.

## 10. Conclusion
The ATM project successfully met all technical constraints, including the use of OOP, STL, and C++ templates. By dividing the work by architecture (UI vs. Core) and using feature branches, we successfully managed a complex Git repository, resolved merge conflicts, and delivered a tested, high-quality C++ application.

## 11. References
* Course materials on C++ OOP and STL.
* GitHub Actions and Google Test official documentation.
* CMake official documentation.
