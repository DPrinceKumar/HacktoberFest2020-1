def symmetric_difference(a, b):
  _a, _b = set(a), set(b)
  return [item for item in a if item not in _b] + [item for item in b if item not in _a]
  
  #input
  #symmetric_difference([1, 2, 3], [1, 2, 4]) 
  #output
  #[3, 4]
