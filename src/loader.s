MBALIGN  equ  1<<0
MEMINFO  equ  1<<1
FLAGS    equ  MBALIGN | MEMINFO
MAGIC    equ  0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)
 
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

section .text
global loader
extern kern_main
KERNEL_STACK_SIZE equ 4096

loader:
    mov eax, 0xCAFEBABE
    mov esp, kernel_stack + KERNEL_STACK_SIZE
    call kern_main
    cli
    hlt
.loop:
    jmp .loop

section .bss
align 4
kernel_stack:
    resb KERNEL_STACK_SIZE