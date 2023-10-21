from paho.mqtt import client as mqtt_client
import tkinter as tk
import winsound
from tkinter import *
from PIL import Image

broker = 'rule28.i4t.swin.edu.au'
port = 1883
topic_sensor = "103799026/motion_sensor/status"
topic_command = "103799026/alarm/command"
client_id = "s103799026-alarm-motion"
username = "103799026"
password = "103799026"
alarm_active = False

beep_duration = 1000

# subscribe to topics
def subscriber():
    client.subscribe(topic_command)
    print("Subscribed to topics:", topic_sensor, topic_command)

# Confirms connection established with MQTT Broker
def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("GUI Connected to MQTT Broker!")
        subscriber()
    else:
        print("Failed to connect, return code %d\n", rc)


# takes in the message and updates the motion status
def on_message(client, userdata, msg):
    global alarm_active
    payload = msg.payload.decode()

    if msg.topic == topic_command and payload == "Activate":
            activate_alarm()
    elif payload == "Deactivate":
            deactivate_alarm()

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

# GUI code

# to activate the alarm
def activate_alarm():
    global alarm_active
    alarm_active = True
    count = 0
    showAnimation = None
    switch_image(count)
    # play_beep()
    winsound.Beep(1000, 1000)  # Beep for 1 second 
    print("Alarm Activated!")

# to deactivate the alarm
def deactivate_alarm():
    global alarm_active
    alarm_active = False
    print("Alarm Deactivated!")
def create_main_window():
    root = tk.Tk()
    root.geometry("800x550")
    root.config(background='#108cff')
    return root

def load_gif_frames(gifImage):
    openImage = Image.open(gifImage)
    frames = openImage.n_frames
    imageObject = [PhotoImage(file=gifImage, format=f"gif -index {i}") for i in range(frames)]
    return imageObject, frames

# Function to switch between the still image (frame 0) and the animated GIF
def switch_image(count):
        if alarm_active:
            newImage = imageObject[count]
            gif_Label.configure(image=newImage)
            count += 1
            if count == frames:
                count = 0
            showAnimation = root.after(50, lambda: switch_image(count))
        else:
            # Display the still image (frame 0)
            gif_Label.configure(image=imageObject[0])

def configure_alarm_gif():
    count = 0
    showAnimation = None
    switch_image(count)

def main():
    # Create the main application window
    global root, imageObject, frames, gif_Label
    root = create_main_window()

    gifImage = "alarm.gif"
    imageObject, frames = load_gif_frames(gifImage)
    gif_Label = Label(root, image="")
    gif_Label.place(x=155, y=20, width=450, height=500)

    configure_alarm_gif()

    frame = tk.Frame(root)
    frame.pack(pady=20)

    # Create and configure widgets
    label = tk.Label(root, text="Alarm System")


    # Place widgets on the window
    label.pack(pady=10)
 

    # Start the GUI event loop
    root.mainloop()

if __name__ == "__main__":
    main()
