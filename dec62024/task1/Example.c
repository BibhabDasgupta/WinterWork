#include <jni.h>
#include <stdio.h>
#include "Example.h"

JNIEXPORT void JNICALL Java_Example_printMessage(JNIEnv *env, jobject thisObj, jobject exampleObj) {
    // Get the class of the passed object
    jclass exampleClass = (*env)->GetObjectClass(env, exampleObj);

    // Get the field ID of the "message" field
    jfieldID messageFieldID = (*env)->GetFieldID(env, exampleClass, "message", "Ljava/lang/String;");
    if (messageFieldID == NULL) {
        printf("Field not found!\n");
        return;
    }


     jmethodID printMessageMethodID = (*env)->GetMethodID(env, exampleClass, "printMessage", "()V");
    if (printMessageMethodID == NULL) {
        printf("Method not found!\n");
        return;
    }

    // Get the value of the "message" field
    jstring message = (jstring)(*env)->GetObjectField(env, exampleObj, messageFieldID);

    // Convert the jstring to a C string
    const char *messageCStr = (*env)->GetStringUTFChars(env, message, NULL);

    // Print the content of the field
    printf("Message from C: %s\n", messageCStr);

    printf("Calling the Java member method from C...\n");
    (*env)->CallVoidMethod(env, exampleObj, printMessageMethodID);

    // Release the C string
    (*env)->ReleaseStringUTFChars(env, message, messageCStr);
}
