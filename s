.model small
.code
mov ah, 2
mov dl, 'A'
l:int 33
add dl, 1
cmp dl, 'Z'
db 01111110b
db -10d
mov ah, 21h
int 33
end
