#ifndef JNIHELPER_H_
#define JNIHELPER_H_

#include <jni.h>

namespace smart_jni {

    class JNIHelper {

    private:
        JNIHelper() {}

    public:

        /**
         * find the methodID by the classname, methodname and the methodsigner.
         */
        static jmethodID findMethod(JNIEnv *smart_jnienv, bool isstatic, const char *classname,
                                    const char *methodname, const char *methodsigner);

        /**
         * find the methodID by the classname, methodname and the methodsigner.
         */
        static jmethodID findMethod(JNIEnv *smart_jnienv, bool isstatic, const jclass claxx,
                                    const char *methodname,const char *methodsigner);

        /**
         *  check the obj was assigned from class whitch name claxxname
         */
        static bool isAssignableFrom(JNIEnv *smart_jnienv, const jobject obj, const char *claxxname);

        /**
         *  check the obj was assigned from claxx
         */
        static bool isAssignableFrom(JNIEnv *smart_jnienv, const jobject obj, const jclass claxx);

        static char* trans2JNIName(const char *name);

        static jclass trans2Primitive(JNIEnv *smart_jnienv, const jclass claxx);

        static char* jstringTostring(JNIEnv *smart_jnienv,const jstring source);

    };

}


#endif /* JNIHELPER_H_ */
