section .data					; data段，数据段，用于保存全局变量
	msg db "hello world",0ah	; msg是变量名 db是msg的数据类型 字节类型，每个字符都是一个字节，最后的0ah是紧跟着字符串的一个ASCII码，可以视为字符串的一部分代表换行符
	len equ $-msg				; len是变量名，用于储存msg的长度，equ表示len代表后边的表达式 $代表当前段的偏移值，因为段中有了msg，所以$偏移了msg长度的大小，而用$减去msg的首地址，就得到了msg的长度
 
section .text					; text段，代码段，用于保存要执行的指令
global _start					; global让_start符号全局可见，两者放到一起就是给代码起始地址定义全局标记  linux寻找这个 _start 标签作为程序的默认进入点。
_start:
	mov eax,4d					; 因为此处为32位程序，所以系统调用中32位的4号函数为写
	mov ebx,1d					; 将文件描述符设为1 文件描述符1为标准输出
	mov ecx,msg					; 将写的首地址设为msg的首地址
    mov edx,len					; 将写的最大长度设为len
    int 80h 					; 执行系统调用
    
    mov eax, 1d					; 32位系统调用1号为退出
    mov ebx, 0d					; 将退出时的状态码设为0代表正常退出
    int 80h						; 执行系统调用