[org 0x7c00]
mov [BOOT_DISK], dl
xor ax, ax
mov es,ax
mov ds,ax
mov bp, 0x8000
mov sp, bp
mov bx, 0x7e00
mov ah, 2
mov al, 1 ;number of sectors
mov ch, 0 ; Cylinder
mov dh, 0 ; head number
mov cl, 2 ; sector number
mov dl, [BOOT_DISK] ; drive number
int 0x13
mov ah, 0x0e
mov al, [0x7e00]
int 0x10
jmp $
BOOT_DISK: db 0
times 510-($-$$) db 0
dw 0xaa55
times 512 db 'A'
times 512 db 'A'
times 512 db 'A'
times 512 db 'A'
times 512 db 'A'
times 512 db 'A'
times 512 db 'A'