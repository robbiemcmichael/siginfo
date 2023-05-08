#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void handler(int signo, siginfo_t *info, void *context)
{
    char *signame;
    char s[200];
    time_t t;
    struct tm *tmp;

    signame = strsignal(signo);

    if (signame == NULL)
    {
        signame = "Unknown";
    }

    t = time(NULL);
    tmp = localtime(&t);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", tmp);

    char *fmt = "[%s] PID %d sent signal: name=\"%s\", number=%d, code=%d\n";
    printf(fmt, s, info->si_pid, signame, signo, info->si_code);
}

int main(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    for (int i = 1; i <= SIGRTMAX; i++)
    {
        sigaction(i, &sa, NULL);
    }

    for (;;)
    {
        pause();
    }
}
