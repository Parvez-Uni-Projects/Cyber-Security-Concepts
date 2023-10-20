import socket

# Define server IP and port
SERVER_IP = '127.0.0.1'
SERVER_PORT = 80

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Send two messages to server
messages = ["TNE20003: Hello from client Rifa!", "TNE20003: okay" ,"TNE20004: okay"   ]
for msg in messages:
    client_socket.sendto(msg.encode('utf-8'), (SERVER_IP, SERVER_PORT))
    response, _ = client_socket.recvfrom(1024)
    print(f"Server Response: {response.decode('utf-8')}")