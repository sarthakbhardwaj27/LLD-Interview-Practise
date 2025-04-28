# SOLID definition:
Single Responsibility Principle (SRP)
Open/Closed Principle
Liskov’s Substitution Principle (LSP)
Interface Segregation Principle (ISP)
Dependency Inversion Principle (DIP)

## why?
-> it helps in reducing tight coupling i.e. a group of classes are highly dependent on one another which one should avoid in the code. Loosely coupled is good and allows making code more reusable.

## Single Responsibility Principle (SRP):
Every class should have 1 responsibility or 1 job/purpose

## Open/Closed principle
Software entities should be open for extension but closed for modification -> we should be able to extend a class behavior without modifying it


## Liskov's substitution principle:
derived or child classes must be substitutable for their base or parent classes. This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behaviour.

🌟 S - Single Responsibility Principle (SRP)
Keep it focused: Each class or module should have only one responsibility. It should be responsible for one thing and not take on multiple unrelated tasks.

Example: A class responsible for logging data should only be concerned with logging. It shouldn’t be involved in processing data or managing business logic.

🌟 O - Open/Closed Principle (OCP)
Open for extension, closed for modification: You should be able to extend the behavior of a class without modifying its existing code. This allows you to add new functionality without breaking existing code.

Example: If you're building a shipping calculator, instead of modifying the existing class when adding a new shipping method, you extend the class or use interfaces to add new methods without changing the old ones.

🌟 L - Liskov Substitution Principle (LSP)
Substitute without breaking: You should be able to use a subclass wherever the base class is used without breaking the program. This ensures that child classes can stand in for parent classes and still behave as expected.

Example: If you have a Bird class with a fly() method, and then a Penguin class extends it, it might violate Liskov if a Penguin can't fly. So, you'd rethink the design and either not let Penguin inherit Bird or ensure that only birds that can fly inherit that class.

🌟 I - Interface Segregation Principle (ISP)
Avoid forcing clients to implement unused methods: Clients (whether they are objects or classes) should only be dependent on the methods that they use. Don’t force classes to implement methods they don’t need.

Example: Instead of having a massive Worker interface with methods for eat(), work(), and sleep(), create smaller, more focused interfaces like Worker, Eater, and Sleeper, so you can mix and match only the relevant methods.

🌟 D - Dependency Inversion Principle (DIP)
Depend on abstractions, not on concrete classes: High-level modules should not depend on low-level modules. Both should depend on abstractions. This reduces the tight coupling between different parts of the system.

Example: Instead of having a Car class depend directly on a Engine class, create an interface for the Engine and make Car depend on that abstraction, so you can plug in different types of engines without modifying Car.

🚀 The Overall Goal of SOLID:
Loosely coupled design: Keep components independent and flexible. Changes in one part of the system should not affect others. This reduces the risk of unintended side effects.

Maintainability: The code becomes easier to maintain, as you don’t need to change or refactor existing parts every time a new feature is added.

Extensibility: It’s easy to extend the functionality of your application without changing existing code.

Testability: Because classes are independent, testing is easier and more isolated.