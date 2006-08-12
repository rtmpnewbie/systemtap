/* COVERAGE: alarm nanosleep pause */
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>

static void
sigrt_act_handler(int signo, siginfo_t *info, void *context)
{
}

int main()
{
  struct timespec rem, t = {0,789};
  struct sigaction sigrt_act;
  memset(&sigrt_act, 0, sizeof(sigrt_act));
  sigrt_act.sa_handler = (void *)sigrt_act_handler;
  sigaction(SIGALRM, &sigrt_act, NULL);

  alarm(1);
  // alarm (1) = 0

  pause();
  // pause () =

  alarm(0);
  // alarm (0) = 0

  sleep(1);
  // nanosleep (\[1.000000000\], XXXX) = 0

  usleep(1234);
  // nanosleep (\[0.001234000\], 0x[0]+) = 0

  nanosleep(&t, &rem); 
  // nanosleep (\[0.000000789\], XXXX) = 0

  nanosleep(&t, NULL); 
  // nanosleep (\[0.000000789\], 0x[0]+) = 0

  return 0;
}
 
