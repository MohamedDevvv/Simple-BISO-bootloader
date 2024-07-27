; setting global offset
[org 0x7c00]

;printg
mov bx, boot
call print

mov bx, realmode
call print

%include "print.asm"

boot: db 'Booting Bruh Bootloader', 0
realmode: db 'Enter 16-bit real mode', 0

; magick number
jmp $

times 510-($-$$) db 0
db 0x55, 0xaa