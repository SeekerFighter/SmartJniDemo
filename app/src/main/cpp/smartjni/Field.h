#ifndef FIELD_H_
#define FIELD_H_

#include <jni.h>

#define FIELD_CLASS "java/lang/reflect/Field"

namespace smart_jni {

    class Field {

    private:
        jobject mFiled;
        JNIEnv *smart_jnienv;

        static jmethodID s_Class_getDeclaredField_ID;
        static jmethodID s_Field_setAccessible_ID;

        static jmethodID s_Field_get_ID;
        static jmethodID s_Field_getBoolean_ID;
        static jmethodID s_Field_getByte_ID;
        static jmethodID s_Filed_getChar_ID;
        static jmethodID s_Filed_getShort_ID;
        static jmethodID s_Field_getInt_ID;
        static jmethodID s_Field_getLong_ID;
        static jmethodID s_Filed_getFloat_ID;
        static jmethodID s_Filed_getDouble_ID;

        static jmethodID s_Field_set_ID;
        static jmethodID s_Field_setBoolean_ID;
        static jmethodID s_Field_setByte_ID;
        static jmethodID s_Filed_setChar_ID;
        static jmethodID s_Filed_setShort_ID;
        static jmethodID s_Field_setInt_ID;
        static jmethodID s_Field_setLong_ID;
        static jmethodID s_Filed_setFloat_ID;
        static jmethodID s_Filed_setDouble_ID;

    public:
        Field(JNIEnv *smart_jnienv, jclass claxx, const char *fieldname);

        virtual ~Field();

        jobject getObject(jobject obj);

        jboolean getBoolean(jobject obj);

        jbyte getByte(jobject obj);

        jchar getChar(jobject obj);

        jshort getShort(jobject obj);

        jint getInt(jobject obj);

        jlong getLong(jobject obj);

        jfloat getFloat(jobject obj);

        jdouble getDouble(jobject obj);

        void setObject(jobject obj, jobject value);

        void setBoolean(jobject obj, jboolean value);

        void setByte(jobject obj, jbyte value);

        void setChar(jobject obj, jchar value);

        void setShort(jobject obj, jshort value);

        void setInt(jobject obj, jint value);

        void setLong(jobject obj, jlong value);

        void setFloat(jobject obj, jfloat value);

        void setDouble(jobject obj, jdouble value);

    };

}


#endif /* FIELD_H_ */
