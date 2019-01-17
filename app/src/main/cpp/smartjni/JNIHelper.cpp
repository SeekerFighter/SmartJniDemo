#include <unistd.h>
#include<stdlib.h>
#include "JNIHelper.h"
#include <string.h>

namespace smart_jni {

    jmethodID JNIHelper::findMethod(JNIEnv *smart_jnienv, bool isstatic, const char *classname,
                                    const char *methodname, const char *methodsigner) {
        jclass claxx = smart_jnienv->FindClass(classname);
        jmethodID method = findMethod(smart_jnienv, isstatic, claxx, methodname, methodsigner);
        smart_jnienv->DeleteLocalRef(claxx);
        return method;
    }

    jmethodID JNIHelper::findMethod(JNIEnv *smart_jnienv, bool isstatic, const jclass claxx,
                                           const char *methodname, const char *methodsigner) {
        return isstatic ? smart_jnienv->GetStaticMethodID(claxx, methodname, methodsigner)
                        : smart_jnienv->GetMethodID(claxx, methodname, methodsigner);
    }

    bool JNIHelper::isAssignableFrom(JNIEnv *smart_jnienv, const jobject obj, const char *classname) {
        jclass claxx = smart_jnienv->FindClass(classname);
        bool result = isAssignableFrom(smart_jnienv, obj, claxx);
        smart_jnienv->DeleteLocalRef(claxx);
        return result;
    }

    bool JNIHelper::isAssignableFrom(JNIEnv *smart_jnienv, const jobject obj, const jclass claxx) {
        jclass obj_claxx = smart_jnienv->GetObjectClass(obj);
        jboolean b = smart_jnienv->IsAssignableFrom(obj_claxx, claxx);
        smart_jnienv->DeleteLocalRef(obj_claxx);
        return b == JNI_TRUE;
    }

    char* JNIHelper::trans2JNIName(const char *name) {
        char *jniname = NULL;
        if (name != NULL && strlen(name) > 0) {
            jniname = strdup(name);
            size_t length = strlen(jniname) + 1;
            for (int i = 0; i < length; i++) {
                if (jniname[i] == '.') {
                    jniname[i] = '/';
                }
            }
        }
        return jniname;
    }

    jclass JNIHelper::trans2Primitive(JNIEnv *smart_jnienv, const jclass claxx) {
        jclass primitiveclaxx = claxx;
        jfieldID TYPE_filedID = smart_jnienv->GetStaticFieldID(claxx, "TYPE", "Ljava/lang/Class;");
        primitiveclaxx = (jclass) smart_jnienv->GetStaticObjectField(claxx, TYPE_filedID);
        return primitiveclaxx;
    }

    char *JNIHelper::jstringTostring(JNIEnv *smart_jnienv,const jstring source) {
        char *rtn = NULL;
        jclass clsstring = smart_jnienv->FindClass("java/lang/String");
        jstring strencode = smart_jnienv->NewStringUTF("utf-8");
        jmethodID mid = smart_jnienv->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr = (jbyteArray) smart_jnienv->CallObjectMethod(source, mid, strencode);
        jsize alen = smart_jnienv->GetArrayLength(barr);
        jbyte *ba = smart_jnienv->GetByteArrayElements(barr, JNI_FALSE);
        if (alen > 0) {
            rtn = (char *) malloc(alen + 1);
            memcpy(rtn, ba, alen);
            rtn[alen] = 0;
        }
        smart_jnienv->ReleaseByteArrayElements(barr, ba, 0);
        return rtn;
    }

}

