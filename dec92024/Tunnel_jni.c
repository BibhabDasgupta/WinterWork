#include <jni.h>
#include <pinggy.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Tunnel.h"

// Callback functions
static void pinggy_authenticated(pinggy_ref_t tunnel) {
    printf("Tunnel authenticated\n");
}

static void pinggy_authentication_failed(pinggy_ref_t tunnel, pinggy_len_t len, pinggy_char_p_p_t reasons) {
    printf("Authentication failed\n");
}

static void pinggy_reverse_forwarding_done(pinggy_ref_t tunnel, pinggy_len_t len, pinggy_char_p_p_t addresses) {
    printf("Reverse forwarding done:\n");
    for (int i = 0; i < len; i++) {
        printf("  %s\n", addresses[i]);
    }
}

static void pinggy_reverse_forwarding_failed(pinggy_ref_t tunnel, pinggy_const_char_p_t reason) {
    printf("Reverse forwarding failed: %s\n", reason);
}

// JNI method to create a Pinggy config
JNIEXPORT jlong JNICALL Java_Tunnel_createConfig(JNIEnv *env, jobject obj) {
    pinggy_ref_t config = pinggy_create_config();
    return (jlong) config;
}

// JNI method to set the server address
JNIEXPORT void JNICALL Java_Tunnel_setServerAddress(JNIEnv *env, jobject obj, jstring address) {
    const char *nativeAddress = (*env)->GetStringUTFChars(env, address, 0);
    pinggy_ref_t config = (pinggy_ref_t)(*env)->GetLongField(env, obj, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, obj), "configRef", "J"));
    pinggy_config_set_server_address(config, (char*)nativeAddress); // Cast const char* to char*
    (*env)->ReleaseStringUTFChars(env, address, nativeAddress);
}

// JNI method to set the SNI server name
JNIEXPORT void JNICALL Java_Tunnel_setSniServerName(JNIEnv *env, jobject obj, jstring sniName) {
    const char *nativeSniName = (*env)->GetStringUTFChars(env, sniName, 0);
    pinggy_ref_t config = (pinggy_ref_t)(*env)->GetLongField(env, obj, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, obj), "configRef", "J"));
    pinggy_config_set_sni_server_name(config, (char*)nativeSniName); // Cast const char* to char*
    (*env)->ReleaseStringUTFChars(env, sniName, nativeSniName);
}

// JNI method to set the TCP forwarding address
JNIEXPORT void JNICALL Java_Tunnel_setTcpForwardTo(JNIEnv *env, jobject obj, jstring forwardTo) {
    const char *nativeForwardTo = (*env)->GetStringUTFChars(env, forwardTo, 0);
    pinggy_ref_t config = (pinggy_ref_t)(*env)->GetLongField(env, obj, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, obj), "configRef", "J"));
    pinggy_config_set_tcp_forward_to(config, (char*)nativeForwardTo); // Cast const char* to char*
    (*env)->ReleaseStringUTFChars(env, forwardTo, nativeForwardTo);
}

// JNI method to start the tunnel
JNIEXPORT void JNICALL Java_Tunnel_startTunnel(JNIEnv *env, jobject obj) {
    pinggy_ref_t config = (pinggy_ref_t)(*env)->GetLongField(env, obj, (*env)->GetFieldID(env, (*env)->GetObjectClass(env, obj), "configRef", "J"));
    pinggy_ref_t tunnel = pinggy_tunnel_initiate(config);

    // Set callback functions
    pinggy_tunnel_set_authenticated_callback(tunnel, pinggy_authenticated);
    pinggy_tunnel_set_authentication_failed_callback(tunnel, pinggy_authentication_failed);
    pinggy_tunnel_set_reverse_forwrding_done_callback(tunnel, pinggy_reverse_forwarding_done);
    pinggy_tunnel_set_reverse_forwrding_failed_callback(tunnel, pinggy_reverse_forwarding_failed);

    // Start the tunnel
    pinggy_tunnel_start(tunnel);
}
