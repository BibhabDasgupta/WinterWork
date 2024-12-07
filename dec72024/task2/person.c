#include <stdio.h>
#include <stdlib.h>   // Include for malloc and free
#include <string.h>
#include <jni.h>

typedef struct {
    char name[100];
    int age;
} Person;

// Create a Person object
Person* createPerson(const char* name, int age) {
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    return person;
}

// Set the person's name
void setName(Person* person, const char* name) {
    strcpy(person->name, name);
}

// Get the person's name
const char* getName(Person* person) {
    return person->name;
}

// Set the person's age
void setAge(Person* person, int age) {
    person->age = age;
}

// Get the person's age
int getAge(Person* person) {
    return person->age;
}

// Free the person object
void freePerson(Person* person) {
    free(person);
}
