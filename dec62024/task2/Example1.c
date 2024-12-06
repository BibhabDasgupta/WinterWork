#include <jni.h>
#include <stdio.h>
#include "Example.h"

// JNI function implementation
JNIEXPORT jobject JNICALL Java_Example1_createObjectInC(JNIEnv *env, jobject thisObj) {
    // Find the Java class (Example)
    jclass exampleClass = (*env)->FindClass(env, "Example1");
    if (exampleClass == NULL) {
        printf("Class not found!\n");
        return NULL;
    }

    // Get the constructor of the Example class
    jmethodID constructor = (*env)->GetMethodID(env, exampleClass, "<init>", "(Ljava/lang/String;)V");
    if (constructor == NULL) {
        printf("Constructor not found!\n");
        return NULL;
    }

    // Create a Java string to pass as the constructor argument
    jstring message = (*env)->NewStringUTF(env, "Hello from C!");

    // Create a new Example object
    jobject newExampleObject = (*env)->NewObject(env, exampleClass, constructor, message);
    if (newExampleObject == NULL) {
        printf("Object creation failed!\n");
        return NULL;
    }

    // Return the newly created object to Java
    return newExampleObject;
}
