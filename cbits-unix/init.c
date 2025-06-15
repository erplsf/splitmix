#include <stdint.h>
#include <unistd.h>

/* for macos */
#ifdef __APPLE__
#include <sys/random.h>
#endif

#include <crypt.h>

uint64_t splitmix_init() {
	uint64_t result;
	int r = getentropy(&result, sizeof(uint64_t));
	return r == 0 ? result : 0xfeed1000;
}
