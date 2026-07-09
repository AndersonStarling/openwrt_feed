#!/bin/sh

TRACE_SYMBOLS=$1

echo $TRACE_SYMBOLS > /sys/kernel/debug/tracing/set_ftrace_filter
echo 1 > /sys/kernel/debug/tracing/tracing_on






