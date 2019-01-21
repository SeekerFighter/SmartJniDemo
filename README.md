# SmartJniDemo
一个用于简化NDK开发时，jni代码生成java对象并赋值的小工具类（据江湖传闻，此类是我百度然后稍加修改的，不过传闻好像是真的，地址链接已无从查找考证，致敬原作者，阿门！！）

## step1 引入smartjni
```
#include "smartjni/Class.h"
using namespace smart_jni;
```
## step2 开始使用
```
Class* test = Class::forName(env,"java对象绝对路径");
    jobject testObj = test->newInstance();
    test->setIntFiledValue(testObj,"java字段参数",100);
    test->setBooleanFiledValue(testObj, "result", static_cast<jboolean>(true));
    test->setByteFiledValue(testObj,"aByte",0x0A);
    delete test;//删除
```
