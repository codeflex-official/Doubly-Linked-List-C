# Doubly Linked List in C

A complete menu-driven implementation of Doubly Linked List in C with all major operations.

![C](https://img.shields.io/badge/Language-C-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

## 📋 About
This project implements a Doubly Linked List where each node contains a data part and two pointers - `prev` and `next`. Unlike Singly Linked List, it can be traversed in both directions (forward and backward).

## ✨ Features
- Create a Doubly Linked List
- Insert Node:
    - At Beginning (First)
    - At End (Last)
    - At Any Position (Middle)
- Delete Node:
    - From Beginning
    - From End
    - From Any Position
- Traverse Forward
- Traverse Backward
- Display List
- Menu-Driven Interface - Traverse multiple times without restarting

## 🛠️ Data Structure

```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
