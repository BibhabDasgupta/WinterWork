#include <jni.h>
#include "PersonWrapper.h" 
#include "person.h"  // Include the generated header file from Java

// JNI function to create a Person object
JNIEXPORT jlong JNICALL Java_PersonWrapper_createPerson(JNIEnv *env, jobject obj, jstring name, jint age) {
    const char *nameStr = (*env)->GetStringUTFChars(env, name, NULL);
    Person* person = createPerson(nameStr, age);
    (*env)->ReleaseStringUTFChars(env, name, nameStr);
    return (jlong)person;  // Returning pointer as jlong
}

// JNI function to set the name of the person
JNIEXPORT void JNICALL Java_PersonWrapper_setName(JNIEnv *env, jobject obj, jlong personPtr, jstring name) {
    Person* person = (Person*)personPtr;
    const char *nameStr = (*env)->GetStringUTFChars(env, name, NULL);
    setName(person, nameStr);
    (*env)->ReleaseStringUTFChars(env, name, nameStr);
}

// JNI function to get the name of the person
JNIEXPORT jstring JNICALL Java_PersonWrapper_getName(JNIEnv *env, jobject obj, jlong personPtr) {
    Person* person = (Person*)personPtr;
    return (*env)->NewStringUTF(env, getName(person));
}

// JNI function to set the age of the person
JNIEXPORT void JNICALL Java_PersonWrapper_setAge(JNIEnv *env, jobject obj, jlong personPtr, jint age) {
    Person* person = (Person*)personPtr;
    setAge(person, age);
}

// JNI function to get the age of the person
JNIEXPORT jint JNICALL Java_PersonWrapper_getAge(JNIEnv *env, jobject obj, jlong personPtr) {
    Person* person = (Person*)personPtr;
    return getAge(person);
}

// JNI function to free the person object
JNIEXPORT void JNICALL Java_PersonWrapper_freePerson(JNIEnv *env, jobject obj, jlong personPtr) {
    Person* person = (Person*)personPtr;
    freePerson(person);
}
