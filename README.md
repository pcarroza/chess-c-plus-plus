# Chess C++

This project is a functional chess game developed in C++, created as a practical demonstration of fundamental software engineering design principles. The primary goal is not just to build a chess game, but to do so by meticulously applying best practices to create a codebase that is maintainable, scalable, and easy to understand.

## Core Objective: Demonstrating Design Principles

The main purpose of this repository is to serve as a case study in the application of key software engineering principles. It aims to showcase how these concepts can be integrated into a real-world C++ project to improve its quality and structure.

## Applied Design Principles

The following principles were central to the development of this project:

### SOLID
The SOLID principles are a set of five design principles intended to make software designs more understandable, flexible, and maintainable.

*   **Single Responsibility Principle (SRP):** Each class has one, and only one, reason to change. For example, the `Board` class is only responsible for managing the state of the chessboard, while `Piece` derivatives handle piece-specific logic.
*   **Open/Closed Principle (OCP):** Software entities (classes, modules, functions) should be open for extension but closed for modification. This is heavily used in the piece movement rules, where new pieces or special moves can be added without modifying existing rule-checking logic.
*   **Liskov Substitution Principle (LSP):** Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program. All piece types (e.g., `Rook`, `Pawn`) are substitutable for the base `Piece` class.
*   **Interface Segregation Principle (ISP):** No client should be forced to depend on methods it does not use. Different controller interfaces (`OperationController`, `PlacementController`) are defined so that views only interact with the operations they need.
*   **Dependency Inversion Principle (DIP):** High-level modules should not depend on low-level modules. Both should depend on abstractions. The logic depends on abstractions like `OperationController` rather than concrete implementations like `LocalOperationController`.

### DRY (Don't Repeat Yourself)
The DRY principle states that "Every piece of knowledge must have a single, unambiguous, authoritative representation within a system." We avoid code duplication by abstracting common functionalities into base classes and helper functions, such as the movement strategies for pieces (`HorizontalMovementStrategy`, `DiagonalMovementStrategy`).

### YAGNI (You Ain't Gonna Need It)
Functionality was only added when it was required. The project focuses on delivering the core chess logic and a simple console interface, avoiding premature optimization or features that are not essential to the main goal.

### Clean Code
Following Clean Code principles, the code is written to be readable and self-documenting. This includes:
*   **Meaningful Names:** Variables and functions are named to clearly express their purpose.
*   **Small Functions:** Functions are kept short and focused on a single task.
*   **Clear Structure:** The project is organized into logical modules and directories.

### MVC (Model-View-Controller)
The project is structured following a Model-View-Controller architectural pattern to ensure a clear separation of concerns:
*   **Model:** Represents the core data and business logic of the game (e.g., `Game`, `Board`, `Piece`). It is completely independent of the UI.
*   **View:** Responsible for presenting the model to the user. The `console` view (`ConsoleView`, `BoardView`) is a concrete implementation that displays the game state on the command line.
*   **Controller:** Acts as an intermediary between the Model and the View, handling user input and updating the model as necessary (e.g., `StartController`, `SelectPieceController`).

### Separation of Responsibilities
Beyond MVC, responsibilities are clearly distributed. For example, coordinate validation, piece movement logic, game state transitions, and user interaction are all handled by distinct parts of the system, making the codebase easier to debug, test, and extend.

## Project Structure

- **`/include`**: Contains all header files (`.hpp`), defining the interfaces and classes.
- **`/src`**: Contains the implementation files (`.cpp`).
- **`/build`**: Contains build artifacts and dependencies.
- **`/docs`**: Project documentation, including diagrams.
- **`Makefile`**: The build script for compiling the project.

## How to Build and Run

1.  **Clone the repository.**
2.  **Navigate to the project root directory.**
3.  **Compile the code:**
    ```sh
    make
    ```
4.  **Run the game:**
    ```sh
    ./bin/chess
    ```

## Use Case Diagram

![Use Case Diagram](docs/diagrams/out/docs/diagrams/src/usecase/caseuse.svg)
