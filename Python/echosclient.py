import socket 
HOST = '127.0.0.1'  #server's hostname or IP Address
PORT = 65432    #port used bye server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
	s.connect((HOST, PORT))
	s.sendall(b'today is funday')
	data = s.recv(1024)

print('Recieved',repr(data))