/* config.h - Windows/MinGW configuration for libusb-1.0.27
 * This file is a manually crafted replacement for the autoconf-generated
 * config.h, used when building libusb as a bundled dependency on Windows.
 */

#pragma once

/* Enable message logging */
#ifndef ENABLE_LOGGING
#define ENABLE_LOGGING 1
#endif

/* Default symbol visibility (empty for static library) */
#ifndef DEFAULT_VISIBILITY
#define DEFAULT_VISIBILITY
#endif

/* Define to 1 if the system has `struct timespec' */
#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC 1
#endif

/* printf format attribute for GCC/MinGW */
#if defined(__GNUC__) && (__GNUC__ >= 3)
#define PRINTF_FORMAT(fmt_idx, arg_idx) \
    __attribute__((__format__(__printf__, fmt_idx, arg_idx)))
#else
#define PRINTF_FORMAT(fmt_idx, arg_idx)
#endif

/* Windows platform */
#ifndef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS 1
#endif

/* No POSIX sys/time.h on Windows */
/* #undef HAVE_SYS_TIME_H */

/* No POSIX poll on Windows */
/* #undef HAVE_POLL_H */
/* #undef HAVE_NFDS_T */

/* No Linux-specific features */
/* #undef HAVE_EVENTFD */
/* #undef HAVE_TIMERFD */

/* No clock_gettime on older Windows */
/* #undef HAVE_CLOCK_GETTIME */

/* No pthreads on Windows */
/* #undef HAVE_PTHREAD */
/* #undef HAVE_PTHREAD_CONDATTR_SETCLOCK */
