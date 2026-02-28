# Pharmacy Management System

A console-based pharmacy management system built with C++ as a multi-phase academic project. The system provides an interactive menu-driven interface for managing pharmacies, medications, customers, and sales operations.

This project was collaboratively developed by: **Sami Abu Touq, Shaima Ahmad, Raghad Alqammaz, Amr Saeed**

## Project Structure

The project is developed incrementally across three phases, each introducing new functionality and more advanced OOP concepts. The third phase contains the final and most complete version.

```
Phase 1/   Core foundation (single pharmacy, basic CRUD)
Phase 2/   Multi-pharmacy management with search, sort, and comparison
Phase 3/   Inheritance, polymorphism, and dynamic memory management
```

### Phase 1 -- Core Foundation

Basic single-pharmacy system supporting medication and customer creation, purchases, inventory display, and sales tracking.

**Classes:** `Medication`, `Customer`, `Date`, `Address`

### Phase 2 -- Multi-Pharmacy Management

Expanded to manage multiple pharmacies with 22 operations including add/remove medications by ID or name, customer search, medication sorting, expired medication tracking, low-stock alerts, revenue computation, and cross-pharmacy comparisons.

**Classes:** `Pharmacy`, `Medication`, `Customer`, `Date`, `Address`

### Phase 3 -- Inheritance and Dynamic Memory

Introduces an inheritance hierarchy with two medication subtypes, dynamic array resizing, deep copy support, and proper memory cleanup.

- **Prescription** (extends `Medication`) -- FDA number and approval date
- **OffTheShelf** (extends `Medication`) -- buy-one-get-one-free promotions

**Classes:** `Pharmacy`, `Medication`, `Prescription`, `OffTheShelf`, `Customer`, `Date`, `Address`

## Class Hierarchy

```
Pharmacy (contains arrays of)
├── Medication
│   ├── Prescription
│   └── OffTheShelf
└── Customer
    └── Address (composition)

Medication
├── Prescription   (inheritance)
└── OffTheShelf    (inheritance)
```

## Key Features

- Manage multiple pharmacies with dynamic array resizing
- Three medication types: general, prescription, and off-the-shelf
- Customer registration and information management
- Purchase processing with automatic inventory updates
- Expired medication detection and removal
- Low-stock alerts
- Revenue tracking and cross-pharmacy comparisons
- Search by ID and sort by name

## Building and Running

Download the project, open the `.sln` file for any phase in a C++ IDE (e.g., Visual Studio), and hit the Run button.

## Documentation

Each phase includes detailed PDF documentation covering design decisions, class diagrams, and implementation details:

- `Phase 1/Phase 1 Documentation.pdf`
- `Phase 2/Phase 2 Documentation.pdf`
- `Phase 3/Phase 3 Documentation.pdf`
