import socket

# Define server IP and port
SERVER_IP = '127.0.0.1'
SERVER_PORT = 80

# Open UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((SERVER_IP, SERVER_PORT))

while True:
    data, addr = server_socket.recvfrom(1024)
    message = data.decode('utf-8')

    if message.startswith('TNE20003:') and len(message.split(':')) == 2:
        client_msg = message.split(':')[1]
        if client_msg:
            if ("Hello" in client_msg):
                response = f"TNE20003:A: Hi Rifa!"
            else:
                response = f"TNE20003:A: Goodbye from server Rifa!"
        else:
            response = "TNE20003:E:Empty message"
    else:
        response = "TNE20003:E:Invalid message format"

    server_socket.sendto(response.encode('utf-8'),addr)