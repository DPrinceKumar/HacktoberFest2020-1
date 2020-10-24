import blinker_basic

while True:
	text = input('>> ')
	result, error = blinker_basic.run('<stdin>',text)

	if error: print(error.as_string())
	else: print(result)