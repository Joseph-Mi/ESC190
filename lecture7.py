import ctypes

def deref(addr, typ):
  return ctypes.cast(addr,ctypes.POINTER(typ))

def change_a(a):
  deref(id(a), ctypes.c_int)[6] = 43

a = 59000
change_a(a)
print(a)

change_a(42)
print(42)

s = "abc"
s = s + "d" #not changing vlaue of s, but reassigning value to s