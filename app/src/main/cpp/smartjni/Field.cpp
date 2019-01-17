#include <jni.h>
#include "Field.h"
#include "JNIHelper.h"

namespace smart_jni {

    Field::Field(JNIEnv *jnienv, jclass claxx, const char *fieldName) : mFiled(NULL) {
        smart_jnienv = jnienv;
        jstring jfieldName = smart_jnienv->NewStringUTF(fieldName);
        if (NULL == s_Class_getDeclaredField_ID) {
            s_Class_getDeclaredField_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                                "java/lang/Class",
                                                                "getDeclaredField",
                                                                "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
        }
        mFiled = smart_jnienv->CallObjectMethod(claxx, s_Class_getDeclaredField_ID, jfieldName);
        smart_jnienv->DeleteLocalRef(jfieldName);
        if (NULL == s_Field_setAccessible_ID) {
            s_Field_setAccessible_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                             "setAccessible", "(Z)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_setAccessible_ID, JNI_TRUE);
    }

    Field::~Field() {}

    void Field::setInt(jobject obj, jint value) {
        if (NULL == s_Field_setInt_ID) {
            s_Field_setInt_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "setInt",
                                                      "(Ljava/lang/Object;I)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_setInt_ID, obj, value);
    }

    jint Field::getInt(jobject obj) {
        if (NULL == s_Field_getInt_ID) {
            s_Field_getInt_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "getInt",
                                                      "(Ljava/lang/Object;)I");
        }
        jint result = smart_jnienv->CallIntMethod(mFiled, s_Field_getInt_ID, obj);
        return result;
    }

    void Field::setShort(jobject obj, jshort value) {
        if (NULL == s_Filed_setShort_ID) {
            s_Filed_setShort_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                        "setShort", "(Ljava/lang/Object;S)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Filed_setShort_ID, obj, value);
    }

    jshort Field::getShort(jobject obj) {
        if (NULL == s_Filed_getShort_ID) {
            s_Filed_getShort_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                        "getShort", "(Ljava/lang/Object;)S");
        }
        jshort result = smart_jnienv->CallShortMethod(mFiled, s_Filed_getShort_ID, obj);
        return result;
    }

    void Field::setChar(jobject obj, jchar value) {
        if (NULL == s_Filed_setChar_ID) {
            s_Filed_setChar_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "setChar",
                                                       "(Ljava/lang/Object;C)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Filed_setChar_ID, obj, value);
    }

    jchar Field::getChar(jobject obj) {
        if (NULL == s_Filed_getChar_ID) {
            s_Filed_getChar_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "getChar",
                                                       "(Ljava/lang/Object;)C");
        }
        jchar result = smart_jnienv->CallCharMethod(mFiled, s_Filed_getChar_ID, obj);
        return result;
    }

    void Field::setLong(jobject obj, jlong value) {
        if (NULL == s_Field_setLong_ID) {
            s_Field_setLong_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "setLong",
                                                       "(Ljava/lang/Object;J)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_setLong_ID, obj, value);
    }

    jlong Field::getLong(jobject obj) {
        if (NULL == s_Field_getLong_ID) {
            s_Field_getLong_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "getLong",
                                                       "(Ljava/lang/Object;)J");
        }
        jlong result = smart_jnienv->CallLongMethod(mFiled, s_Field_getLong_ID, obj);
        return result;
    }

    void Field::setObject(jobject obj, jobject value) {
        if (NULL == s_Field_set_ID) {
            s_Field_set_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "set",
                                                   "(Ljava/lang/Object;Ljava/lang/Object;)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_set_ID, obj, value);
    }

    jobject Field::getObject(jobject obj) {
        if (NULL == s_Field_get_ID) {
            s_Field_get_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "get",
                                                   "(Ljava/lang/Object;)Ljava/lang/Object;");
        }
        jobject result = smart_jnienv->CallObjectMethod(mFiled, s_Field_get_ID, obj);
        return result;
    }

    void Field::setBoolean(jobject obj, jboolean value) {
        if (NULL == s_Field_setBoolean_ID) {
            s_Field_setBoolean_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                          "setBoolean",
                                                          "(Ljava/lang/Object;Z)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_setBoolean_ID, obj, value);
    }

    jboolean Field::getBoolean(jobject obj) {
        if (NULL == s_Field_getBoolean_ID) {
            s_Field_getBoolean_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                          "getBoolean",
                                                          "(Ljava/lang/Object;)Z");
        }
        jboolean result = smart_jnienv->CallBooleanMethod(mFiled, s_Field_getBoolean_ID, obj);
        return result;
    }

    void Field::setByte(jobject obj, jbyte value) {
        if (NULL == s_Field_setByte_ID) {
            s_Field_setByte_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "setByte",
                                                       "(Ljava/lang/Object;B)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Field_setByte_ID, obj, value);
    }

    jbyte Field::getByte(jobject obj) {
        if (NULL == s_Field_getByte_ID) {
            s_Field_getByte_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS, "getByte",
                                                       "(Ljava/lang/Object;)B");
        }
        jbyte result = smart_jnienv->CallByteMethod(mFiled, s_Field_getByte_ID, obj);
        return result;
    }

    void Field::setFloat(jobject obj, jfloat value) {
        if (NULL == s_Filed_setFloat_ID) {
            s_Filed_setFloat_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                        "setFloat",
                                                        "(Ljava/lang/Object;F)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Filed_setFloat_ID, obj, value);
    }

    jfloat Field::getFloat(jobject obj) {
        if (NULL == s_Filed_getFloat_ID) {
            s_Filed_getFloat_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                        "getFloat",
                                                        "(Ljava/lang/Object;)F");
        }
        jfloat result = smart_jnienv->CallFloatMethod(mFiled, s_Filed_getFloat_ID, obj);
        return result;
    }

    void Field::setDouble(jobject obj, jdouble value) {
        if (NULL == s_Filed_setDouble_ID) {
            s_Filed_setDouble_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                         "setDouble",
                                                         "(Ljava/lang/Object;D)V");
        }
        smart_jnienv->CallVoidMethod(mFiled, s_Filed_setDouble_ID, obj, value);
    }

    jdouble Field::getDouble(jobject obj) {
        if (NULL == s_Filed_getDouble_ID) {
            s_Filed_getDouble_ID = JNIHelper::findMethod(smart_jnienv, false, FIELD_CLASS,
                                                         "getDouble",
                                                         "(Ljava/lang/Object;)D");
        }
        jdouble result = smart_jnienv->CallDoubleMethod(mFiled, s_Filed_getDouble_ID, obj);
        return result;
    }

    jmethodID Field::s_Class_getDeclaredField_ID = NULL;
    jmethodID Field::s_Field_setAccessible_ID = NULL;
    jmethodID Field::s_Field_getInt_ID = NULL;
    jmethodID Field::s_Field_getLong_ID = NULL;
    jmethodID Field::s_Field_get_ID = NULL;
    jmethodID Field::s_Field_setInt_ID = NULL;
    jmethodID Field::s_Field_setLong_ID = NULL;
    jmethodID Field::s_Field_set_ID = NULL;
    jmethodID Field::s_Filed_getShort_ID = NULL;
    jmethodID Field::s_Filed_getChar_ID = NULL;
    jmethodID Field::s_Filed_setShort_ID = NULL;
    jmethodID Field::s_Filed_setChar_ID = NULL;
    jmethodID Field::s_Field_getBoolean_ID = NULL;
    jmethodID Field::s_Field_setBoolean_ID = NULL;
    jmethodID Field::s_Field_getByte_ID = NULL;
    jmethodID Field::s_Field_setByte_ID = NULL;
    jmethodID Field::s_Filed_getFloat_ID = NULL;
    jmethodID Field::s_Filed_setFloat_ID = NULL;
    jmethodID Field::s_Filed_getDouble_ID = NULL;
    jmethodID Field::s_Filed_setDouble_ID = NULL;

}


