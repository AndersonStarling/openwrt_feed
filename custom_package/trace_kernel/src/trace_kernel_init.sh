#!/bin/sh

mount -t tracefs nodev /sys/kernel/tracing
echo function_graph > /sys/kernel/debug/tracing/current_tracer
echo > /sys/kernel/debug/tracing/trace
