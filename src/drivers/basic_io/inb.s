global inb

; inb - return a byte from an I/O port
; stack: [esp + 4] The address of the I/O port
;        [esp    ] The return address
inb:
    mov dx, [esp + 4]
    in al, dx
    ret