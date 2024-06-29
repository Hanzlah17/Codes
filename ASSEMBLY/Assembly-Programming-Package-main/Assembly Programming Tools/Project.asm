[org 0x0100]
jmp start
tickcount: dw 0
score:
 dw 0
seconds:
dw 60
minutes:
dw 5
scor:
 db '    SCORE      ',0
 Tim:
 db '    TIME       ',0
 Nxtshape:
 db '         NEXT SHAPE          ',0
oldisr: dd 0 
xcordinate:
 dw 30
 ycordinate:
 dw 2
 randNum:
 dw 0
 oldrandNum:
 dw 0
valid: db 1
cmpcolor: db 0
rowNumber: db 20
scroll: db 0
 clearscreen:
 push ax
 push es
 push cx
 push di
 mov cx,2000
 xor di,di
 mov ax,0xb800
 mov es,ax
 mov ax,0x0020
 cld 
 rep stosw
 pop di
 pop cx
 pop es
 pop ax
 ret
 strlen:
 push bp
 mov bp,sp
 push es
 push cx
 push di
 les di,[bp+4]
 mov cx,0xffff
 xor al,al
 repne scasb
 mov ax,0xffff
 sub ax,cx
 dec ax
 pop di
 pop cx
 pop es
 pop bp
 ret 4
;This function will take attribiute and create a pattern based on value in ah at position di
MakeSquareWithBoundary:
push bp
mov bp, sp
push es
push ax
push dx
push di
push cx

mov ax, 0xb800
mov es, ax
mov dx, 3
mov ah, [bp+4]
mov al,0xdc  ;0xdc

; Draw the top boundary of the square
mov cx, 3
rep stosw
; Draw the bottom boundary of the square
add di,314
mov cx, 3
rep stosw
; Draw the sides of the square
sub di,322
mov cx, 2
mov al,0xde ;de
add di,154
lrside:
mov [es:di],ax
add di,6
mov [es:di],ax
add di,154
dec cx
jnz lrside
mov al,0xdb


pop cx
pop di
pop dx
pop ax
pop es
pop bp
ret 2
;different shapes
;-----------
Line:
push bp
mov bp,sp
push di
push cx
push ax
mov cx,3
mov ax,[bp+4]; color attribute
lineloop:
push ax
call MakeSquareWithBoundary
add di,6
dec cx
jnz lineloop
pop ax
pop cx
pop di
pop bp
ret 2
;---------
SingleSquare:
push bp
mov bp,sp
push ax
mov ax,[bp+4]
push ax
call MakeSquareWithBoundary
pop ax
pop bp
ret 2
;---------------
Lshape:
push di
push ax
call SingleSquare
push ax
add di,320
call Line
pop di
ret
;-----------------
TShape:
push di
push ax
call Line
push ax
add di,326
call SingleSquare
pop di 
ret
;------------
DoubleLine:
push di
push ax
call Line
add di,320
push ax
call Line
pop di
ret 
;-------------
Sqaure:
push di
push ax
call SingleSquare
add di,6
push ax
call SingleSquare
sub di,6
add di,320
push ax
call SingleSquare
add di,6
push ax
call SingleSquare
pop di
ret
;this function will make pattern based on number in ax at position passed as parameter
CreatePattern:
push bp
mov bp,sp
push ax
push cx
mov cx,ax
push di
push si
mov si,di
;;determining pattern 
cmp cx,1
je P1
cmp cx,2
je P2
cmp cx,3
je P3
cmp cx,4
je P4
cmp cx,5
je P5
cmp cx,6
je P6
jmp exit
P1:
mov byte[cmpcolor],0 
call canMakeSquare
cmp byte[valid],0
je exit
mov ax,0x01
push ax
call SingleSquare
jmp exit
P2:
mov byte[cmpcolor],0 
call PlaceLine
cmp byte[valid],0
je exit
mov ax,0x04
push ax
call Line
jmp exit
P3:
mov byte[cmpcolor],0 
call canMakeSquare
cmp byte[valid],0
je exit
add si,320
call PlaceLine
cmp byte[valid],0
je exit
mov ax,0x02
call Lshape
jmp exit
P4:
mov byte[cmpcolor],0 
call PlaceLine
cmp byte[valid],0
je exit
add si,320
call PlaceLine
cmp byte[valid],0
je exit
mov ax,0x03
call DoubleLine
jmp exit
P5:
mov byte[cmpcolor],0 
call canMakeSquare
cmp byte[valid],0
je exit
add si,6
call canMakeSquare
cmp byte[valid],0
je exit
add si,314
call canMakeSquare
cmp byte[valid],0
je exit
add si,6
call canMakeSquare
cmp byte[valid],0
je exit
mov ax,0x05
call Sqaure
jmp exit
P6:
mov byte[cmpcolor],0 
call PlaceLine
cmp byte[valid],0
je exit
add si,326
call canMakeSquare
cmp byte[valid],0
je exit
mov ax,0x06
call TShape
jmp exit
exit:
pop si
pop di
pop cx
pop ax
pop bp
ret 
CreateblackPattern:
push bp
mov bp,sp
push ax
push cx
push di
mov cx,ax
mov ax,0
;;determining pattern 
cmp cx,1
je Pb1
cmp cx,2
je Pb2
cmp cx,3
je Pb3
cmp cx,4
je Pb4
cmp cx,5
je Pb5
cmp cx,6
je Pb6
jmp bexit
Pb1:
push ax
call SingleSquare
jmp bexit
Pb2:
push ax
call Line
jmp bexit
Pb3:
call Lshape
jmp bexit
Pb4:
call DoubleLine
jmp bexit
Pb5:
call Sqaure
jmp bexit
Pb6:
call TShape
jmp bexit
bexit:
pop di
pop cx
pop ax
pop bp
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
 PrintText:
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	push ds 
	mov ax, [bp+4]
	push ax
	call strlen
	cmp ax, 0 
	jz exitt
	mov cx, ax 
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	mul byte [bp+8] 
	add ax, [bp+10]
	shl ax, 1 
	mov di,ax 
	mov si, [bp+4] 
	mov ah, [bp+6] 
	cld 
	nextchar: lodsb 
	stosw 
	loop nextchar
	exitt:
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 8
	
	CheckSingleRow:
push es
push ax
push cx
push di
mov ax,0xb800
mov al, 80 
mul byte [rowNumber] 
add ax, 2
shl ax, 1 
mov di,ax
mov ax,0xb800
mov es,ax
mov cx,48
rowcheck:
mov ax,[es:di]
cmp ah,0x00
je nomatch
add di,2
loop rowcheck
mov byte[scroll],1
jmp rExit
nomatch:
mov byte[scroll],0
rExit:
pop di
pop cx
pop ax
pop es
ret
CheckLine:
push ax
mov byte[rowNumber],20
loopline:
call CheckSingleRow
cmp byte[scroll],1
je scrollcase
sub byte[rowNumber],4
cmp byte[rowNumber],2
jnl loopline
jmp chExit
scrollcase:
add word[score],10
call timedelay
call timedelay
call RemoveLine

chExit:
pop ax
ret

RemoveLine:
push cx
mov cx,4
removeLoop:
call scrolldown
loop removeLoop
pop cx
ret
scrolldown:
push ax
push cx
push si
push di
push es
push ds
mov di, 3622
mov si,di
sub si,160
mov ax,0xb800
mov es,ax
mov ds,ax
scrollloop1:
mov cx,50
scrollloop2:
std
rep movsw
sub di,60
sub si,60
cmp di,62
jnl scrollloop1
mov cx,50
mov di,2
cld 
mov ax,0x0720
rep stosw
pop ds
pop es
pop di
pop si
pop cx
pop ax
ret 
PrintScore:
 push ax
 mov ax,55
 push ax
 mov ax,5
 push ax
 mov ax,0x0f ;color of text
 push ax
 mov ax,[score]
 push ax
 call Printnumber
 pop ax
 ret
 PrintTime:
 push ax
 push es
 cmp word[minutes],0
 je timexit
 cmp word[seconds],0
jne printingtime
dec word[minutes]
mov word[seconds],59
printingtime:
mov ax,0xb800
mov es,ax
mov ah,0x0f
mov al,'0'
mov [es:934],ax
mov ax,[minutes]
add al,0x30
mov ah,0x0f
mov [es:936],ax
mov al,':'
mov [es:938],ax
mov ax,70
push ax
mov ax,5
push ax
mov ax,0x0f ;color of text
push ax
mov ax,[seconds]
push ax
call Printnumber 
 timexit:
 pop es
 pop ax
 ret
 PrintScreen:
 push ax
 push es
 push cx
 push di
 mov cx,80
 xor di,di
 mov ax,0xb800
 mov es,ax
 mov ax,0x7720 ;upper boundary attribute
 cld 
 rep stosw ;upper boundary
 mov cx,80
 mov di,3840
 mov ax,0xb800
 mov es,ax
 mov ax,0x7720 ;lower boundary attribute
 cld 
 rep stosw ;lower boundary

 mov di,158
 mov cx,23
 next:
 add di,2
 mov [es:di],ax ;left boundary 
 add di,158
 mov [es:di],ax ; right boundary
 loop next 
 mov di,258
 mov cx,23
 ;mov ax,0x0020
 middleline:
 mov [es:di],ax ;middle boundary 
 add di,160
 loop middleline
 mov cx,30
 mov di,1700
 ;mov ax,0x0020
 cld 
 rep stosw ;lower-half boundary
 mov cx,9
 mov di,290
 ;mov ax,0x0020
 midhalf:
 mov [es:di],ax ;middle-half boundary 
 add di,160
 loop midhalf
 
 ;printing score and timer label
 ;score
 mov ax,50
 push ax
 mov ax,1
 push ax
 mov ax,0x7f ;color of text
 push ax
 mov ax,scor
 push ax
 call PrintText
 ;timer
 mov ax,66
 push ax
 mov ax,1
 push ax
 mov ax,0x7f ;color of text
 push ax
 mov ax,Tim
 push ax
 call PrintText
 ;nextshape
 mov ax,50
 push ax
 mov ax,11
 push ax
 mov ax,0x7f ;color of text
 push ax
 mov ax,Nxtshape
 push ax
 call PrintText
 pop di
 pop cx
 pop es
 pop ax
 ret
 ;-----------------------
timedelay:
push ax
push cx
mov cx,0xffff
l1:
mov ax,10
l2:
dec ax
jnz l2
dec cx
jnz l1
pop cx
pop ax
ret
Printtotal: 
push bp
mov bp, sp
push es
push ax
push bx
push cx
push dx
push di
push si
mov ax, 0xb800
mov es, ax 
mov ax, [score] 
mov bx, 10 
mov cx, 0 
nextdig: 
mov dx, 0 
div bx 
add dl, 0x30 
push dx 
inc cx 
cmp ax, 0 
jnz nextdig 
mov di,1360 ;position of score box
mov si,1516 ;position of score digit
createb:
mov ax,0x007f	;color
push ax
call MakeSquareWithBoundary
add si,4
mov word[es:si], 0x0720
add si,2
pop dx 
mov dh,0x0f; color of score
mov [es:si], dx 
add di,6
loop createb
pop si
pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret
DisplayEnd:
push es
push ax
push cx
push dx
push di
call clearscreen
mov ax,0xb800
mov es,ax
mov cx,40
mov di,670
mov ax,0x7f20 ;upper
rep stosw
mov ax,0x4b20;inner
mov dx,9
inner:
add di,120
mov cx,20
rep stosw
dec dx
jnz inner
mov cx,40
mov di,2270
mov ax,0x7f20;lower
rep stosw
call Printtotal
;score
mov ax,37
push ax
mov ax,6
push ax
mov ax,0xff ;color of text
push ax
mov ax,scor
push ax
call PrintText
mov di,996
mov cx,10
nextitr:
mov ax,1
nexts:
call CreatePattern
call timedelay
call CreateblackPattern
mov di,996
inc ax
cmp ax,7
jnz nexts
loop nextitr
pop di
pop dx
pop cx
pop ax
pop es
ret

;; keyboard isr
kbisr:
push ax
push es
mov ax, 0xb800
mov es, ax 
in al, 0x60 
cmp al, 0x4b ;;scan code for left key
jne nextcmp 
cmp word[xcordinate],2
jz notmatch
call RemoveShape
sub word[xcordinate],2
call MoveShape
jmp notmatch 
nextcmp:
cmp al, 0x4d ; scan code for right key
jne notmatch
call RemoveShape
add word[xcordinate],2
call MoveShape
cmp byte[valid],0
jnz notmatch
sub word[xcordinate],2
call MoveShape
notmatch: 
pop es
pop ax
jmp far [cs:oldisr] 
; timer interrupt service routine
timer: 
push ax
inc word [cs:tickcount]; increment tick count
cmp word[cs:tickcount],19
jl texit
mov word[cs:tickcount],0
dec word[cs:seconds] 
call PrintTime
cmp word[cs:minutes],0
je texit
call RemoveShape
inc word[ycordinate]
call MoveShape
cmp byte[valid],0
je reset
jmp texit
reset:
dec word[ycordinate]
cmp word[ycordinate],2
je gameEnd
call MoveShape
call CheckLine
mov word[ycordinate],2
mov word[xcordinate],30
mov ax,[randNum]
mov [oldrandNum],ax
mov ax,6
push ax
call randGen
call PrintNextShape
mov di,210
texit:
mov al, 0x20
out 0x20, al ; end of interrupt
pop ax
iret 
RemoveShape:
push ax
push di
mov al, 80 
mul byte [ycordinate] 
add ax, [xcordinate]
shl ax, 1 
mov di,ax
mov ax,[oldrandNum]
call CreateblackPattern
pop di
pop ax
ret
canMakeSquare:
push es
push ax
push cx
push di
push si
mov ax,0xb800
mov es,ax
check1:
mov cx,3
c1:
mov ax,[es:si]
cmp ah,[cmpcolor]
jnz notValid
add si,2
loop c1
sub si,6
checkdown:
mov cx,2
c2:
add si,160
mov ax,[es:si]
cmp ah,[cmpcolor]
jnz notValid
loop c2
mov byte[valid],1
jmp checkexit
notValid:
mov byte[valid],0
checkexit:
pop si
pop di
pop cx
pop ax
pop es
ret
PlaceLine:
push ax
push cx
push si
mov cx,3
ploop:
call canMakeSquare
cmp byte[valid],0
je pexit
add si,6
loop ploop
pexit:
pop si
pop cx
pop ax
ret
MoveShape:
push ax
push di
mov al, 80 
mul byte [ycordinate] 
add ax, [xcordinate]
shl ax, 1 
mov di,ax
mov ax,[oldrandNum]
call CreatePattern
pop di
pop ax
ret
randGen:
        push bp
        mov bp, sp
        push cx
        push dx
        push ax
        rdtsc                   
        xor dx,dx               
        mov cx, [bp + 4]
        div cx                  
		inc dl
		mov [randNum], dl  
        pop ax
        pop dx
        pop cx
        pop bp

        ret 2
;;---------------------------------
PrintNextShape:
push di
cmp word[minutes],0
je nexit
mov di,2520
mov ax,[oldrandNum]
call CreateblackPattern
mov ax,[randNum]
call CreatePattern
nexit:
pop di
ret
;;------------------------------------------------------------------------
start:
call clearscreen
;;timer 
xor ax, ax
mov es, ax 
cli 
mov word [es:8*4], timer
mov [es:8*4+2], cs 
sti

;;left right key
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
call PrintScreen
call PrintScore
mov ax,6
push ax
call randGen
mov ax,[randNum]
mov word[oldrandNum],ax
mov ax,6
push ax
call randGen
call PrintNextShape 
mov di,210
label1:
cmp word[minutes],0
jnz label1
gameEnd:
call clearscreen
call DisplayEnd
mov ax,0x4c00
int 21h