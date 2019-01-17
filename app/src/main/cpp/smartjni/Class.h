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

        jobject newInstance();

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
