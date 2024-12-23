import string

def decrypt(ciphertext):
    original_alphabet = string.ascii_lowercase + string.ascii_uppercase
    
    shifted_alphabet = string.ascii_lowercase[2:] + string.ascii_lowercase[:2] + string.ascii_uppercase[2:] + string.ascii_uppercase[:2]
    
    translation_table = str.maketrans(original_alphabet, shifted_alphabet)
    
    decrypted_text = ciphertext.translate(translation_table)
    
    return decrypted_text

ciphertext = "g fmnc wms bgblr rpylqjyr gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."

decrypted_text = decrypt(ciphertext)
print(decrypted_text)
