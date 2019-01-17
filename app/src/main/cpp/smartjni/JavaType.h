#ifndef JAVATYPE_H_
#define JAVATYPE_H_

#include <stddef.h>
#include <jni.h>

#include "Class.h"


namespace smart_jni {

    class Integer : public Class {

    private:
        static jmethodID s_Integer_init_ID;
        static jmethodID s_Integer_intValue_ID;
        static Integer *sInstance;

        Integer(JNIEnv *smart_jnienv);

    public:

        /**
         * jint -> Integer ת��
         */
        static jobject valueOf(JNIEnv *smart_jnienv, jint value);

        static jint intValue(JNIEnv *smart_jnienv, jobject value);

        static const Integer *type(JNIEnv *smart_jnienv);

        virtual ~Integer();
    };


    class Jint : public Class {

    private:
        static jmethodID s_Integer_intValue_ID;

        static Jint *sInstance;

        Jint(JNIEnv *smart_jnienv);

    public:
        static const Jint *type(JNIEnv *smart_jnienv);

        virtual ~Jint();

    };

    class Long : public Class {

    private:
        static jmethodID s_Long_init_ID;
        static jmethodID s_Long_longValue_ID;
        static Long *sInstance;

        Long(JNIEnv *smart_jnienv);

    public:

        /**
         * jlong -> Long
         */
        static jobject valueOf(JNIEnv *smart_jnienv, jlong value);

        static jlong longValue(JNIEnv *smart_jnienv, jobject value);

        static const Long *type(JNIEnv *smart_jnienv);

        virtual ~Long();
    };

    class Jlong : public Class {

    private:
        static Jlong *sInstance;

        Jlong(JNIEnv *smart_jnienv);

    public:
        static const Jlong *type(JNIEnv *smart_jnienv);

        virtual ~Jlong();

    };

}


#endif /* JAVATYPE_H_ */
