[org 0x7c00] ; tell the assembler that our offset is bootsector code

call newline

mov bx, BOOT
call print
call newline

mov bx, REALMODE
call print
call newline
call newline

mov bx, TITLE
call print

jmp $

%include "print.asm"

; data
BOOT: db "Bootable disk detected", 0

REALMODE: db "Enter Real Mode (16-bit)", 0

TITLE: db "Welcome to Bruh Bootloader!", 0

; padding and magic number
times 510-($-$$) db 0
dw 0xaa55