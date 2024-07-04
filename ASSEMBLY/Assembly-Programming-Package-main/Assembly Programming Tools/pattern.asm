[org 0x0100]
jmp start
width:
dw 30 ;;change to change size of rectangle
length:
dw 12
tickcount: 
dw 0
seconds: 
dw 0
shiftFlag: 
dw 1
oldisr: 
dd 0
clearscreen:
push ax
push es
push cx
push di
mov cx,2000
xor di,di
mov ax,0xb800
mov es,ax
mov ax,0x0720
cld 
rep stosw
pop di
pop cx
pop es
pop ax
ret
PrintRectangle:
push es
push ax
push cx
push di
push si
mov ax,0xb800
mov es,ax
mov ah,0x0f
mov al,'A'
mov cx,[width]
mov di,520
upperrow:
mov [es:di],ax
inc al
cmp al,'[' ;;character after Z
jne nochange1
mov al,'A' ;;so that A is printed after Z if width is greater than 26
nochange1:
add di,2
loop upperrow
mov al,'a'
mov cx,[length]
mov si,di ;;mov si to right side of rectangle
add si,158 ;;mov to next line
mov di,680 ;;mov to next line
sides:
mov [es:di],ax  ;;print left side
mov [es:si],ax  ;;print right side
add di,160
add si,160
inc al
loop sides
mov al,'A'
mov cx,[width]
lowerrow:
mov [es:si],ax
inc al
cmp al,'[' ;;character after Z
jne nochange2
mov al,'A' ;;so that A is printed after Z if width is greater than 26
nochange2:
sub si,2
loop lowerrow
pop si
pop di
pop cx
pop ax
pop es
ret
ShiftRectangle:
push es
push ax
push bx
push cx
push si
push di
mov ax,0xb800
mov es,ax
mov di,680
mov bx,[es:di] ;;rotation starting from left side (clockwise)
mov di,520
mov ax,bx
mov cx,[cs:width]
shiftrow1:
mov bx,[es:di]
mov [es:di],ax
add di,2
mov ax,bx
loop shiftrow1
add di,158
mov ax,bx
mov cx,[cs:length]
shiftRside:
mov bx,[es:di]
mov [es:di],ax
add di,160
mov ax,bx
loop shiftRside
mov ax,bx
mov cx,[cs:width]
shiftrow2:
mov bx,[es:di]
mov [es:di],ax
sub di,2
mov ax,bx
loop shiftrow2
sub di,158
mov ax,bx
mov cx,[cs:length]
shiftLside:
mov bx,[es:di]
mov [es:di],ax
sub di,160
mov ax,bx
loop shiftLside
pop di
pop si
pop cx
pop bx
pop ax
pop es
ret
; timer interrupt service routine
timer: 
push ax
inc word [cs:tickcount]
cmp word [cs:tickcount],18
jnge texit
inc word [cs:seconds]
mov word [cs:tickcount],0
cmp word [cs:seconds],2  ;;call shift after 2 seconds
jne texit
mov word [cs:seconds],0
cmp word [cs:shiftFlag],0
je texit ;;if user has paused the shift
call ShiftRectangle
texit:
mov al, 0x20
out 0x20, al ; end of interrupt
pop ax
iret ; return from interrupt
;;;;;---------------------------------------------
; keyboard interrupt service routine
kbisr: 
push ax
in al, 0x60 ; read a char from keyboard port
cmp al, 0x19 ;; if P is pressed
jne nextcmp 
mov word [cs:shiftFlag],0 ;;disable shift
jmp nomatch
nextcmp: 
cmp al, 0x13 ;; if R is pressed
jne nomatch 
mov word [cs:shiftFlag],1  ;;enable shift
nomatch: 
pop ax
jmp far [cs:oldisr] ; call the original ISR
start:
call clearscreen
call PrintRectangle
xor ax, ax
mov es, ax 
cli 
mov word [es:8*4], timer
mov [es:8*4+2], cs 
sti 

xor ax, ax
mov es, ax 
mov ax, [es:9*4]
mov [oldisr], ax 
mov ax, [es:9*4+2]
mov [oldisr+2], ax 
cli 
mov word [es:9*4], kbisr 
mov [es:9*4+2], cs 
sti
mov ax, 0x4c00 
int 0x21