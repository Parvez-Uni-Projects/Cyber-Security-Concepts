import tkinter as tk
from paho.mqtt import client as mqtt_client

# MQTT Broker Settings ###
broker = 'rule28.i4t.swin.edu.au'
port = 1883
topic_command = "103799026/alarm/command"
topic_sensor = "103799026/alarm/sensor"
client_id = "s103799026-alarm-gui"
username = "103799026"
password = "103799026"


#  Publishes a message to a topic
def publisher(topic, msg):
    # example: publisher("103799026/alarm/sensor", "Motion Detected")
    client.publish(topic, msg)
    print(f"Published `{msg}` to topic `{topic}`")

# Subscribes to topics
def subscriber():
    client.subscribe(topic_sensor)
    print("Subscribed to topics:", topic_sensor)

# Confirms connection established with MQTT Broker
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("GUI Connected to MQTT Broker!")
        subscriber()
    else:
        print("Failed to connect, return code %d\n", rc)


def on_message(client, userdata, msg):
    payload = msg.payload.decode()
    if msg.topic == topic_sensor:
        update_motion_status(payload)
        log(f"Received sensor feedback: {payload}")
    else:
        log(f"Received msg: {payload}")

# is used to connect to the MQTT Broker
def connect_mqtt():
    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.connect(broker, port)
    client.on_connect = on_connect
    client.on_message = on_message
    return client


client = connect_mqtt()

client.loop_start()


# GUI functions
def activate_alarm():
    publisher(topic_command, "Activate")
    log("Alarm Activated!")


def deactivate_alarm():
    publisher(topic_command, "Deactivate")
    log("Alarm Deactivated!")


def update_motion_status(status):
    motion_status_label.config(text=f"Motion Status: {status}")


def log(message):
    text_area.insert(tk.END, message + "\n")
    text_area.see(tk.END)  # auto-scroll to the end


# Create GUI
root = tk.Tk()
root.title("Alarm System Interface")

frame = tk.Frame(root)
frame.pack(pady=20)

btn_activate = tk.Button(frame, text="Activate", command=activate_alarm)
btn_activate.grid(row=0, column=0, padx=20)

btn_deactivate = tk.Button(frame, text="Deactivate", command=deactivate_alarm)
btn_deactivate.grid(row=0, column=1, padx=20)

motion_status_label = tk.Label(root, text="Motion Status: No Motion")
motion_status_label.pack(pady=10)

text_area = tk.Text(root, height=10, width=50)
text_area.pack(padx=20, pady=20)

root.mainloop()

client.loop_stop()
