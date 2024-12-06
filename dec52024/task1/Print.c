#include <stdio.h>
#include "Print.h"

JNIEXPORT jfloat JNICALL Java_Print_printValues
  (JNIEnv *env, jobject obj, jint intVal, jfloat floatVal) {
     float result = intVal + floatVal;
    printf("Received int: %d\n", intVal);
    printf("Received float: %f\n", floatVal);
    return result;
}
