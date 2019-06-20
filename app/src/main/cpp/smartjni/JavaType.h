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
         * jint -> Integer
         */
        static jobject valueOf(JNIEnv *smart_jnienv, jint value);

        static jint intValue(JNIEnv *smart_jnienv, jobject value);

        static const Integer *type(JNIEnv *smart_jnienv);

        virtual ~Integer();
    };


    class Jint : public Class {

    private:

        static Jint *sInstance;

        Jint(JNIEnv *smart_jnienv,jint value);

    public:

        jint mValue;

        static const Jint *type(JNIEnv *smart_jnienv);

        static const Jint *type(JNIEnv *smart_jnienv,jint value);

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

        Jlong(JNIEnv *smart_jnienv,jlong value);

    public:
        jlong mValue;
        static const Jlong *type(JNIEnv *smart_jnienv);
        static const Jlong *type(JNIEnv *smart_jnienv,jlong value);
        virtual ~Jlong();
    };


    class Byte : public Class {

    private:
        static jmethodID s_Byte_init_ID;
        static jmethodID s_Byte_byteValue_ID;
        static Byte *sInstance;

        Byte(JNIEnv *smart_jnienv);

    public:

        /**
         * jlong -> Long
         */
        static jobject valueOf(JNIEnv *smart_jnienv, jbyte value);

        static jbyte byteValue(JNIEnv *smart_jnienv, jobject value);

        static const Byte *type(JNIEnv *smart_jnienv);

        virtual ~Byte();
    };

    class Jbyte : public Class {

    private:
        static Jbyte *sInstance;

        Jbyte(JNIEnv *smart_jnienv,jbyte value);

    public:
        jbyte mValue;
        static const Jbyte *type(JNIEnv *smart_jnienv);
        static const Jbyte *type(JNIEnv *smart_jnienv,jbyte value);
        virtual ~Jbyte();
    };


    class Float : public Class {

    private:
        static jmethodID s_Float_init_ID;
        static jmethodID s_Float_floatValue_ID;
        static Float *sInstance;

        Float(JNIEnv *smart_jnienv);

    public:

        static jobject valueOf(JNIEnv *smart_jnienv, jfloat value);

        static jfloat floatValue(JNIEnv *smart_jnienv, jobject value);

        static const Float *type(JNIEnv *smart_jnienv);

        virtual ~Float();
    };


    class Jfloat : public Class {

    private:

        static Jfloat *sInstance;

        Jfloat(JNIEnv *smart_jnienv,jfloat value);

    public:

        jfloat mValue;

        static const Jfloat *type(JNIEnv *smart_jnienv);

        static const Jfloat *type(JNIEnv *smart_jnienv,jfloat value);

        virtual ~Jfloat();

    };

    class Short : public Class {

    private:
        static jmethodID s_Short_init_ID;
        static jmethodID s_Short_shortValue_ID;
        static Short *sInstance;

        Short(JNIEnv *smart_jnienv);

    public:

        static jobject valueOf(JNIEnv *smart_jnienv, jshort value);

        static jshort shortValue(JNIEnv *smart_jnienv, jobject value);

        static const Short *type(JNIEnv *smart_jnienv);

        virtual ~Short();
    };


    class Jshort : public Class {

    private:

        static Jshort *sInstance;

        Jshort(JNIEnv *smart_jnienv,jshort value);

    public:

        jshort mValue;

        static const Jshort *type(JNIEnv *smart_jnienv);

        static const Jshort *type(JNIEnv *smart_jnienv,jshort value);

        virtual ~Jshort();

    };


    class Double : public Class {

    private:
        static jmethodID s_Double_init_ID;
        static jmethodID s_Double_doubleValue_ID;
        static Double *sInstance;

        Double(JNIEnv *smart_jnienv);

    public:

        static jobject valueOf(JNIEnv *smart_jnienv, jdouble value);

        static jdouble doubleValue(JNIEnv *smart_jnienv, jobject value);

        static const Double *type(JNIEnv *smart_jnienv);

        virtual ~Double();
    };


    class Jdouble : public Class {

    private:

        static Jdouble *sInstance;

        Jdouble(JNIEnv *smart_jnienv,jdouble value);

    public:

        jdouble mValue;

        static const Jdouble *type(JNIEnv *smart_jnienv);

        static const Jdouble *type(JNIEnv *smart_jnienv,jdouble value);

        virtual ~Jdouble();

    };


    class Object : public Class {

    private:
        static Object *sInstance;
        Object(JNIEnv *smart_jnienv,const char *name,jobject value);

    public:

        jobject mValue;

        static const Object *type(JNIEnv *smart_jnienv,const char *name);

        static const Object *type(JNIEnv *smart_jnienv,const char *name,jobject value);

        static void release();

        virtual ~Object();
    };
}


#endif /* JAVATYPE_H_ */
