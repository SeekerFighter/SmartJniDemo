#include <jni.h>

#include "Class.h"
#include "JavaType.h"
#include "JNIHelper.h"

namespace smart_jni {

    //For Integer Impl
    Integer::Integer(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Integer") {}

    Integer::~Integer() {}

    jobject Integer::valueOf(JNIEnv *smart_jnienv, jint value) {
        jclass claxx = Integer::type(smart_jnienv)->mClass;
        if (NULL == s_Integer_init_ID) {
            s_Integer_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Integer",
                                                      "<init>", "(I)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Integer_init_ID, value);
        return result;
    }

    jint Integer::intValue(JNIEnv *smart_jnienv, jobject value) {

        jint result = 0xffffffff;
        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Integer_intValue_ID) {
                s_Integer_intValue_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                              "java/lang/Integer", "intValue",
                                                              "()I");
            }
            result = smart_jnienv->CallIntMethod(value, s_Integer_intValue_ID);
        }

        return result;
    }

    const Integer *Integer::type(JNIEnv *smart_jnienv) {

        if (sInstance == NULL) {
            sInstance = new Integer(smart_jnienv);
        }

        return sInstance;
    }

    Integer *Integer::sInstance = NULL;
    jmethodID Integer::s_Integer_init_ID = NULL;
    jmethodID Integer::s_Integer_intValue_ID = NULL;


    //For Jint Impl
    Jint::Jint(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Integer") {
        jclass tmp = mClass;
        mClass = JNIHelper::trans2Primitive(smart_jnienv, mClass);

        smart_jnienv->DeleteGlobalRef(tmp);
        mClass = (jclass) smart_jnienv->NewGlobalRef(mClass);
    }

    Jint::~Jint() {}

    const Jint *Jint::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jint(smart_jnienv);
        }
        return sInstance;
    }

    Jint *Jint::sInstance = NULL;


    //For Long Impl
    Long::Long(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Long") {}

    Long::~Long() {}

    const Long *Long::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Long(smart_jnienv);
        }

        return sInstance;
    }

    jobject Long::valueOf(JNIEnv *smart_jnienv, jlong value) {
        jclass claxx = type(smart_jnienv)->mClass;
        if (NULL == s_Long_init_ID) {
            s_Long_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Long", "<init>",
                                                   "(J)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Long_init_ID, value);
        return result;
    }

    jlong Long::longValue(JNIEnv *smart_jnienv, jobject value) {
        jlong result = 0xffffffff;

        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Long_longValue_ID) {
                s_Long_longValue_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Long",
                                                            "longValue", "()J");
            }
            result = smart_jnienv->CallLongMethod(value, s_Long_longValue_ID);
        }

        return result;
    }

    Long *Long::sInstance = NULL;
    jmethodID Long::s_Long_init_ID = NULL;
    jmethodID Long::s_Long_longValue_ID = NULL;


    //For Jlong Impl
    Jlong::Jlong(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Long") {
        jclass tmp = mClass;
        mClass = (jclass) smart_jnienv->NewGlobalRef(JNIHelper::trans2Primitive(smart_jnienv, mClass));

        smart_jnienv->DeleteGlobalRef(tmp);
    }

    Jlong::~Jlong() {}

    const Jlong *Jlong::type(JNIEnv *smart_jnienv) {

        if (sInstance == NULL) {
            sInstance = new Jlong(smart_jnienv);
        }

        return sInstance;
    }

    Jlong *Jlong::sInstance = NULL;
}


