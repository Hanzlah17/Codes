[org 0x0100]
jmp start
input:
db 'Enter a number:'
sum:
db 'Sum= '
Dif:
db 'Difference= '
Pro:
db 'Product= '
Divide:
db 'Division= '
num1:
dw 0
num2:
dw 0
temp:
dw 0
clearscreen:
push es
push ax
push cx
push di
mov ax,0xb800
mov es,ax
mov di,0
mov ax,0x0720
mov cx,2000
cld
rep stosw
pop di
pop cx
pop ax
pop es
ret
Printnumber: 
push bp
mov bp, sp
push es
push ax
push bx
push cx
push dx
push di
mov ax, 0xb800
mov es, ax 
mov ax, [bp+4] 
mov bx, 10 
mov cx, 0 
nextdigit: 
mov dx, 0 
div bx 
add dl, 0x30 
push dx 
inc cx 
cmp ax, 0 
jnz nextdigit 
mov al, 80 
mul byte [bp+8] 
add ax, [bp+10]
shl ax, 1 
mov di,ax 
nextpos: 
pop dx 
mov dh, [bp+6] 
mov [es:di], dx 
add di, 2 
loop nextpos 
pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 8
start:
call clearscreen
;;-------------
;;interept for printing
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
xor dx,dx 
mov cx, 15 
push cs
pop es 
mov bp, input 
int 0x10 
;;----------
mov ax,0xb800
mov es,ax
mov di,32
mov ah,0
int 16h
sub al,0x30
mov [num1],al
add al,0x30
mov ah,0x0f
mov [es:di],ax
;;interept for printing
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
mov dx,0x0100
mov cx, 15 
push cs
pop es 
mov bp, input 
int 0x10 
;;----------
mov ax,0xb800
mov es,ax
mov di,192
cin:
mov ah,0
int 16h
sub al,0x30
cmp al,0
jz cin
mov [num2],al
add al,0x30
mov ah,0x0f
mov [es:di],ax
;;-----------------
mov ax,[num1]
add ax,[num2]
mov [temp],ax
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
mov dx,0x0200 
mov cx, 5
push cs
pop es 
mov bp, sum 
int 0x10
;;
mov ax,5
push ax
mov ax,2
push ax
mov ax,0x0f
push ax
mov ax,[temp]
push ax
call Printnumber
;;--------------
mov ax,[num1]
sub ax,[num2]
mov [temp],ax
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
mov dx,0x0300 
mov cx, 11
push cs
pop es 
mov bp, Dif 
int 0x10
;;
mov ax,12
push ax
mov ax,3
push ax
mov ax,0x0f
push ax
mov ax,[temp]
push ax
call Printnumber
;;--------------
mov ax,[num1]
mul byte [num2]
mov [temp],ax
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
mov dx,0x0400 
mov cx, 8
push cs
pop es 
mov bp, Pro
int 0x10
;;
mov ax,9
push ax
mov ax,4
push ax
mov ax,0x0f
push ax
mov ax,[temp]
push ax
call Printnumber
;---------
mov ax,[num1]
div byte [num2]
mov [temp],al
mov [temp],ax
mov ah, 0x13 
mov al, 0 
mov bh, 0
mov bl, 15 
mov dx,0x0500 
mov cx, 9
push cs
pop es 
mov bp, Divide
int 0x10
;;
mov ax,10
push ax
mov ax,5
push ax
mov ax,0x0f
push ax
mov ax,[temp]
push ax
call Printnumber
mov ax,0x4c00

int 21h




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