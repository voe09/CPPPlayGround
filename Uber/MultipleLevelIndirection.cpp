/*
Implement a data structure to represent this [1, [2], [[[5]]], 6, 7, 8]
Multi level indirection with in a list
 */

This can be basically a linkList, The direct question is how do you manage xml tree or JSON structure.

struct Element {
String value;
Element *next; // this is object encapsulation
};

struct Node {
Element elem; // elementValue
Node *next; // NextElement in a list
} ;
