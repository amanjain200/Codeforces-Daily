import socket

# Create a TCP/IP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port
server_address = ('localhost', 8080)
server_socket.bind(server_address)

# Listen for incoming connections
server_socket.listen(1)

# Configure socket options
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)

server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, 4096)  # Send buffer size
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 4096)  # Receive buffer size
server_socket.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)  # Disable Nagle's algorithm

# Print configured options
keepalive = server_socket.getsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE)
linger = server_socket.getsockopt(socket.SOL_SOCKET, socket.SO_LINGER)
sndbuf = server_socket.getsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF)
rcvbuf = server_socket.getsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF)
tcp_nodelay = server_socket.getsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY)

print(f'SO_KEEPALIVE: {keepalive}')
print(f'SO_LINGER: {linger}')
print(f'SO_SNDBUF: {sndbuf}')
print(f'SO_RCVBUF: {rcvbuf}')
print(f'TCP_NODELAY: {tcp_nodelay}')

# Accept and handle a connection
connection, client_address = server_socket.accept()
try:
    print('Connection from', client_address)
    while True:
        data = connection.recv(1024)
        if data:
            connection.sendall(data)
        else:
            break
finally:
    connection.close()
    server_socket.close()
