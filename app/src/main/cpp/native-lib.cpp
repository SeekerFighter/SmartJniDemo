#include <jni.h>
#include <string>

#include "smartjni/Class.h"
#include "smartjni/JavaType.h"
#include "smartjni/Method.h"
#include "smartjni/LogUtil.h"

using namespace smart_jni;

extern "C" JNIEXPORT jstring JNICALL

Java_seeker_smartjnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jobject JNICALL
Java_seeker_smartjnidemo_MainActivity_getTestSmartJni(JNIEnv *env, jobject instance) {

    Class* test = Class::forName(env,"seeker.smartjnidemo.SmartJni");
    jobject testObj = test->newInstance(JNI_FALSE);

    test->setIntFiledValue(testObj,"code",100);
    test->setBooleanFiledValue(testObj, "result",JNI_TRUE);
    test->setByteFiledValue(testObj,"aByte",0x0A);

    jobject result = NULL;

    result = test->invokeMethod(testObj,"setJint",Jint::type(env,10),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setJint2",Jint::type(env,11),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setJbyte",Jbyte::type(env,0x0B),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setJlong",Jlong::type(env,20),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setJfloat",Jfloat::type(env,5),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setMuiti",Jdouble::type(env,30),Jshort::type(env,40),Class::END);
    env->DeleteLocalRef(result);
    result = test->invokeMethod(testObj,"setJobject",Object::type(env,"java.lang.Integer",Integer::valueOf(env,200)),Class::END);
    env->DeleteLocalRef(result);

//    Method * setJobject = test->getMethod("setJobject",Object::type(env,"java.lang.Integer"),Class::END);
//    setJobject->invoke(testObj,Integer::valueOf(env,200));

    Class* list = Class::forName(env,"seeker.smartjnidemo.ByteList");
    jobject listObj = list->newInstance(JNI_TRUE);
    result = list->invokeMethod(listObj,"add",Object::type(env,"java.lang.Byte",Byte::valueOf(env,0x0C)),Class::END);
    env->DeleteLocalRef(result);
    Method* setObj = test->getMethod("setObj",Object::type(env,"seeker.smartjnidemo.ByteList"),Class::END);
    result = setObj->invoke(testObj,listObj);
    env->DeleteLocalRef(result);


    Class* list2 = Class::forName(env,"java.util.ArrayList");
    jobject listObj2 = list2->newInstance(JNI_TRUE);
    Method* add = list2->getMethod("add",Object::type(env,"java.lang.Object"),Class::END);
    result = add->invoke(listObj2,Byte::valueOf(env,0x0E));
    env->DeleteLocalRef(result);

    for (int i = 0; i < 10000; ++i) {
       result = add->invoke(listObj2,Byte::valueOf(env,0x0E));
       env->DeleteLocalRef(result);
    }

    result = test->invokeMethod(testObj,"setByteList",Object::type(env,"java.util.List",listObj2),Class::END);
    env->DeleteLocalRef(result);

    delete add;
    delete list;
    delete list2;
    delete setObj;
    delete test;
    return testObj;
}