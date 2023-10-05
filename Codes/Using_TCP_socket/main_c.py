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

# Receive and process the response
response = b""
while True:
    data = client_socket.recv(1024)
    if not data:
        break
    response += data

# Close the socket
client_socket.close()

# Split the response into HTTP response, headers, and HTML content
header_data, _, html_content = response.partition(b'\r\n\r\n')

# Convert the header data to a dictionary
headers = {}
header_lines = header_data.decode('utf-8', errors='ignore').split('\r\n')
for line in header_lines:
    if ':' in line:
        key, value = line.split(':', 1)
        headers[key.strip()] = value.strip()

# Extract response code and message or set defaults
response_code = headers.get('HTTP/1.0', '200 OK')[0:3]
response_message = headers.get('HTTP/1.0', '200 OK')[4:]

# Display response code and message
print(f"Response Code: {response_code}")
print(f"Response Message: {response_message}")

# Display headers
print("\nHeaders:")
for key, value in headers.items():
    print(f"{key}: {value}")

# Check the HTTP response code
if response_code == '200':
    # Display HTML content
    with open('google_response_c.html', 'wb') as file:
        file.write(html_content)
    print("HTML content saved to google_response_c.html")
else:
    print("\nError: HTTP Response Code is not 200.")
