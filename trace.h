#ifndef TRACE_H
#define TRACE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define ATRACE_MESSAGE_LEN 256


class Tracer {
public:
	void trace_init();


	inline void trace_begin(const char *name)
	{
	    char buf[ATRACE_MESSAGE_LEN];
	    int len = snprintf(buf, ATRACE_MESSAGE_LEN, "B|%d|%s", getpid(), name);
	    write(atrace_marker_fd, buf, len);
	}

	inline void trace_end()
	{
	    char c = 'E';
	    write(atrace_marker_fd, &c, 1);
	}

	int atrace_marker_fd;
};

#endif
