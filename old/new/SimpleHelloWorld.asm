[org 0x7c00]

mov ah, 0x0e
mov bx, variableName

HelloWorld:
	mov al, [bx]
	cmp al, 0
	je end
	int 0x10
	inc bx
	jmp HelloWorld
variableName:
	db "Hey Bitchs! I am the MASTER KING OF OSes", 0
end:

jmp $

times 510-($-$$) db 0
dw 0xaa55