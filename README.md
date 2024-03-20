Introduction

Welcome to the culmination of the "C++ in Financial Engineering" course from Baruch College, where the integration of finance and computer science is paramount. This project represents an in-depth exploration of option pricing and Greek computation, leveraging advanced object-oriented and generic programming techniques in C++.

Goals and Objectives

Our primary objective is to design and implement a flexible and extensible framework for option pricing, encompassing both European and American options, along with the computation of essential Greeks. To achieve this, we utilize a hierarchical class structure, with a base Option class serving as the foundation for specialized derivatives.

Project Structure

At the core of our project are four key components:

Option Class: Serving as the foundation, this class encapsulates essential attributes such as expiry time, strike price, volatility, risk-free interest rate, current stock price, and cost of carry. It defines virtual functions for calculating call and put option prices, enabling polymorphic behavior in derived classes.

EuropeanOption Class (PlainOption): Derived from the Option class, this class represents European options and provides implementations for calculating call and put option prices. Additionally, it computes various Greeks such as delta, gamma, vega, and theta, essential for risk management and trading strategies. It also includes methods for Put-Call parity verification and utilizes the divided difference method to enhance computational efficiency.

AmericanOption Class (PerpetualAmericanOption): Another derived class from Option, this class models American options and includes functionality for calculating call and put option prices. While not yet fully implemented, it will offer flexibility for early exercise decisions, characteristic of American-style derivatives. Future iterations may incorporate features such as Put-Call parity verification and support for the divided difference method to enhance its utility and versatility.

Option Array and Matrix: These auxiliary classes facilitate the management of collections of options, allowing for efficient computations and analysis across multiple instances. Leveraging the concept of polymorphism, calculations within these structures adapt dynamically based on the specific type of option stored, enhancing code reusability and flexibility.

Key Features and Contributions

Object-Oriented Design: Employing modularity and inheritance, we construct a cohesive framework that promotes code reuse and maintainability.

Generic Programming: Leveraging C++'s generic programming features, we ensure adaptability and scalability, enabling seamless integration of new option types and analytical functionalities.

Exact Solution Focus: Our project prioritizes the computation of exact option prices and Greeks, leveraging advanced mathematical techniques and rigorous analysis to achieve greater precision in financial modeling and analysis.

By the project's conclusion, we aim not only to showcase proficiency in C++ programming but also to deepen our understanding of option pricing principles and their practical applications in financial engineering.


