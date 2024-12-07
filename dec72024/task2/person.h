// person.h
#ifndef PERSON_H
#define PERSON_H

typedef struct {
    char name[100];
    int age;
} Person;

// Core functions declarations
Person* createPerson(const char* name, int age);
void setName(Person* person, const char* name);
const char* getName(Person* person);
void setAge(Person* person, int age);
int getAge(Person* person);
void freePerson(Person* person);

#endif // PERSON_H
