mov ah, 0x0e
mov al, 'H'
int 0x10

mov ah, 0x0e
mov al, 'e'
int 0x10

mov ah, 0x0e
mov al, 'l'
int 0x10

mov ah, 0x0e
mov al, 'l'
int 0x10

mov ah, 0x0e
mov al, 'o'
int 0x10

mov ah, 0x0e
mov al, ','
int 0x10

mov ah, 0x0e
mov al, ' '
int 0x10

mov ah, 0x0e
mov al, 'W'
int 0x10

mov ah, 0x0e
mov al, 'o'
int 0x10

mov ah, 0x0e
mov al, 'r'
int 0x10

mov ah, 0x0e
mov al, 'l'
int 0x10

mov ah, 0x0e
mov al, 'd'
int 0x10

mov ah, 0x0e
mov al, '!'
int 0x10

mov ah, 0x0e    ; function number = 0Eh : Display Character
mov al, '!'     ; AL = code of character to display
int 0x10        ; call INT 10h, BIOS video service

mov ah, 1
int 0x10

mov ah, 3
int 0x10

mov ah, 0x11
int 0x10

mov ah, 0x0e ; Enter writing mode
mov al, 13
int 0x10

mov al, 10
int 0x10

mov ah, 0x0e
mov al, 'a'
int 0x10

jmp loop

loop:
	inc al
	cmp al, 'z' + 1
	je exit
	int 0x10
	jmp loop

exit:

	jmp $

times 510-($-$$) db 0
dw 0xaa55
