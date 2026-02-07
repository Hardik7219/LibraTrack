# LibraTrack

A command-line library management system written in C++. LibraTrack lets you manage books, users, and book transactions (issue/return) through an interactive menu.

## Features

- **Book Management**: Add books and view catalog with availability status
- **User Management**: Create new users and list registered users
- **Issue Books**: Assign books to users
- **Return Books**: Return issued books to the library
- **Transactions**: View which books are issued to users (all users or specific user)



## Classes

| Class | Description |
|-------|-------------|
| `Book` | Stores book id, title, issued status, and which user has it |
| `User` | Stores user name, id, and list of issued books |
| `Library` | Manages books and users; handles add, issue, return, and display operations |

## Build

Compile with a C++ compiler:

```bash
g++ -o output/library library.cpp
```

## Usage

Run the executable:

```bash
./output/library
```

### Menu Options

| Choice | Action |
|--------|--------|
| 1 | New User — Create a user (enter name) |
| 2 | Show Books — List all books with id, title, and availability |
| 3 | Issue book — Issue a book to a user (enter userId and bookId) |
| 4 | Show Transactions — View issued books (all users or by username) |
| 5 | Add book — Add a new book to the library |
| 6 | Return book — Return an issued book (enter userId and bookId) |
| 7 | Show users — List all registered users |
| 8 | Exit |

## Requirements

- C++ compiler (g++ or compatible)
- Standard C++ library (iostream, vector, string)
