[org 0x7c00] ; tell the assembler that our offset is bootsector code

mov bp, 0x8000 ; set the stack safely away from us
mov sp, bp

call newline

mov bx, TITLE
call print
call newline

mov bx, 0x9000 ; es:bx = 0x0000:0x9000 = 0x09000
mov dh, 5 ; read 2 sectors

call disk_laod
    mov dx, [0x9000 + 8] ; retrieve the first loaded word, 0xdada
    call print_hex
    mov dx, [0x9000 + 512] ; retrieve the first loaded word, 0xdada
    call print_hex
    mov dx, [0x9000 + 1024] ; retrieve the first loaded word, 0xdada
    call print_hex
    mov dx, [0x9000 + 1024 + 512] ; retrieve the first loaded word, 0xdada
    call print_hex
    mov dx, [0x9000 + 1024 + 1024] ; retrieve the first loaded word, 0xdada
    call print_hex

call newline

mov bx, MSG_REAL_MODE
call print ; This will be written after the BIOS messages

call switch_to_pm

jmp $

%include "disk_load.asm"
%include "print.asm"
%include "print_hex.asm"
%include "gdt.asm"
%include "print_vga.asm"
%include "switchto32.asm"
; data
TITLE: db "Welcome to Bruh Bootloader!", 0

[bits 32]
BEGIN_PM: ; after the switch we will get here
    mov ebx, MSG_PROT_MODE
    call print_string_pm ; Note that this will be written at the top left corner
    jmp $

MSG_REAL_MODE db "Started in 16-bit real mode", 0
MSG_PROT_MODE db "Loaded 32-bit protected mode", 0


; padding and magic number
times 510-($-$$) db 0
dw 0xaa55

; boot sector = sector 1 of cyl 0 of head 0 of hdd 0
; from now on = sector 2 ...
db "Pay Day", 0
times 249 dw 0xdada ; sector 2 = 512 bytes
times 256 dw 0xfafa ; sector 3 = 512 bytes
times 256 dw 0xcaca ; sector 4 = 512 bytes
times 256 dw 0xaaaa ; sector 5 = 512 bytes
times 256 dw 0x1234 ; sector 5 = 512 bytes