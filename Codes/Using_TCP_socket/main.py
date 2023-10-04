import socket

# Define the host and port
host = "www.google.com"
port = 80

# Create a socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
client_socket.connect((host, port))

# Construct the HTTP request
request = "GET / HTTP/1.0\r\nHost: www.google.com\r\n\r\n"

# Send the request to the server
client_socket.send(request.encode())

# Receive and save the response to a file
response = b""
while True:
    data = client_socket.recv(1024)
    if not data:
        break
    response += data


# Close the socket
client_socket.close()

# Check the Content-Type header
headers, _, body = response.partition(b'\r\n\r\n')
header_lines = headers.split(b'\r\n')
content_type = None
for line in header_lines:
    if line.startswith(b'Content-Type:'):
        content_type = line.split(b':', 1)[1].strip()



# print ("GET / HTTP/1.0\r\nHost: www.google.com\r\n\r\n")

# Save the response to a file if it's text data
if content_type and b'text/html' in content_type:
    with open('google_response.txt', 'wb') as file:
        file.write(body)
    print("Response saved to google_response.txt")
else:
    print("Received binary data. Not saving to a text file.")

