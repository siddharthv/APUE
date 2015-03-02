Exercises
---------

1. Verify on your system that the directories dot and dot-dot are not the same, except in the root directory.

    * Use inode to check
    * ls -i (Shell)
    * C Program written 

2. In the output from the program in Figure 1.6, what happened to the processes with process IDs 852 and 853?

    * As UNIX is a multi-processing system, other processes could have obtained these in between PIDs.

3. In Section 1.7 the argument to perror is defined with the ISO C attribute const, whereas the integer argument to strerror is not defined with this atrribute. Why?

   * perror cannot modify the message (as indicated by const)
   * errno is passed by value to strerror and we needn't worry here!

4. In the err- logging function log_doit in Appendix B, why is the value of errno saved when the function is called?
    
        static void
        log_doit(int errnoflag, int priority, const char *fmt, va_list ap)
        {
    	    int		errno_save;
    	    char	buf[MAXLINE];
    
    	    errno_save = errno;		/* value caller might want printed */
    	    vsnprintf(buf, MAXLINE, fmt, ap);
    	    if (errnoflag)
    		    snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s",
    		    strerror(errno_save));
        }

    * As other methods might modify errno

5. If the calendar time is stored as signed 32-bit integer, in what year will it overflow? What ways can be used to extend the overflow point? Are they compatible with existing applications?

        * 2^31 / ( 24 * 60 * 60 * 365) + 1970 = 68 + 1970 = 2038
	* C program written
    
    We can update the time_t data type to 64bit integer, but this might cause some problems for old software.

6. If the process time is tored as a signed 32-bit integer, and if the system counts 100 ticks per second, after how many days will the value overflow?

        * 2^31 / ( 24 * 60 * 60 * 100) = 248
	* C program written