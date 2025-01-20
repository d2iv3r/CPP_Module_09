# C++ Module 09:

## Overview

In this module, we will explore **STL (The Standard Template Library)**, a powerful library that provides a rich set of pre-built templates for common data structures and algorithms in C++. The STL simplifies the development process by offering ready-made implementations for containers, iterators, algorithms, and function objects, allowing developers to avoid reinventing the wheel. Understanding the STL is essential for writing efficient, reusable, and maintainable C++ code.

## Topics Covered

### 1. **Introduction to STL**
- What the **Standard Template Library (STL)** is and its importance in modern C++ development.
- The components of the STL: **Containers**, **Iterators**, **Algorithms**, and **Function Objects**.
- How STL enables the use of generic programming and promotes code reuse.
  
### 2. **STL Containers**
- Overview of **container types** in STL and how to choose the appropriate container for a given use case.
- **Sequence containers**:
  - `std::vector`: A dynamic array that supports fast random access.
  - `std::list`: A doubly-linked list that supports fast insertions/deletions.
  - `std::deque`: A double-ended queue that allows fast insertions at both ends.
- **Associative containers**:
  - `std::set` and `std::multiset`: Sorted collections of unique elements (or allowing duplicates in `multiset`).
  - `std::map` and `std::multimap`: Sorted key-value pairs with unique keys (or allowing duplicates in `multimap`).
- **Unordered containers**:
  - `std::unordered_set` and `std::unordered_map`: Containers that use hash tables for fast access.
- How to declare, initialize, and perform basic operations like insertion, deletion, and traversal with these containers.

### 3. **Iterators in STL**
- What **iterators** are and their role in STL for accessing container elements.
- Types of iterators: **Input iterators**, **Output iterators**, **Bidirectional iterators**, **Random-access iterators**.
- How to use iterators to traverse and modify elements in STL containers.
- **Const iterators** for read-only access to container elements.
  
### 4. **STL Algorithms**
- Overview of **generic algorithms** in STL that work with any container that supports iterators.
- Commonly used algorithms:
  - `std::sort()`, `std::find()`, `std::accumulate()`, `std::reverse()`, `std::copy()`, and more.
- How to use algorithms for sorting, searching, modifying, and transforming container data.
- How **lambda expressions** can be used with STL algorithms to customize behavior.
  
### 5. **Function Objects (Functors)**
- What **function objects (functors)** are and how they can be used with STL algorithms.
- How to create function objects by overloading the `operator()`.
- Examples of using function objects with algorithms like `std::sort()` and `std::for_each`.
- Comparison between function objects and regular functions or lambda expressions.

### 6. **STL Utilities**
- An introduction to useful utility components in STL:
  - `std::pair`: A container for storing two values.
  - `std::tuple`: A container for storing a fixed number of elements of different types.
  - `std::make_pair()` and `std::make_tuple()` functions to create pairs and tuples.
- **STL type traits** like `std::is_integral`, `std::is_floating_point`, and others for type-checking in generic code.

### 7. **Advanced STL Topics**
- **Allocators**: Custom memory management in STL containers.
- **Memory management**: How STL containers handle memory and the trade-offs between different container types.
- How STL containers and algorithms work together to provide high-performance solutions.

## Subject
https://cdn.intra.42.fr/pdf/pdf/147958/en.subject.pdf

---
