#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

#include "JavaType.h"
#include "Method.h"
#include "JNIHelper.h"

namespace smart_jni {

    Method::Method(JNIEnv *jnienv, const jclass claxx, const char *methodname, const int n,
                   Class **params_class)
            : mClass(claxx),
              mParamsCount(n),
              mParamsClass(params_class),
              mMethod(NULL) {
        smart_jnienv = jnienv;
        jclass class_claxx = smart_jnienv->FindClass("java/lang/Class");
        jobjectArray param_class_array = smart_jnienv->NewObjectArray(mParamsCount, class_claxx,NULL);

        for (int i = 0; i < mParamsCount; i++) {
            smart_jnienv->SetObjectArrayElement(param_class_array, i,mParamsClass[i]->getJNIClass());
        }

        jstring jmethod_name = smart_jnienv->NewStringUTF(methodname);
        if (NULL == s_Class_getDeclaredMethod_ID) {
            s_Class_getDeclaredMethod_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                                 "java/lang/Class",
                                                                 "getDeclaredMethod",
                                                                 "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
        }
        mMethod = smart_jnienv->CallObjectMethod(mClass, s_Class_getDeclaredMethod_ID, jmethod_name,
                                                 param_class_array);

        if (NULL == s_Method_setAccessible_ID) {
            s_Method_setAccessible_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                              "java/lang/reflect/Method",
                                                              "setAccessible", "(Z)V");
        }
        smart_jnienv->CallVoidMethod(mMethod, s_Method_setAccessible_ID, JNI_TRUE);

        //delete localrel
        smart_jnienv->DeleteLocalRef(jmethod_name);
        smart_jnienv->DeleteLocalRef(param_class_array);
        smart_jnienv->DeleteLocalRef(class_claxx);
    }

    Method::~Method() {
        delete mParamsClass;
    }

    jobject Method::invoke(jobject receiver, ...) {
        jobject result = NULL;
        jclass element_claxx = smart_jnienv->FindClass("java/lang/Object");
        jobjectArray params = smart_jnienv->NewObjectArray(mParamsCount, element_claxx, NULL);
        va_list va;
        va_start(va, receiver);

        for (int i = 0; i < mParamsCount; i++) {
            Class *cur = mParamsClass[i];
            jobject value = NULL;

            if (cur == Jint::type(smart_jnienv)) {
                value = Integer::valueOf(smart_jnienv, va_arg(va, jint));
            } else if (cur == Jlong::type(smart_jnienv)) {
                value = Long::valueOf(smart_jnienv, va_arg(va, jlong));
            }else if (cur == Jbyte::type(smart_jnienv)) {
                value = Byte::valueOf(smart_jnienv, va_arg(va, jbyte));
            }else if (cur == Jfloat::type(smart_jnienv)) {
                value = Float::valueOf(smart_jnienv, va_arg(va, jfloat));
            }else if (cur == Jdouble::type(smart_jnienv)) {
                value = Double::valueOf(smart_jnienv, va_arg(va, jdouble));
            }else if (cur == Jshort::type(smart_jnienv)) {
                value = Short::valueOf(smart_jnienv, va_arg(va, jshort));
            }else {
                value = va_arg(va,jobject);
                Object* ob = dynamic_cast<Object *>(cur);
                ob->release();
            }

            smart_jnienv->SetObjectArrayElement(params, i, value);
            smart_jnienv->DeleteLocalRef(value);
        }

        va_end(va);

        if (NULL == s_Method_invoke_ID) {
            s_Method_invoke_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                       "java/lang/reflect/Method", "invoke",
                                                       "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
        }
        result = smart_jnienv->CallObjectMethod(mMethod, s_Method_invoke_ID, receiver, params);
        smart_jnienv->DeleteLocalRef(params);
        smart_jnienv->DeleteLocalRef(element_claxx);
        return result;
    }

    jobject Method::_invoke(jobject receiver) {
        jobject result = NULL;

        jclass element_claxx = smart_jnienv->FindClass("java/lang/Object");
        jobjectArray params = smart_jnienv->NewObjectArray(mParamsCount, element_claxx, NULL);

        for (int i = 0; i < mParamsCount; i++) {
            Class *cur = mParamsClass[i];
            jobject value = NULL;

            if (cur == Jint::type(smart_jnienv)) {
                Jint* ji = dynamic_cast<Jint *>(cur);
                value = Integer::valueOf(smart_jnienv,ji->mValue);
            } else if (cur == Jlong::type(smart_jnienv)) {
                Jlong* jl = dynamic_cast<Jlong *>(cur);
                value = Long::valueOf(smart_jnienv,jl->mValue);
            }else if (cur == Jbyte::type(smart_jnienv)) {
                Jbyte* jb = dynamic_cast<Jbyte *>(cur);
                value = Byte::valueOf(smart_jnienv,jb->mValue);
            }else if (cur == Jfloat::type(smart_jnienv)) {
                Jfloat* jf = dynamic_cast<Jfloat *>(cur);
                value = Float::valueOf(smart_jnienv,jf->mValue);
            }else if (cur == Jdouble::type(smart_jnienv)) {
                Jdouble* jd = dynamic_cast<Jdouble *>(cur);
                value = Double::valueOf(smart_jnienv,jd->mValue);
            }else if (cur == Jshort::type(smart_jnienv)) {
                Jshort* js = dynamic_cast<Jshort *>(cur);
                value = Short::valueOf(smart_jnienv,js->mValue);
            }
            else {
                Object* ob = dynamic_cast<Object *>(cur);
                value = ob->mValue;
                ob->release();
            }

            smart_jnienv->SetObjectArrayElement(params, i, value);
            smart_jnienv->DeleteLocalRef(value);
        }

        if (NULL == s_Method_invoke_ID) {
            s_Method_invoke_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                       "java/lang/reflect/Method", "invoke",
                                                       "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
        }

        result = smart_jnienv->CallObjectMethod(mMethod, s_Method_invoke_ID, receiver, params);
        smart_jnienv->DeleteLocalRef(params);
        smart_jnienv->DeleteLocalRef(element_claxx);
        return result;
    }

    const char *Method::getName() {
        if (NULL == s_Method_getName_ID) {
            s_Method_getName_ID = JNIHelper::findMethod(smart_jnienv, false,
                                                        "java/lang/reflect/Method", "getName",
                                                        "()Ljava/lang/String;");
        }
        jstring jname = (jstring) smart_jnienv->CallObjectMethod(mMethod, s_Method_getName_ID);
        return smart_jnienv->GetStringUTFChars(jname, NULL);
    }

    jmethodID Method::s_Class_getDeclaredMethod_ID = NULL;
    jmethodID Method::s_Method_setAccessible_ID = NULL;
    jmethodID Method::s_Method_invoke_ID = NULL;
    jmethodID Method::s_Method_getName_ID = NULL;

}

