# Module_03_SOLID

## Introduction

This project explores key design patterns within the context of Object-Oriented Programming (OOP). The exercises focus on implementing real-world systems using patterns like Factory, Command, Mediator, Observer, and Facade. These patterns help create software that is modular, flexible, and easily maintainable. Understanding and applying design patterns is a critical skill for designing robust and scalable applications.

## Why are Design Patterns Relevant?

Design patterns provide proven solutions to common problems in software design. They promote best practices by solving architectural challenges in a structured and reusable way. Implementing these patterns improves code maintainability, scalability, and reusability, making your systems easier to evolve over time.

## How to Run

1. **Clone the Repository**:  
   ```sh
   git clone git@github.com:<your-username>/Module_03_SOLID.git
   cd Module_03_SOLID

2. For each exercise, navigate to the corresponding directory and run the code using the following command:
   ```sh
   cd <exercise-folder>
   make all
   ./<exercise-name>
   ```
    For example, to run the `SingleResponsibilityPrinciple` exercise:
    ```sh
    cd ex00
    make all
    ./single_responsibility_principle
    ```
    The output will be displayed in the terminal.

## Exercises

### Exercise 00: Introduction to Design Patterns

- **Synopsis**: Introduce the basics of design patterns and their purpose in software design. This exercise helps set the foundation for understanding how design patterns work by presenting simple, real-world examples.

- **Relevance**: This exercise emphasizes the importance of design patterns for solving common design problems, making the code more reusable and flexible.

### Exercise 01: Singleton

- **Description**: Implement the Singleton pattern to ensure that only one instance of the `Headmaster` class is created throughout the system.

- **Singleton Pattern**: This pattern ensures that a class has only one instance and provides a global point of access to it. The `Headmaster` instance, once created, will be reused across the entire system, ensuring centralized control.

### Exercise 02: Factory and Command

- **Synopsis**: Implement a `Secretary` class that creates forms based on a `FormType` enum (Factory Pattern) and a `Headmaster` class that signs and executes these forms (Command Pattern).

- **Relevance**: This exercise highlights the Factory pattern for object creation and the Command pattern to encapsulate the request for performing an action (signing and executing forms). It shows how design patterns simplify and decouple code, improving maintainability.

### Exercise 03: Mediator

- **Description**: Implement the `Headmaster` class as a mediator that coordinates interactions between professors, students, and secretaries. Professors create courses, students join courses, and the headmaster facilitates the signing and execution of all interactions.

- **Mediator Pattern**: The Mediator pattern centralizes communication between components, reducing the direct dependencies between them. This exercise showcases how the headmaster can manage communication between professors, students, and secretaries while adhering to the Mediator pattern.

### Exercise 04: Observer

- **Description**: Implement a bell system that notifies students and professors when classes start or end (Observer Pattern). The headmaster will ring the bell, and the students and professors will react accordingly.

- **Observer Pattern**: This pattern allows objects (students and professors) to be notified when an event (the bell ringing) occurs. It promotes loose coupling between the observable (bell) and the observers (students and professors).

### Exercise 05: Facade

- **Description**: Create a `School` class that encapsulates the complexities of the school's daily routine, including managing students, professors, and headmaster interactions. The `School` class serves as a Facade, simplifying the interface to underlying subsystems.

- **Facade Pattern**: This pattern provides a simplified interface to a complex system. In this exercise, the `School` class wraps multiple processes (classes, recreation, graduation, etc.) into an easy-to-use structure.


## Conclusion

This module provides a deep dive into essential design patterns and demonstrates their practical application in software systems. By implementing patterns like Factory, Command, Mediator, Observer, and Facade, I have gained a better understanding of how to structure code for scalability, maintainability, and flexibility, building on the SOLID principles explored in previous modules.

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Author

👤 **André Francisco Baião Rolão Cândido da Silva**

