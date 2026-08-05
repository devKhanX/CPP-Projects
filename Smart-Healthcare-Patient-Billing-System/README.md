# Smart Healthcare Patient & Billing System

## Overview

The Smart Healthcare Patient & Billing System is a console-based C++ project developed to manage basic hospital operations.

The system allows users to manage patients and doctors, assign doctors to patients, create appointments, generate patient bills, and view patient and doctor records.

This project was developed to practice and demonstrate Object-Oriented Programming concepts in C++.

## Features

* Add new patients
* Add doctors
* Assign doctors to patients
* Create appointments
* Generate patient bills
* Add consultation fees
* Add medicine charges
* Display patient records
* Display doctor records
* Display appointments
* Display bills
* Search for a doctor by ID

## Object-Oriented Programming Concepts Used

* Classes and Objects
* Encapsulation
* Inheritance
* Constructors
* Constructor Overloading
* Static Data Members
* Getters and Setters
* Operator Overloading
* Composition
* Access Specifiers

## Main Classes

### Person

The base class containing common information such as:

* Name
* Age

### Patient

Inherits from `Person` and stores:

* Patient ID
* Disease
* Assigned Doctor ID

### Doctor

Inherits from `Person` and stores:

* Doctor ID
* Specialization

### Appointment

Manages:

* Patient ID
* Doctor ID
* Appointment date
* Appointment time

### Bill

Manages:

* Patient ID
* Consultation fee
* Medicine charges
* Total bill

The `+` operator is overloaded to combine bill components.

### HospitalSystem

Acts as the main management class and stores collections of:

* Patients
* Doctors
* Appointments
* Bills

It provides functionality for managing and displaying these records.

## Technologies

* C++
* Object-Oriented Programming
* STL `vector`

## How to Run

1. Clone or download the repository.
2. Open `main.cpp` in a C++ IDE or compiler.
3. Compile the program using a C++ compiler.
4. Run the program.
5. Use the menu-driven interface to manage the healthcare system.

## Menu Options

```text
1. Add Patient
2. Add Doctor
3. Assign Doctor to Patient
4. Create Appointment
5. Generate Bill
6. Show Patients
7. Show Doctors
8. Show Appointments
9. Show Bills
10. Show Patient Record
11. Show Doctor By ID
12. Exit
```

## Project Purpose

This project was created as part of my C++ and Object-Oriented Programming learning journey to apply OOP concepts to a practical healthcare management scenario.
