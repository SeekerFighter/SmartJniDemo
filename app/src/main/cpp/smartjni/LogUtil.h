#ifndef LOGUTIL_H_
#define LOGUTIL_H_

#include <android/log.h>

#define SHOW_LOG 1

#ifdef SHOW_LOG

#define Log_i(TAG, x...)  __android_log_print(ANDROID_LOG_INFO, TAG,  x)

#else

#define Log_i

#endif


#endif /* LOGUTIL_H_ */
