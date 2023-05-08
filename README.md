# siginfo

A simple C program which uses `sigaction` with the `SA_SIGINFO` flag to print
additional details about a signal that are not exposed in many other
programming languages.

This may be useful for trying to figure out the PID that is terminating other
processes on a system, as long as you can get it to target the desired process.
If you're comfortable with eBPF tools, a more powerful alternative is
[`killsnoop`][killsnoop].

## Usage

Compile and run the program:

```bash
make build
bin/siginfo
```

In another terminal, send it a signal:

```bash
killall -s TERM siginfo
```

Kill it for real:

```bash
killall -s KILL siginfo
```


[killsnoop]: https://github.com/iovisor/bcc/blob/master/tools/killsnoop_example.txt
