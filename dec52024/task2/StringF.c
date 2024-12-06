#include <stdio.h>
#include <string.h>
#include <jni.h>
#include "StringF.h"
#include <stdlib.h> 

JNIEXPORT jstring JNICALL Java_StringF_modifyString
  (JNIEnv *env, jobject obj, jstring input) {
    
   const char *inputCStr = (*env)->GetStringUTFChars(env, input, 0);

    const char *suffix = "_edited_in_c";
    size_t inputLength = strlen(inputCStr);
    size_t suffixLength = strlen(suffix);
    size_t totalLength = inputLength + suffixLength;

    // Allocate memory dynamically for the modified string
    char *modifiedStr = (char *)malloc(totalLength + 1);  // +1 for null terminator
    if (modifiedStr == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    strcpy(modifiedStr, inputCStr);  
    strcat(modifiedStr, suffix);    

    // Release the memory of the input C string
    (*env)->ReleaseStringUTFChars(env, input, inputCStr);

    // Create a new Java string from the modified C string
    jstring result = (*env)->NewStringUTF(env, modifiedStr);

    // Free the dynamically allocated memory
    free(modifiedStr);

    // Return the new Java string
    return result;
}
