disk_laod:
    pusha

    push dx

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02
    mov ch, 0x00
    mov dh, 0x00

    int 0x13
    jc disk_err

    pop dx
    cmp al, dh
    jne sectors_error

    call newline
    mov bx, SUCCESSFUL
    call print
    call newline

    popa
    ret


disk_err:
    mov bx, DISK_ERROR
    call print
    call newline
    mov dh, ah ; ah = error code, dl = disk drive that dropped the error
    call print_hex ; check out the code at http://stanislavs.org/helppc/int_13-1.html
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0
SUCCESSFUL: db "Disk read successful with return code: 0x00", 0