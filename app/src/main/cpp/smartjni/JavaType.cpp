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
        jint result = 0;
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
    Jint::Jint(JNIEnv *smart_jnienv, jint value) : Class(smart_jnienv, "java/lang/Integer") {
        jclass tmp = mClass;
        mClass = JNIHelper::trans2Primitive(smart_jnienv, mClass);
        smart_jnienv->DeleteGlobalRef(tmp);
        mClass = (jclass) smart_jnienv->NewGlobalRef(mClass);
        mValue = value;
    }

    Jint::~Jint() {}

    const Jint *Jint::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jint(smart_jnienv, 0);
        }
        return sInstance;
    }

    const Jint *Jint::type(JNIEnv *smart_jnienv, jint value) {
        if (sInstance == NULL) {
            sInstance = new Jint(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
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
        jlong result = 0;

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
    Jlong::Jlong(JNIEnv *smart_jnienv, jlong value) : Class(smart_jnienv, "java/lang/Long") {
        jclass tmp = mClass;
        mClass = (jclass) smart_jnienv->NewGlobalRef(
                JNIHelper::trans2Primitive(smart_jnienv, mClass));
        smart_jnienv->DeleteGlobalRef(tmp);
        mValue = value;
    }

    Jlong::~Jlong() {}

    const Jlong *Jlong::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jlong(smart_jnienv, 0);
        }
        return sInstance;
    }

    const Jlong *Jlong::type(JNIEnv *smart_jnienv, jlong value) {

        if (sInstance == NULL) {
            sInstance = new Jlong(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
        }

        return sInstance;
    }

    Jlong *Jlong::sInstance = NULL;


    //For Byte Impl
    Byte::Byte(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Byte") {}

    Byte::~Byte() {}

    const Byte *Byte::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Byte(smart_jnienv);
        }

        return sInstance;
    }

    jobject Byte::valueOf(JNIEnv *smart_jnienv, jbyte value) {
        jclass claxx = type(smart_jnienv)->mClass;
        if (NULL == s_Byte_init_ID) {
            s_Byte_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Byte", "<init>",
                                                   "(B)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Byte_init_ID, value);
        return result;
    }

    jbyte Byte::byteValue(JNIEnv *smart_jnienv, jobject value) {
        jbyte result = 0;
        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Byte_byteValue_ID) {
                s_Byte_byteValue_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Byte",
                                                            "byteValue", "()J");
            }
            result = smart_jnienv->CallByteMethod(value, s_Byte_byteValue_ID);
        }

        return result;
    }

    Byte *Byte::sInstance = NULL;
    jmethodID Byte::s_Byte_init_ID = NULL;
    jmethodID Byte::s_Byte_byteValue_ID = NULL;

    //For Jbyte Impl
    Jbyte::Jbyte(JNIEnv *smart_jnienv, jbyte value) : Class(smart_jnienv, "java/lang/Byte") {
        jclass tmp = mClass;
        mClass = (jclass) smart_jnienv->NewGlobalRef(
                JNIHelper::trans2Primitive(smart_jnienv, mClass));
        smart_jnienv->DeleteGlobalRef(tmp);
        mValue = value;
    }

    Jbyte::~Jbyte() {}

    const Jbyte *Jbyte::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jbyte(smart_jnienv, 0x00);
        }
        return sInstance;
    }

    const Jbyte *Jbyte::type(JNIEnv *smart_jnienv, jbyte value) {

        if (sInstance == NULL) {
            sInstance = new Jbyte(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
        }

        return sInstance;
    }

    Jbyte *Jbyte::sInstance = NULL;


    //For Float Impl
    Float::Float(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Float") {}

    Float::~Float() {}

    jobject Float::valueOf(JNIEnv *smart_jnienv, jfloat value) {
        jclass claxx = Float::type(smart_jnienv)->mClass;
        if (NULL == s_Float_init_ID) {
            s_Float_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Float",
                                                    "<init>", "(F)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Float_init_ID, value);
        return result;
    }

    jfloat Float::floatValue(JNIEnv *smart_jnienv, jobject value) {
        jfloat result = 0;
        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Float_floatValue_ID) {
                s_Float_floatValue_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                              "java/lang/Float", "floatValue",
                                                              "()F");
            }
            result = smart_jnienv->CallFloatMethod(value, s_Float_floatValue_ID);
        }

        return result;
    }

    const Float *Float::type(JNIEnv *smart_jnienv) {

        if (sInstance == NULL) {
            sInstance = new Float(smart_jnienv);
        }

        return sInstance;
    }

    Float *Float::sInstance = NULL;
    jmethodID Float::s_Float_init_ID = NULL;
    jmethodID Float::s_Float_floatValue_ID = NULL;


    //For Jfloat Impl
    Jfloat::Jfloat(JNIEnv *smart_jnienv, jfloat value) : Class(smart_jnienv, "java/lang/Float") {
        jclass tmp = mClass;
        mClass = JNIHelper::trans2Primitive(smart_jnienv, mClass);
        smart_jnienv->DeleteGlobalRef(tmp);
        mClass = (jclass) smart_jnienv->NewGlobalRef(mClass);
        mValue = value;
    }

    Jfloat::~Jfloat() {}

    const Jfloat *Jfloat::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jfloat(smart_jnienv, 0);
        }
        return sInstance;
    }

    const Jfloat *Jfloat::type(JNIEnv *smart_jnienv, jfloat value) {
        if (sInstance == NULL) {
            sInstance = new Jfloat(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
        }
        return sInstance;
    }

    Jfloat *Jfloat::sInstance = NULL;

    //For Short Impl
    Short::Short(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Short") {}

    Short::~Short() {}

    jobject Short::valueOf(JNIEnv *smart_jnienv, jshort value) {
        jclass claxx = Short::type(smart_jnienv)->mClass;
        if (NULL == s_Short_init_ID) {
            s_Short_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Short",
                                                    "<init>", "(S)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Short_init_ID, value);
        return result;
    }

    jshort Short::shortValue(JNIEnv *smart_jnienv, jobject value) {
        jshort result = 0;
        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Short_shortValue_ID) {
                s_Short_shortValue_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                              "java/lang/Short", "shortValue",
                                                              "()S");
            }
            result = smart_jnienv->CallShortMethod(value, s_Short_shortValue_ID);
        }

        return result;
    }

    const Short *Short::type(JNIEnv *smart_jnienv) {

        if (sInstance == NULL) {
            sInstance = new Short(smart_jnienv);
        }

        return sInstance;
    }

    Short *Short::sInstance = NULL;
    jmethodID Short::s_Short_init_ID = NULL;
    jmethodID Short::s_Short_shortValue_ID = NULL;


    //For Jshort Impl
    Jshort::Jshort(JNIEnv *smart_jnienv, jshort value) : Class(smart_jnienv, "java/lang/Short") {
        jclass tmp = mClass;
        mClass = JNIHelper::trans2Primitive(smart_jnienv, mClass);
        smart_jnienv->DeleteGlobalRef(tmp);
        mClass = (jclass) smart_jnienv->NewGlobalRef(mClass);
        mValue = value;
    }

    Jshort::~Jshort() {}

    const Jshort *Jshort::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jshort(smart_jnienv, 0);
        }
        return sInstance;
    }

    const Jshort *Jshort::type(JNIEnv *smart_jnienv, jshort value) {
        if (sInstance == NULL) {
            sInstance = new Jshort(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
        }
        return sInstance;
    }

    Jshort *Jshort::sInstance = NULL;



    //For Double Impl
    Double::Double(JNIEnv *smart_jnienv) : Class(smart_jnienv, "java/lang/Double") {}

    Double::~Double() {}

    jobject Double::valueOf(JNIEnv *smart_jnienv, jdouble value) {
        jclass claxx = Double::type(smart_jnienv)->mClass;
        if (NULL == s_Double_init_ID) {
            s_Double_init_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Double",
                                                    "<init>", "(D)V");
        }
        jobject result = smart_jnienv->NewObject(claxx, s_Double_init_ID, value);
        return result;
    }

    jdouble Double::doubleValue(JNIEnv *smart_jnienv, jobject value) {
        jdouble result = 0;
        if (JNIHelper::isAssignableFrom(smart_jnienv, value, type(smart_jnienv)->mClass)) {
            if (NULL == s_Double_doubleValue_ID) {
                s_Double_doubleValue_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                              "java/lang/Double", "floatValue",
                                                              "()D");
            }
            result = smart_jnienv->CallDoubleMethod(value, s_Double_doubleValue_ID);
        }

        return result;
    }

    const Double *Double::type(JNIEnv *smart_jnienv) {

        if (sInstance == NULL) {
            sInstance = new Double(smart_jnienv);
        }

        return sInstance;
    }

    Double *Double::sInstance = NULL;
    jmethodID Double::s_Double_init_ID = NULL;
    jmethodID Double::s_Double_doubleValue_ID = NULL;


    //For Jdouble Impl
    Jdouble::Jdouble(JNIEnv *smart_jnienv, jdouble value) : Class(smart_jnienv, "java/lang/Double") {
        jclass tmp = mClass;
        mClass = JNIHelper::trans2Primitive(smart_jnienv, mClass);
        smart_jnienv->DeleteGlobalRef(tmp);
        mClass = (jclass) smart_jnienv->NewGlobalRef(mClass);
        mValue = value;
    }

    Jdouble::~Jdouble() {}

    const Jdouble *Jdouble::type(JNIEnv *smart_jnienv) {
        if (sInstance == NULL) {
            sInstance = new Jdouble(smart_jnienv, 0);
        }
        return sInstance;
    }

    const Jdouble *Jdouble::type(JNIEnv *smart_jnienv, jdouble value) {
        if (sInstance == NULL) {
            sInstance = new Jdouble(smart_jnienv, value);
        } else {
            sInstance->mValue = value;
        }
        return sInstance;
    }

    Jdouble *Jdouble::sInstance = NULL;

    //For Object Impl
    Object::Object(JNIEnv *smart_jnienv, const char *name,jobject value) : Class(smart_jnienv, name) {
        mValue = value;
    }

    Object::~Object() {}

    const Object *Object::type(JNIEnv *smart_jnienv, const char *name) {
        if (sInstance == NULL) {
            sInstance = new Object(smart_jnienv, name,NULL);
        }
        return sInstance;
    }

    const Object *Object::type(JNIEnv *smart_jnienv, const char *name,jobject value) {
        if (sInstance == NULL) {
            sInstance = new Object(smart_jnienv,name,value);
        } else{
            sInstance->mValue = value;
        }

        return sInstance;
    }

    void Object::release() {
        delete sInstance;
        sInstance = NULL;
    }

    Object *Object::sInstance = NULL;
}


