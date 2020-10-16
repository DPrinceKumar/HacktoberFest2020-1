import re

def words(s, pattern = '[a-zA-Z-]+'):
  return re.findall(pattern, s)
