print:
    ; to stop printing
    mov al, [bx]
    cmp al, 0
    je done

    ; to print
    mov ah, 0x0e
    int 0x10
    add bx, 1
    jmp print

done:
    popa
    ret