import random
import time
import tkinter as tk
from paho.mqtt import client as mqtt_client
import threading

### MQTT Broker Settings ###
broker = 'rule28.i4t.swin.edu.au'
port = 1883
topic = "103799026/alarm/sensor"
client_id = "s103799026-alarm"
username = "103799026"
password = "103799026"

# Publishes a message to a topic
def publisher(client, topic, msg):
    client.publish(topic, msg)
    log(f"Published `{msg}` to topic `{topic}`")
    print(f"Published `{msg}` to topic `{topic}`")

# Confirms connection established with MQTT Broker
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Motion Sensor Connected to MQTT Broker!")
    else:
        print(f"Failed to connect, return code {rc}")

# is used to connect to the MQTT Broker
def connect_mqtt():
    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.connect(broker, port)
    client.on_connect = on_connect
    return client

# Simulates motion detection using random choice
def simulate_motion_detection(client):
    while True:
        time.sleep(5)  # Check for motion every 5 seconds
        motion_detected = random.choice(
            [True, False])  # Simulate motion detection
        if motion_detected:
            publisher(client, topic, "Motion Detected")
        else:
            publisher(client, topic, "No Motion")

# Create the MQTT client and start the simulation in a separate thread
client = connect_mqtt()
client.loop_start()

mqtt_thread = threading.Thread(target=simulate_motion_detection, args=(client,))
mqtt_thread.daemon = True
mqtt_thread.start()

## GUI Code ##
def log(message):
    text_area.insert(tk.END, message + "\n")
    text_area.see(tk.END)  # auto-scroll to the end

root = tk.Tk()
root.title("Alarm System Interface")

frame = tk.Frame(root)
frame.pack(pady=20)

text_area = tk.Text(root, height=20, width=80)
text_area.pack(padx=20, pady=20)

root.mainloop()
