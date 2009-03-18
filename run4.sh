#!/bin/bash
qemu-system-x86_64 -d int -serial file:qemu.log -m 1024 -fda fd-buzzer-vm-debug-level-0-vmx-tests-at-startup.img
