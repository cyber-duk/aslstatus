/* See LICENSE file for copyright and license details. */
#if defined(__linux__)
	#include <stdint.h>
	#include <stdio.h>

	#include "../util.h"

	void
	entropy(char *out)
	{
		uintmax_t num;

		if (pscanf("/proc/sys/kernel/random/entropy_avail", "%ju", &num)
		    != 1) {
			ERRRET(out);
		}

		bprintf(out, "%ju", num);
	}
#elif defined(__OpenBSD__) | defined(__FreeBSD__)
	#include <string.h>

	void
	entropy(char *out)
	{
		/* Unicode Character 'INFINITY' (U+221E) */
		strcpy(out, "\xe2\x88\x9e");
	}
#endif
