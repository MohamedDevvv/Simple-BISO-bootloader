[org 0x7c00]

mov ah, 0x0e ; enable printing
mov bx, greeting

printing:
	mov al, [bx]
	cmp al, 0
	je end
	int 0x10
	inc bx
	jmp printing
	
end:
;end:
;	jmp eol


;savename:
;	mov bx, variable
;input:
;	mov ah, 0
;	int 0x16
;	mov ah, 0x0e
;	int 0x10
;	cmp al, 13
;	je eol
;	mov [bx], al
;	inc bx
;	jmp input

eol:
	mov ah, 0x0e
	mov al, 13
	int 0x10
	mov al, 10
	int 0x10

output:
	mov ah, 0x0e
	int 0x10

input:
	mov ah, 0
	int 0x16
	jmp output


jmp $

greeting:
	db "Hey Man How Are you?, Write down your ideas", 0

;variable:
;	times 10 db 0

times 510-($-$$) db 0
db 0x55, 0xaa