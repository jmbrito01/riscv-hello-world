riscv-hello-world
==================================

This repo is based on [riscv64-in-qemu](https://github.com/rtfb/riscv64-in-qemu).

`riscv-hello-world` is a simple package intended to understand how a risc-v chip works under the hood. It creates a new bootable OS that listens to the Machine Interrupt Timer and execute code with machine privileges. It also creates two user-mode executions in loop.

For nexts steps, we need to update `boot.s` to allow multi-core processors.

This code is compiled with the [riscv-gnu-toolchain][riscv-gnu-toolchain] and
can be run with the QEMU `sifive_u` and `sifive_e` machines. Both 32bit and
64bit targets are supported.

As of this writing, these are the latest versions of the software involved:
* Qemu: `v5.1.0`
* RISC-V GNU toolchain: `10.1.0`

## Running
`./scripts/start.sh`

As of this writing, these are the latest versions of the software involved:
* Qemu: `v5.1.0`
* Linux: `v5.9`
* Busybox: `1_9_2`
* RISC-V GNU toolchain: `10.1.0`

Make targets
------------

`make prereqs` -- apt-get the prerequisites.
`make clone` -- clone the relevant source code.
`make qemu` -- build Qemu for RISC-V.

`make run-linux` -- build Linux bootable image, add our executable and launch
via QEMU.

RISC-V ELF executable in SPIKE
==============================

Run a RISC-V ELF executable in [SPIKE][spike] a standard RISC-V ISA simulator.

As of this writing, these are the latest versions of the software involved:
* Qemu: `v5.1.0`
* Spike" `v1.0.1-dev`
* RISC-V GNU toolchain: `10.1.0`

TODO: install Spike

Make targets
------------

`make run-spike` -- build RISC-V ELF executable and launch it via SPIKE.

RISC-V Quick References
=======================

* [RISC-V Assembly Cheat Sheet][riscv-asm-sheet]
* [RISC-V Assembly Programmer's Manual][riscv-asm-man]
* [SiFive U (SiFive Freedom U540-C000 SoC) Hardware Manual][sifive-u]
* [SiFive E (SiFive Freedom U310-G002 SoC) Hardware Manual][sifive-e]

[riscv-gnu-toolchain]: https://github.com/riscv/riscv-gnu-toolchain
[riscv-qemu-docs]: https://risc-v-getting-started-guide.readthedocs.io/en/latest/linux-qemu.html
[custom-kernel-tutorial]: http://mgalgs.github.io/2015/05/16/how-to-build-a-custom-linux-kernel-for-qemu-2015-edition.html
[riscv-hello-asm]: https://github.com/noteed/riscv-hello-asm
[riscv-hello-asm2]: https://theintobooks.wordpress.com/2019/12/28/hello-world-on-risc-v-with-qemu
[spike]: https://github.com/riscv/riscv-isa-sim

[riscv-asm-sheet]: https://github.com/jameslzhu/riscv-card/blob/master/riscv-card.pdf
[riscv-asm-man]: https://github.com/riscv/riscv-asm-manual/blob/master/riscv-asm.md
[sifive-u]: https://static.dev.sifive.com/FU540-C000-v1.0.pdf
[sifive-e]: https://sifive.cdn.prismic.io/sifive%2F59a1f74e-d918-41c5-b837-3fe01ba7eaa1_fe310-g002-manual-v19p05.pdf
[sifive-toolchain]: https://www.sifive.com/software
