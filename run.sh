#!/bin/bash
qemu-system-x86_64 -d cpu_reset -serial file:qemu.log -m 1024 -fda fd.img
