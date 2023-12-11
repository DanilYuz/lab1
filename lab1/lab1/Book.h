#pragma once
#include <iostream>
#include "Stack.h"
#include <sstream>

class Book {
private:

    class Character {
    private:
        Stack<std::string> names;
        Stack<std::string> roles;
        Stack<std::string> books;

    public:
        Character() {}

        Character(Stack<std::string> names, Stack<std::string> books, Stack<std::string> roles)
            : names(names), books(books), roles(roles) {}


        void addName(std::string& name) {
            names.push(name);
        }

        void addBook(std::string book, std::string& role) {
            books.push(book);
            roles.push(role);
        }
        Stack<std::string>& getBooks() {
            return books;
        }
        Stack<std::string>& getRoles() {
            return roles;
        }
        Stack<std::string> getName() {
            return names;
        }


    };

    std::string title;
    Stack<std::string> authors; 
    Stack<Character> characters;
    std::string publicationDate;
    int numberOfPages;
    std::string shortAbstract;

public:
    
    Book() {}

    Book(std::string t, Stack<std::string>& a, std::string d, int pages, std::string abstract)
        : title(t), authors(a), publicationDate(d), numberOfPages(pages), shortAbstract(abstract) {}

    std::string getTitle() {
        return title;
    }

    const Stack<std::string>& getAuthors() {
        return authors;
    }

    const Stack<Character>& getCharacters() {
        return characters;
    }

    std::string getPublicationDate() {
        return publicationDate;
    }

    int getNumberOfPages() {
        return numberOfPages;
    }
    void addCherecter(Stack<std::string> names, Stack<std::string> books, Stack<std::string> roles) {
        Book::Character newChar = Character(names, books, roles);
        characters.push(newChar);
    }

    std::string getShortAbstract() {
        return shortAbstract;
    }
    void addCharacter(Stack<std::string> names, Stack<Book> books, Stack<std::string> roles) {
        characters.push(Character());
    }

    std::string getAllInfo() {
        std::string info;

        // Title
        info += "Title: " + title + "\n";

        // Authors
        info += "Authors: ";
        Stack<std::string> tempAuthors = authors;
        while (!tempAuthors.isEmpty()) {
            info += tempAuthors.top();
            tempAuthors.pop();
            if (!tempAuthors.isEmpty()) {
                info += ", ";
            }
        }
        info += "\n";

        // Characters
        info += "Characters:\n";
        Stack<Character> tempCharacters = characters;
        while (!tempCharacters.isEmpty()) {
            Character character = tempCharacters.top();
            tempCharacters.pop();
            // Character Names
            Stack<std::string> tempNames = character.getName();
            info += "  Character Names: ";
            while (!tempNames.isEmpty()) {
                info += tempNames.top();
                tempNames.pop();
                if (!tempNames.isEmpty()) {
                    info += ", ";
                }
            }
            info += "\n";

            // Character Books and Roles
            Stack<std::string> tempBooks = character.getBooks();
            Stack<std::string> tempRoles = character.getRoles();
            info += "  Character Books and Roles:\n";
            while (!tempBooks.isEmpty()) {
                info += "    Book Title: " + tempBooks.top() + ", Role: " + tempRoles.top() + "\n";
                tempBooks.pop();
                tempRoles.pop();
            }
        }

        // Publication Date
        info += "Publication Date: " + publicationDate + "\n";

        // Number of Pages
        info += "Number of Pages: " + std::to_string(numberOfPages) + "\n";

        // Short Abstract
        info += "Short Abstract: " + shortAbstract + "\n";

        return info;
    }

};