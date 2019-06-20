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
         * ���ݷ������Լ����������ҷ���
         */
        Method *getMethod(const char *methodname, ...) const;

        /**
         * �����ֶ���,�����ֶ�
         */
        Field *getField(const char *filedname) const;

        /**
         * ��ȡ������
         */
        const char *getName();

        /**
         * ��ȡjclass����
         */
        const jclass getJNIClass();

        /**
         *  checking self is assignable from the claxx
         */
        bool isAssignableFrom(const Class &claxx);

        /**
         * ʵ��������
         */

        jobject newInstance(bool userEmptyParamsConstruct);

        /**
         * ����
         */
        virtual ~Class();

        /**
         * ��ȡ�û��Զ���Class
         */
        static Class *forName(JNIEnv *smart_jnienv, const char *name);

        /**
         * ������β
         */
        static const Class *END;


        void setIntFiledValue(jobject receiver, const char *filedname, jint value);

        void setShortFiledValue(jobject receiver, const char *filedname, jshort value);

        void setCharFiledValue(jobject receiver, const char *filedname, jchar value);

        void setLongFiledValue(jobject receiver, const char *filedname, jlong value);

        void setObjectFiledValue(jobject receiver, const char *filedname, jobject value);

        void setBooleanFiledValue(jobject receiver, const char *filedname, jboolean value);

        void setByteFiledValue(jobject receiver, const char *filedname, jbyte value);

        void setFloatFiledValue(jobject receiver, const char *filedname, jfloat value);

        void setDoubleFiledValue(jobject receiver, const char *filedname, jdouble value);

        jint getIntFiledValue(jobject receiver, const char *filedname);

        jobject invokeMethod(jobject receiver, const char *methodname,...);

    };

}


#endif /* CLASS_H_ */
