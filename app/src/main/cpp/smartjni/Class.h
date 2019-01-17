#ifndef CLASS_H_
#define CLASS_H_

#include <jni.h>

namespace smart_jni {

    class Method;

    class Field;

    class Class {

    private:
        static jmethodID s_Class_getName_ID;
        JNIEnv *smart_jnienv;

    protected:
        jclass mClass;

        Class(JNIEnv *smart_jnienv, const char *name);

    public:
        /**
         * 根据方法名以及参数表，查找方法
         */
        Method *getMethod(const char *methodname, ...) const;

        /**
         * 根据字段名,查找字段
         */
        Field *getField(const char *filedname) const;

        /**
         * 获取类名字
         */
        const char *getName();

        /**
         * 获取jclass对象
         */
        const jclass getJNIClass();

        /**
         *  checking self is assignable from the claxx
         */
        bool isAssignableFrom(const Class &claxx);

        /**
         * 实例化对象
         */

        jobject newInstance();

        /**
         * 析构
         */
        virtual ~Class();

        /**
         * 获取用户自定义Class
         */
        static Class *forName(JNIEnv *smart_jnienv, const char *name);

        /**
         * 参数结尾
         */
        static const Class *END;


        void setIntFiledValue(jobject obj, const char *filedname, jint value);

        void setShortFiledValue(jobject obj, const char *filedname, jshort value);

        void setCharFiledValue(jobject obj, const char *filedname, jchar value);

        void setLongFiledValue(jobject obj, const char *filedname, jlong value);

        void setObjectFiledValue(jobject obj, const char *filedname, jobject value);

        void setBooleanFiledValue(jobject obj, const char *filedname, jboolean value);

        void setByteFiledValue(jobject obj, const char *filedname, jbyte value);

        void setFloatFiledValue(jobject obj, const char *filedname, jfloat value);

        void setDoubleFiledValue(jobject obj, const char *filedname, jdouble value);

        jint getIntFiledValue(jobject obj, const char *filedname);

    };

}


#endif /* CLASS_H_ */
