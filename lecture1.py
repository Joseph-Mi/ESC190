# want to create deep copy of lists
#if i can create deep copy of simple lists, i can create deep copy of more complicated (arbitrary) lists

#to create deep copy of L, make new list [deepcopy([0]), deepcopy(L[1]), ...]  

def deepcopy(L):  
  '''return a Dcopy of L, which is either a list ot list of ... ints or an int'''
  if type(L) != list:
    return 

  res = []
  for e in L:
    if type(e) == list:
      res.append(deepcopy(e))
    else:
      res.append(e)
  return res

L = [[[[1, 2]], 5], 2]

#shallow copy of L:
L2 = L[:] # or L2 = L.copy() - only works with lists 
#shallow copy means that L and L2 are separate lists, but the elements of L and L2 are aliases
#changing L[0] DN change L2[0]
# changing L[0] is the same as changing the contents of L2
## L[0][0] = 3 changes L2[0][0] to 3 as well



###########################################################
alphabet = "abcdefg"

'''for letter1 in alphabet:
  for letter2 in alphabet:
    for letter3 in alphabet:
      print(letter1 + letter2 + letter3)'''

for letter1 in alphabet:
  #use a helper function to get all completions
  pass

def all_str(k, alphabet):
  '''return a list of all strs of length k over alphabet'''
  if k == 0:
    return [""]
  
  res = []
  for letter in alphabet:
    all_k1_str = all_str(k-1, alphabet)
    for string in all_k1_str:
      res.append(letter + string)
  return res

result = all_str(1, "abc")
print(result)