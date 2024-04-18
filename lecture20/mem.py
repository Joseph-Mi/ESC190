def f(x):
    print("current arg:", x)
    print("prev arg:", f.mem)
    f.mem = x

f.mem = None
f(10)