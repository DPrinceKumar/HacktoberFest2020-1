import hashlib
print("SHA-1")
hash_object=hashlib.sha1(b'hello')
hex_dig=hash_object.hexdigest()
print(hex_dig)
print("MD5")
string=input("enter string to hash:")
hash_object=hashlib.md5(string.encode())
print(hash_object.hexdigest())
