#include <jni.h>
#include <stdlib.h>

#include "Class.h"
#include "Method.h"
#include "Field.h"
#include "JNIHelper.h"
#include "JavaType.h"
#include "LogUtil.h"

namespace smart_jni {

    Class *Class::forName(JNIEnv *smart_jnienv, const char *name) {
        Class *clazz = new Class(smart_jnienv, name);
        return clazz;
    }

    jobject Class::newInstance(bool userEmptyParamsConstruct) {
        if (userEmptyParamsConstruct){
            jmethodID construct = JNIHelper::findMethod(smart_jnienv, false, mClass,"<init>", "()V");
            return smart_jnienv->NewObject(mClass,construct,"");
        }
        return smart_jnienv->AllocObject(mClass);
    }

    void Class::setIntFiledValue(jobject obj, const char *filedName, jint value) {
        Field *field = getField(filedName);
        field->setInt(obj, value);
        delete field;
    }

    void Class::setShortFiledValue(jobject obj, const char *filedName, jshort value) {
        Field *field = getField(filedName);
        field->setShort(obj, value);
        delete field;
    }

    void Class::setCharFiledValue(jobject obj, const char *filedName, jchar value) {
        Field *field = getField(filedName);
        field->setChar(obj, value);
        delete field;
    }

    void Class::setLongFiledValue(jobject obj, const char *filedName, jlong value) {
        Field *field = getField(filedName);
        field->setLong(obj, value);
        delete field;
    }

    void Class::setBooleanFiledValue(jobject obj, const char *filedName, jboolean value) {
        Field *field = getField(filedName);
        field->setBoolean(obj, value);
        delete field;
    }

    void Class::setByteFiledValue(jobject obj, const char *filedName, jbyte value) {
        Field *field = getField(filedName);
        field->setByte(obj, value);
        delete field;
    }

    void Class::setFloatFiledValue(jobject obj, const char *filedName, jfloat value) {
        Field *field = getField(filedName);
        field->setFloat(obj, value);
        delete field;
    }

    void Class::setDoubleFiledValue(jobject obj, const char *filedName, jdouble value) {
        Field *field = getField(filedName);
        field->setDouble(obj, value);
        delete field;
    }

    void Class::setObjectFiledValue(jobject obj, const char *filedName, jobject value) {
        Field *field = getField(filedName);
        field->setObject(obj, value);
        delete field;
    }

    jint Class::getIntFiledValue(jobject obj, const char *filedName) {
        Field *field = getField(filedName);
        jint value = field->getInt(obj);
        delete field;
        return value;
    }

    Class::Class(JNIEnv *jnienv, const char *name) {
        smart_jnienv = jnienv;
        char *jniname = JNIHelper::trans2JNIName(name);
        if (jniname != NULL) {
            mClass = (jclass) smart_jnienv->NewGlobalRef(smart_jnienv->FindClass(jniname));
            delete jniname;
        }
    }

    bool Class::isAssignableFrom(const Class &clazz) {
        jboolean b = smart_jnienv->IsAssignableFrom(mClass, clazz.mClass);
        return b == JNI_TRUE;
    }

    Class::~Class() {
        if (mClass != NULL) {
            smart_jnienv->DeleteGlobalRef(mClass);
        }
    }

    Method *Class::getMethod(const char *methodname, ...) const {
        va_list vl;
        va_start(vl, methodname);

        int size = 0;
        while (va_arg(vl, Class*) != END) {
            size++;
        }

        va_start(vl, methodname);
        Class *clazz = NULL;
        Class **params_clazz = (Class **) malloc(size * sizeof(Class *));
        size = 0;
        while ((clazz = va_arg(vl, Class*)) != END) {
            params_clazz[size++] = clazz;
        }
        va_end(vl);
        Method *method = new Method(smart_jnienv, mClass, methodname, size, params_clazz);
        return method;
    }

    Field *Class::getField(const char *fieldName) const {
        Field *field = new Field(smart_jnienv, mClass, fieldName);
        return field;
    }

    const char *Class::getName() {
        if (NULL == s_Class_getName_ID) {
            s_Class_getName_ID = JNIHelper::findMethod(smart_jnienv, false, "java/lang/Class",
                                                       "getName",
                                                       "()Ljava/lang/String;");
        }
        jstring jname = (jstring) smart_jnienv->CallObjectMethod(mClass, s_Class_getName_ID);
        return smart_jnienv->GetStringUTFChars(jname, NULL);
    }

    const jclass Class::getJNIClass() {
        return mClass;
    }

    jmethodID Class::s_Class_getName_ID = NULL;
    const Class *Class::END = NULL;


    jobject Class::invokeMethod(jobject receiver, const char *methodname, ...) {
        va_list vl;
        va_start(vl, methodname);

        int size = 0;
        while (va_arg(vl, Class*) != END) {
            size++;
        }

        va_start(vl, methodname);
        Class *clazz = NULL;
        Class **params_clazz = (Class **) malloc(size * sizeof(Class *));
        size = 0;
        while ((clazz = va_arg(vl, Class*)) != END) {
            params_clazz[size++] = clazz;
        }
        va_end(vl);
        Method *method = new Method(smart_jnienv, mClass, methodname, size, params_clazz);
        jobject result = method->_invoke(receiver);
        delete method;
        return result;
    }

}




