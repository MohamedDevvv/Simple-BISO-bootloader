.set ALIGN,    1<<0
.set MEMINFO,  1<<1 
.set MAGIC,    0x1BADB002
.set FLAGS,    ALIGN | MEMINFO    # Define FLAGS using the constants you set
.set CHECKSUM, -(MAGIC + FLAGS)   # Ensure the checksum is correctly calculated

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:

mov $stack_top, %esp

call kernel_main

	cli
1:	hlt
	jmp 1b

.size _start, . - _start

