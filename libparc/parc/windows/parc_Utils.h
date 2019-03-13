/*
 * Copyright (c) 2019 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PARC_UTILS_H
#define PARC_UTILS_H
#define WIN32_LEAN_AND_MEAN
#define HAVE_STRUCT_TIMESPEC
#include <Windows.h>
#include <stdint.h>
#include <io.h>
#include <stdlib.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <parc/windows/getopt.h>
#include <parc/windows/queue.h>

#ifndef IOVEC
#define IOVEC
struct iovec {
	void* iov_base;
	size_t iov_len;
};
#endif

typedef uint16_t in_port_t;

#ifndef SLEEP
#define SLEEP
#define sleep Sleep
#endif

#ifndef USLEEP
#define USLEEP
void usleep(__int64 usec);
#endif

#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#define PARCLibrary_DISABLE_ATOMICS
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#ifndef __ATTRIBUTE__
#define __ATTRIBUTE__
#define __attribute__(A)
#endif

#ifndef RESTRICT
#define RESTRICT
#define restrict __restrict
#endif

#ifndef _vscprintf
/* For some reason, MSVC fails to honour this #ifndef. */
/* Hence function renamed to _vscprintf_so(). */
int _vscprintf_so(const char *format, va_list pargs);
#endif // _vscprintf

#ifndef vasprintf
int vasprintf(char **strp, const char *fmt, va_list ap);
#endif // vasprintf

#ifndef asprintf
int asprintf(char *strp[], const char *fmt, ...);
#endif // asprintf

#ifndef GETTIMEOFDAY
#define GETTIMEOFDAY
int gettimeofday(struct timeval * tp, struct timezone * tzp);
#endif

#ifndef strndup
char *strndup(const char *str, size_t chars);
#endif

#ifndef dprintf
int dprintf(int fd, char *fmt, ...);
#endif

#ifndef timersub
#define timersub(a, b, result) \
        do { \
                (result)->tv_sec = (a)->tv_sec - (b)->tv_sec; \
                (result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
                if ((result)->tv_usec < 0) { \
                        --(result)->tv_sec; \
                        (result)->tv_usec += 1000000; \
                } \
        } while (0)
#endif // timersub

#ifndef dup
#define dup _dup
#endif

#ifndef access
#define access _access
#endif

#ifndef __cplusplus

#ifndef close
#define close _close
#endif

#ifndef write
#define write _write
#endif

#ifndef open
#define open _open
#endif

#endif

#ifndef unlink
#define unlink _unlink
#endif

#ifndef read
#define read _read
#endif

#ifndef strcasecmp
#define strncasecmp _strnicmp
#endif

#ifndef strcasecmp

#define strcasecmp _stricmp
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif
#ifndef R_OK
#define R_OK    4       /* Test for read permission.  */
#endif
#ifndef  W_OK
#define W_OK    2       /* Test for write permission.  */
#endif
#ifndef F_OK
#define F_OK    0
#endif

#ifndef STDIN_FILENO
#define STDIN_FILENO _fileno(stdin)
#endif

#ifndef STDOUT_FILENO
#define STDOUT_FILENO _fileno(stdout)
#endif

#ifndef STDERR_FILENO
#define STDERR_FILENO _fileno(stderr)
#endif

#endif