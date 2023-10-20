import random
import time
from paho.mqtt import client as mqtt_client

broker = 'rule28.i4t.swin.edu.au'
port = 1883
topic = "103799026/alarm/command"
client_id = "s103799026-alarm"
username = "103799026"
password = "103799026"

def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Motion Sensor Connected to MQTT Broker!")
        else:
            print(f"Failed to connect, return code {rc}")
        
def connect_mqtt():
    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.connect(broker, port)
    client.on_connect = on_connect
    return client

def simulate_motion_detection(client):
    while True:
        time.sleep(5)  # Check for motion every 5 seconds
        motion_detected = random.choice([True, False])  # Simulate motion detection
        if motion_detected:
            # print("Motion Detected!")
            client.publish(topic, "Motion Detected")
        else:
            # print("No Motion")
            client.publish(topic, "No Motion")

client = connect_mqtt()
client.loop_start()
simulate_motion_detection(client)