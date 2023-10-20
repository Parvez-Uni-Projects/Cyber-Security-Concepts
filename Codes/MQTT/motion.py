from paho.mqtt import client as mqtt_client

broker = 'rule28.i4t.swin.edu.au'
port = 1883
topic_sensor = "103799026/motion_sensor/status"
topic_command = "103799026/alarm/command"
client_id = "s103799026-alarm-motion"
username = "103799026"
password = "103799026"
alarm_active = False

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("GUI Connected to MQTT Broker!")
        client.subscribe(topic_sensor)
        client.subscribe(topic_command)
        print("Subscribed to topics:", topic_sensor, topic_command)
    else:
        print("Failed to connect, return code %d\n", rc)

def on_message(client, userdata, msg):
    global alarm_active
    payload = msg.payload.decode()
    if msg.topic == topic_sensor and payload == "Motion Detected" and alarm_active:
        print("ALARM TRIGGERED!")
    elif msg.topic == topic_command:
        if payload == "Activate":
            alarm_active = True
            print("Alarm Activated!")
        elif payload == "Deactivate":
            alarm_active = False
            print("Alarm Deactivated!")

def connect_mqtt():
    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.connect(broker, port)
    client.on_connect = on_connect
    client.on_message = on_message
    return client

client = connect_mqtt()
client.loop_forever()