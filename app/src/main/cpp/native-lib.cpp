#include <jni.h>
#include <string>

#include "smartjni/Class.h"
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

    Class* test = Class::forName(env,"seeker.smartjnidemo.TestSmartJni");
    jobject testObj = test->newInstance();
    test->setIntFiledValue(testObj,"code",100);
    test->setBooleanFiledValue(testObj, "result", static_cast<jboolean>(true));
    test->setByteFiledValue(testObj,"aByte",0x0A);
    delete test;
    return testObj;
}