#include <stdint.h>
#include <unistd.h>

/* for macos */
#ifdef __APPLE__
#include <sys/random.h>
#endif

uint64_t splitmix_init() {
	uint64_t result;
#if (!defined(__ANDROID__) || __ANDROID_API__ >= 28)
	int r = getentropy(&result, sizeof(uint64_t));
#else
	int r = -1;
#endif
	return r == 0 ? result : 0xfeed1000;
}
